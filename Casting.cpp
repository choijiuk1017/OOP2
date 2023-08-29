#include <iostream>

using namespace std;

//static_cast용 클래스
class CMyData
{
private:
    int m_nData = 0;

public:
    CMyData() {}
    virtual ~CMyData() {}

    void SetData(int nParam) { m_nData = nParam; }

    int GetData() { return m_nData; }
};

class CMyDataEx : public CMyData
{
public:
    void SetData(int nParam)
    {
        if (nParam > 10)
        {
            nParam = 10;
        }

        CMyData::SetData(nParam);
    }

    void PrintData()
    {
        cout << "PrintData(): " << GetData() << endl;
    }
};


//dynamic_cast용 클래스

class CShape
{
public:
    CShape() {}
    virtual ~CShape() {}
    virtual void Draw()
    {
        cout << "CShape::Draw()" << endl;
    }
};

class CRectangle : public CShape
{
public:
    virtual void Draw()
    {
        cout << "CRectangle::Draw()" << endl;
    }
};

class CCircle : public CShape
{
public:
    virtual void Draw()
    {
        cout << "CCircle::Draw()" << endl;
    }
};
/*
int main()
{

    //1. static_cast
    //파생 형식의 객체를 기본 형식으로 포인팅
    CMyData* pData = new CMyDataEx;

    CMyDataEx* pNewData = NULL;


    //파생 형식의 객체를 기본 형식으로 포인팅했기 때문에 CMyData의 SetData()를 호출
    //가상 함수가 아니라면 실 형식보다 참조 형식이 우선 되기 때문
    pData->SetData(15);


    //CMyData* 형식인 pData의 값을 CMyDataEX* 형식으로 변환한다
    //형 변환 연산자의 피연산자는 반드시 괄호에 들어가야 하며 문법적으로 적절한 상향, 하향 형변환이 아니면 오류 발생
    pNewData = static_cast<CMyDataEx*>(pData);

    pNewData->PrintData();


    //2. dynamic_cast
    //dynamic_cast를 사용한다면 좋지 않은 방향으로 흘러가고 있다는 것을 의미한다.
    //dunamic_cast는 꼭 필요한 상황이 아니면 사용하지 않는다
    //성능을 떨어뜨리는 주범이며 코드를 복잡하게 만들기 때문
    cout << "도형 번호를 입력하시오. [1: 사각형, 2: 원]: " << endl;
    int input = 0;

    cin >> input;

    CShape* pShape = nullptr;
    if (input == 1)
    {
        pShape = new CRectangle;
    }
    else if (input == 2)
    {
        pShape = new CCircle;
    }
    else
    {
        pShape = new CShape;
    }

    //좋은 예
    pShape->Draw();

    //나쁜 예
    //가상 함수를 활용한다면 이딴 코드를 작성하지 않아도 된다
    CRectangle* pRect = dynamic_cast<CRectangle*>(pShape);
    if (pRect != NULL)  //dynamic_cast는 실패하면 NULL을 반환하기 때문
    {
        cout << "CRectangle::Draw()" << endl;
    }
    else
    {
        CCircle* pCircle = dynamic_cast<CCircle*>(pShape);
        if (pCircle != NULL)
        {
            cout << "CCircle::Draw()" << endl;
        }
        else
        {
            cout << "CShape::Draw()" << endl;
        }
    }
    //이와 같은 자료형 확인법을 RTTI(Run Time Type Information)라고 한다

    delete pData;

    return 0;
}*/

