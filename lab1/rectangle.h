#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "figure.h"
#include <iostream>

class Rectangle:public Figure{
public:
    Rectangle();
    Rectangle(std::istream&is);
    void Print(std::ostream&os);
    size_t VertexesNumber();
    double Area();
    virtual ~Rectangle();

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

#endif // RECTANGLE_H
