#include<iostream>

using namespace std;

class CNode
{
	friend class CMyList;

private:
	char m_szName[32];

	CNode* pNext = nullptr;
public: 
	explicit CNode(const char* pszName)
	{
		strcpy_s(m_szName, sizeof(m_szName), pszName);
	}
};

class CMyList
{
private:
	CNode m_HeadNode;
public:
	CMyList() : m_HeadNode("Dummy Head") {}

	~CMyList()
	{
		CNode* pNode = m_HeadNode.pNext;

		CNode* pDelete = nullptr;

		while (pNode)
		{
			pDelete = pNode;

			pNode = pNode->pNext;

			delete pDelete;
		}

		m_HeadNode.pNext = nullptr;
	}

	void AddNewNode(const char *pszName)
	{
		CNode* pNode = new CNode(pszName);

		pNode->pNext = m_HeadNode.pNext;

		m_HeadNode.pNext = pNode;
	}

	void Print()
	{
		CNode* pNode = m_HeadNode.pNext;

		while (pNode)
		{
			cout << pNode->m_szName << endl;

			pNode = pNode->pNext;
		}
	}
};

//CMyUI 클래스는 CMyList 클래스의 인스턴스를 멤버 데이터로 가지게 함
//이 덕분에 CMyUI 인스턴스가 생성되면 CMyList 인스턴스도 함께 생성되고 CMyUI 인스턴스가 소멸하면 CMyList 인스턴스도 함께 소멸함
class CMyUI
{
private:
	//CMyUI의 멤버로 CMyList 클래스의 인스턴스가 선언됨
	//만일 포인터나 참조였다면 Aggregation 관계가 됨(CMyUi 클래스가 소멸하더라도 CMyList의 객체는 따로 떨어져 남을 수 있기 때문)
	CMyList m_list;
public:
	int PrintMenu()
	{
		system("cls");
		cout << "[1]Add\t" << "[2]Print\t" << "[0]Exit\n:";
		cout.flush();

		int nInput = 0;

		cin >> nInput;

		return nInput;
	}

	void Run()
	{
		char szName[32];

		int nInput = 0;

		while ((nInput = PrintMenu()) > 0)
		{
			switch (nInput)
			{
			case 1:
				cout << "이름: ";
				cout.flush();

				cin >> szName;
				m_list.AddNewNode(szName);

				break;
			case 2:
				m_list.Print();

				break;

			default:
				break;
			}
		}
	}
};
/*
int main()
{
	CMyUI ui;

	ui.Run();

	return 0;
}*/