#include "tvector.h"
#include "rectangle.h"
TVector::TVector():length(0),count(0)
{  }

int TVector::Length(){
    return this->length;
}
bool TVector::Empty(){
    if(this->length>0) return true;
    else return false;
}

void TVector::Resize(int newlength){
    std::cout<<length<< " " << count<<std::endl;
    if(newlength==length) return;
    if(newlength>length){
        Rectangle *narr=new Rectangle[newlength];
        for(int i=0;i<length;i++)
            narr[i]=arr[i];
        arr=narr;
        length=newlength;
    }
    else {
        Rectangle *narr=new Rectangle[newlength];
        for(int i=0;i<newlength;i++)
            narr[i]=arr[i];
        arr=narr;
        count=newlength;
    }
    std::cout<<length<< " " << count<<std::endl;
}
void TVector::InsertLast(Rectangle &newrec){
    if(count==length){
        length++;
        count++;
        Rectangle *narr=new Rectangle[length];
        for(int i=0;i<length-1;i++) narr[i]=arr[i];
        narr[length-1]=newrec;
        //free(arr);
        arr=narr;
    }
    else if(count<length){
        arr[count]=newrec;
        count++;
    }
}

void TVector::Clear(){
    free(arr);
    length=0;
    count=0;
}
const Rectangle TVector::Last(){
        Rectangle *narr=new Rectangle[length];
        for(int i=0;i<count-1;i++){
                narr[i]=arr[i];
        }
        Rectangle tmp=arr[count-1];
        count--;
        length--;
        arr=narr;
        return tmp;
}

void TVector::Remove(int pos){
if(count==0)
{
    std::cout<<"Container is empty"<<std::endl;
    return;
}
    Rectangle *narr=new Rectangle[length-1];
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
Rectangle& TVector::operator[] (int i)
{
    if(i >= 0 && i < this->length)
        return this->arr[i];
}


std::ostream& operator<<(std::ostream &out,  TVector &cont){
    for(int i=0;i<cont.count;i++){
        out<<"Rectangle #"<< i+1<<"coords is " << cont[i];
    }
    return out;
}

