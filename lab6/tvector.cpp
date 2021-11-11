#include "tvector.h"
#include "rectangle.h"
template <class T>
TVector<T>::TVector():length(0),count(0)
{  }

template <class T>
int TVector<T>::size(){
    return this->count;
}

template <class T>
bool TVector<T>::empty(){
return count==0;
}

template <class T>
void TVector<T>::push_back(std::shared_ptr<T> newfig){
  std::shared_ptr<Item<T>> other(new Item<T>(newfig));
    if(count==length){
        length++;
        count++;
        std::shared_ptr<std::shared_ptr<Item<T>>[]> narr(new std::shared_ptr<Item<T>>[length]);
        for(int i=0;i<length-1;i++) narr[i]=arr[i];

        narr[length-1]= other;
        if(count-1){
            arr[count-2]->SetNext(narr[count-1]);
          }
        //free(arr);
        arr=narr;
    }
    else if(count<length){
        arr[count]=other;
        count++;
        if(count-1){
            arr[count-2]->SetNext(arr[count-1]);
          }
    }
}

template <class T>
TVector<T>::~TVector(){

}

template <class T>
std::shared_ptr<T> TVector<T>::pop_back(){
        std::shared_ptr<T> result;
  if(length>1){
        std::shared_ptr<std::shared_ptr<Item<T>>[]> narr(new std::shared_ptr<Item<T>>[length-1]);
        for(int i=0;i<count-1;i++){
                narr[i]=arr[i];
        }
        result=arr[count-1]->Get();
        count--;
        length--;
        arr=narr;
        return result;
    }
  else{
      count--;
      length--;
      return arr[0]->Get();
    }
}

template <class T>
void TVector<T>::resize(int newlength){
    if(newlength==length) return;
    if(newlength>length){
        std::shared_ptr<std::shared_ptr<Item<T>>[]> narr(new std::shared_ptr<Item<T>>[length]);
        for(int i=0;i<length;i++)
            narr[i]=arr[i];
        arr=narr;
        length=newlength;
    }
    else {
        std::shared_ptr<std::shared_ptr<Item<T>>[]> narr(new std::shared_ptr<Item<T>>[length]);
        for(int i=0;i<newlength;i++)
            narr[i]=arr[i];
        arr=narr;
        count=newlength;
    }
}

template <class T>
void TVector<T>::clear(){
    resize(1);
    pop_back();
    length=0;
    count=0;
}

template <class T>
void TVector<T>::erase(int pos){
if(count==0)
{
    std::cout<<"Container is empty"<<std::endl;
    return;
}
        std::shared_ptr<std::shared_ptr<Item<T>>[]> narr(new std::shared_ptr<Item<T>>[length]);
    int current_index=0;
    for(int i=0;i<count;i++){
        if(i!=pos-1) {
            narr[current_index]=arr[i];
            current_index++;
        }
    }
    count--;
    length--;
    arr=narr;

}

template <class T>
Iter<Item<T>, T> TVector<T>::begin() {
  return Iter<Item<T>, T>(arr[0]);
}

template <class T>
Iter<Item<T>, T> TVector<T>::end() {
  return Iter<Item<T>, T>(nullptr);
}
//перегрузка операций
template <class T>
std::shared_ptr<Item<T>> TVector<T>::operator[] (int i)
{
    if(i >= 0 && i < this->length)
        return this->arr[i];
}


template <class T>
std::ostream& operator<<(std::ostream &out,   TVector<T> &cont){
    for(int i=0;i<cont.count;i++){
        out<<"figure #"<< i+1<<"coords is " << *cont[i];
    }
    return out;
}

template class TVector<Rectangle>;
template std::ostream& operator<<(std::ostream& out,  TVector<Rectangle>& cont);
