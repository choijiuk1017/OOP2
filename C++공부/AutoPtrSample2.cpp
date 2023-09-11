#include<memory>
#include<iostream>

using namespace std;
class CMyData
{
public:
	CMyData() { cout << "CMyData()" << endl; }
	~CMyData() { cout << "~CMyData()" << endl; }
	void TestFunction() { cout << "CMyData::TestFunction()" << endl; }
};

int main()
{
	auto_ptr<CMyData> ptrTest(new CMyData);

	auto_ptr<CMyData> ptrNew;

	cout << "0x" << ptrTest.get() << endl;

	ptrNew = ptrTest;
	cout << "0x" << ptrTest.get() << endl;

	ptrTest->TestFunction();

	return 0;
}