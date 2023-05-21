#include "functions.hpp"

using namespace std;

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 1000
#define	DOODLE "doodle"
#define DOODLE_START_PLACE_WID 258
#define DOODLE_START_PLACE_HEI 880
#define DOODLE_WIDTH 124
#define DOODLE_HEIGHT 120
#define DELAY_TIME 0.005

int main(){
	Window *window = new Window(WINDOW_WIDTH, WINDOW_HEIGHT, "RSDL Demo");
	Doodle doodle(DOODLE_START_PLACE_WID, DOODLE_START_PLACE_HEI, DOODLE, DOODLE_WIDTH, DOODLE_HEIGHT);
	vector<Shape*> shapes;
	bool key_down = false;
	bool finish_game = false;
	bool check_finish = false;
	int check_pressed_char = 0;
	get_map(shapes, window);
	while(true){
		update(window, doodle, shapes, key_down, check_pressed_char, finish_game);
		for (int i = 0; i < shapes.size(); i++) {
			if(shapes[i]->get_y() > WINDOW_HEIGHT){
				delete shapes[i];
				shapes.erase(shapes.begin() + i);
			}
		}
		if(check_finish == false){
			draw(window, doodle, shapes, check_pressed_char, finish_game, check_finish);
			delay(DELAY_TIME * 100);
		}
	}
	return 0;
}