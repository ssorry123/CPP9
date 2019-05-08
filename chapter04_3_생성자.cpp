#include <iostream>
#include <cstdio>
using namespace std;

class SimpleClass {
private:
	int a = 1;
	int b;
public:
	// default생성자
	// 어떠한 생성자 하나라도 없을 때 자동으로 내용이 없는 default 생성자가 실행된다.
	// 생성자가 하나라도 있게 되면  인자가 없는 생성자를 이용하여 객체를 생성하더라도
	// 인자가 없는 생성자가 정의되어 있지 않으면 오류가 난다.
	SimpleClass() {
		cout << "default 생성자" << endl;
		b = 1;
	}
	// 생성자 오버로딩
	SimpleClass(int a, int b) {
		cout << "(int a, int b) 생성자" << endl;
		this->a = a;
		this->b = b;
	}
	// MemberInitializer를 이용한 객체가 아닌 필드 멤버 초기화.
	SimpleClass(int x) :b(x) {
		a = x;
		// MI를 사용하지 않고 초기화하는경우 아래와 같이
		// 멤버 선언 후 바로 초기화 되지 않는다.
		// int a;
		// a = x;

		// b(x) 처럼 MI를 사용하면
		// int b = x;
		// 처럼 선언하자마자 동시에 초기화 하는 효과를 볼 수 있다.
	}
};

class AnotherClass {
private:
	SimpleClass a;	//객체참조를 필드멤버로 가지는 AnotherClass
	SimpleClass b;
public:
	// default 생성자
	AnotherClass() {
		a = SimpleClass();
		b = SimpleClass(2, 3);
	}
	// 생성자 내에서 객체 생성후 멤버 초기화
	AnotherClass(const int& x) {
		a = SimpleClass(x, 3);
		b = SimpleClass(2, 3);
	}
	// Member Initializer를 이용한 객체 멤버 초기화
	AnotherClass(const int& x, const int& y) :a(x, y), b() {
		//...//
	}
};

class MemInitClass {
	// 참조자와 상수는 선언시 바로 초기화 해줘야 하기 때문에 MemberInitializer를 이용해야만 한다.
	int a = 3;
	int& ref;
	const int XXX;
	const int& refYYY;
	int* ptr_array;
	
public:
	MemInitClass() :ref(a), XXX(4), refYYY(5), ptr_array(new int[5]){
		// 필드 멤버의 int배열을 동적할당했으므로 객체 소멸시 같이 소멸되야함.
		//ptr_array = new int[5];	
		//...//
	}
	void vunc1() {
		MemInitClass mic(4);
	}
private:
	// 클래스 내에서만 객체의 생성을 허용하고 싶을때 private으로 오버로딩
	MemInitClass(int n) :ref(n), XXX(5), refYYY(7), ptr_array(new int[5]) {
		// 필드 멤버의 int배열을 동적할당했으므로 객체 소멸시 같이 소멸되야함.
		//ptr_array = new int[5];	
		//...//
	}
	~MemInitClass() {
		delete[]ptr_array;
	}
};

int main4_3() {
	// 생성자
	SimpleClass sc1;	//전역, 지역 및 매개변수의 형태 객체 생성, 디폴트 생성자
	SimpleClass* ptr_sc2 = new SimpleClass;		// 동적할당 객체 생성, 디폴트생성자
	SimpleClass* ptr_sc3 = new SimpleClass();	// 동적할당 객체 생성, 디폴트생성자
	delete(ptr_sc2);	//GC를 지원하지 않는 c++
	delete(ptr_sc3);

	SimpleClass sc4(3, 4);	// 오버로딩된 생성자
	SimpleClass* ptr_sc5 = new SimpleClass(6, 7);
	delete(ptr_sc5);

	// main함수 내에서 sc6 함수 정의
	SimpleClass sc6();	// 디폴트생성자이용하려고 이렇게 객체를 생성하면 생성되지 않는다. 오류도 나지 않는다.
	SimpleClass sc7 = sc6();




	// 함수 인자 디폴트
	void method(int a, int b, int c = 3);
	method(1, 2);

	return 0;
}

SimpleClass sc6() {
	SimpleClass sc;
	cout << "SimpleClass Type 반환하는 sc6() 함수 실행" << endl;
	return sc;
}
void method(int a, int b, int c) {
	printf("%d %d %d\n", a, b, c);
}