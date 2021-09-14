#include "trapezoid.h"
#include <math.h>

trapezoid::trapezoid(std::istream&is){
    std::cout <<"set x1 and y1:";
    is >> x1 >> y1;
    std::cout <<"set x2 and y2:";
    is >> x2 >> y2;
    std::cout <<"set x3 and y3:";
    is >> x3 >> y3;
    std::cout <<"set x4 and y4:";
    is >> x4 >> y4;
}
void trapezoid::Print(std::ostream&os){
    os << "Trapezoid " << "(" <<x1<<" "<<y1<<")"<< "(" <<x2<<" "<<y2<<")"<< "(" <<x3<<" "<<y3<<")"<< "(" <<x4<<" " <<y4<<")" <<std::endl;
}
size_t trapezoid::VertexesNumber(){
    return 4;
}
bool trapezoid::isit(){
double k=(y1-y4)/(x1-x4);
double k1=(y2-y3)/(x2-x3);
if(k==k1) return true;
else return false;
}
double trapezoid::Area(){
  double h=sqrt((y2-y1)*(y2-y1));
  double os1=sqrt((x4-x1)*(x4-x1)+(y1-y4)*(y1-y4));
  double os2=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
  double s=(os1+os2)*h/2;
    return s;
}
