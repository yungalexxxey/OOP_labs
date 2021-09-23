#ifndef TVECTOR_H
#define TVECTOR_H
#include "rectangle.h"

class TVector
{
private:
    int length;
    int count;
    rectangle *arr;
public:
    TVector();
    int size();
    bool empty();
    void resize(int nindex);
    void push_back(rectangle newrec);
    void erase(int pos);
    rectangle pop_back();
    void clear();

    rectangle& operator[] (int i) ;
    friend std::istream& operator>>(std::istream &in, TVector &cont);
    friend std::ostream& operator<<(std::ostream &out,  TVector &cont);
};

#endif // TVECTOR_H
