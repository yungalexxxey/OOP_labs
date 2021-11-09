#ifndef ITEM_H
#define ITEM_H

#include <memory>
#include <tallocation_block.h>
template <class T>
class Item {
 public:
  Item(const std::shared_ptr<T>& triangle);
  std::shared_ptr<T> Get() const;
  template <class A>
  friend std::ostream& operator<<(std::ostream& os, const Item<A>& obj);
  void SetNext(std::shared_ptr<Item<T>>& next);
  std::shared_ptr<Item<T>> GetNext();
  void forget();
  void* operator new(size_t size);
  void operator delete(void* p);

  virtual ~Item();

 private:
  std::shared_ptr<T> item;
  std::shared_ptr<Item<T>> next;
  static TAllocationBlock tvec_alloc;
};


#endif // ITEM_H
