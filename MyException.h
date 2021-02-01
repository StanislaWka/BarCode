

#pragma once
#include <exception>
#include <vector>
#include <string>
#include <iostream>


using namespace std;
class MyException : public exception
{
protected:
    int number;
    string message;
public:
    explicit MyException();
    explicit MyException(int Number);
    explicit MyException(int Number, string message);
    ~MyException();
    virtual string What();
};

