#include "Ean13.h"


Ean13::Ean13()
{
	//this->county = 0;
	//this->manufacture = 0;
	//this->product = 0;
	this->lastNumber = false;
}

Ean13::Ean13(string number)
{
	this->numberBarCode = number;
	//this->county = 0;
	//this->manufacture = 0;
	//this->product = 0;
}
Ean13::~Ean13()
{
	this->numberBarCode.clear();
}

string Ean13::NumberCountry()
{
	ifstream file("MyFile.txt");
	string temp;
	string other = this->numberBarCode;
	int a;
	while (!file.eof())
	{
		temp.clear();
		other = this->numberBarCode;
		file >> temp;
		a = temp.find('-');
		temp.erase(a);
		other.erase(a);
		if (other == temp)
		{
			break;
		}
	}
	this->county = other;
	file.close();
	return this->county;
}

string Ean13::NumberManufacture()
{
	string temp;
	temp = this->numberBarCode;
	int number, country;
	if (this->county.size() < 3)
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
	temp=temp.substr(country );
	this->manufacture = temp;
	temp.clear();
	return this->manufacture;
}

string Ean13::NumberProduct()
{
	string temp;
	temp = this->numberBarCode;
	temp=temp.substr(7);
	temp.resize(5);
	this->product = temp;
	return this->product;
}

bool Ean13::CheckingNumber()
{
	string other = this->numberBarCode;
	int x, y, z, sum, temp;
	x = 0;
	z = 0;
	y = 0;
	sum = 0;
	int flg;
	char tmp[1];
	for(int i=0; i<this->numberBarCode.size()-1; i++)
	{
		if (0 == i % 2) {
			tmp[0] = this->numberBarCode[i];
			temp = atoi(tmp);
			y += temp;
		}
		if (1 == i % 2) {
			tmp[0] = this->numberBarCode[i];
			temp = atoi(tmp);
			x += temp;
		}
	}
	sum = 3 * x + y;
	z = sum % 10;
	other=other.substr(12);
	if((10-z)==atoi(other.c_str()))
	{
		this->lastNumber = true;
		return this->lastNumber;
	}
	else
	{
		this->lastNumber = false;
		return this->lastNumber;
	}
	
}

istream& operator>>(istream& is, Ean13& other)
{
	is >> other.numberBarCode;
	InputEx::CheckingEan13(other.numberBarCode);
	other.county = other.NumberCountry();
	other.manufacture = other.NumberManufacture();
	other.product = other.NumberProduct();
	other.lastNumber = other.CheckingNumber();
	return is;
}

ostream& operator << (ostream& out, Ean13& other)
{
	out << "Barcode : " << other.numberBarCode << endl;
	out << "Code of country : " << other.county << endl;
	out << "Code of Manufacture : " << other.manufacture << endl;
	out << "Code of product : " << other.product << endl;
	if(other.lastNumber)
	{
		cout << "Last number is true" << endl;
	}
	else
	{
		cout << "Last number is false" << endl;
	}
	return out;
}


