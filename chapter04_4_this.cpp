#include <iostream>
using namespace std;


//c++���� this�� �ڱ� �ڽ� ��ü�� ����Ű�� �������̴�.

class ThisClass {

public:
	ThisClass* get_ptr() {	// �ڱ� �ڽ� ������ ��ȯ
		return this;
	}

	// Self-Reference
	ThisClass& get_ref() {	// �ڱ� �ڽ��� �����Ͱ� ����Ű�� �ڱ� �ڽ��� �����ڸ� ��ȯ
		return *this;
	}

};

int main() {

	return 0;
}