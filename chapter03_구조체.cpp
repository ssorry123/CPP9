#include <iostream>
#include <cstdio>
using std::cout; using std::cin; using std::endl;
/*
// 구조체, 필드와 메소드의 default 는 public이다.
namespace CAR {
	enum { A = 20, B = 30, C = 40 };
	int a;	// 함수 내 변수가 아니므로 0으로 초기화
	struct  Car
	{
	public:
		enum { D = 50, E = 60, F = 70 };	//c#과 다르게 enum은 상수인듯..
		int a;	// 구조체 변수는 자동 초기화되지 않는다. 생성자나 직접대입{}으로 초기화해줘야함

	public:
		Car(int n) { a = n; }

		void func1() { cout << "구조체 내 func1" << endl; }	// 구조체 내의 함수는 기본적으로 inline함수
		void func2();	// 구조체의 함수를 외부에서 구현
		void func3();	// 구조체의 함수를 외부에서 구현
	};

	void Car::func2() { cout << "구조체 외에서구현 func2" << endl; }	// 외부에서 구현되면 inline 속성이 사라짐.
	inline void Car::func3() { cout << "구조체 외에서구현 func3" << endl; }

	struct Toy {
		enum { D = 1, E = 2, F = 3 };
		int a, b, c;
	};
}

int main3() {
	// 구조체
	CAR::Car car1 = {3};
	CAR::Car car2 = CAR::Car(5);
	cout << car1.a << endl;
	cout << car2.a << endl;
	cout << CAR::a << endl;


	return 0;
}
*/