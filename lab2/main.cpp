
#include <iostream>
#include "rectangle.cpp"
#include "rectangle.h"
#include "figure.h"
#include "tvector.h"
int main()
{
    TVector container;
    Rectangle rec1(1,2,3,4,5,6,7,1);
    Rectangle rec2(1,2,3,4,5,6,7,2);
    Rectangle rec3(1,2,3,4,5,6,7,3);
    Rectangle rec4(1,2,3,4,5,6,7,4);
    container.InsertLast(rec1);
    container.InsertLast(rec2);
    container.InsertLast(rec3);
    container.InsertLast(rec4);
    std::cout<<container;
    std::cout<< container.Length()<<std::endl;
    container.Remove(2);
    std::cout<<container.Last()<<std::endl;
    std::cout<<container;
    return 0;
}
