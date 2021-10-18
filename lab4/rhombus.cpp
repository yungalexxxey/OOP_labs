#include "rhombus.h"
#include <math.h>
Rhombus::Rhombus():x1(0),y1(0),x2(1),y2(1),x3(0),y3(0),x4(0),y4(0){

}
Rhombus::Rhombus(int x1,int x2,int x3,int x4,int y1,int y2,int y3,int y4){
    this->x1=x1;
    this->x2=x2;
    this->x3=x3;
    this->x4=x4;
    this->y1=y1;
    this->y2=y2;
    this->y3=y3;
    this->y4=y4;
}
Rhombus::~Rhombus(){
    std::cout<<"Rhombus was deleted\n";
}
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
void Rhombus::Print(std::ostream&os){
    os << "Rhombus " << "(" <<x1<<" "<<y1<<")"<< "(" <<x2<<" "<<y2<<")"<< "(" <<x3<<" "<<y3<<")"<< "(" <<x4<<" " <<y4<<")" <<std::endl;
}
size_t Rhombus::VertexesNumber(){
    return 4;
}
bool Rhombus::isit(){
    if((sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))==sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3)))&&(sqrt((x3-x4)*(x3-x4)+(y3-y4)*(y3-y4))==sqrt((x1-x4)*(x1-x4)+(y1-y4)*(y1-y4)))) return true;
    else return false;
}
double Rhombus::Area(){
    double d1 = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
    double d2 = sqrt((x2 - x4) * (x2 - x4) + (y2 - y4) * (y2 - y4));
    double s=d1*d2/2;
    return s;
}


std::ostream& operator<<(std::ostream &out, const Rhombus &rec){
    out << "Rhombus coords " <<"("<< rec.x1 << "," << rec.y1 << ")"<< " "  <<"("<< rec.x2 << "," << rec.y2 << ")"<< " "<< "("<< rec.x3 << "," << rec.y3 << ")"<< " " << "("<<rec.x4 << "," << rec.y4 << ")\n";
    return out;
}
std::istream& operator>>(std::istream &in,Rhombus &rec){
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
