#ifndef BPLATFORM_H
#define BPLATFORM_H

#include "shape.hpp"

using namespace std;

#define BPLATFORM_IMG_1 "pictures/bplatform1.png"
#define BPLATFORM_IMG_2 "pictures/bplatform2.png"
#define BPLATFORM_IMG_3 "pictures/bplatform3.png"
#define BPLATFORM_IMG_4 "pictures/bplatform4.png"
#define PLATFORM_WIDTH 120
#define PLATFORM_HEIGHT 36
#define MOVE_DOWN 0.2

class BPlatform : public Shape {
public:
	BPlatform(float _x, float _y, string n, float wid, float hei);
	virtual void perform_animation();
	virtual bool get_check_when_b(){ return check_when_b; }
	virtual void change_when_breaking();
	virtual void draw(Window *window);

private:
	int when_breaking;
	bool check_when_b;
};

#endif