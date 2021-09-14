
#include <iostream>
#include "rectangle.cpp"
#include "rhombus.cpp"
#include "trapezoid.h"
int main()
{
while(true){
std::cout<<"set Trapezoid coords"<<std::endl;
figure *a=new trapezoid(std::cin);
if(a->isit()){
a->Print(std::cout);
std::cout<<"S="<< a->Area()<<std::endl;
std::cout<< "Vertex number is "<<a->VertexesNumber()<<std::endl;
delete a;
break;
}
else std::cout<<"This is not trapezoid"<<std::endl;
}

while(true){
std::cout<<"set Rectangle coords"<<std::endl;
figure *b=new rectangle(std::cin);
if(b->isit()){
b->Print(std::cout);
std::cout<<"S="<< b->Area()<<std::endl;
std::cout<< "Vertex number is "<<b->VertexesNumber()<<std::endl;
delete b;
break;
}
else std::cout<<"This is not rectangle"<<std::endl;
}

std::cout<<"set Rhombus coords"<<std::endl;
while(true) {
figure *c=new rhombus(std::cin);
  std::cout<<c->isit()<<std::endl;
if (c->isit()) {
    std::cout<<"S="<< c->Area()<<std::endl;
    std::cout<< "Vertex number is "<<c->VertexesNumber()<<std::endl;
    delete c;
    break;
}
else std::cout<<"This is not rhombus" <<std::endl;;
}

return 0;
}
