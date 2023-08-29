#include<iostream>

using namespace std;
class CMyData
{
private:
	int m_nData = 0;

public:
	CMyData(int nParam) : m_nData(nParam) {}

	int GetData() const { return m_nData; }

	void SetData(int nParam)
	{
		m_nData = nParam;
	}

	friend void PrintData(const CMyData&);

};

void PrintData(const CMyData& rData)
{
	//������ �Լ��̹Ƿ� ���� ���� �������� ������ ���� ����
	//private ����� ���� ����
	cout << "PrintData(): " << rData.m_nData << endl;
}


int main()
{
	CMyData a(5);
	PrintData(a);

	return 0;
}