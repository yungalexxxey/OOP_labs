#ifndef RHOMBUS_H
#define RHOMBUS_H
#include "figure.h"
#include <iostream>

class Rhombus:public figure{
public:
    Rhombus();
    Rhombus(int x1,int x2,int x3,int x4,int y1,int y2,int y3, int y4);
    Rhombus(std::istream&is);
    bool isit();
    void Print(std::ostream&os);
    size_t VertexesNumber();
    double Area();
    ~Rhombus();
    friend std::ostream &operator<<(std::ostream &out,const Rhombus &rec);
    friend std::istream &operator>>(std::istream &in,Rhombus &rec);
private:
    double x1;
    double y1;
    double x2;
    double y2;
    double x3;
    double y3;
    double x4;
    double y4;
};

#endif // RHOMBUS_H
