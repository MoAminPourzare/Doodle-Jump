#include "platform.hpp"

Platform::Platform(float _x, float _y, string n, float wid, float hei)
 		 : Shape(_x, _y, n, wid, hei){}

void Platform::draw(Window *window){
	window->draw_img(PLATFORM_IMG, Rectangle(x, y, PLATFORM_WIDTH, PLATFORM_HEIGHT));
}