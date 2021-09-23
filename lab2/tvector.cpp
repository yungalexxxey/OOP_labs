#include "tvector.h"
#include "rectangle.h"
TVector::TVector():length(0),count(0)
{  }

int TVector::size(){
    return this->length;
}
bool TVector::empty(){
    if(this->length>0) return true;
    else return false;
}

void TVector::resize(int newlength){
    std::cout<<length<< " " << count<<std::endl;
    if(newlength==length) return;
    if(newlength>length){
        rectangle *narr=new rectangle[newlength];
        for(int i=0;i<length;i++)
            narr[i]=arr[i];
        arr=narr;
        length=newlength;
    }
    else {
        rectangle *narr=new rectangle[newlength];
        for(int i=0;i<newlength;i++)
            narr[i]=arr[i];
        arr=narr;
        count=newlength;
    }
    std::cout<<length<< " " << count<<std::endl;
}
void TVector::push_back(rectangle newrec){
    std::cout<<length<<" " << count<<std::endl;
    if(count==length){
        length++;
        count++;
        rectangle *narr=new rectangle[length];
        for(int i=0;i<length-1;i++) narr[i]=arr[i];
        narr[length-1]=newrec;
        //free(arr);
        arr=narr;
    }
    else if(count<length){
        arr[count]=newrec;
        count++;
        std::cout<<length<<" " << count<<std::endl;
    }
}

void TVector::clear(){
    free(arr);
    length=0;
    count=0;
}
rectangle TVector::pop_back(){
        rectangle *narr=new rectangle[length];
        for(int i=0;i<count-1;i++){
                narr[i]=arr[i];
        }
        rectangle tmp=arr[count-1];
        count--;
        length--;
        arr=narr;
        return tmp;

}

void TVector::erase(int pos){
if(count==0)
{
    std::cout<<"Container is empty"<<std::endl;
    return;
}
    rectangle *narr=new rectangle[length-1];
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
rectangle& TVector::operator[] (int i)
{
    if(i >= 0 && i < this->length)
        return this->arr[i];
}

std::istream& operator>>(std::istream &in, TVector &cont){
    for(int i=0;i<cont.length;i++){
        std::cout<<"Insert rectangle #"<<i+1<<" coords:";
        cont.count+=1;
        in>>cont.arr[i];
    }
    return in;
}


std::ostream& operator<<(std::ostream &out,  TVector &cont){
    for(int i=0;i<cont.count;i++){
        out<<"Rectangle #"<< i+1<<"coords is " << cont[i];
    }
    return out;
}

