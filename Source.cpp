#include <iostream>
#include <string>
#include "UpcData.h"
#include "EanData.h"
#include <Windows.h>
#include "Template.h"
#include "Template.cpp"
#include "List.h"




string OneStringEan(EanData& ean)
{
	string tmp;
	tmp = ean.GetNameNumberBarcode() + " " + ean.GetNameCountry() + " " + ean.GetNameManufactura() + " " + ean.GetNameProduct() + " " + ean.GetOriginals() + "\n";
	return tmp;
}
string OneStringUpc(UpcData& upc)
{
	string tmp;
	tmp = upc.GetNameNumberBarcode() + " " + upc.GetNameCountry() + " " + upc.GetNameManufactura() + " " + upc.GetNameProduct()+ "\n";
	return tmp;
}

int main()
{
	
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "	COURSE WORK\n" << "\n" << "BARCODE ANALYSIS" << endl << "TYPE OF BARCODE: EAN13 & UPC" << endl;
	cout << "----------------------------------------------------------------------------------------------------------" << endl;
    int i = 1;
	

	string tmp;
	cList<EanData> vean;
    cList<UpcData> vupc;
	cList<EanData>::iterator eaniterator;
	cList<UpcData>::iterator upciterator;
	EanData ean;
	UpcData upc;
	fstream file;
	file.open("Codes.txt", ios_base::in | ios_base::out | ios_base::trunc);
	file.close();

	while(i)
	{
		SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 11));
		cout << " What type of code do you want to analysis?\n" << "[1] - EAN13\n" << "[2] - UPC" << endl;
		cout << "[3] - Show all analyzes code" << endl;
		cout << "[4] - Clear File" << endl;
		cout << "[5] - Find Barcode" << endl;
		cout << "[6] - Edit Barcode" << endl;
		cout << "[0] - Exit" << endl;
		cin >> i;
		switch (i)
		{
		case(1):
			file.open("Codes.txt", ios_base::out | ios_base::app);
			cout << "Enter the barcode format of EAN-13" << endl;
			cin >> ean;
			system("cls");
			SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) |14));
			cout << ean;
			file << OneStringEan(ean);
			vean.addNode(ean);
			file.close();
			break;
		case(2):
			cout << "Enter the Barcode format of UPC" << endl;
			file.open("Codes.txt", ios_base::out | ios_base::app);
			cin >> upc;
			system("cls");
			SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 14));
			cout << upc;
			vupc.addNode(upc);
			file << OneStringUpc(upc);
			file.close();
			break;
		case(3):
			SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 10));
			eaniterator = vean.begin();
			upciterator = vupc.begin();
			if (!vean.isEmpty()) {
				for (int i = 0; i < vean.getCount(); i++)
				{
					cout << eaniterator;
					++eaniterator;
				}
			}
			if (!vupc.isEmpty()) {
				for (int i = 0; i < vupc.getCount(); i++)
				{
					cout << upciterator;
					++upciterator;
				}
			}
			system("pause");
			system("cls");
			break;
		case(4):
			file.open("Codes.txt", ios_base::out |ios_base::trunc);
			vean.remove();
			vupc.remove();
			file.close();
			break;
		case(5):
			cout << "Enter the Barcode" << endl;
			while(i)
			{
				cin >> tmp;
				if(tmp.size()<12 || tmp.size()>13)
				{
					cout << "Enter Barcode length by 12 or 13 numbers" << endl;
				}
				else
				{
					break;
				}
				
			}
			if(!(vean.FindItem(vean.getFirst(),tmp)) && !(vupc.FindItem(vupc.getFirst(),tmp))){
				cout << "No such BarCode" << endl;
			};
			system("pause");
			system("cls");
			break;
		case(6):
			cout << "Enter Number od Barcode which you want to change" << endl;
			cin >> tmp;
			if (tmp.size() < 12 || tmp.size() > 13)
			{
				cout << "Enter Barcode length by 12 or 13 numbers" << endl;
			}
			if(tmp.size() == 12)
			{
				vupc.Edit(vupc.getFirst(), tmp);
			}
			else if(tmp.size() == 13)
			{
				vean.Edit(vean.getLast(), tmp);
			}
			file.open("Codes.txt", ios_base::out | ios_base::trunc);
			eaniterator = vean.begin();
			upciterator = vupc.begin();
			if (!vean.isEmpty()) {
				for (int i = 0; i < vean.getCount(); i++)
				{
					file << OneStringEan(*eaniterator);
					++eaniterator;
				}
			}
			if (!vupc.isEmpty()) {
				for (int i = 0; i < vupc.getCount(); i++)
				{
					file << OneStringUpc(*upciterator);
					++upciterator;
				}
			}
			break;
		case(0):
			break;
		default:
			cout << "Enter the number from 0 to 3" << endl;
			cin >> i;
		}
		file.close();
	}
	return 0;
}


