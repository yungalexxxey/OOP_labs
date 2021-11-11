#include "item.h"

template <class T>
Item<T>::Item(const std::shared_ptr<T>& item)
    : item(item){
  std::cout << "TVector item: created" << std::endl;
}

template <class T>
TAllocationBlock Item<T>::tvec_alloc(sizeof(Item<T>), 10);

template <class T>
std::shared_ptr<T> Item<T>::Get() const {
  return this->item;
}

template <class T>
std::shared_ptr<Item<T>> Item<T>::GetNext() {
  return this->next;
}
template <class T>
Item<T>::~Item() {
  std::cout << "TVector item: deleted" << std::endl;
}
template <class T>
void Item<T>::SetNext(std::shared_ptr<Item<T>>& next) {
this->next=next;
}
template <class A>
std::ostream& operator<<(std::ostream& os, const Item<A>& obj) {
  os << "Item: " << *obj.item << std::endl;
  return os;
}
template <class T>
void Item<T>::forget(){
 next=nullptr;
}
template <class T>
void* Item<T>::operator new(size_t size) {
  return tvec_alloc.allocate();
}

template <class T>
void Item<T>::operator delete(void* p) {
  tvec_alloc.deallocate(p);
}

#include "rectangle.h"
template class Item<Rectangle>;
template std::ostream& operator<<(std::ostream& os,
                                  const Item<Rectangle>& obj);
