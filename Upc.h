#pragma once
#include "BarCode.h"

class Upc :
    public BarCode
{
protected:
	string numberBarCode;
	string county;
	string manufacture;
	string product;
public:
	Upc();
	Upc(string number);
    string NumberCountry() override;
	string NumberManufacture() override;
	string NumberProduct() override;
	friend istream& operator >> (istream& is, Upc& other);
	friend ostream& operator << (ostream& os, Upc& other);
	~Upc() override;
};

