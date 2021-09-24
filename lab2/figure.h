#ifndef FIGURE_H
#define FIGURE_H
#include <iostream>
class figure {
public:
    virtual double Area()=0;
    virtual size_t VertexesNumber()=0;
    virtual bool isit()=0;
};
#endif // FIGURE_H
