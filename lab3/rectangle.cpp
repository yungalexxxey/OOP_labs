#include "rectangle.h"
#include <math.h>


rectangle::rectangle():x1(0),y1(0),x2(1),y2(1),x3(0),y3(0),x4(0),y4(0){

}
rectangle::rectangle(int x1,int x2,int x3,int x4,int y1,int y2,int y3,int y4){
    this->x1=x1;
    this->x2=x2;
    this->x3=x3;
    this->x4=x4;
    this->y1=y1;
    this->y2=y2;
    this->y3=y3;
    this->y4=y4;
}
size_t rectangle::VertexesNumber(){
    return 4;
}
rectangle::~rectangle(){
    std::cout<<"Rectangle was deleted\n";
}

bool rectangle::isit(){
    double perp;
    double perp2;
    perp=(x4-x1)*(x2-x1)+(y4-y1)*(y2-y1);
    perp2=(x3-x4)*(x3-x2)+(y3-y4)*(y3-y2);
    if((perp+perp2)==0) return true;
    else return false;
}
double rectangle::Area(){
    double r1 = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    double r2 = sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3));
    double r3 = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
    double p=(r1+r2+r3)/2;
    double s= 2*sqrt((p * (p - r1) * (p - r2) * (p - r3)));
    return s;
}

std::ostream& operator<<(std::ostream &out, const rectangle &rec){
    out << "Rectangle coords " <<"("<< rec.x1 << "," << rec.y1 << ")"<< " "  <<"("<< rec.x2 << "," << rec.y2 << ")"<< " "<< "("<< rec.x3 << "," << rec.y3 << ")"<< " " << "("<<rec.x4 << "," << rec.y4 << ")"<< std::endl;
    return out;
}
std::istream& operator>>(std::istream &in,rectangle &rec){
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
rectangle& rectangle::operator= (rectangle &rec){
    this->x1=rec.x1;
    this->x2=rec.x2;
    this->x3=rec.x3;
    this->x4=rec.x4;
    this->y1=rec.y1;
    this->y2=rec.y2;
    this->y3=rec.y3;
    this->y4=rec.y4;
    return *this;
}
