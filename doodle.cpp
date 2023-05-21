#include "doodle.hpp"

Doodle::Doodle(float _x, float _y, string n, float wid, float hei)
	   : Shape(_x, _y, n, wid, hei){
	   	g = ACCELERATION;
	   	vy = START_VELOCITY;
	   	dy = 0;
	   	score = 0;
	   	first_achieved_s = 0;
	   	when_jumping = 0;
}

void Doodle::update(vector<Shape*>& shapes, Window *window){
	bool check = false;
	if(y >= MIDDLE_OF_PAGE){
		y += ((-1/2) * g * (DELAY_TIME) * (DELAY_TIME)) + (vy * DELAY_TIME);
		if(y < MIDDLE_OF_PAGE){
			dy = (((-1/2) * g * (DELAY_TIME) * (DELAY_TIME)) + (vy * DELAY_TIME)) - (MIDDLE_OF_PAGE - y);
		}
		if(first_achieved_s <= MIDDLE_OF_PAGE && first_achieved_s < WINDOW_HEIGHT - y)
			first_achieved_s = WINDOW_HEIGHT - y;
	}
	else if(vy >= 0)
		y += ((-1/2) * g * (DELAY_TIME) * (DELAY_TIME)) + (vy * DELAY_TIME);
	else if(y < MIDDLE_OF_PAGE){
		check = true;
		for (int i = 0; i < shapes.size(); ++i)
			shapes[i]->change_y(dy);
	}
	if(check == true)
		score -= dy;
	else if(first_achieved_s < MIDDLE_OF_PAGE)
		score = first_achieved_s;
	dy = ((-1/2) * g * (DELAY_TIME) * (DELAY_TIME)) + (vy * DELAY_TIME);
	vy += g * DELAY_TIME;
}

void Doodle::show_score(Window *window, bool& finish_game){
	stringstream ss;
	string s_score;
	ss << score;
	ss >> s_score;
	window->show_text(s_score, Point(50, 50), RGB (255, 0, 0), FREESANS_FONT, 38);
	if(finish_game == true)
		final_score = s_score;
}

void Doodle::draw(Window *window, int check_pressed_char){
	if(check_pressed_char == LEFT || check_pressed_char == 0){
		if(when_jumping == 0)
			window->draw_img(DOODLE_LEFT_IMG, Rectangle(x, y, size.width, size.height));
		else if(when_jumping >= 1 && when_jumping <= FINISH_BENDING_LEGS)
			window->draw_img(DOODLE_LEFT_J_IMG, Rectangle(x, y, size.width, size.height));
		if(when_jumping == FINISH_BENDING_LEGS)
			when_jumping = 0;
	}
	else if(check_pressed_char == RIGHT){
		if(when_jumping == 0)
			window->draw_img(DOODLE_RIGHT_IMG, Rectangle(x, y, size.width, size.height));
		else if(when_jumping >= 1 && when_jumping <= FINISH_BENDING_LEGS)
			window->draw_img(DOODLE_RIGHT_J_IMG, Rectangle(x, y, size.width, size.height));
		if(when_jumping == FINISH_BENDING_LEGS)
			when_jumping = 0;
	}
}

void Doodle::move(float d){
	x += d;
}

void Doodle::exit_the_page(Doodle doodle, Window *window){
	if(x > window->get_width())
		x = -size.width;
	if(x + size.width < 0)
		x = window->get_width();
}

void Doodle::collision_plat(){
	vy = START_VELOCITY;
}

void Doodle::collision_enemy(bool& finish_game){
	finish_game = true;
}

void Doodle::collision_spring(){
	vy = START_VELOCITY * 2;
}

void Doodle::change_when_jump(){
	when_jumping++;
}