//unique_ptr�� shared_ptr�� ������
//shared_ptr���� �޸� �� ����� ������ �� �����ͷθ� ������ ����

#include<memory>
#include<iostream>

using namespace std;

class CTest
{
public:
	CTest() { cout << "CTest()" << endl; }
	~CTest() { cout << "~CTest()" << endl; }
	void TestFunc() { cout << "TestFunc()" << endl; }
};

int main()
{
	unique_ptr<CTest> ptr1(new CTest);

	//�Ʒ� �ڵ���� �����ϸ� ��� ������ ������ �߻��Ѵ�
	//unique_ptr�� �ϳ��� ��� ���� �ϳ��� �����͸� ������ �� �ֱ� ����
	//unique_ptr<CTest> ptr2(ptr1);
	//ptr2 = ptr1;

	return 0;
}
//shared_ptr�� unique_ptr�� ������ ��� ����ϴ� ���� ����