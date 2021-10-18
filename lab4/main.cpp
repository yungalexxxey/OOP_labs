
#include <iostream>
#include "rectangle.cpp"
#include "rhombus.cpp"
#include "trapezoid.h"
#include <tvector.h>

int main()
{
    TVector<Rectangle> containerrec;
    TVector<Rhombus> containerrhom;
    TVector<Trapezoid> containertrap;
    containerrec.push_back(std::shared_ptr<Rectangle>(new Rectangle(1,2,2,3,4,4,4,4)));
    containerrhom.push_back(std::shared_ptr<Rhombus>(new Rhombus(1,2,2,3,4,4,4,4)));
    containertrap.push_back(std::shared_ptr<Trapezoid>(new Trapezoid(2,2,2,3,4,4,4,4)));
    containerrec.push_back(std::shared_ptr<Rectangle>(new Rectangle(1,2,2,3,4,4,4,4)));
    containerrhom.push_back(std::shared_ptr<Rhombus>(new Rhombus(1,2,2,3,4,4,4,4)));
    containertrap.push_back(std::shared_ptr<Trapezoid>(new Trapezoid(2,2,2,3,4,4,4,4)));
    containerrec.push_back(std::shared_ptr<Rectangle>(new Rectangle(1,2,2,3,4,4,4,4)));
    containerrhom.push_back(std::shared_ptr<Rhombus>(new Rhombus(1,2,2,3,4,4,4,4)));
    containertrap.push_back(std::shared_ptr<Trapezoid>(new Trapezoid(2,2,2,3,4,4,4,4)));
    std::shared_ptr<Rectangle> trec;
    std::shared_ptr<Rhombus> trhom;
    std::shared_ptr<Trapezoid> ttrap;
    std::cout<<containerrec<<std::endl;
    trec=containerrec.pop_back();
    ttrap=containertrap.pop_back();
    trhom=containerrhom.pop_back();
    std::cout<<*trec<<std::endl;
    std::cout<<*trhom<<std::endl;
    std::cout<<*ttrap<<std::endl;
    std::cout<<containerrec<<std::endl;
    std::cout<< containerrhom<<std::endl;
    std::cout<< containertrap<<std::endl;
return 0;
}
