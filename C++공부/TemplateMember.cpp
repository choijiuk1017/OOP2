#include<iostream>

using namespace std;

//필요하다면 클래스 템플릿에서도 선언과 정의를 분리할 수 있으며, 정적 멤버를 포함시키는 것도 가능
//정의가 분리되고 기술될 때마다 template<typename 형식>을 매번 선언해야 함
//이외에는 일반 클래스에서의 분리 방법과 다르지 않음

template<typename T>

class CTest
{
protected: 
	//정적 멤버 데이터 선언
	static T m_Data;

public:
	//생성자 선언
	CTest();
	T TestFunc();
};

//생성자 정의
template<typename T>
CTest<T>::CTest()
{

}

//멤버 함수 정의
template<typename T>
T CTest<T>::TestFunc()
{
	return m_Data;
}

//정적 멤버 변수 정의
template<typename T>
T CTest<T>::m_Data = 15;

/*
int main()
{
	CTest<double> a;

	cout << a.TestFunc() << endl;

	return 0;
}*/