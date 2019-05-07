#include <iostream>
using std::cout; using std::cin; using std::endl;

// const�� ������
int val1, val2, val3;
const int num = 10;	// num �� ���
const int* ptr1 = &val1;	//ptr1�����ͷ� val1�� ���� ������ �� ����
int* const ptr2 = &val2;	//ptr2�����ʹ� ���������
const int* const ptr3 = &val3;	//ptr3�����ʹ� ����������̰� val3�� ���� ������ �� ����.

// ������ �Լ�
void SWAP(int& ref1, int& ref2);
void func(const int& ref) {};		// �����ڸ� �̿��� ���� �������� �ʰڴ�.
int Adder1(int a, int b) { return a + b; }
int Adder2(int& a, int& b) { return a + b; }
int Adder3(const int& a, const int& b) { return a + b; }

int& RefRetFuncOne(int& ref) { ref++; return ref; }	// �����ڷ� ��ȯ�ϴµ� ���������� ��ȯ
int RefRetFuncTwo(int& ref) { ref++; return ref; }	// �����ڷ� ��ȯ�ϴµ� �⺻�ڷ������� ��ȯ

int main2() {
	// ������,  ���! ����!�� ����! �Ͽ��� �Ѵ�.
	int num1 = 1020;
	int& num2 = num1;	//num2�� num1�� �����Ѵ�. num2�� num1�� �����̴�. �ּҿ� ���� �Ȱ���.
	int& num3 = num1;
	int& num4 = num2;
	num1 = 3012;
	cout << num1 << ' ' << num2 << endl;
	cout << &num1 << ' ' << &num2 << endl;
	// �����ڴ� �迭�� ���(�迭 ����)�� �����͵� ������ �� �ִ�.
	int arr[3] = { 1,3,5 };
	int& ref1 = arr[0];
	int& ref2 = arr[1];
	int& ref3 = arr[2];
	cout << ref1 << endl; cout << ref2 << endl; cout << ref3 << "\n" << endl;
	SWAP(ref1, ref2);	// ref1, ref2�� �Ű������� �ʱ�ȭ�� ����
	cout << ref1 << endl; cout << ref2 << endl; cout << ref3 << "\n" << endl;
	SWAP(arr[0], arr[1]);	// arr[0], arr[1]�� �Ű������� �ʱ�ȭ�� ����.
	cout << ref1 << endl; cout << ref2 << endl; cout << ref3 << "\n" << endl;

	int num = 12;			//int���� num
	int* ptr = &num;		//int������ ������ ptr
	int** dptr = &ptr;		//������ ptr�� ������
	int& ref = num;			//int���� num�� ������ ref
	int* (&pref) = ptr;		//ptr�������� ������ pref
	int** (&dpref) = dptr;	//���������� dptr�� ������ dpref
	cout << ref << endl;
	cout << *pref << endl;
	cout << **dpref << endl;

	int n1 = 1;
	int& n2 = RefRetFuncOne(n1); // int& n2 = int& ref = n1; �ᱹ ��� n1�� ����Ŵ.
	n1++; n2++;
	cout << n1 << ' ' << n2 << endl;

	int n3 = 1;
	int n4 = RefRetFuncOne(n3);	// int n4 = int& ref = n3; ref�� n3�� ���������� n4�� ���Ӱ� ź���Ǿ���.
	n3++; n4 = n4 + 100;
	cout << n3 << ' ' << n4 << endl;

	int n5 = 1;
	int n6 = RefRetFuncTwo(n5); //
	// int& n6 = RefRetFuncTwo(n5); RefRetFuncTwo �� �⺻�ڷ����� (��ȯ���� ���)��ȯ�ϹǷ� �����ڿ� ��ȯ�� �� ����. ������ �����ؾ���.

	const int n7 = 20;		//���� n7 ���ȭ
	const int& ref8 = n7;	//���ȭ ���� n7�� ������
	const int& ref7 = 30;	//��� ����..(literal or literal constant)

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
