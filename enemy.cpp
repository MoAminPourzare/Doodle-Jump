#include "enemy.hpp"

Enemy::Enemy(float _x, float _y, string n, float wid, float hei)
	  : Shape(_x, _y, n, wid, hei){}

void Enemy::draw(Window *window){
	window->draw_img(ENEMY_IMG, Rectangle(x, y, ENEMY_WIDTH, ENEMY_HEIGHT));
}