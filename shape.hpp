#ifndef SHAPE_H
#define SHAPE_H

#include "rsdl.hpp"

using namespace std;

#define PLATFORM_IMG "pictures/platform.png"

class Shape {
public:
	Shape(float _x, float _y, string n, float len, float wid);
	float get_x() { return x; }
	float get_y() { return y; }
	float get_width() { return size.width; }
	float get_height() { return size.height; }
	string get_name() { return name; }
	virtual void draw(Window *window){}
	virtual void move_mplatform(Window *window){}
	virtual void change_y(float dy);
	virtual void perform_animation(){}
	virtual bool get_check_when_b(){ return true; }
	virtual void change_when_breaking(){}

protected:
	float x;
	float y;
	string name;
	struct Size {
		float width;
		float height;
	} size;
};

#endif