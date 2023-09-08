#include<iostream>

using namespace std;

template<typename T>
class CMyData
{
private: 
	T m_Data;
public:
	CMyData(T param) : m_Data(param) {}

	T GetData() const { return m_Data; }

	void SetData(T param)
	{
		m_Data = param;
	}
};

template< >
class CMyData<char*>
{
private:
	char* m_Data;
public:
	CMyData(char* pszParam)
	{
		int nLen = strlen(pszParam);
		m_Data = new char[nLen + 1];
	}

	~CMyData() { delete[] m_Data; }

	char* GetData() const { return m_Data; }

};

/*
int main()
{
	CMyData<char*> a("Hello");

	cout << a.GetData() << endl;

	return 0;
}*/