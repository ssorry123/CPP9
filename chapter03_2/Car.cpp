#pragma warning (disable: 4996)	//strcpy예외가 여기서 발생하므로 여기서 선언해줘야..
#include <iostream>
#include <cstring>
#include "Car.h"
using std::cout; using std::cin; using std::endl;



// 헤더파일에 있는 함수들의 몸체

// Car클래스의 필드들 초기화
void Car::InitMembers(char* ID, int fuel) {
	strcpy(gamerID, ID);
	fuelGauge = fuel;
	curSpeed = 0;
}

void Car::showCarState() {
	cout << "소유자 ID : " << gamerID << endl;
	cout << "연료량 : " << fuelGauge << '%' << endl;
	cout << "현재속도 : " << curSpeed << "km/s" << endl << endl;
}

void Car::Accel() {
	if (fuelGauge <= 0)
		return; //기름이 없으면 종료
	else
		fuelGauge -= CAR_CONST::FUEL_STEP; //기름이 있으면 기름 감소

	// 속도를 최대보다 올릴 수 없으면 최대로 리턴
	if ((curSpeed + CAR_CONST::ACC_STEP) >= CAR_CONST::MAX_SPD) {
		curSpeed = CAR_CONST::MAX_SPD;
		return;
	}
	curSpeed += CAR_CONST::ACC_STEP;
}

void Car::Break() {
	// 현재 속도가 브레이크 밟았을떄 줄어드는 속도보다 작으면
	if (curSpeed < CAR_CONST::BRK_STEP) {
		curSpeed = 0;
		return;
	}
	curSpeed -= CAR_CONST::BRK_STEP;
}