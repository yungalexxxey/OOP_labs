
#include <iostream>
#include "rectangle.cpp"
#include "rectangle.h"
#include "Figure.h"
#include "tvector.h"
//#include "rhombus.cpp"
//#include "trapezoid.h"
int main()
{
    TVector container;
    container.push_back(std::shared_ptr<rectangle>(new rectangle));
    container.push_back(std::shared_ptr<rectangle>(new rectangle(1,2,3,4,5,6,7,8)));
    std::shared_ptr<rectangle> t;
    std::cout<<container<<std::endl;
    std::cout<<container.size()<<std::endl;
    t=container.pop_back();
    std::cout<< *t;
    std::cout<<container.size()<<std::endl;
    container.resize(5);
    std::cout<<container.size()<<std::endl;
    return 0;
}
