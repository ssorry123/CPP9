#ifndef __RECTANGLE_H_
#define __RECTANGLE_H_

#include "Point.h"	//같은 폴더에 있는 Point헤더파일을 이용하여 Rectangle 클래스 정의

class Rectangle {
private:
	Point upLeft;
	Point downRight;
public:
	bool InitMembers(const Point& uL, const Point& dR);
	void ShowRecInfo() const;
};


#endif // !__RECTANGLE_H_
