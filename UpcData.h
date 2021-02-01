#pragma once
#include "Upc.h"
class UpcData :
    public Upc
{
	string nameCountry;
	string nameManufactura;
	string nameProduct;
public:
	UpcData();
	UpcData(string& code);
	void SetNameCountry();
	void SetNameCountry(string tmp);
	void SetNameManufactura();
	void SetNameManufactura(string tmp);
	void SetNameProduct();
	void SetNameProduct(string tmp);
	void Print();
	friend ostream& operator << (ostream& out, UpcData& upc_data);
	friend istream& operator >> (istream& in, UpcData& upc_data);
	string GetNameCountry();
	string GetNameManufactura();
	string GetNameProduct();
	string GetNameNumberBarcode();
	~UpcData();
	UpcData& operator = (UpcData& other)
	{
		this->product = other.product;
		this->county = other.county;
		this->manufacture = other.manufacture;
		this->numberBarCode = other.numberBarCode;
		this->nameProduct = other.nameProduct;
		this->nameManufactura = other.nameManufactura;
		this->nameCountry = other.nameCountry;
		return *this;
	}
};

