#include "rectangle.h"
#include <math.h>


Rectangle::Rectangle():x1(0),y1(0),x2(0),y2(0),x3(0),y3(0),x4(0),y4(0){

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

std::ostream& operator<<(std::ostream &out, const Rectangle &rec){

    out << "Rectangle coords " <<"("<< rec.x1 << "," << rec.y1 << ")"<< " "  <<"("<< rec.x2 << "," << rec.y2 << ")"<< " "<< "("<< rec.x3 << "," << rec.y3 << ")"<< " " << "("<<rec.x4 << "," << rec.y4 << ")"<< std::endl;
    return out;
}
std::istream& operator>>(std::istream &in,Rectangle &rec){
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
Rectangle& Rectangle::operator= (Rectangle &rec){
    this->x1=rec.x1;
    this->x2=rec.x2;
    this->x3=rec.x3;
    this->x4=rec.x4;
    this->y1=rec.y1;
    this->y2=rec.y2;
    this->y3=rec.y3;
    this->y4=rec.y4;
}
