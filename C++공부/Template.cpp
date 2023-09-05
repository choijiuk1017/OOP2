#include<iostream>

using namespace std;


template<typename T>
class CMyData
{
private:
	T m_Data;

public: 
	CMyData(T param) : m_Data(param) {}

	T GetData() const
	{
		return m_Data;
	}

	operator T() { return m_Data; }

	void SetData(T param)
	{
		m_Data = param;
	}	
};
/*
int main()
{
	CMyData<int> a(5);

	cout << a << endl;

	CMyData<double> b(123.45);

	cout << b << endl;

	//CMyData<char*> c("Hello");

}*/