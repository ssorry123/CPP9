#include <iostream>
#include "Point.h"
using namespace std;

// point를 0보다 크거나 같은 값으로 초기화
bool Point::InitMembers(int xpos, int ypos) {
	if (xpos < 0 || ypos < 0) {
		cout << "x와 y의 좌표가 0보다 작다" << endl;
		return false;
	}

	//  정상적으로 초기화 하면 true 리턴
	x = xpos;
	y = ypos;
	return true;
}

int Point::GetX() const{
	return x;
}
int Point::GetY() const {
	return y;
}

bool Point::SetX(int xpos) {
	if (xpos < 0 || xpos>100) {
		cout << "x의 좌표가 0~100이 아님" << endl;
		return false;
	}

	x = xpos;
	return true;
}

bool Point::SetY(int ypos) {
	if (ypos < 0 || ypos>100) {
		cout << "y의 좌표가 0~100이 아님" << endl;
		return false;
	}

	x = ypos;
	return true;
}

