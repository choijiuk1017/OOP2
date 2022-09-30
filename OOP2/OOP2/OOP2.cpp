#include <iostream>
#include "Pet.h"
#include "Dog.h"
#include "Utils.h"

int main()
{
    Dog* happy = new Dog("happy", 1);

    happy->eat();
    happy->sleep();

    (static_cast<Dog*>(happy))->bark();

    delete happy;
    
    return 0;
}
