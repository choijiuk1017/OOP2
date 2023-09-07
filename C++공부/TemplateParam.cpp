
#include<iostream>

using namespace std;

//���ø��� ������ �� ������ ���� �� �ۼ� ����
//���� ���� �� �Ϻδ� ������ ��ü������ �ۼ��ص� �������


//���ø� �Ű������� �Լ�ó�� ����
//���ø� �Ű������� Ŭ���� ���ø� ���ο��� ��� ���� ����
template <typename T = int , int nSize = 3> //����� �ڵ忡�� ���� ������� ������ ����Ʈ ������ ���� ����
class CMyArray
{
private:
	T* m_pData = nullptr;

public:

	//���� �ڵ忡 ���̴� ��� nSize ������ ���ø� �Ű� �����̴�.
	CMyArray() { m_pData = new T[nSize]; }

	~CMyArray() { delete[] m_pData; }

	//�迭 ������
	T& operator[](int nIndex)
	{
		if (nIndex < 0 || nIndex >= nSize)
		{
			cout << "ERROR: �迭�� ��踦 ��� �����Դϴ�." << endl;

			exit(1);

		}

		return m_pData[nIndex];
	}

	//���ȭ�� �迭 ������
	T& operator[](int nIndex) const { return operator[](nIndex); }

	//�迭 ����� ������ ��ȯ
	int GetSize() { return nSize; }

};

/*
int main()
{
	CMyArray<int, 3> arr;

	arr[0] = 10;
	arr[1] = 20;
	arr[2] = 30;

	for (int i = 0; i < 3; i++)
	{
		cout << arr[i] << endl;
	}

	return 0;
}*/