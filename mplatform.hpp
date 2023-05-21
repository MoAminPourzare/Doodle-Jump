#ifndef MPLATFORM_H
#define MPLATFORM_H

#include "shape.hpp"

using namespace std;

#define MPLATFORM_IMG "pictures/mplatform.png"
#define PLATFORM_WIDTH 120
#define PLATFORM_HEIGHT 36
#define MOVE_RIGHT 0.2
#define MOVE_LEFT -0.2
#define RIGHT 1
#define LEFT -1

class MPlatform : public Shape {
public:
	MPlatform(float _x, float _y, string n, float wid, float hei);
	virtual void draw(Window *window);
	virtual void move_mplatform(Window *window);

private:
	int move_direction;
};

#endif