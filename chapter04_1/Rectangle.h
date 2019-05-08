#ifndef __RECTANGLE_H_
#define __RECTANGLE_H_

#include "Point.h"	//���� ������ �ִ� Point��������� �̿��Ͽ� Rectangle Ŭ���� ����

class Rectangle {
private:
	Point upLeft;
	Point downRight;
public:
	bool InitMembers(const Point& uL, const Point& dR);
	void ShowRecInfo() const;
};


#endif // !__RECTANGLE_H_
