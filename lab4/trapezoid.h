#ifndef TRAPEZOID_H
#define TRAPEZOID_H
#include "figure.h"
#include <iostream>

class Trapezoid:public figure
{
public:
    Trapezoid();
    Trapezoid(std::istream&is);
    Trapezoid(int x1,int x2,int x3,int x4,int y1,int y2,int y3, int y4);
    bool isit();
    void Print(std::ostream&os);
    size_t VertexesNumber();
    double Area();
    ~Trapezoid();
    friend std::ostream &operator<<(std::ostream &out,const Trapezoid &rec);
    friend std::istream &operator>>(std::istream &in,Trapezoid &rec);
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

#endif // TRAPEZOID_H
