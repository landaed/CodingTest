#include "../header/rectangle2D.h"
#include <iostream>
using namespace std;
Rectangle2D::Rectangle2D(vec2 position, vec2 sizeVal, int i){
	pos = position;
	size = sizeVal;
	index = i;
};
Rectangle2D::Rectangle2D(){
	pos = vec2((float)0,(float)0);
	size = vec2((float)1,(float)1);
	index = 0;
}
Rectangle2D::~Rectangle2D(){

};
Rectangle2D::Rectangle2D(const Rectangle2D &rect){
	pos = rect.pos; size = rect.size; index = rect.index;
};
void Rectangle2D::setPos(vec2 position){
	pos = position;
};
vec2 Rectangle2D::getPos(){
	return pos;
};
vec2 Rectangle2D::getSize(){
	return size;
};
int Rectangle2D::getIndex(){
	return index;
};

bool checkSide(float a, float b, float widthA, float widthB){

	if(a<b){

	}

	float coeff = 0.5;
	bool overlap = false;
	if(a < b){
//		coeff*=-1;
		float x = a + coeff*widthA;
		if(x > b - coeff*widthA){
			overlap = true;
		}
	}
	else{
		float x = a - coeff*widthA;
		if(x < b + coeff*widthA){
			overlap = true;
		}
	}
	return overlap;

}
float Rectangle2D::getTopBound(){
	return pos.y+(0.5*size.y);
}

bool isIntersect(Rectangle2D rectA, Rectangle2D rectB){
	vec2 sizeA(rectA.getSize());
	vec2 sizeB(rectB.getSize());
	vec2 posA(rectA.getPos());
	vec2 posB(rectB.getPos());

	vec2 aBoundsLR = vec2(posA.x-(0.5*sizeA.x),posA.x+(0.5*sizeA.x));
	vec2 aBoundsTB = vec2(posA.y-(0.5*sizeA.y),posA.y+(0.5*sizeA.y));
	vec2 bBoundsLR = vec2(posB.x-(0.5*sizeB.x),posB.x+(0.5*sizeB.x));
	vec2 bBoundsTB = vec2(posB.y-(0.5*sizeB.y),posB.y+(0.5*sizeB.y));
	/*cout << "rect1 left bounds " << aBoundsLR.x << endl;
	cout << "rect1 right bounds " << aBoundsLR.y << endl;
	cout << "rect1 sizex " << sizeA.x << endl;
	cout << "rect1 sizey " << sizeA.y << endl << endl;
	cout << "rect2 left bounds " << bBoundsLR.x << endl;
	cout << "rect2 right bounds " << bBoundsLR.y << endl;
	cout << "rect2 sizex " << sizeB.x << endl;
	cout << "rect2 sizey " << sizeB.y << endl;*/
	if (aBoundsLR.x < bBoundsLR.y && aBoundsLR.y > bBoundsLR.x && aBoundsTB.x < bBoundsTB.y && aBoundsTB.y > bBoundsTB.x) {
			return true;
		}
		else{
			return false;
		}

}
