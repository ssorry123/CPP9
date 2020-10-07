#pragma warning(disable: 4996)
#include <iostream>

// c의 헤더를 사용할 수도 있다. 
#include <string.h>
#include <stdio.h>
#include <math.h>

// .h를 때고 앞에 c를 붙이면 c헤더파일에 대응하는 c++헤더를 포함할 수 있다.
#include <cstdio>
#include <cmath>
#include <cstring>


using std::cout; using std::cin; using std::endl;

// new 동적할당과 delete 해제
char* MakeStrAdr(int len) {
	// char *str = (char*)malloc( sizeof(char)*len ); c언어 방법
	char* str = new char[len];
	return str;
}

int main2_5() {

	// new와 delete를 이용한 동적할당
	char* str = MakeStrAdr(20);
	strcpy(str, "asdfasdf");
	cout << str << endl;
	//free(str);	c언어 방법
	delete[]str;	//괄호를 뒤에다 쓰면 안딘다.

	// new와 delete를 이용해 할당한 변수의 포인터, 참조자 접근
	int* ptr = new int;	//int형 하나 동적 할당
	int& ref = *ptr;	//ptr이 가리키는 값의 참조자 ref
	ref = 20;
	cout << ref << endl;

	// c언어와의 호환
	printf("HelloWorld\n");

	return 0;
}