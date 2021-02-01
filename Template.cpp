#include "Template.h"

template <class  T>
Vector<T>::Vector(int n)
{
    create(n);
}

template <class  T>
Vector<T>::~Vector(void)
{
    delete[] data;
}

template <class  T>
int Vector<T>::Size(void) const
{
    return size;
}

template <class  T>
T& Vector<T>::operator[](int i)
{
    return data[i];
}

template<class T>
bool Vector<T>::operator==(int)
{
    return false;
}

template<class T>
bool Vector<T>::operator==(string &a)
{
    for (int i = 0; i < this->size; i++)
    {
        if (this->data[i].GetNameNumberBarcode() == a) {
            cout << data[i] << endl;
            return true;
        }
    }
    return false;
}

template <class T>
Vector<T> Vector<T>::operator=(const Vector& a)
{
    size = a.size;
    for (int i = 0; i != a.size; ++i) {
        this->date[i] = a.data[i];
    }
    return *this;
}

template <class T>
bool Vector<T>::operator==(const Vector& v)
{
    if (this->size == v.size)
    {
        for (int i = 0; i < this->size; i++)
        {
            if (this->data[i] != v.data[i])
                return false;
        }
        return true;
    }
    else {
        return  false;
    }
}

template <class T>
Vector<T>::Vector(Vector& a) {
    this->size = a.size;
    for (int i = 0; i != a.size; ++i) {
        this->date[i] = a.data[i];
    }
}

template <class T>
void Vector<T>::push_back(T val) {
    T* newdata;
    if (size = cap) {
        cap = cap * 2;
        newdata = new T[cap];
        for (int i = 0; i < size; i++)
            newdata[i] = data[i];
        delete[] data;
        data = newdata;
    }
    data[size] = val;
    size++;
}

template <class  T>
int Vector<T>::Capacity() const
{
    return cap;
}

template <class  T>
void Vector<T>::remove(const int& i)
{
    T* newdata = new T[cap];
    bool f = false;

    for (int j = 0; j < this->size; j++)
    {
        if (j == i)
        {
            f = true;
        }
        if (f)
        {
            newdata[j - 1] = this->data[j];
        }
        else {
            newdata[j] = this->data[j];
        }
    }
    this->size -= 1;
    delete[] this->data;
    this->data = newdata;
}

template <class T>
void Vector<T>::remove(string& tmp)
{
    T* newdata = new T[cap];
    bool f = false;
    for (int j = 0; j < this->size; j++)
    {
        if (data[j].GetNameNumberBarcode() == tmp)
        {
            f = true;
        }
        if (f)
        {
            newdata[j - 1] = this->data[j];
        }
        else {
            newdata[j] = this->data[j];
        }
    }
    this->size -= 1;
    delete[] this->data;
    this->data = newdata;
}

template <class  T>
void Vector<T>::resize(const int& n)
{
    T* newdata = new T[n];
    this->cap = n;
    this->size = n > this->size ? this->size : n;
    for (int i = 0; i < this->size; i++)
    {
        newdata[i] = this->data[i];
    }
    delete[] this->data;
    this->data = newdata;
}


template <class  T>
void Vector<T>::clear()
{
    delete[] this->data;
    this->size = 0;
    this->cap = 1;
    this->data = new T[1];
}

template <class  T>
void Vector<T>::create(const int& i) {
    if (this->data)
        delete[] data;
    size = 0;
    cap = i;
    data = new T[i];
}

