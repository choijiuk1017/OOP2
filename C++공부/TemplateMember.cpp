#include<iostream>

using namespace std;

//�ʿ��ϴٸ� Ŭ���� ���ø������� ����� ���Ǹ� �и��� �� ������, ���� ����� ���Խ�Ű�� �͵� ����
//���ǰ� �и��ǰ� ����� ������ template<typename ����>�� �Ź� �����ؾ� ��
//�̿ܿ��� �Ϲ� Ŭ���������� �и� ����� �ٸ��� ����

template<typename T>

class CTest
{
protected: 
	//���� ��� ������ ����
	static T m_Data;

public:
	//������ ����
	CTest();
	T TestFunc();
};

//������ ����
template<typename T>
CTest<T>::CTest()
{

}

//��� �Լ� ����
template<typename T>
T CTest<T>::TestFunc()
{
	return m_Data;
}

//���� ��� ���� ����
template<typename T>
T CTest<T>::m_Data = 15;

/*
int main()
{
	CTest<double> a;

	cout << a.TestFunc() << endl;

	return 0;
}*/