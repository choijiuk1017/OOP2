#include<iostream>

using namespace std;

class CNode
{
	friend class CMyList;
private: 
	char m_szName[32];

	CNode* pNext = nullptr;
public:
	//explicit을 사용하여 해당 생성자가 암시적 형변환을 허용하지 않도록 지정한다.
	//형변환 연산자로 인한 예기치 않은 동작을 방지하고 코드 안정성을 높이는데 도움이 됨
	explicit CNode(const char* pszName)
	{
		//문자열 복사 함수
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

			cout << pDelete->m_szName << endl;

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
};


int main()
{
	CMyList list;

	list.AddNewNode("길동");

	list.AddNewNode("철수");

	list.AddNewNode("영희");

	return 0;
}