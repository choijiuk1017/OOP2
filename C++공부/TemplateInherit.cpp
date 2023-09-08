#include<iostream>

using namespace std;

//클래스 템플릿의 상속
//상속 시 template 선언

template<typename T>
class CMyData
{
protected:
	T m_Data;
public:

};

/*
template<typename T>
class CMyDataEx : public CMyData<T>
{
public:
	T GetData() const { return m_Data; }

	void SetData(T param) { m_Data = param; }

};
*/

/*
int main()
{
	CMyDataEx<int> a;

	a.SetData(5);

	cout << a.GetData() << endl;

	return 0;
}*/