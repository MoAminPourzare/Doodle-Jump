#include "shape.hpp"

Shape::Shape(float _x, float _y, string n, float wid, float hei){
	x = _x;
	y = _y;
	name = n;
	size.width = wid;
	size.height = hei;
}

void Shape::change_y(float dy){
	y -= dy;
}