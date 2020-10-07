#ifndef __CAR_H__	// __CAR_H__�� ���ǵǾ����� ������
#define __CAR_H__	// __CAR_H__�� �����Ѵ�

namespace CAR_CONST {
	enum {
		ID_LEN = 20, MAX_SPD = 200, FUEL_STEP = 2,
		ACC_STEP = 10, BRK_STEP = 10
	};
}

class Car {
private:
	char gamerID[CAR_CONST::ID_LEN];
	int fuelGauge;
	int curSpeed;
public:
	// �Լ��� ��ü�� Car.cpp���� ����
	// �Լ��� inline���� ����� ��� Ŭ������ ����� ������ ���Ͽ��� ��ü�� �����ؾ� �Ѵ�.
	void InitMembers(char* ID, int fuel);
	void showCarState();
	void Accel();
	void Break();
};


#endif
