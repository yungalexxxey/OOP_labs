#include "rhombus.h"
#include <math.h>

Rhombus::Rhombus(std::istream&is){
    std::cout <<"set x1 and y1:";
    is >> x1 >> y1;
    std::cout <<"set x2 and y2:";
    is >> x2 >> y2;
    std::cout <<"set x3 and y3:";
    is >> x3 >> y3;
    std::cout <<"set x4 and y4:";
    is >> x4 >> y4;
}
Rhombus::~Rhombus(){
    
}
void Rhombus::Print(std::ostream&os){
    os << "Rhombus " << "(" <<x1<<" "<<y1<<")"<< "(" <<x2<<" "<<y2<<")"<< "(" <<x3<<" "<<y3<<")"<< "(" <<x4<<" " <<y4<<")" <<std::endl;
}
size_t Rhombus::VertexesNumber(){
    return 4;
}
bool Rhombus::isit(){
    if((sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))==sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3)))&&(sqrt((x3-x4)*(x3-x4)+(y3-y4)*(y3-y4))==sqrt((x1-x4)*(x1-x4)+(y1-y4)*(y1-y4)))) return true;
}
double Rhombus::Area(){
    double d1 = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
    double d2 = sqrt((x2 - x4) * (x2 - x4) + (y2 - y4) * (y2 - y4));
    double s=d1*d2/2;
    return s;
}
