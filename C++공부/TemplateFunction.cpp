//간혹 특별한 형식이 있을 경우 나머지 다른 형식들과 전혀 다른 코드를 적용
#include<memory>
#include<iostream>

using namespace std;

template<typename T>
T Add(T a, T b) { return a + b;} 

//두 개의 변수가 모두 char* 이면 이 함수로 대체
template<>
char* Add(char* pszLeft, char* pszRight) //
{
	int nLenLeft = strlen(pszLeft);
	int nLenRight = strlen(pszRight);
	char* pszResult = new char[nLenLeft + nLenRight + 1];

	//새로 할당한 메모리에 문자열을 복사
	strcpy_s(pszResult, nLenLeft + 1, pszLeft);
	strcpy_s(pszResult + nLenLeft, nLenRight + 1, pszRight);

	return pszResult;
}

/*
int main()
{
	int nResult = Add<int>(3, 4);

	cout << nResult << endl;

	char* pszResult = Add<char*>("Hello", "World");
	cout << pszResult << endl;

	delete[] pszResult;

	return 0;


}*/