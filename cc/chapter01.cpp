#include <iostream>

// 매개변수의 디폴트값
int SimpleFunc(int a = 11);
int SimpleFunc();	// 위의 디폴트 함수 때문에 실행될 수 없는 함수

// 인라인 함수
#define SQUARE1(x) ((x)*(x))	//매크로 함수 (손실이 없다)
inline int SQUARE2(int x) { return x * x; }	// inline 함수(큰 자료형일 경우 손실이 일어남)
template <typename T>
inline T SQUARE3(T x) { return x * x; }	// 템플릿 이용 inline함수 ( 손실이 없다)

//전역변수
int val = 100;

// 네임 스페이스
using std::cout;	//출력
using std::cin;		//입력
using std::endl;	//뉴라인

namespace AAA { void Func() { } }
namespace BBB { void Func() { } }
namespace CCC { namespace c1 { namespace c2 { void Func() { } } } }

int main01() {
	// 표준 출력
	int num = 20;
	std::cout << "Hello World!" << std::endl;
	std::cout << "Hello " << "World!" << std::endl;
	std::cout << num << ' ' << 'A';
	std::cout << ' ' << 3.14 << std::endl;

	// 매개변수의 디폴트값
	//SimpleFunc();
	SimpleFunc(2);

	//인라인 함수

	// 지역변수와 전역변수
	int val = 11;
	val = val + 1;	//지역변수 val 1 증가
	::val = ::val + 1;	//전역변수 val 1 증가

	// 네임스페이스
	AAA::Func();
	BBB::Func();
	namespace C = CCC::c1::c2;
	C::Func();

	return 0;
}
int SimpleFunc(int a) {
	std::cout << "SimpleFunc(int a = 10);" << std::endl;
	return 5 * a;
}
int SimpleFunc() {
	std::cout << "SimpleFunc();" << std::endl;
	return 10;
}
