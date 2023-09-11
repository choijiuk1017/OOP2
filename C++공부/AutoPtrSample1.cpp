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

/*
int main()
{
	cout << "*****Begin*****" << endl;
	{
		//속한 범위를 벗어나면 대상 객체는 자동으로 소멸한다.
		//ptrTest는 CMyData 객체를 동적으로 생성하고 그 주소를 생성자의 인수로 받음
		//ptrTest 내부의 포인터 멤버가 동적 생성된 객체의 주소를 담고 있다가 ptrTest가 소멸하면서 가리키는 대상을 삭제함
		auto_ptr<CMyData> ptrTest(new CMyData);

		//auto_ptr<CMyData> ptrTest(new CMyData[3]); 배열로 동적 할당하면 문제가 발생함
		//배열로 동적 생성은 가능하나 배열로 삭제가 되지 않기 때문
	}

	cout << "*****End*****" << endl;

	return 0;
}*/