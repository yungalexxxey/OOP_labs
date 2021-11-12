#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <iostream>

class Rectangle
{
public:
    Rectangle();
    Rectangle(int x1, int x2, int x3, int x4, int y1, int y2, int y3, int y4);
    Rectangle(std::istream &is);
    bool isit();
    void Print(std::ostream &os);
    size_t VertexesNumber();
    double Area();
    ~Rectangle();
    friend std::ostream &operator<<(std::ostream &out, const Rectangle &rec);
    friend std::istream &operator>>(std::istream &in, Rectangle &rec);

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
