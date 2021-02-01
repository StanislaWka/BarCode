#pragma once
#include "Ean13.h"
class EanData:public Ean13
{
	string nameCountry;
	string nameManufactura;
	string nameProduct;
public:
	EanData();
	EanData(string& code);
	void SetNameCountry();
	void SetNameCountry(string tmp);
	void SetNameManufactura();
	void SetNameManufactura(string tmp);
	void SetNameProduct();
	void SetNameProduct(string tmp);
	void Print();
	friend ostream& operator << (ostream& out, EanData& ean_data);
	friend istream& operator >> (istream& in, EanData& ean_data);
	string GetNameCountry();
	string GetNameManufactura();
	string GetNameProduct();
	string GetNameNumberBarcode();
	string GetOriginals();
	EanData& operator = (EanData& other)
	{
		this->product = other.product;
		this->county = other.county;
		this->lastNumber = other.lastNumber;
		this->manufacture = other.manufacture;
		this->numberBarCode = other.numberBarCode;
		this->nameProduct = other.nameProduct;
		this->nameManufactura = other.nameManufactura;
		this->nameCountry = other.nameCountry;
		return *this;
	}
	~EanData();
};

