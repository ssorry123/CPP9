#ifndef __CAR_H__	// __CAR_H__가 정의되어있지 않으면
#define __CAR_H__	// __CAR_H__를 정의한다

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
	// 함수의 본체는 Car.cpp에서 정의
	// 함수가 inline으로 선언될 경우 클래스의 선언과 동일한 파일에서 몸체를 정의해야 한다.
	void InitMembers(char* ID, int fuel);
	void showCarState();
	void Accel();
	void Break();
};


#endif
