#include "Car.h"

int main3_2() {
	Car run99; //Car��ü ����
	char name[20] = "run99";
	run99.InitMembers(name, 100);	// å�� �ٸ��� string�� ����..
	run99.Accel();
	run99.Accel();
	run99.Accel();
	run99.showCarState();
	run99.Break();
	run99.showCarState();

	return 0;
}