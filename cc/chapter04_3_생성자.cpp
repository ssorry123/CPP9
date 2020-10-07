#include <iostream>
#include <cstdio>
using namespace std;

class SimpleClass {
private:
	int a = 1;
	int b;
public:
	// default������
	// ��� ������ �ϳ��� ���� �� �ڵ����� ������ ���� default �����ڰ� ����ȴ�.
	// �����ڰ� �ϳ��� �ְ� �Ǹ�  ���ڰ� ���� �����ڸ� �̿��Ͽ� ��ü�� �����ϴ���
	// ���ڰ� ���� �����ڰ� ���ǵǾ� ���� ������ ������ ����.
	SimpleClass() {
		cout << "default ������" << endl;
		b = 1;
	}
	// ������ �����ε�
	SimpleClass(int a, int b) {
		cout << "(int a, int b) ������" << endl;
		this->a = a;
		this->b = b;
	}
	// MemberInitializer�� �̿��� ��ü�� �ƴ� �ʵ� ��� �ʱ�ȭ.
	SimpleClass(int x) :b(x) {
		a = x;
		// MI�� ������� �ʰ� �ʱ�ȭ�ϴ°�� �Ʒ��� ����
		// ��� ���� �� �ٷ� �ʱ�ȭ ���� �ʴ´�.
		// int a;
		// a = x;

		// b(x) ó�� MI�� ����ϸ�
		// int b = x;
		// ó�� �������ڸ��� ���ÿ� �ʱ�ȭ �ϴ� ȿ���� �� �� �ִ�.
	}
};

class AnotherClass {
private:
	SimpleClass a;	//��ü������ �ʵ����� ������ AnotherClass
	SimpleClass b;
public:
	// default ������
	AnotherClass() {
		a = SimpleClass();
		b = SimpleClass(2, 3);
	}
	// ������ ������ ��ü ������ ��� �ʱ�ȭ
	AnotherClass(const int& x) {
		a = SimpleClass(x, 3);
		b = SimpleClass(2, 3);
	}
	// Member Initializer�� �̿��� ��ü ��� �ʱ�ȭ
	AnotherClass(const int& x, const int& y) :a(x, y), b() {
		//...//
	}
};

class MemInitClass {
	// �����ڿ� ����� ����� �ٷ� �ʱ�ȭ ����� �ϱ� ������ MemberInitializer�� �̿��ؾ߸� �Ѵ�.
	int a = 3;
	int& ref;
	const int XXX;
	const int& refYYY;
	int* ptr_array;
	
public:
	MemInitClass() :ref(a), XXX(4), refYYY(5), ptr_array(new int[5]){
		// �ʵ� ����� int�迭�� �����Ҵ������Ƿ� ��ü �Ҹ�� ���� �Ҹ�Ǿ���.
		//ptr_array = new int[5];	
		//...//
	}
	void vunc1() {
		MemInitClass mic(4);
	}
private:
	// Ŭ���� �������� ��ü�� ������ ����ϰ� ������ private���� �����ε�
	MemInitClass(int n) :ref(n), XXX(5), refYYY(7), ptr_array(new int[5]) {
		// �ʵ� ����� int�迭�� �����Ҵ������Ƿ� ��ü �Ҹ�� ���� �Ҹ�Ǿ���.
		//ptr_array = new int[5];	
		//...//
	}
	~MemInitClass() {
		delete[]ptr_array;
	}
};

int main4_3() {
	// ������
	SimpleClass sc1;	//����, ���� �� �Ű������� ���� ��ü ����, ����Ʈ ������
	SimpleClass* ptr_sc2 = new SimpleClass;		// �����Ҵ� ��ü ����, ����Ʈ������
	SimpleClass* ptr_sc3 = new SimpleClass();	// �����Ҵ� ��ü ����, ����Ʈ������
	delete(ptr_sc2);	//GC�� �������� �ʴ� c++
	delete(ptr_sc3);

	SimpleClass sc4(3, 4);	// �����ε��� ������
	SimpleClass* ptr_sc5 = new SimpleClass(6, 7);
	delete(ptr_sc5);

	// main�Լ� ������ sc6 �Լ� ����
	SimpleClass sc6();	// ����Ʈ�������̿��Ϸ��� �̷��� ��ü�� �����ϸ� �������� �ʴ´�. ������ ���� �ʴ´�.
	SimpleClass sc7 = sc6();




	// �Լ� ���� ����Ʈ
	void method(int a, int b, int c = 3);
	method(1, 2);

	return 0;
}

SimpleClass sc6() {
	SimpleClass sc;
	cout << "SimpleClass Type ��ȯ�ϴ� sc6() �Լ� ����" << endl;
	return sc;
}
void method(int a, int b, int c) {
	printf("%d %d %d\n", a, b, c);
}