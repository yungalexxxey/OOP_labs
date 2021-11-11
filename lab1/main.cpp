
#include <iostream>
#include "rectangle.h"
#include "rhombus.h"
#include "trapezoid.h"
//#include "Figure.h"
int main()
{
Figure *a=new Trapezoid(std::cin);
while(true){
std::cout<<"set Trapezoid coords"<<std::endl;
if(a->isit()){
a->Print(std::cout);
std::cout<<"S="<< a->Area()<<std::endl;
std::cout<< "Vertex number is "<<a->VertexesNumber()<<std::endl;
break;
}
else std::cout<<"This is not trapezoid"<<std::endl;
}

Figure *b=new Rectangle(std::cin);
while(true){
std::cout<<"set Rectangle coords"<<std::endl;
if(b->isit()){
b->Print(std::cout);
std::cout<<"S="<< b->Area()<<std::endl;
std::cout<< "Vertex number is "<<b->VertexesNumber()<<std::endl;
break;
}
else std::cout<<"This is not rectangle"<<std::endl;
}

std::cout<<"set Rhombus coords"<<std::endl;
Figure *c=new Rhombus(std::cin);
while(true) {
  std::cout<<c->isit()<<std::endl;
if (c->isit()) {
    std::cout<<"S="<< c->Area()<<std::endl;
    std::cout<< "Vertex number is "<<c->VertexesNumber()<<std::endl;
    break;
}
else std::cout<<"This is not rhombus" <<std::endl;;
}
delete (Trapezoid*)a;
delete (Rectangle*)b;
delete (Rhombus*)c;
return 0;
}
