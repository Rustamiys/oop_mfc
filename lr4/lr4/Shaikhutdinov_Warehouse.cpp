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

void Shaikhutdinov_Warehouse::Load(CArchive& ar)
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

bool Shaikhutdinov_Warehouse::Empty()
{
	return warehouse.empty();
}

CSize Shaikhutdinov_Warehouse::Draw(CDC* pDC)
{
	vector<CString> name = { L"Марка" , L"Модель" , L"Мощность(л.с)" ,L"Объем двигателя(л)" ,
	L"Год выпуска" , L"Количество владельцев" , L"Пробег(км):" };

	vector<int> position = {};
	int col_size = 10;
	int lin_size = 30;
	int x = 10; int y = 10;

	POINT pos;
	position.push_back(x);

	for (int i = 0; i < name.size(); i++) {
		pDC->TextOutW(x, y, name[i]);
		x += col_size + MaxStr(pDC, i, pDC->GetTextExtent(name[i]).cx);
		position.push_back(x);
	}

	pos.y = y;
	for (auto pShaikhutdinov_Car : warehouse) {
		for (int i = 0; i < 7; i++) {
			CSize len = pDC->GetTextExtent(pShaikhutdinov_Car->getCStr(i));
			if (pos.y < len.cy)
				pos.y = len.cy;
		}
	}

	int i = 0;
	y += lin_size;
	lin_size += pos.y;
	for_each(warehouse.begin(), warehouse.end(), bind(&Shaikhutdinov_Car::Draw, placeholders::_1, pDC, i, position, lin_size, y));

	pos.x = position[7] - col_size;
	pos.y = (warehouse.size()) ? pos.y + y + lin_size * (warehouse.size() - 1) : y + pos.y - lin_size;
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


void Shaikhutdinov_Warehouse::Save(CArchive& ar)
{
	ar << size_t(warehouse.size());
	for (auto Shaikhutdinov_Car : warehouse)
		ar << Shaikhutdinov_Car.get();

	cout << "Выполнено" << endl;
}

CString Shaikhutdinov_Warehouse::GetCStr(int i, int j) {
	return warehouse[i]->getCStr(j);
}

int Shaikhutdinov_Warehouse::Size() {
	return warehouse.size();
}

void Shaikhutdinov_Warehouse::EraseObj(int i) {
	warehouse.erase(warehouse.begin() + i);
}

void Shaikhutdinov_Warehouse::AddObj(const vector<CString> vec, int n) {
	shared_ptr<Shaikhutdinov_Car> pSC;
	if (vec[6] == L"")
		pSC = make_shared<Shaikhutdinov_Car>();
	else
		pSC = make_shared<Shaikhutdinov_UsedCar>();
	pSC->add(vec);
	warehouse.push_back(pSC);
}
