//unique_ptr은 shared_ptr과 유사함
//shared_ptr과는 달리 한 대상을 오로지 한 포인터로만 포인팅 가능

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

int main()
{
	unique_ptr<CTest> ptr1(new CTest);

	//아래 코드들은 실행하면 모두 컴파일 오류가 발생한다
	//unique_ptr은 하나의 대상에 오직 하나의 포인터만 존재할 수 있기 때문
	//unique_ptr<CTest> ptr2(ptr1);
	//ptr2 = ptr1;

	return 0;
}
//shared_ptr과 unique_ptr을 적절히 섞어서 사용하는 것이 좋음