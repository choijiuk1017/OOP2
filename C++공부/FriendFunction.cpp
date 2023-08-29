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
	//프렌드 함수이므로 접근 제어 지시자의 영향을 받지 않음
	//private 멤버에 직접 접근
	cout << "PrintData(): " << rData.m_nData << endl;
}


int main()
{
	CMyData a(5);
	PrintData(a);

	return 0;
}