//스마트 포인터
//동적 할당한 인스턴스를 자동으로 삭제해주는 편리한 포인터

//auto_ptr
//사용하지 않는 것이 바람직함
//배열 지원 없음, 얕은 복사 문제가 해결되지 않음

#include<memory>
#include<iostream>

using namespace std;

class CMyData
{
private:
public:
	CMyData() { cout << "CMyData()" << endl; }
	~CMyData() { cout << "~CMyData()" << endl; }

};

int main()
{
	cout << "*****Begin*****" << endl;
	{
		//속한 범위를 벗어나면 대상 객체는 자동으로 소멸한다.
		auto_ptr<CMyData> ptrTest(new CMyData);
	}

	cout << "*****End*****" << endl;

	return 0;
}