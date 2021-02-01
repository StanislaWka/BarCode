#pragma once
#include <string>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include "InputEx.h"
using namespace std;

using namespace std;

class BarCode
{
public:
	virtual string NumberCountry() = 0;
	virtual string NumberManufacture() = 0;
	virtual string NumberProduct() = 0;
	virtual ~BarCode();
};

