#pragma warning(disable: 4996)
#include <iostream>

// c�� ����� ����� ���� �ִ�. 
#include <string.h>
#include <stdio.h>
#include <math.h>

// .h�� ���� �տ� c�� ���̸� c������Ͽ� �����ϴ� c++����� ������ �� �ִ�.
#include <cstdio>
#include <cmath>
#include <cstring>


using std::cout; using std::cin; using std::endl;

// new �����Ҵ�� delete ����
char* MakeStrAdr(int len) {
	// char *str = (char*)malloc( sizeof(char)*len ); c��� ���
	char* str = new char[len];
	return str;
}

int main2_5() {

	// new�� delete�� �̿��� �����Ҵ�
	char* str = MakeStrAdr(20);
	strcpy(str, "asdfasdf");
	cout << str << endl;
	//free(str);	c��� ���
	delete[]str;	//��ȣ�� �ڿ��� ���� �ȵ��.

	// new�� delete�� �̿��� �Ҵ��� ������ ������, ������ ����
	int* ptr = new int;	//int�� �ϳ� ���� �Ҵ�
	int& ref = *ptr;	//ptr�� ����Ű�� ���� ������ ref
	ref = 20;
	cout << ref << endl;

	// c������ ȣȯ
	printf("HelloWorld\n");

	return 0;
}