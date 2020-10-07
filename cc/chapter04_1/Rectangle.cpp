#include <iostream>
#include <cstdio>
#include "Rectangle.h"
using namespace std;

// const Point������ �̹Ƿ� Point�� �ʵ���� �ٲ� �� ����.
bool Rectangle::InitMembers(const Point& ul, const Point& dr) {
	if (ul.GetX() > dr.GetX() || ul.GetY() > dr.GetY()) {
		cout << "���� X��ǥ�� ������ X��ǥ���� �����ʿ� �ְų�" << endl
			<< "���� Y��ǥ�� ������ Y��ǥ���� �Ʒ��� �ִ�." << endl;
		return false;
	}

	// Rectangle��ü�� ���� ���� �Ʒ� �������� ��ǥ��
	// Point��ü�� �̿��Ͽ� ������
	upLeft = ul;
	downRight = dr;
	return true;
}

void Rectangle::ShowRecInfo() const {
	// rectangle ��ü�� ����� point ��ü�� �Լ��� �̿��Ͽ� ��ǥ�� �˾Ƴ�.
	printf("�»�� [%d,  %d]\n", upLeft.GetX(), upLeft.GetY());
	printf("���ϴ� [%d,  %d]\n", downRight.GetX(), downRight.GetY());
}