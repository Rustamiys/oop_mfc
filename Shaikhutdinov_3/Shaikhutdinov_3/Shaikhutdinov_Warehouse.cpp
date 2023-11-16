#include "pch.h"
#include "Shaikhutdinov_Warehouse.h"
#include <algorithm>
#include <memory>
#include <functional>


void Shaikhutdinov_Warehouse::Input()
{
	shared_ptr<Shaikhutdinov_Car> uShaikhutdinov_Car;
	if (GetCorrectNumber("1. Новая\n2. б/у\nвведите число: ", 1, 2) == 1)
		uShaikhutdinov_Car = make_shared<Shaikhutdinov_Car>();
	else
		uShaikhutdinov_Car = make_shared<Shaikhutdinov_UsedCar>();
	//uShaikhutdinov_Car = (GetCorrectNumber("1. Новая\n2. б/у\nвведите число:", 1, 2)==1) ? make_shared<Shaikhutdinov_Car>() : make_shared<Shaikhutdinov_UsedCar>();
	uShaikhutdinov_Car->input();
	warehouse.push_back(uShaikhutdinov_Car);
}


void Shaikhutdinov_Warehouse::Print()
{
	if (warehouse.size() != 0)
		for (auto pShaikhutdinov_Car : warehouse)
			pShaikhutdinov_Car->print();
	else
		cout << "Пусто" << endl;
}

void Shaikhutdinov_Warehouse::Clear()
{
	warehouse.clear();
}

void Shaikhutdinov_Warehouse::Load(CArchive &ar)
{
	size_t t;
	ar >> t;
	for (int i = 0; i < t; i++)
	{
		Shaikhutdinov_Car* nShaikhutdinov_Car;
		ar >> nShaikhutdinov_Car;
		shared_ptr<Shaikhutdinov_Car> Shaikhutdinov_Car(nShaikhutdinov_Car);
		warehouse.push_back(Shaikhutdinov_Car);
	}
	cout << "Выполнено!" << endl;
}

CSize Shaikhutdinov_Warehouse::Draw(CDC* pDC)
{
	vector<CString> name = { L"Марка" , L"Модель" , L"Мощность(л.с)" ,L"Объем двигателя(л)" , 
	L"Год выпуска" , L"Количество владельцев" , L"Пробег(км):" };
	
	vector<int> position = {};
	int x = 10; int y = 10;
	position.push_back(x);
	for (int i = 0; i < name.size(); i++) {
		pDC->TextOutW(x, y, name[i]);
		position.push_back(10 + x + 11 * MaxStr(i, name[i].GetLength()));
		x = position[i+1];
	}

	int i = 0;
	for_each(warehouse.begin(), warehouse.end(), bind(&Shaikhutdinov_Car::Draw, placeholders::_1, pDC, i, position));
	POINT sizeAll;
	sizeAll.x = position[7];
	sizeAll.y = 50 + 20 * warehouse.size();
	return sizeAll;
}


int Shaikhutdinov_Warehouse::MaxStr(int row, int max1)
{
	for (auto pShaikhutdinov_Car : warehouse) {
		int len = pShaikhutdinov_Car->getCStr(row).GetLength();
		if (max1 < len) max1 = len;
	}
	return max1;
}


void Shaikhutdinov_Warehouse::Save(CArchive &ar)
{
	ar << size_t(warehouse.size());
	for (auto Shaikhutdinov_Car : warehouse)
		ar << Shaikhutdinov_Car.get();

	cout << "Выполнено" << endl;
}