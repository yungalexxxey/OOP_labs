#include "tvector.h"
#include "rectangle.h"

template <class T>
TVector<T>::TVector():length(0),count(0) {  }

template <class T>
int TVector<T>::size(){
    return this->length;
}
template <class T>
bool TVector<T>::empty(){
    if(this->length>0) return true;
    else return false;
}
template <class T>
void TVector<T>::push_back(std::shared_ptr<T> &&newrec){
      std::shared_ptr<Item<T>> other(new Item<T>(newrec));

    if(count==length){
        length++;
        count++;
        std::shared_ptr<Item<T>> *narr=new std::shared_ptr<Item<T>>[length];
        for(int i=0;i<length-1;i++) narr[i]=arr[i];
        narr[length-1]=other;
        if(count-1) narr[length-2]->SetNext(other);
        //free(arr);
        arr=narr;
    }
    else if(count<length){
        arr[count]=other;
        if(count)
        arr[count-1]->SetNext(other);
        count++;
    }

}
template <class T>
TVector<T>::~TVector(){

}
template <class T>
std::shared_ptr<T> TVector<T>::pop_back(){
    std::shared_ptr<T> result;
        std::shared_ptr<Item<T>> *narr=new std::shared_ptr<Item<T>>[length];
        for(int i=0;i<count-1;i++){
                narr[i]=arr[i];
        }
        result=arr[count-1]->Get();
        count--;
        length--;
        arr=narr;
        arr[count-1]->forget();
        return result;
}

template <class T>
void TVector<T>::resize(int newlength){
    if(newlength==length) return;
    if(newlength>length){
        std::shared_ptr<Item<T>> *narr=new std::shared_ptr<Item<T>>[newlength];
        for(int i=0;i<length;i++)
            narr[i]=arr[i];
        arr=narr;
        length=newlength;
    }
    else {
       std::shared_ptr<Item<T>> *narr=new std::shared_ptr<Item<T>>[newlength];
        for(int i=0;i<newlength;i++)
            narr[i]=arr[i];
        arr=narr;
        count=newlength;
    }
    arr[count-1]->forget();
}

template <class T>
void TVector<T>::clear(){
    free(arr);
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
 std::shared_ptr<Item<T>> *narr=new std::shared_ptr<Item<T>>[length-1];
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
    arr[count-1]->forget();
}

//перегрузка операций
template <class T>
std::shared_ptr<Item<T>>& TVector<T>::operator[] (int i)
{
    if(i >= 0 && i < this->length)
        return this->arr[i];
    else perror("Out of bounds\n");
}


template <class T>
std::ostream& operator<<(std::ostream &out,   TVector<T> &cont){
    for(int i=0;i<cont.count;i++){
        out<<"figure #"<< i+1<<"coords is " << *cont[i];
    }
    return out;
}
template <class T>
Iter<Item<T>, T> TVector<T>::begin() {
  return Iter<Item<T>, T>(arr[0]);
}

template <class T>
Iter<Item<T>, T> TVector<T>::end() {
  return Iter<Item<T>, T>(nullptr);
}
template class TVector<Rectangle>;
template std::ostream& operator<<(std::ostream& out,  TVector<Rectangle>& cont);
