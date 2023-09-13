//shared_ptr은 auto_ptr과 달리 포인팅 횟수를 계산해서 0이 되면 대상을 삭제함

//shared_ptr을 사용하기 위해 선언
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

/*
int main()
{
	cout << "*****Begin*****" << endl;
	shared_ptr<CTest> ptr1(new CTest);

	//한 대상을 한 포인터로 포인팅한다
	cout << "Counter: " << ptr1.use_count() << endl; //use_count()는 포인터 개수를 출력하는 함수
	{
		shared_ptr<CTest> ptr2(ptr1);
		//ptr2 = ptr1 이와같이 작성해도 실행 결과는 동일함
		//ptr1의 값이 NULL이 되지 않음

		//한 대상을 두 포인터로 포인팅한다
		cout << "Counter: " << ptr2.use_count() << endl;
		ptr2->TestFunc();
	}

	//한 포인터가 소멸했으므로 포인팅 개수가 1 감소한다
	cout << "Counter: " << ptr1.use_count() << endl;

	//포인팅 개수가 감소해도 이미 참조 개수가 1이므로 ptr1은 삭제되지 않음
	ptr1->TestFunc();

	cout << "*****End*****" << endl;

	//결국 카운터가 0이 되면 대상 객체를 소멸한다.
	return 0;
 }*/