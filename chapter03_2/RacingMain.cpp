#include "Car.h"

int main3_2() {
	Car run99; //Car객체 생성
	char name[20] = "run99";
	run99.InitMembers(name, 100);	// 책과 다르게 string을 전달..
	run99.Accel();
	run99.Accel();
	run99.Accel();
	run99.showCarState();
	run99.Break();
	run99.showCarState();

	return 0;
}