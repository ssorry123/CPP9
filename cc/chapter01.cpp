#include <iostream>

// �Ű������� ����Ʈ��
int SimpleFunc(int a = 11);
int SimpleFunc();	// ���� ����Ʈ �Լ� ������ ����� �� ���� �Լ�

// �ζ��� �Լ�
#define SQUARE1(x) ((x)*(x))	//��ũ�� �Լ� (�ս��� ����)
inline int SQUARE2(int x) { return x * x; }	// inline �Լ�(ū �ڷ����� ��� �ս��� �Ͼ)
template <typename T>
inline T SQUARE3(T x) { return x * x; }	// ���ø� �̿� inline�Լ� ( �ս��� ����)

//��������
int val = 100;

// ���� �����̽�
using std::cout;	//���
using std::cin;		//�Է�
using std::endl;	//������

namespace AAA { void Func() { } }
namespace BBB { void Func() { } }
namespace CCC { namespace c1 { namespace c2 { void Func() { } } } }

int main01() {
	// ǥ�� ���
	int num = 20;
	std::cout << "Hello World!" << std::endl;
	std::cout << "Hello " << "World!" << std::endl;
	std::cout << num << ' ' << 'A';
	std::cout << ' ' << 3.14 << std::endl;

	// �Ű������� ����Ʈ��
	//SimpleFunc();
	SimpleFunc(2);

	//�ζ��� �Լ�

	// ���������� ��������
	int val = 11;
	val = val + 1;	//�������� val 1 ����
	::val = ::val + 1;	//�������� val 1 ����

	// ���ӽ����̽�
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
