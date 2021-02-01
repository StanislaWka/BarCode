#include "EanData.h"

EanData::EanData(string& code) : Ean13(code)
{
	
}

EanData::EanData()
{
	
}

void EanData::SetNameCountry()
{
	ifstream file("MyFile.txt");
	string tmp;
	string numbers;
	int a;
	while(!file.eof())
	{
		tmp.clear();
		file >> tmp;
		a = tmp.find('-');
		numbers = tmp;
		numbers.erase(a);
		if(this->county == numbers)
		{
			this->nameCountry = tmp.substr(a + 1);
		}
			
	}
	file.close();
}
void EanData::SetNameCountry(string tmp)
{
	this->nameCountry = tmp;
}

void EanData::SetNameManufactura()
{
	string f;
	int n;
	if(this->county.size() == 2)
	{
		 n = 5;
	}
	else
	{
		n = 4;
	}
	f = this->manufacture.substr(n - 1);
	string tmp;
	string num;
	ifstream file("Firms.txt");
	while (!file.eof()) {
		file >> tmp;
		num = tmp;

		if (f == num)
		{
			file >> tmp;
			tmp.substr(2);
			this->nameManufactura = tmp;
		}
		file >> tmp;
	}
	
	file.close();
	
}
void EanData::SetNameManufactura(string tmp)
{
	this->nameManufactura = tmp;
}

void EanData::SetNameProduct()
{
	string f;
	int n;
	if (this->county.size() == 2)
	{
		n = 5;
	}
	else
	{
		n = 4;
	}
	string tmp;
	string temp;
	f = this->manufacture.substr(n - 1);
	char a = f[0];
	ifstream file("202.txt");
	ifstream file1("BMW.txt");
	ifstream file2("Coca-Cola.txt");
	ifstream file3("McDonalds.txt");
	ifstream file4("Jack.txt");
	ifstream file5("Pinsk.txt");
	ifstream file6("JB.txt");
	ifstream file7("Apple.txt");
	ifstream file8("DT.txt");
	ifstream file9("Casio.txt");
	
	
	switch(a)
	{
	case('0'): 
		while (!file.eof())
		{
			file >> tmp;
			if(f == tmp)
			{
				file >> temp;
				this->nameProduct = temp;
				break;
			}
			else
			{
				file >> temp;
			}
			
		}
		
		break;
	case('1'): 
		while (!file1.eof())
		{
			file1 >> tmp;
			if (f == tmp)
			{
				file1 >> temp;
				this->nameProduct = temp;
				break;
			}
			else
			{
				file1 >> temp;
			}

		}
		
		break;
	case('2'): 
		
		while (!file2.eof())
		{
			file2 >> tmp;
			if (f == tmp)
			{
				file2 >> temp;
				this->nameProduct = temp;
				break;
			}
			else
			{
				file2 >> temp;
			}

		}
		
		break;
	case('3'): 
		
		while (!file3.eof())
		{
			file3 >> tmp;
			if (f == tmp)
			{
				file3 >> temp;
				this->nameProduct = temp;
				break;
			}
			else
			{
				file3 >> temp;
			}

		}
		
		break;
	case('4'): 
		while (!file4.eof())
		{
			file4 >> tmp;
			if (f == tmp)
			{
				file4 >> temp;
				this->nameProduct = temp;
				break;
			}
			else
			{
				file4 >> temp;
			}

		}
		
		break;
	case('5'): 
		while (!file5.eof())
		{
			file5 >> tmp;
			if (f == tmp)
			{
				file5 >> temp;
				this->nameProduct = temp;
				break;
			}
			else
			{
				file5 >> temp;
			}

		}
		
		break;
	case('6'): 
		while (!file6.eof())
		{
			file6 >> tmp;
			if (f == tmp)
			{
				file6 >> temp;
				this->nameProduct = temp;
				break;
			}
			else
			{
				file6 >> temp;
			}

		}
		
		break;
	case('7'): 
		while (!file7.eof())
		{
			file7 >> tmp;
			if (f == tmp)
			{
				file7 >> temp;
				this->nameProduct = temp;
				break;
			}
			else
			{
				file7 >> temp;
			}

		}
		
		break;
	case('8'): 
		while (!file8.eof())
		{
			file8 >> tmp;
			if (f == tmp)
			{
				file8 >> temp;
				this->nameProduct = temp;
				break;
			}
			else
			{
				file8 >> temp;
			}

		}
		
		break;
	case('9'): 
		while (!file9.eof())
		{
			file9 >> tmp;
			if (f == tmp)
			{
				file9 >> temp;
				this->nameProduct = temp;
				break;
			}
			else
			{
				file9 >> temp;
			}

		}
		
		break;
	default: break;
	}
	file2.close();
	file1.close();
	file.close();
	file3.close();
	file4.close();
	file5.close();
	file6.close();
	file7.close();
	file8.close();
	file9.close();
	
}

void EanData::SetNameProduct(string tmp)
{
	this->nameProduct = tmp;
}


ostream& operator << (ostream& out, EanData& ean_data)
{
	out << ean_data.numberBarCode << " " << ean_data.nameCountry << " " << ean_data.nameManufactura << " " <<
		ean_data.nameProduct;
	if (ean_data.lastNumber)
	{
		cout << " Original" << endl;
	}
	else
	{
		cout << " Fake" << endl;
	}
	return out;
}

istream& operator >> (istream& in, EanData& ean_data)
{
	Ean13* ean;
	ean = &ean_data;
	in >> *(dynamic_cast<Ean13*>(ean));
	ean_data.SetNameCountry();
	ean_data.SetNameManufactura();
	ean_data.SetNameProduct();
	return in;
}

string EanData::GetNameCountry()
{
	return this->nameCountry;
}

string EanData::GetNameManufactura()
{
	return this->nameManufactura;
}

string EanData::GetNameProduct()
{
	return this->nameProduct;
}

string EanData::GetNameNumberBarcode()
{
	return this->numberBarCode;
}

string EanData::GetOriginals()
{
	if(this->lastNumber)
	{
		return "Original";
	}
	else
	{
		return "Fake";
	}
}


EanData::~EanData()
{
	nameCountry.clear();
	nameManufactura.clear();
	nameProduct.clear();
}

void EanData::Print()
{
	cout << this->numberBarCode << " " << this->nameCountry << " " << this->nameManufactura << " " << this->nameProduct << " " << this->GetOriginals() << endl;
}
