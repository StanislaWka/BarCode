#pragma once
#include <exception>
#include "MyException.h"
#include <fstream>
using namespace std;
class InputEx :
    public MyException
{
public:
    static void CheckingUpc(string& code);
    static void CheckingEan13(string& code);
    static void CheckingFile();
};

