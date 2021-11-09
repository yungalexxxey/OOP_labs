
#include <iostream>
#include "rectangle.cpp"
#include <tvector.h>
#include "Iter.h"
#include "Tree.h"
#include <tallocation_block.h>
void TestTVector() {
  TVector<Rectangle> vec;

  vec.push_back(std::shared_ptr<Rectangle>(new Rectangle(1, 1, 1,1,1,1, 1, 1)));
  vec.push_back(std::shared_ptr<Rectangle>(new Rectangle(2, 2, 2,2,2,2,2,2)));
  vec.push_back(std::shared_ptr<Rectangle>(new Rectangle(3, 3, 3,3,3,3,3,3)));
  vec.push_back(std::shared_ptr<Rectangle>(new Rectangle(4,4,4,4,4,4,4,4)));

  for (auto i : vec) {
    std::cout << *i << std::endl;
  }

  while (!vec.empty()) {
    std::cout << *vec.pop_back() << std::endl;
  }
}
void TestAllocationBlock() {
  TAllocationBlock allocator(sizeof(int), 10);

  int* a1 = nullptr;
  int* a2 = nullptr;
  int* a3 = nullptr;
  int* a4 = nullptr;
  int* a5 = nullptr;

  a1 = (int*)allocator.allocate();
  *a1 = 1;
  std::cout << "a1 pointer value:" << *a1 << std::endl;

  a2 = (int*)allocator.allocate();
  *a2 = 2;
  std::cout << "a2 pointer value:" << *a2 << std::endl;

  a3 = (int*)allocator.allocate();
  *a3 = 3;
  std::cout << "a3 pointer value:" << *a3 << std::endl;

  allocator.deallocate(a1);
  allocator.deallocate(a3);
  a4 = (int*)allocator.allocate();
  *a4 = 4;
  std::cout << "a4 pointer value:" << *a4 << std::endl;

  a5 = (int*)allocator.allocate();
  *a5 = 5;
  std::cout << "a5 pointer value:" << *a5 << std::endl;

  std::cout << "a1 pointer value:" << *a1 << std::endl;
  std::cout << "a2 pointer value:" << *a2 << std::endl;
  std::cout << "a3 pointer value:" << *a3 << std::endl;

  allocator.deallocate(a2);
  allocator.deallocate(a4);
  allocator.deallocate(a5);
}
int main()
{
  TestAllocationBlock();
  TestTVector();
  return 0;
}
