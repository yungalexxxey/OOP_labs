#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "figure.h"
#include <iostream>

class rectangle:public figure{
public:
    rectangle();
    size_t VertexesNumber();
    double Area();
    bool isit();
    friend std::ostream& operator<<(std::ostream &out, const rectangle &rec);
    friend std::istream& operator>>(std::istream &in, rectangle &rec);
    rectangle& operator= (rectangle &rec1);

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
