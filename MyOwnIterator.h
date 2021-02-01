#pragma once
#pragma once

#include <iostream>

#include "InputEx.h"
#include "List.h"

using namespace std;

template <class Type> class cList;
template <class Type> struct ListNode;

template <class Type>
class OwnIterator {
protected:
    ListNode<Type>* Iter;
public:
    friend class List;
    OwnIterator();
    OwnIterator(Type* p);
    OwnIterator(ListNode<Type>* node);
    OwnIterator(const OwnIterator& cO);

    OwnIterator& operator++();
    OwnIterator& operator--();
    bool operator==(const OwnIterator& other) const;
    bool operator!=(const OwnIterator& other) const;
    OwnIterator& operator=(ListNode<Type>& cOI);
    Type& operator*();
    Type& operator[](const int index);

    friend ostream& operator<<(ostream& os, OwnIterator& cOI) {
        os << cOI.Iter->value;
        return os;
    }

    friend istream& operator>>(istream& in, OwnIterator& cOI) {
        in >> cOI.Iter->value;
        return in;
    }
};


