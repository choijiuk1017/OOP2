//����Ʈ ������
//���� �Ҵ��� �ν��Ͻ��� �ڵ����� �������ִ� ���� ������

//auto_ptr
//������� �ʴ� ���� �ٶ�����
//�迭 ���� ����, ���� ���� ������ �ذ���� ����

#include<memory>
#include<iostream>

using namespace std;

class CMyData
{
private:
public:
	CMyData() { cout << "CMyData()" << endl; }
	~CMyData() { cout << "~CMyData()" << endl; }

};

int main()
{
	cout << "*****Begin*****" << endl;
	{
		//���� ������ ����� ��� ��ü�� �ڵ����� �Ҹ��Ѵ�.
		auto_ptr<CMyData> ptrTest(new CMyData);
	}

	cout << "*****End*****" << endl;

	return 0;
}