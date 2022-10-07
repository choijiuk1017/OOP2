#include <iostream>
#include "Pet.h"
#include "Dog.h"
#include "Utils.h"


//2022.10.07
//C에서는 함수 이름만 같으면 같은 함수로 취급
//C++에서는 상관 없음

 /*
void print(int a);

void print(float a);

함수 오버로딩 function overloading
 */

/* 함수의 소속에 따라서 같은 이름의 함수이어도 다른 함수로 취급
class A : public B{

    B b; --> A가 만들어질 때 B도 만들어짐

public:
    void print(int a);

    void printB()
    {
        B::print() -->  오류, B의 정보가 없기 때문에 불러올 수 없음
        --> B를 상속받았을 때에는 가능

        B b;
        b.print(); --> B를 실체화하였기 때문에 불러올 수 있음

    }

};

class B{
public:
    void print(int a);

};
*/

int main()
{
    //method
    //materialization, instantiation (변수화)

    //A a; 클래스를 변수화 해 실체로 만듦
    //B b;

    //A::print(); 사용 안됨
    //B::print();

    Dog* happy = new Dog("happy", 1);

    happy->eat();
    happy->sleep();

    (static_cast<Dog*>(happy))->bark();

    delete happy;
    
    return 0;
}
