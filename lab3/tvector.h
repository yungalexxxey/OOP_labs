#ifndef TVECTOR_H
#define TVECTOR_H
#include "rectangle.h"
#include <memory>

class TVector
{
private:
    int length;
    int count;
    std::shared_ptr<std::shared_ptr<rectangle>[]> arr;
public:
    TVector();
    ~TVector();
    int size();
    bool empty();
    void resize(int nindex);
    void push_back(std::shared_ptr<rectangle> newrec);
    void erase(int pos);
    std::shared_ptr<rectangle> pop_back();
    void clear();

    std::shared_ptr<rectangle> operator[] (int i) ;
    friend std::istream& operator>>(std::istream &in, TVector &cont);
    friend std::ostream& operator<<(std::ostream &out,  TVector &cont);
};

#endif // TVECTOR_H
