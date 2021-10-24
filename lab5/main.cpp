
#include <iostream>
#include "rectangle.cpp"
#include <tvector.h>
#include "Iter.h"

int main()
{  TVector<Rectangle> vec;
    vec.push_back(std::shared_ptr<Rectangle>(new Rectangle(1, 1, 1,1,1,1,1,1)));
    vec.push_back(std::shared_ptr<Rectangle>(new Rectangle(2, 2, 2,2,2,2,2,2)));
    vec.push_back(std::shared_ptr<Rectangle>(new Rectangle(3, 3, 3,3,3,3,3,3)));
    std::cout<<"Last obj is " <<*vec.pop_back()<<std::endl;
    for (auto i : vec) {
     std::cout << *i << std::endl;
    }
return 0;
}
