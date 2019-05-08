#include <iostream>
#include "Point.h"
using namespace std;

// point�� 0���� ũ�ų� ���� ������ �ʱ�ȭ
bool Point::InitMembers(int xpos, int ypos) {
	if (xpos < 0 || ypos < 0) {
		cout << "x�� y�� ��ǥ�� 0���� �۴�" << endl;
		return false;
	}

	//  ���������� �ʱ�ȭ �ϸ� true ����
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
		cout << "x�� ��ǥ�� 0~100�� �ƴ�" << endl;
		return false;
	}

	x = xpos;
	return true;
}

bool Point::SetY(int ypos) {
	if (ypos < 0 || ypos>100) {
		cout << "y�� ��ǥ�� 0~100�� �ƴ�" << endl;
		return false;
	}

	x = ypos;
	return true;
}

