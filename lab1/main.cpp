
#include <iostream>
#include <vector>
#include "rectangle.h"
#include "rhombus.h"
#include "trapezoid.h"
//#include "Figure.h"
int main()
{
  std::vector<Figure *> vect;
  Figure *a = new Trapezoid(std::cin);
  vect.push_back(a);
  Figure *b = new Rectangle(std::cin);
  vect.push_back(b);
  Figure *c = new Rhombus(std::cin);
  vect.push_back(c);
  for (int i = 0; i < vect.size(); i++)
  {
    vect[i]->Print(std::cout);
    std::cout << "S=" << vect[i]->Area() << std::endl;
    std::cout << "Vertex number is " << vect[i]->VertexesNumber() << std::endl;
  }
  delete (Trapezoid *)a;
  delete (Rectangle *)b;
  delete (Rhombus *)c;
  return 0;
}
