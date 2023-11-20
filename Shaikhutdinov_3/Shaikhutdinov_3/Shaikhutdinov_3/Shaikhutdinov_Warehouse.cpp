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
	
	/*vector<int> position = {};
	int col_size = 10;
	int lin_size = 20;
	int x = 10; int y = 10;

	position.push_back(x);

	double mmX = 25.4 / pDC->GetDeviceCaps(LOGPIXELSX);
	double mmY = 25.4 / pDC->GetDeviceCaps(LOGPIXELSY);



	for (int i = 0; i < name.size(); i++) {
		pDC->TextOutW(x, y, name[i]);
		x += col_size + MaxStr(pDC, i, pDC->GetTextExtent(name[i]).cx);
		position.push_back(x);
	}
	int i = 0;
	y += lin_size;
	for_each(warehouse.begin(), warehouse.end(), bind(&Shaikhutdinov_Car::Draw, placeholders::_1, pDC, i, position, lin_size, y));
	POINT pos;
	pos.x = position[7]; pos.y = y + lin_size * i;
	return pos;*/
	pDC->SetMapMode(MM_LOMETRIC);


	vector<double> position = {};
	double mmX = 10 * 25.4 / pDC->GetDeviceCaps(LOGPIXELSX);
	double mmY = 10 * 25.4 / pDC->GetDeviceCaps(LOGPIXELSY);
	
	double col_size = 10 * mmX;
	double lin_size = 30 * mmY;
	double x = 10 * mmX; double y = 10 * mmY;

	position.push_back(x);

	for (int i = 0; i < name.size(); i++) {
		pDC->TextOutW(x, -y, name[i]);
		x += col_size + mmX * MaxStr(pDC, i, pDC->GetTextExtent(name[i]).cx);
		position.push_back(x);
	}
	int i = 0;
	y += lin_size;
	for_each(warehouse.begin(), warehouse.end(), bind(&Shaikhutdinov_Car::Draw, placeholders::_1, pDC, i, position, lin_size, y));
	POINT pos;
	pos.x = position[7]; pos.y = y + lin_size * (i+5);
	return pos;
}


int Shaikhutdinov_Warehouse::MaxStr(CDC* pDC, int row, int max)
{
	for (auto pShaikhutdinov_Car : warehouse) {
		CSize len = pDC->GetTextExtent(pShaikhutdinov_Car->getCStr(row));
		if (max < len.cx) 
			max = len.cx;
	}

	return max;
}


void Shaikhutdinov_Warehouse::Save(CArchive &ar)
{
	ar << size_t(warehouse.size());
	for (auto Shaikhutdinov_Car : warehouse)
		ar << Shaikhutdinov_Car.get();

	cout << "Выполнено" << endl;
}