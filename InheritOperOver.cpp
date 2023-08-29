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

	//using 키워드 사용으로 상위 클래스의 연산자 함수를 그대로 차용
	//CMyDataEx는 자신만의 연산자를 따로 가진 것처럼 작동
	using CMyData::operator+;
	using CMyData::operator=;

	//기본 형식의 operator +()를 그대로 호출해주고 연산 결과가 저장된 CMyDataEx 객체를 반환
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
	//CMyDataEx 클래스에 맞는 대입 연산자가 없으면컴파일 오류 발생
	//c + d 는 오류 발생 x -> +가 CMyData 형식이기 때문
	//이 문제를 해결하기 위해선 CMyDataEx에서 operator +를 생성하면 됨

	cout << e << endl;

	return 0;
}*/