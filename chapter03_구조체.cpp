#include <iostream>
#include <cstdio>
using std::cout; using std::cin; using std::endl;
/*
// ����ü, �ʵ�� �޼ҵ��� default �� public�̴�.
namespace CAR {
	enum { A = 20, B = 30, C = 40 };
	int a;	// �Լ� �� ������ �ƴϹǷ� 0���� �ʱ�ȭ
	struct  Car
	{
	public:
		enum { D = 50, E = 60, F = 70 };	//c#�� �ٸ��� enum�� ����ε�..
		int a;	// ����ü ������ �ڵ� �ʱ�ȭ���� �ʴ´�. �����ڳ� ��������{}���� �ʱ�ȭ�������

	public:
		Car(int n) { a = n; }

		void func1() { cout << "����ü �� func1" << endl; }	// ����ü ���� �Լ��� �⺻������ inline�Լ�
		void func2();	// ����ü�� �Լ��� �ܺο��� ����
		void func3();	// ����ü�� �Լ��� �ܺο��� ����
	};

	void Car::func2() { cout << "����ü �ܿ������� func2" << endl; }	// �ܺο��� �����Ǹ� inline �Ӽ��� �����.
	inline void Car::func3() { cout << "����ü �ܿ������� func3" << endl; }

	struct Toy {
		enum { D = 1, E = 2, F = 3 };
		int a, b, c;
	};
}

int main3() {
	// ����ü
	CAR::Car car1 = {3};
	CAR::Car car2 = CAR::Car(5);
	cout << car1.a << endl;
	cout << car2.a << endl;
	cout << CAR::a << endl;


	return 0;
}
*/