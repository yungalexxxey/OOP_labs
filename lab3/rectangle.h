#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "figure.h"
#include <iostream>

class rectangle:public figure{
public:
    rectangle();
    rectangle(int x1,int x2,int x3,int x4,int y1,int y2,int y3,int y4);
    size_t VertexesNumber();
    double Area();
    bool isit();
    friend std::ostream& operator<<(std::ostream &out, const rectangle &rec);
    friend std::istream& operator>>(std::istream &in, rectangle &rec);
    rectangle& operator= (rectangle &rec1);
    virtual ~rectangle();
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
