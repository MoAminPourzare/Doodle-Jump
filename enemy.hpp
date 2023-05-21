#ifndef ENEMY_H
#define ENEMY_H

#include "shape.hpp"

using namespace std;

#define ENEMY_IMG "pictures/enemy.png"
#define ENEMY_WIDTH 163
#define ENEMY_HEIGHT 132

class Enemy : public Shape {
public:
	Enemy(float _x, float _y, string n, float wid, float hei);
	virtual void draw(Window *window);
};

#endif