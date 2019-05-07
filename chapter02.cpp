#include <iostream>
using std::cout; using std::cin; using std::endl;

// const와 포인터
int val1, val2, val3;
const int num = 10;	// num 은 상수
const int* ptr1 = &val1;	//ptr1포인터로 val1의 값을 변경할 수 없음
int* const ptr2 = &val2;	//ptr2포인터는 상수포인터
const int* const ptr3 = &val3;	//ptr3포인터는 상수포인터이고 val3의 값을 수정할 수 없음.

// 참조자 함수
void SWAP(int& ref1, int& ref2);
void func(const int& ref) {};		// 참조자를 이용해 값을 변경하지 않겠다.
int Adder1(int a, int b) { return a + b; }
int Adder2(int& a, int& b) { return a + b; }
int Adder3(const int& a, const int& b) { return a + b; }

int& RefRetFuncOne(int& ref) { ref++; return ref; }	// 참조자로 반환하는데 참조형으로 반환
int RefRetFuncTwo(int& ref) { ref++; return ref; }	// 참조자로 반환하는데 기본자료형으로 반환

int main2() {
	// 참조자,  즉시! 변수!를 참조! 하여야 한다.
	int num1 = 1020;
	int& num2 = num1;	//num2는 num1을 참조한다. num2는 num1의 별명이다. 주소와 값이 똑같다.
	int& num3 = num1;
	int& num4 = num2;
	num1 = 3012;
	cout << num1 << ' ' << num2 << endl;
	cout << &num1 << ' ' << &num2 << endl;
	// 참조자는 배열의 요소(배열 말고)와 포인터도 참조할 수 있다.
	int arr[3] = { 1,3,5 };
	int& ref1 = arr[0];
	int& ref2 = arr[1];
	int& ref3 = arr[2];
	cout << ref1 << endl; cout << ref2 << endl; cout << ref3 << "\n" << endl;
	SWAP(ref1, ref2);	// ref1, ref2로 매개변수를 초기화후 전달
	cout << ref1 << endl; cout << ref2 << endl; cout << ref3 << "\n" << endl;
	SWAP(arr[0], arr[1]);	// arr[0], arr[1]로 매개변수를 초기화후 전달.
	cout << ref1 << endl; cout << ref2 << endl; cout << ref3 << "\n" << endl;

	int num = 12;			//int변수 num
	int* ptr = &num;		//int변수의 포인터 ptr
	int** dptr = &ptr;		//포인터 ptr의 포인터
	int& ref = num;			//int변수 num의 참조자 ref
	int* (&pref) = ptr;		//ptr포인터의 참조자 pref
	int** (&dpref) = dptr;	//더블포인터 dptr의 참조자 dpref
	cout << ref << endl;
	cout << *pref << endl;
	cout << **dpref << endl;

	int n1 = 1;
	int& n2 = RefRetFuncOne(n1); // int& n2 = int& ref = n1; 결국 모두 n1을 가리킴.
	n1++; n2++;
	cout << n1 << ' ' << n2 << endl;

	int n3 = 1;
	int n4 = RefRetFuncOne(n3);	// int n4 = int& ref = n3; ref는 n3을 가리켰지만 n4는 새롭게 탄생되었다.
	n3++; n4 = n4 + 100;
	cout << n3 << ' ' << n4 << endl;

	int n5 = 1;
	int n6 = RefRetFuncTwo(n5); //
	// int& n6 = RefRetFuncTwo(n5); RefRetFuncTwo 는 기본자료형을 (반환값은 상수)반환하므로 참조자에 반환할 수 없다. 변수에 저장해야함.

	const int n7 = 20;		//변수 n7 상수화
	const int& ref8 = n7;	//상수화 변수 n7의 참조자
	const int& ref7 = 30;	//상수 참조..(literal or literal constant)

	Adder1(5, 7);
	//Adder2(5, 7);
	Adder3(5, 7);
	int a = 5, b = 7;
	Adder2(a, b);

	return 0;
}
void SWAP(int& ref1, int& ref2) {
	int temp;
	temp = ref1;
	ref1 = ref2;
	ref2 = temp;
	return;
}
