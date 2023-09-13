//shared_ptr은 배열로 객체를 삭제할 수 있는 방법 제공
//배열로 대상을 삭제하는 함수를 개발자가 직접 작성하고 등록해야함

#include<memory>
#include<iostream>

using namespace std;

class CTest
{
public:
	CTest() { cout << "CTest()" << endl; }
	~CTest() { cout << "~CTest()" << endl; }
	void TestFunc() { cout << "TestFunc()" << endl; }
};

void RemoveTest(CTest* pTest)
{
	cout << "RemoveTest()" << endl;

	//대상을 배열로 삭제한다
	delete[] pTest;
}

int main()
{
	cout << "*****Begin*****" << endl;

	//대상 객체를 소멸할 함수를 별도로 등록한다
	//RemoveTest 함수는 ptr이 소멸할 때 자동으로 호출되며 함수 내부에서 배열로 삭제함
	shared_ptr<CTest> ptr(new CTest[3], RemoveTest);

	cout << "*****End*****" << endl;

	return 0;
}

//auto_ptr보다 shared_ptr을 사용하는 것이 바람직함