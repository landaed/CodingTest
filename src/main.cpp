#include <iostream>
#include "../header/rectangle2D.h"

int main(int argc, char* argv[]){
	//ensure there are at least 8 args
	if(argc < 8){
		std::cout << "ERROR: Not enough arguments" << std::endl;
		return 1;
	}
	//make 2 rectangles
	Rectangle2D rect1(vec2(atof(argv[1]),atof(argv[2])),vec2(atof(argv[3]),atof(argv[4])), 0);
	Rectangle2D rect2(vec2(atof(argv[5]),atof(argv[6])),vec2(atof(argv[7]),atof(argv[8])), 0);
	//check for intersection
	if(isIntersect(rect1, rect2)){
		std::cout << "SUCCESS" << std::endl;
	}
	else{
		std::cout << "FAILED" << std::endl;
	}
	return 0;
}
