#ifndef __POINT_H__	//����ٴ� ������� �ص� ��� ���µ�.
#define __POINT_H__

class Point {
private:
	int x;
	int y;
public:
	bool InitMembers(int xpos, int ypos);
	int GetX() const;	//const �Լ�, �� �Լ������� Ŭ������ �ʵ� ������ ������� �ʴ´�.
	int GetY() const;
	bool SetX(int xpos);
	bool SetY(int ypos);
};

#endif // !__POINT_H__
