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

	void AddNewNode(const char* pszName)
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

//Composition 관계와 기능적으로 달라지는 것은 없음
//Aggregation 관계가 Composition 관계보다 좋을 경우가 많음
//프로그램의 제어 시스템, 사용자 인터페이스, 원본 데이터는 분리하는 것이 원칙
class CMyUI
{
private:

	//UI 클래스 내부에 자료구조 객체에 대한 참조만 존재한다
	CMyList& m_list;

public:
	//참조 멤버는 반드시 초기화 목록을 이용해 초기화한다
	CMyUI(CMyList &rList) : m_list(rList) {}

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
	CMyList list;
	CMyUI ui(list);

	ui.Run();

	return 0;
}*/