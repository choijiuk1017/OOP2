#include<memory>
#include<iostream>

//얕은 복사 실행 시 auto_ptr

using namespace std;
class CMyData
{
public:
	CMyData() { cout << "CMyData()" << endl; }
	~CMyData() { cout << "~CMyData()" << endl; }
	void TestFunction() { cout << "CMyData::TestFunction()" << endl; }
};

/*
int main()
{
	//CMyData 클래스를 동적 생성하고 그 주소를 생성자의 인수로 받음
	auto_ptr<CMyData> ptrTest(new CMyData);

	//가리키는 대상 없이 포인터만 선언함
	auto_ptr<CMyData> ptrNew;

	cout << "0x" << ptrTest.get() << endl;

	//포인터를 대입하면 원본 포인터는 NULL이 된다
	//ptrTest는 자신이 가리키는 포인터의 값을 ptrNew 인스턴스에 복사해주고 자기 자신의 포인터를 NULL로 초기화함
	ptrNew = ptrTest;
	cout << "0x" << ptrTest.get() << endl;

	//따라서 이 코드를 실행할 수 없다
	ptrTest->TestFunction();

	return 0;
}
*/