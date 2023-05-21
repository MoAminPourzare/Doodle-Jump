#ifndef PLATFORM_H
#define PLATFORM_H

#include "shape.hpp"

using namespace std;

#define PLATFORM_IMG "pictures/platform.png"
#define PLATFORM_WIDTH 120
#define PLATFORM_HEIGHT 36

class Platform : public Shape {
public:
	Platform(float _x, float _y, string n, float wid, float hei);
	virtual void draw(Window *window);
};

#endif