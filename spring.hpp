#ifndef SPRING_H
#define SPRING_H

#include "shape.hpp"

using namespace std;

#define SPRING_IMG "pictures/spring.png"
#define SPRING_WIDTH 56
#define SPRING_HEIGHT 46

class Spring : public Shape {
public:
	Spring(float _x, float _y, string n, float wid, float hei);
	virtual void draw(Window *window);
};

#endif