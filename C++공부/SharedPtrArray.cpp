//shared_ptr�� �迭�� ��ü�� ������ �� �ִ� ��� ����
//�迭�� ����� �����ϴ� �Լ��� �����ڰ� ���� �ۼ��ϰ� ����ؾ���

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

void RemoveTest(CTest* pTest)
{
	cout << "RemoveTest()" << endl;

	//����� �迭�� �����Ѵ�
	delete[] pTest;
}

int main()
{
	cout << "*****Begin*****" << endl;

	//��� ��ü�� �Ҹ��� �Լ��� ������ ����Ѵ�
	//RemoveTest �Լ��� ptr�� �Ҹ��� �� �ڵ����� ȣ��Ǹ� �Լ� ���ο��� �迭�� ������
	shared_ptr<CTest> ptr(new CTest[3], RemoveTest);

	cout << "*****End*****" << endl;

	return 0;
}

//auto_ptr���� shared_ptr�� ����ϴ� ���� �ٶ�����