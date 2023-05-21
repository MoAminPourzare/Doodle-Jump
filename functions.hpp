#ifndef FUNCTION_H
#define FUNCTION_H

using namespace std;

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "rsdl.hpp"
#include "shape.hpp"
#include "spring.hpp"
#include "bplatform.hpp"
#include "mplatform.hpp"
#include "platform.hpp"
#include "doodle.hpp"
#include "enemy.hpp"

#define MAP "map.txt"
#define PLATFORM "platform"
#define BPLATFORM "bplatform"
#define MPLATFORM "mplatform"
#define SPRING "spring"
#define ENEMY "enemy"
#define SHOW_SCORE_WIDTH 440
#define SHOW_SCORE_HEIGHT 300
#define START_BENDING_LEGS 1
#define BACKGROUND_IMG "pictures/background.png"
#define GAMEOVER_IMG "pictures/gameover.png"
#define FREESANS_FONT "FreeSansBold-Rdmo.otf"
#define SPRING_HEIGHT 46
#define WINDOW_WIDTH 640

void update(Window *window, Doodle& doodle, vector<Shape*> shapes, bool& key_down, int& check_pressed_char, bool& finish_game);
void draw(Window *window, Doodle& doodle, vector<Shape*> shapes, int check_pressed_char, bool& finish_game, bool& check_finish);
void doodle_move(Window *window, Doodle& doodle, vector<Shape*> shapes, bool& finish_game);
void get_map(vector<Shape*>& shapes, Window *window);
void sort_shapes(float& map_y, int height, Window *window);
void mplatforms_update(vector<Shape*>& shapes, Window *window);

#endif