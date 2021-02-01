#include "InputEx.h"

enum MyEnum {
	string13 = 1,
	string12,
	file,
	numbers,
	country
};

void InputEx::CheckingEan13(string& code)
{
	try
	{
		if (code.size() != 13)
		{
			throw MyException(string13);
		}
		for (char i : code)
		{
			if (i < '0' || i > '9')
			{
				throw MyException(numbers);
			}
		}
		ifstream file("MyFile.txt");
		InputEx::CheckingFile();
		string temp;
		string other = code;
		int a;
		while (!file.eof())
		{
			temp.clear();
			other = code;
			file >> temp;
			a = temp.find('-');
			temp.erase(a);
			other.erase(a);
			if (other == temp)
			{
				break;
			}
			if (file.eof())
			{
				throw MyException(country);
			}
		}
		file.close();
	}
	catch (MyException& ex) {
		cin.clear();
		rewind(stdin);
		cout << ex.What() << endl;
		cin >> code;
		InputEx::CheckingEan13(code);
	}
	catch (...)
	{
		MyException ex;
		cin.clear();
		rewind(stdin);
		cout << ex.What() << endl;
		cin >> code;
		InputEx::CheckingEan13(code);
	}
}

void InputEx::CheckingUpc(string& code)
{
	try
	{
		if (code.size() != 12)
		{
			throw MyException(string12);
		}
		for (char i : code)
		{
			if (i < '0' || i >> '9')
			{
				throw MyException(numbers);
			}
		}
		ifstream file("MyFile.txt");
		InputEx::CheckingFile();
		string temp;
		string other = code;
		int a;
		while (!file.eof())
		{
			temp.clear();
			other = code;
			file >> temp;
			a = temp.find('-');
			temp.erase(a);
			other.erase(a);
			if (other == temp)
			{
				break;
			}
			if (file.eof())
			{
				throw MyException(country);
			}
		}
		file.close();
	}
	catch (MyException& ex) {
		cin.clear();
		rewind(stdin);
		cout << ex.What() << endl;
		cin >> code;
		InputEx::CheckingUpc(code);
	}
	catch(...)
	{
		MyException ex;
		cin.clear();
		rewind(stdin);
		cout << ex.What() << endl;
		cin >> code;
		InputEx::CheckingUpc(code);
	}
}

void InputEx::CheckingFile()
{
	try {
		ifstream file("MyFile.txt");
		/*file.open("MyFile.txt", fstream::in );*/
		if (file.is_open()==false)
		{
			throw MyException(MyEnum::file);
		}
		file.close();
	}
	catch(MyException& ex)
	{
		cout << "Can't open the file pls try again" << endl;
		exit(-1);
	}
	catch(...)
	{
		cout << "Can't open the file pls try again" << endl;
		exit(-1);
	}
}


