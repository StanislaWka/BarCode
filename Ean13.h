#pragma once
#include "BarCode.h"
class Ean13 :
    public BarCode
{
protected:
	string numberBarCode;
	string county;
	string manufacture;
	string product;
	bool lastNumber;
public:
	Ean13();
	Ean13(string number);
	string NumberCountry() override;
    string NumberManufacture() override;
    string NumberProduct() override;
	bool CheckingNumber();
	~Ean13();
	friend istream& operator >> (istream& is, Ean13& other);
	friend ostream& operator << (ostream& out, Ean13& other);
};

