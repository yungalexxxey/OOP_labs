#ifndef TVECTOR_H
#define TVECTOR_H
#include "rectangle.h"
#include <memory>
#include <figure.h>

template <class T>
class TVector
{
private:
    int length;
    int count;
    std::shared_ptr<T> *arr;
public:
     TVector();
    virtual ~TVector();
    int size();
    bool empty();
    void resize(int nindex);
    void push_back(std::shared_ptr<T> &&newrec);
    void erase(int pos);
    std::shared_ptr<T> pop_back();
    void clear();

    std::shared_ptr<T>& operator[] (int i) ;
    template <class A>
    friend std::ostream& operator<<(std::ostream &out, TVector<A> &cont);
};

#endif // TVECTOR_H
