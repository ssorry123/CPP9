#include <iostream>
#include <cstdio>
#include "Rectangle.h"
using namespace std;

// const Point참조자 이므로 Point의 필드들을 바꿀 수 없다.
bool Rectangle::InitMembers(const Point& ul, const Point& dr) {
	if (ul.GetX() > dr.GetX() || ul.GetY() > dr.GetY()) {
		cout << "왼쪽 X좌표가 오른쪽 X좌표보다 오른쪽에 있거나" << endl
			<< "왼쪽 Y좌표가 오른쪽 Y좌표보다 아래에 있다." << endl;
		return false;
	}

	// Rectangle객체의 왼쪽 위와 아래 오른쪽의 좌표를
	// Point객체를 이용하여 정해줌
	upLeft = ul;
	downRight = dr;
	return true;
}

void Rectangle::ShowRecInfo() const {
	// rectangle 객체의 멤버인 point 객체의 함수를 이용하여 좌표를 알아냄.
	printf("좌상단 [%d,  %d]\n", upLeft.GetX(), upLeft.GetY());
	printf("우하단 [%d,  %d]\n", downRight.GetX(), downRight.GetY());
}