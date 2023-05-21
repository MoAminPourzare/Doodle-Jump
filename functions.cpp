#include "functions.hpp"

using namespace std;

void get_map(vector<Shape*>& shapes, Window *window){
	int number_of_entities;
	float map_x, map_y;
	string map_name;
	ifstream map(MAP);
	map >> number_of_entities;
	while(map >> map_x){
		map >> map_y;
		map >> map_name;
		if(map_name == PLATFORM){
			sort_shapes(map_y, PLATFORM_HEIGHT, window);
			Platform *platform = new Platform(map_x, map_y, PLATFORM, PLATFORM_WIDTH, PLATFORM_HEIGHT);
			shapes.push_back(platform);
		}
		else if(map_name == MPLATFORM){
			sort_shapes(map_y, PLATFORM_HEIGHT, window);
			MPlatform *mplatform = new MPlatform(map_x, map_y, MPLATFORM, PLATFORM_WIDTH, PLATFORM_HEIGHT);
			shapes.push_back(mplatform);
		}
		else if(map_name == BPLATFORM){
			sort_shapes(map_y, PLATFORM_HEIGHT, window);
			BPlatform *bplatform = new BPlatform(map_x, map_y, BPLATFORM, PLATFORM_WIDTH, PLATFORM_HEIGHT);
			shapes.push_back(bplatform);
		}
		else if(map_name == SPRING){
			sort_shapes(map_y, SPRING_HEIGHT, window);
			Spring *spring = new Spring(map_x, map_y, SPRING, SPRING_WIDTH, SPRING_HEIGHT);
			shapes.push_back(spring);
		}
		else if(map_name == ENEMY){
			sort_shapes(map_y, ENEMY_HEIGHT, window);
			Enemy *enemy = new Enemy(map_x, map_y, ENEMY, ENEMY_WIDTH, ENEMY_HEIGHT);
			shapes.push_back(enemy);
		}
	}
	map.close();
}

void sort_shapes(float& map_y, int height, Window *window){
	map_y = window->get_height() - map_y;
	map_y = map_y - height;
}

void update(Window *window, Doodle& doodle, vector<Shape*> shapes, bool& key_down, int& check_pressed_char, bool& finish_game){
	Event event;
	char pressed_char;
	if(doodle.get_y() > window->get_height()){
		finish_game = true;
	}
	if (window->has_pending_event()) {
		event = window->poll_for_event();
		pressed_char = event.get_pressed_key();
		if(pressed_char == 'd')
			check_pressed_char = RIGHT;
		else if(pressed_char == 'a')
			check_pressed_char = LEFT;
		if(event.get_type() == Event::EventType::QUIT)
			exit(0);
		if(event.get_type() == Event::EventType::KEY_PRESS)
			key_down = true;
	}
	if (key_down == true) {
		if(check_pressed_char == RIGHT)
			doodle.move(MOVE_RIGHT);
		else if(check_pressed_char == LEFT)
			doodle.move(MOVE_LEFT);
	}
	doodle.exit_the_page(doodle, window);
	event = window->poll_for_event();
	if (event.get_type() == Event::EventType::KEY_RELEASE)
		key_down = false;
	doodle.update(shapes, window);
	mplatforms_update(shapes, window);
	doodle_move(window, doodle, shapes, finish_game);
}

void mplatforms_update(vector<Shape*>& shapes, Window *window){
	for (int i = 0; i < shapes.size(); ++i) {
		if(shapes[i]->get_name() == MPLATFORM)
			shapes[i]->move_mplatform(window);
	}
}

void draw(Window *window, Doodle& doodle, vector<Shape*> shapes, int check_pressed_char, bool& finish_game, bool& check_finish) {
	window->clear();
	window->draw_img(BACKGROUND_IMG, Rectangle(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT));
	if(doodle.get_vy() == START_VELOCITY || doodle.get_vy() == START_VELOCITY * 2)
		doodle.change_when_jump();
	if(doodle.get_when_junp() >= START_BENDING_LEGS)
		doodle.change_when_jump();
	doodle.draw(window, check_pressed_char);
	doodle.show_score(window, finish_game);
	for (int i = 0; i < shapes.size(); ++i) {
		if(shapes[i]->get_name() == BPLATFORM)
			if(shapes[i]->get_check_when_b() == true)
				shapes[i]->change_when_breaking();
		shapes[i]->draw(window);
	}
	if(finish_game == true) {
		window->draw_img(GAMEOVER_IMG, Rectangle(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT));
		window->show_text("YOUR HIGH SCORE : ", Point(50, SHOW_SCORE_HEIGHT), RGB (255, 0, 0), FREESANS_FONT, 38);
		window->show_text(doodle.get_final_score(), Point(SHOW_SCORE_WIDTH, SHOW_SCORE_HEIGHT), RGB (255, 0, 0), FREESANS_FONT, 38);
		check_finish = true;
	}
	window->update_screen();
}

void doodle_move(Window *window, Doodle& doodle, vector<Shape*> shapes, bool& finish_game){
	for (int i = 0; i < shapes.size(); ++i) {
		if(shapes[i]->get_name() == ENEMY){
			if(doodle.get_x() + doodle.get_width() >= shapes[i]->get_x()
				&& doodle.get_x() <= shapes[i]->get_x() + shapes[i]->get_width()
				&& doodle.get_y() + doodle.get_height() >= shapes[i]->get_y()
				&& doodle.get_y() <= shapes[i]->get_y() + shapes[i]->get_height())
				doodle.collision_enemy(finish_game);
		}
		else {
			if(doodle.get_y() + doodle.get_height() >= shapes[i]->get_y()
				&& doodle.get_y() + doodle.get_height() <= shapes[i]->get_y() + shapes[i]->get_height()
				&& doodle.get_x() + doodle.get_width() >= shapes[i]->get_x()
				&& doodle.get_x() <= shapes[i]->get_x() + shapes[i]->get_width()
				&& doodle.get_vy() > 0){
					if(shapes[i]->get_name() == PLATFORM || shapes[i]->get_name() == MPLATFORM)
						doodle.collision_plat();
					if(shapes[i]->get_name() == SPRING)
						doodle.collision_spring();
					if(shapes[i]->get_name() == BPLATFORM)
						shapes[i]->perform_animation();
			}
		}
	}
}