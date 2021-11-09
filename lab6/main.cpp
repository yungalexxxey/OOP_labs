
#include <iostream>
#include "rectangle.cpp"
#include <tvector.h>
#include "Iter.h"
#include "Tree.h"
int main()
{
//    TVector<Rectangle> vec;
//    vec.push_back(std::shared_ptr<Rectangle>(new Rectangle(1, 1, 1,1,1,1,1,1)));
//    vec.push_back(std::shared_ptr<Rectangle>(new Rectangle(2, 2, 2,2,2,2,2,2)));
//    vec.push_back(std::shared_ptr<Rectangle>(new Rectangle(3, 3, 3,3,3,3,3,3)));
//    std::shared_ptr<Rectangle> t;
//    t=vec.pop_back();
//    std::cout<<"Last obj is " <<*t<<std::endl;
//    for (auto i : vec) {
//     std::cout << *i << std::endl;
//    }
  Tree<int> tree;
  tree.insert(1);
  tree.insert(6);
  tree.print();
  return 0;
}
