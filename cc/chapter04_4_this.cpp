#include <iostream>
using namespace std;


//c++에서 this는 자기 자신 객체를 가리키는 포인터이다.

class ThisClass {

public:
	ThisClass* get_ptr() {	// 자기 자신 포인터 반환
		return this;
	}

	// Self-Reference
	ThisClass& get_ref() {	// 자기 자신의 포인터가 가리키는 자기 자신의 참조자를 반환
		return *this;
	}

};

int main() {

	return 0;
}