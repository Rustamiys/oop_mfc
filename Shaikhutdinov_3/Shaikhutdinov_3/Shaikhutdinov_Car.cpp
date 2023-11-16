#include "pch.h"
#include "Shaikhutdinov_Car.h"



Shaikhutdinov_Car::Shaikhutdinov_Car() {
	engine_capacity = 0;
	power = 0;
	production_year = 0;
	make;
	model;
}

Shaikhutdinov_Car::~Shaikhutdinov_Car()
{
}



CString Shaikhutdinov_Car::getCStr(int i)
{
	CString stringT;

	if (i == 0) { return make; }
	else if (i == 1) { return model; }
	else if (i == 2) {
		stringT.Format(L"%i", power);
		return stringT;
	}
	else if (i == 3) {
		stringT.Format(L"%f", engine_capacity);
		return stringT;
	}
	else if (i == 4) { 
		stringT.Format(L"%i", production_year);;
		return stringT;
	}
	else {
		return L"";
	}
}

void Shaikhutdinov_Car::Draw(CDC* pDC, int& i, vector<int> vec)
{
	CString stringT;
	pDC->TextOutW(vec[0], 30 + 20 * i, make);
	pDC->TextOutW(vec[1], 30 + 20 * i, model);
	
	stringT.Format(L"%i", power);
	pDC->TextOutW(vec[2], 30 + 20 * i, stringT); 

	stringT.Format(L"%f", engine_capacity);
	pDC->TextOutW(vec[3], 30 + 20 * i, stringT);
	
	stringT.Format(L"%i", production_year);
	pDC->TextOutW(vec[4], 30 + 20 * i, stringT);
	i++;
}


void Shaikhutdinov_Car::input() {
	string make1;
	string model1;

	cin.clear();
	cin.ignore(1024, '\n');
	cout << "Марка автомобиля: ";
	getline(cin, make1);
	cout << "Модель автомобиля: ";
	getline(cin, model1);
	power = GetCorrectNumber("Мощность (л.с): ", 0, 10000);
	engine_capacity = GetCorrectNumber("Объем двигателя(л): ", 0.1, 10.0);
	production_year = GetCorrectNumber("Год выпуска: ", 1800, 2023);
	make = make1.c_str();
	model = model1.c_str();
}


void Shaikhutdinov_Car::print() {
	cout << "Марка: " << make << endl
		<< "Модель: " << model << endl
		<< "Мощность: " << power << endl
		<< "Объем двигателя: " << engine_capacity << endl
		<< "Год выпуска: " << production_year << endl;
}

void Shaikhutdinov_Car::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
		ar << make << model
		<< power << engine_capacity << production_year;
	else
		ar >> make >> model >> power >> engine_capacity >> production_year;
}
IMPLEMENT_SERIAL(Shaikhutdinov_Car, CObject, 0);