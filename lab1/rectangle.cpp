#include "rectangle.h"
#include <math.h>

Rectangle::Rectangle(std::istream&is){
    std::cout <<"set x1 and y1:";
    is >> x1 >> y1;
    std::cout <<"set x2 and y2:";
    is >> x2 >> y2;
    std::cout <<"set x3 and y3:";
    is >> x3 >> y3;
    std::cout <<"set x4 and y4:";
    is >> x4 >> y4;
}
void Rectangle::Print(std::ostream&os){
    os << "Rectangle " << "(" <<x1<<" "<<y1<<")"<< "(" <<x2<<" "<<y2<<")"<< "(" <<x3<<" "<<y3<<")"<< "(" <<x4<<" " <<y4<<")" <<std::endl;
}
size_t Rectangle::VertexesNumber(){
    return 4;
}
bool Rectangle::isit(){
double perp;
double perp2;
perp=(x4-x1)*(x2-x1)+(y4-y1)*(y2-y1);
perp2=(x3-x4)*(x3-x2)+(y3-y4)*(y3-y2);
if((perp+perp2)==0) return true;
else return false;

}
double Rectangle::Area(){
    double r1 = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    double r2 = sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3));
    double r3 = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
    double p=(r1+r2+r3)/2;
    double s= 2*sqrt((p * (p - r1) * (p - r2) * (p - r3)));
    return s;
}
