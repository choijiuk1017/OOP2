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

//CMyUI Ŭ������ CMyList Ŭ������ �ν��Ͻ��� ��� �����ͷ� ������ ��
//�� ���п� CMyUI �ν��Ͻ��� �����Ǹ� CMyList �ν��Ͻ��� �Բ� �����ǰ� CMyUI �ν��Ͻ��� �Ҹ��ϸ� CMyList �ν��Ͻ��� �Բ� �Ҹ���
class CMyUI
{
private:
	//CMyUI�� ����� CMyList Ŭ������ �ν��Ͻ��� �����
	//���� �����ͳ� �������ٸ� Aggregation ���谡 ��(CMyUi Ŭ������ �Ҹ��ϴ��� CMyList�� ��ü�� ���� ������ ���� �� �ֱ� ����)
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
				cout << "�̸�: ";
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