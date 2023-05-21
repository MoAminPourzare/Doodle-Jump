#include "mplatform.hpp"

MPlatform::MPlatform(float _x, float _y, string n, float wid, float hei)
		  : Shape(_x, _y, n, wid, hei){}


void MPlatform::draw(Window *window){
	window->draw_img(MPLATFORM_IMG, Rectangle(x, y, PLATFORM_WIDTH, PLATFORM_HEIGHT));
}

void MPlatform::move_mplatform(Window *window){
	if(x + size.width < window->get_width() && move_direction == RIGHT)
		x += MOVE_RIGHT;
	else if(x > 0){
		move_direction = LEFT;
		x += MOVE_LEFT;
	}
	else
		move_direction = RIGHT;
}