#include "spring.hpp"

Spring::Spring(float _x, float _y, string n, float wid, float hei)
	   : Shape(_x, _y, n, wid, hei){}

void Spring::draw(Window *window){
	window->draw_img(SPRING_IMG, Rectangle(x, y, SPRING_WIDTH, SPRING_HEIGHT));
}