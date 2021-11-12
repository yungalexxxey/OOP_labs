#ifndef TALLOCATION_BLOCK_H
#define TALLOCATION_BLOCK_H

#include <cstdlib>
#include "Tree.h"
class TAllocationBlock {
 public:
  TAllocationBlock(size_t size, size_t count);
  void* allocate();
  void deallocate(void* pointer);
  bool has_free_blocks();
  virtual ~TAllocationBlock();

 private:
  size_t _size;
  size_t _count;

  char* _used_blocks;
  Tree <void*> _free_blocks;

  size_t _free_count;
};

#endif  // TALLOCATION_BLOCK_H
