#include "item.h"

#include <iostream>

template <class T>
Item<T>::Item(const std::shared_ptr<T>& item)
    : item(item){
  std::cout << "TVector item: created" << std::endl;
}

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
  std::cout << "Stack item: deleted" << std::endl;
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
  std::cout << "Allocated :" << size << "bytes" << std::endl;
  return malloc(size);
}

template <class T>
void Item<T>::operator delete(void* p) {
  std::cout << "Deleted" << std::endl;
  free(p);
}

#include "rectangle.h"
template class Item<Rectangle>;
template std::ostream& operator<<(std::ostream& os,
                                  const Item<Rectangle>& obj);
