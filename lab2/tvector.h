#ifndef TVECTOR_H
#define TVECTOR_H
#include "rectangle.h"

class TVector
{
private:
    int length;
    int count;
    Rectangle *arr;
public:
    TVector();
    ~TVector();
    TVector(const TVector& other);
    void InsertLast(Rectangle &newrec);
    const Rectangle Last();
    int Length();
    bool Empty();
    void Resize(int nindex);
    void Remove(int pos);
    void Clear();

    Rectangle& operator[] (int i) ;
    friend std::ostream& operator<<(std::ostream &out, TVector &cont);
};

#endif // TVECTOR_H
