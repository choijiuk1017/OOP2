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

/*
int main()
{
	cout << "*****Begin*****" << endl;
	{
		//���� ������ ����� ��� ��ü�� �ڵ����� �Ҹ��Ѵ�.
		//ptrTest�� CMyData ��ü�� �������� �����ϰ� �� �ּҸ� �������� �μ��� ����
		//ptrTest ������ ������ ����� ���� ������ ��ü�� �ּҸ� ��� �ִٰ� ptrTest�� �Ҹ��ϸ鼭 ����Ű�� ����� ������
		auto_ptr<CMyData> ptrTest(new CMyData);

		//auto_ptr<CMyData> ptrTest(new CMyData[3]); �迭�� ���� �Ҵ��ϸ� ������ �߻���
		//�迭�� ���� ������ �����ϳ� �迭�� ������ ���� �ʱ� ����
	}

	cout << "*****End*****" << endl;

	return 0;
}*/