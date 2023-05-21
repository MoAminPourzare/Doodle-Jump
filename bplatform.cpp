#include "bplatform.hpp"

BPlatform::BPlatform(float _x, float _y, string n, float wid, float hei)
		  : Shape(_x, _y, n, wid, hei){
		  	when_breaking = 0;
		  	check_when_b = false;
}

void BPlatform::draw(Window *window){
	if(when_breaking < 100)
		window->draw_img(BPLATFORM_IMG_1, Rectangle(x, y, PLATFORM_WIDTH, PLATFORM_HEIGHT));
	if(when_breaking >= 100 && when_breaking < 200)
		window->draw_img(BPLATFORM_IMG_2, Rectangle(x, y, PLATFORM_WIDTH, PLATFORM_HEIGHT));
	if(when_breaking >= 200 && when_breaking < 300)
		window->draw_img(BPLATFORM_IMG_3, Rectangle(x, y, PLATFORM_WIDTH, PLATFORM_HEIGHT));
	if(when_breaking >= 300){
		window->draw_img(BPLATFORM_IMG_4, Rectangle(x, y, PLATFORM_WIDTH, PLATFORM_HEIGHT));
		y += MOVE_DOWN;
	}
}

void BPlatform::perform_animation(){
		check_when_b = true;
}

void BPlatform::change_when_breaking(){
		when_breaking++;
}