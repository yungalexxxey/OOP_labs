#ifndef FIGURE_H
#define FIGURE_H
#include <iostream>
class Figure {
 public:
     virtual void Print(std::ostream&os)=0;
     virtual double Area()=0;
     virtual size_t VertexesNumber()=0;
};
#endif // FIGURE_H
