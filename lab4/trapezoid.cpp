#include "trapezoid.h"
#include <math.h>
Trapezoid::Trapezoid():x1(0),y1(0),x2(1),y2(1),x3(0),y3(0),x4(0),y4(0){

}
Trapezoid::Trapezoid(int x1,int x2,int x3,int x4,int y1,int y2,int y3,int y4){
    this->x1=x1;
    this->x2=x2;
    this->x3=x3;
    this->x4=x4;
    this->y1=y1;
    this->y2=y2;
    this->y3=y3;
    this->y4=y4;
}
Trapezoid::Trapezoid(std::istream&is){
    std::cout <<"set x1 and y1:";
    is >> x1 >> y1;
    std::cout <<"set x2 and y2:";
    is >> x2 >> y2;
    std::cout <<"set x3 and y3:";
    is >> x3 >> y3;
    std::cout <<"set x4 and y4:";
    is >> x4 >> y4;
}
void Trapezoid::Print(std::ostream&os){
    os << "Trapezoid " << "(" <<x1<<" "<<y1<<")"<< "(" <<x2<<" "<<y2<<")"<< "(" <<x3<<" "<<y3<<")"<< "(" <<x4<<" " <<y4<<")" <<std::endl;
}
size_t Trapezoid::VertexesNumber(){
    return 4;
}
Trapezoid::~Trapezoid(){
    std::cout<<"Rectangle was deleted\n";
}

bool Trapezoid::isit(){
double k=(y1-y4)/(x1-x4);
double k1=(y2-y3)/(x2-x3);
if(k==k1) return true;
else return false;
}
double Trapezoid::Area(){
  double h=sqrt((y2-y1)*(y2-y1));
  double os1=sqrt((x4-x1)*(x4-x1)+(y1-y4)*(y1-y4));
  double os2=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
  double s=(os1+os2)*h/2;
    return s;
}
std::ostream& operator<<(std::ostream &out, const Trapezoid &rec){
    out << "Rhombus coords " <<"("<< rec.x1 << "," << rec.y1 << ")"<< " "  <<"("<< rec.x2 << "," << rec.y2 << ")"<< " "<< "("<< rec.x3 << "," << rec.y3 << ")"<< " " << "("<<rec.x4 << "," << rec.y4 << ")"<< std::endl;
    return out;
}
std::istream& operator>>(std::istream &in,Trapezoid &rec){
    in >> rec.x1;
    in >> rec.y1;
    in >> rec.x2;
    in >> rec.y2;
    in >> rec.x3;
    in >> rec.y3;
    in >> rec.x4;
    in >> rec.y4;
    return in;
}
