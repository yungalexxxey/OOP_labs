#include "tvector.h"
#include "figure.h"
#include "rectangle.h"
#include "rhombus.h"
#include "trapezoid.h"

template <class T>
TVector<T>::TVector():length(0),count(0)
{  }

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
void TVector<T>::push_back(std::shared_ptr<T> newfig){
    if(count==length){
        length++;
        count++;
        std::shared_ptr<std::shared_ptr<T>[]> narr(new std::shared_ptr<T>[length]);
        for(int i=0;i<length-1;i++) narr[i]=arr[i];

        narr[length-1]= newfig;
        //free(arr);
        arr=narr;
    }
    else if(count<length){
        arr[count]=newfig;
        count++;
    }
}

template <class T>
TVector<T>::~TVector(){

}

template <class T>
std::shared_ptr<T> TVector<T>::pop_back(){
        std::shared_ptr<std::shared_ptr<T>[]> narr(new std::shared_ptr<T>[length]);
        for(int i=0;i<count-1;i++){
                narr[i]=arr[i];
        }
        std::shared_ptr<T> tmp=arr[count-1];
        count--;
        length--;
        arr=narr;
        return tmp;
}

template <class T>
void TVector<T>::resize(int newlength){
    if(newlength==length) return;
    if(newlength>length){
        std::shared_ptr<std::shared_ptr<T>[]> narr(new std::shared_ptr<T>[length]);
        for(int i=0;i<length;i++)
            narr[i]=arr[i];
        arr=narr;
        length=newlength;
    }
    else {
        std::shared_ptr<std::shared_ptr<T>[]> narr(new std::shared_ptr<T>[length]);
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
        std::shared_ptr<std::shared_ptr<T>[]> narr(new std::shared_ptr<T>[length]);
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

//перегрузка операций
template <class T>
std::shared_ptr<T> TVector<T>::operator[] (int i)
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
template class TVector<Rhombus>;
template std::ostream& operator<<(std::ostream& out,  TVector<Rhombus>& cont);
template class TVector<Trapezoid>;
template std::ostream& operator<<(std::ostream& out,  TVector<Trapezoid>& cont);
