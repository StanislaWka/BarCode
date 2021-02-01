#include "MyException.h"

#include <utility>

//enum MyEnum {
//	Day,
//	Month,
//	Year,
//	NameBigLetter,
//	NameEngLetter,
//	SurnameBigLetter,
//	SurnameEngLetter,
//};

enum MyEnum {
	string13=1,
	string12,
	file,
	numbers,
	country
	
};

MyException::MyException() {
	this->number = 0;
	this->message = "Unknown error";
}


MyException::MyException(int nummer, string message) {
	this->number = nummer;
	this->message = message;
}

string MyException::What() {
	return this->message;
}

MyException::MyException(int number) {
	switch (number) {
	case(string13):this->number = string13;
		this->message = "Enter the 13 numbers";
		break;
	case(string12): this->number = string12;
		this->message = "Enter the 12 numbers";
		break;
	case(file): this->number = file;
		this->message = "Can't open the file";
		break;
	case(numbers): this->number = numbers;
		this->message = "Enter only Numbers!";
		break;
	case(country): this->number = country;
		this->message = "No such country for this bar code";
		break;

	default: break;
	}
}

MyException::~MyException() {
	this->message.clear();
	cout << "~My Exception" << endl;
}