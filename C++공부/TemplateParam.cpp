
#include<iostream>

using namespace std;

//템플릿을 선언할 때 형식을 여러 개 작성 가능
//여러 형식 중 일부는 형식을 구체적으로 작성해도 상관없음


//템플릿 매개변수를 함수처럼 선언
//템플릿 매개변수는 클래스 템플릿 내부에서 모두 접근 가능
template <typename T = int , int nSize = 3> //사용자 코드에서 따로 기술하지 않으면 디폴트 값으로 적용 가능
class CMyArray
{
private:
	T* m_pData = nullptr;

public:

	//이하 코드에 보이는 모든 nSize 변수는 템플릿 매개 변수이다.
	CMyArray() { m_pData = new T[nSize]; }

	~CMyArray() { delete[] m_pData; }

	//배열 연산자
	T& operator[](int nIndex)
	{
		if (nIndex < 0 || nIndex >= nSize)
		{
			cout << "ERROR: 배열의 경계를 벗어난 접근입니다." << endl;

			exit(1);

		}

		return m_pData[nIndex];
	}

	//상수화된 배열 연산자
	T& operator[](int nIndex) const { return operator[](nIndex); }

	//배열 요소의 개수를 반환
	int GetSize() { return nSize; }

};

/*
int main()
{
	CMyArray<int, 3> arr;

	arr[0] = 10;
	arr[1] = 20;
	arr[2] = 30;

	for (int i = 0; i < 3; i++)
	{
		cout << arr[i] << endl;
	}

	return 0;
}*/