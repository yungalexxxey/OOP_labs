
#include <iostream>
#include "rectangle.h"
#include "Figure.h"
#include "tvector.h"
int main()
{
    TVector container;
    container.push_back(std::shared_ptr<rectangle>(new rectangle));
    container.push_back(std::shared_ptr<rectangle>(new rectangle(1,2,3,4,5,6,7,8)));
    std::shared_ptr<rectangle> t;
    std::cout<<container<<std::endl;
    std::cout<<container.size()<<std::endl;
    container.clear();
    std::cout<<container<<std::endl;
    return 0;
}
