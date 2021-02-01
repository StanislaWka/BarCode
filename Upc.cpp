#include "Upc.h"

Upc::Upc()
{
	//this->county = 0;
	//this->product = 0;
	//this->manufacture = 0;
}

Upc::Upc(string number)
{
	this->numberBarCode = number;
	//this->county = 0;
	//this->product = 0;
	//this->manufacture = 0;
	number.clear();
}

string Upc::NumberCountry()
{	
	ifstream file("MyFile.txt");
	string temp;
	string other = this->numberBarCode;
	int a;
	while(!file.eof())
	{
		temp.clear();
		other = this->numberBarCode;
		file >> temp;
		a = temp.find('-');
		temp.erase(a);
		other.erase(a);
		if(other==temp)
		{
			break;
		}
	}
	this->county = other;
	temp.clear();
	other.clear();
	return this->county;
}

string Upc::NumberManufacture()
{
	string temp;
	temp = this->numberBarCode;
	int number, country;
	if(this->county.size()<3)
	{
		number = 5;
		country = 2;
	}
	else
	{
		number = 4;
		country = 3;
	}
	temp.resize(7);
	temp=temp.substr(country);
	this->manufacture = temp;
	temp.clear();
	return this->manufacture;
}

 string Upc::NumberProduct()
 {
	 string temp;
	 temp = this->numberBarCode;
	 temp=temp.substr(7);
	 this->product = temp;
	 return this->product;
 }

Upc::~Upc()
{
	this->numberBarCode.clear();
}

istream& operator>>(istream& is, Upc& other)
{
	is >> other.numberBarCode;
	InputEx::CheckingUpc(other.numberBarCode);
	other.county = other.NumberCountry();
	other.manufacture = other.NumberManufacture();
	other.product = other.NumberProduct();
	return is;
}

ostream& operator << (ostream& out, Upc& other)
{
	out << "Barcode : " << other.numberBarCode << endl;
	out << "Code of country : " << other.county << endl;
	out << "Code of Manufacture : " << other.manufacture << endl;
	out << "Code of product : " << other.product << endl;
	return out;
}


