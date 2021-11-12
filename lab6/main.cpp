
#include <iostream>
#include "rectangle.h"
#include "tvector.h"
#include "Tree.h"
void TestTVector()
{
  TVector<Rectangle> vec;

  vec.push_back(std::shared_ptr<Rectangle>(new Rectangle(1, 1, 1, 1, 1, 1, 1, 1)));
  vec.push_back(std::shared_ptr<Rectangle>(new Rectangle(1, 1, 1, 1, 1, 1, 1, 2)));
  for (auto i : vec)
  {
    std::cout << *i << std::endl;
  }

  while (!vec.empty())
  {
    std::cout << *vec.pop_back() << std::endl;
  }
}
void TestAllocationBlock()
{
  TAllocationBlock allocator(sizeof(int), 3);

  int *a1 = nullptr;
  int *a2 = nullptr;
  int *a3 = nullptr;

  a1 = (int *)allocator.allocate();
  *a1 = 1;
  std::cout << "a1 pointer value:" << *a1 << std::endl;

  a2 = (int *)allocator.allocate();
  *a2 = 2;
  a3 = (int *)allocator.allocate();
  *a3 = 3;
  std::cout << "a2 pointer value:" << *a2 << std::endl;
  allocator.deallocate(a1);
  allocator.deallocate(a2);
  allocator.deallocate(a3);
}
int main()
{
  TestAllocationBlock();
  TestTVector();
  return 0;
}
