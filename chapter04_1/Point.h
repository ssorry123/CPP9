#ifndef __POINT_H__	//언더바는 지맘대로 해도 상관 없는듯.
#define __POINT_H__

class Point {
private:
	int x;
	int y;
public:
	bool InitMembers(int xpos, int ypos);
	int GetX() const;	//const 함수, 이 함수에서는 클래스의 필드 변경을 허락하지 않는다.
	int GetY() const;
	bool SetX(int xpos);
	bool SetY(int ypos);
};

#endif // !__POINT_H__
