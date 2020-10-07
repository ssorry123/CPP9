#pragma warning (disable: 4996)	//strcpy���ܰ� ���⼭ �߻��ϹǷ� ���⼭ ���������..
#include <iostream>
#include <cstring>
#include "Car.h"
using std::cout; using std::cin; using std::endl;



// ������Ͽ� �ִ� �Լ����� ��ü

// CarŬ������ �ʵ�� �ʱ�ȭ
void Car::InitMembers(char* ID, int fuel) {
	strcpy(gamerID, ID);
	fuelGauge = fuel;
	curSpeed = 0;
}

void Car::showCarState() {
	cout << "������ ID : " << gamerID << endl;
	cout << "���ᷮ : " << fuelGauge << '%' << endl;
	cout << "����ӵ� : " << curSpeed << "km/s" << endl << endl;
}

void Car::Accel() {
	if (fuelGauge <= 0)
		return; //�⸧�� ������ ����
	else
		fuelGauge -= CAR_CONST::FUEL_STEP; //�⸧�� ������ �⸧ ����

	// �ӵ��� �ִ뺸�� �ø� �� ������ �ִ�� ����
	if ((curSpeed + CAR_CONST::ACC_STEP) >= CAR_CONST::MAX_SPD) {
		curSpeed = CAR_CONST::MAX_SPD;
		return;
	}
	curSpeed += CAR_CONST::ACC_STEP;
}

void Car::Break() {
	// ���� �ӵ��� �극��ũ ������� �پ��� �ӵ����� ������
	if (curSpeed < CAR_CONST::BRK_STEP) {
		curSpeed = 0;
		return;
	}
	curSpeed -= CAR_CONST::BRK_STEP;
}