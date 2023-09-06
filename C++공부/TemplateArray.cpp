#include<iostream>

using namespace std;


template<typename T>
class CMyArray
{
private:
	T* m_pData = nullptr;

	int m_nSize = 0;

public:

	explicit CMyArray(int nSzie) : m_nSize(nSzie)
	{
		m_pData = new T[nSzie];
	}

	~CMyArray() { delete[] m_pData; }

	//복사 생성자
	CMyArray(const CMyArray& rhs)
	{
		m_pData = new T[rhs.m_nSize];

		memcpy(m_pData, rhs.m_pData, sizeof(T) * rhs.m_nSize);

		m_nSize = rhs.m_nSize;
	}

	//대입 연산자
	CMyArray& operator = (const CMyArray& rhs)
	{
		if (this == &rhs)
		{
			return *this;
		}

		delete m_pData;

		//r-value에 맞게 새로 생성
		m_pData = new T[rhs.m_nSize];

		memcpy(m_pData, rhs.m_pData, sizeof(T) * rhs.m_nSize);

		m_nSize = rhs.m_nSize;

		return *this;
	}

	//이동 생성자
	CMyArray(CMyArray&& rhs)
	{
		operator = (rhs);
	}

	//이동 대입 연산자
	CMyArray& operator = (const CMyArray&& rhs)
	{
		m_pData = rhs.m_pData;

		m_nSize = rhs.m_nSize;

		rhs.m_pData = nullptr;
		rhs.m_nSize = 0;
	}

	//배열 연산자
	T& operator[](int nIndex)
	{
		if (nIndex < 0 || nIndex >= m_nSize)
		{
			cout << "Error: 배열의 경계를 벗어난 접근입니다." << endl;

			exit(1);
		}

		return m_pData[nIndex];
	}

	//상수화된 배열 연산자
	T& operator[](int nIndex) const
	{
		return operator[](nIndex);
	}

	//배열 요소의 개수를 반환
	int GetSize() { return m_nSize; }

};

/*
int main()
{
	//int 자료형 배열
	//int 자료형 값 다섯 개가 저장 될 수 있는 메모리를 동적 할당, arr 인스턴스 생성
	CMyArray<int> arr(5);

	arr[0] = 10;
	arr[1] = 20;
	arr[2] = 30;
	arr[3] = 40;
	arr[4] = 50;

	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;

	//새로 CMyArray 클래스 템플릿의 인스턴스 생성, 요소의 개수 3
	CMyArray<int> arr2(3);

	//arr은 5개, arr2는 3개이나 새로 정의한 대입 연산자를 통해 r-value에 맞춰 추가 생성
	arr2 = arr;

	for (int i = 0; i < 5; i++)
	{
		cout << arr2[i] << ' ';
	}

	cout << endl;

	return 0;
}*/