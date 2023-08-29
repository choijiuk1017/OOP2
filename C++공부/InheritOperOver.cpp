#include<iostream>

using namespace std;
class CMyData
{
protected:
	int m_nData = 0;
public:
	CMyData(int nParam) : m_nData(nParam) {}

	CMyData operator+(const CMyData& rhs)
	{
		return CMyData(m_nData + rhs.m_nData);
	}

	CMyData operator=(const CMyData& rhs)
	{
		m_nData = rhs.m_nData;

		return *this;
	}

	operator int() 
	{
		return m_nData;
	}
};

class CMyDataEx : public CMyData
{
public:
	CMyDataEx(int nParam) : CMyData(nParam) {}

	//using Ű���� ������� ���� Ŭ������ ������ �Լ��� �״�� ����
	//CMyDataEx�� �ڽŸ��� �����ڸ� ���� ���� ��ó�� �۵�
	using CMyData::operator+;
	using CMyData::operator=;

	//�⺻ ������ operator +()�� �״�� ȣ�����ְ� ���� ����� ����� CMyDataEx ��ü�� ��ȯ
	/*CMyDataEx operator +(const CMyDataEx& rhs)
	{
		return CMyDataEx(static_cast<int>(CMyData::operator+(rhs)));
	}*/
};

/*
int main()
{
	CMyData a(3), b(4);

	cout << a + b << endl;

	CMyDataEx c(3), d(4), e(0);

	e = c + d; 
	//CMyDataEx Ŭ������ �´� ���� �����ڰ� ������������ ���� �߻�
	//c + d �� ���� �߻� x -> +�� CMyData �����̱� ����
	//�� ������ �ذ��ϱ� ���ؼ� CMyDataEx���� operator +�� �����ϸ� ��

	cout << e << endl;

	return 0;
}*/