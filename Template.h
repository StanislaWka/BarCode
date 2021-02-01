#pragma once
#include <iostream>
//
using namespace std;

template <class T>
class Vector
{
    T* data;
    int size;
    int cap;
public:
    Vector(int = 1);
    Vector(Vector&);
    Vector operator=(const Vector&);
    bool operator==(const Vector&);
    bool operator==(string& a);
    int Capacity() const;
    int Size() const;
    T& operator [](int);
    bool operator==(int);
    void push_back(T);
    void clear();
    void create(const int& i);
    void remove(const int& i);
    void remove(string& tmp);
    void resize(const int& n);
    friend std::ostream& operator << (ostream& out, Vector<T>& v)
    {
        for (int i = 0; i < v.Size(); i++)
        {
            out << v.data[i] << std::endl;
        }
        return out;
    }
	
    ~Vector<T>(void);

};


