#include<memory>
#include<iostream>

//���� ���� ���� �� auto_ptr

using namespace std;
class CMyData
{
public:
	CMyData() { cout << "CMyData()" << endl; }
	~CMyData() { cout << "~CMyData()" << endl; }
	void TestFunction() { cout << "CMyData::TestFunction()" << endl; }
};

/*
int main()
{
	//CMyData Ŭ������ ���� �����ϰ� �� �ּҸ� �������� �μ��� ����
	auto_ptr<CMyData> ptrTest(new CMyData);

	//����Ű�� ��� ���� �����͸� ������
	auto_ptr<CMyData> ptrNew;

	cout << "0x" << ptrTest.get() << endl;

	//�����͸� �����ϸ� ���� �����ʹ� NULL�� �ȴ�
	//ptrTest�� �ڽ��� ����Ű�� �������� ���� ptrNew �ν��Ͻ��� �������ְ� �ڱ� �ڽ��� �����͸� NULL�� �ʱ�ȭ��
	ptrNew = ptrTest;
	cout << "0x" << ptrTest.get() << endl;

	//���� �� �ڵ带 ������ �� ����
	ptrTest->TestFunction();

	return 0;
}
*/