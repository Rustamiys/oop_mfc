#include "pch.h"
#include "Shaikhutdinov_Warehouse.h"


void Shaikhutdinov_Warehouse::Input()
{
	shared_ptr<Shaikhutdinov_Car> uShaikhutdinov_Car;
	if (GetCorrectNumber("1. Новая\n2. б/у\nВведите цифру: ", 1, 2) == 1)
		uShaikhutdinov_Car = make_shared<Shaikhutdinov_Car>();
	else
		uShaikhutdinov_Car = make_shared<Shaikhutdinov_UsedCar>();
	//uShaikhutdinov_Car = (GetCorrectNumber("1. Новая\n2. б/у\nВведите цифру: ", 1, 2)==1) ? make_shared<Shaikhutdinov_Car>() : make_shared<Shaikhutdinov_UsedCar>();
	uShaikhutdinov_Car->input();
	warehouse.push_back(uShaikhutdinov_Car);
}


void Shaikhutdinov_Warehouse::Print()
{
	if (warehouse.size() != 0)
		for (auto pShaikhutdinov_Car : warehouse)
			pShaikhutdinov_Car->print();
	else
		cout << "Нет машин" << endl;
}

void Shaikhutdinov_Warehouse::Clear()
{
	warehouse.clear();
}

void Shaikhutdinov_Warehouse::Load(CString fname)
{
	ifstream fin(fname);
	if (!fin.good()) {
		cout << "wrong input" << endl;
		fin.close();
		return;
	}
	fin.close();
	CFile file(fname, CFile::modeRead);
	CArchive ar(&file, CArchive::load);

	size_t t;
	ar >> t;
	for (int i = 0; i < t; i++)
	{
		Shaikhutdinov_Car* nShaikhutdinov_Car;
		ar >> nShaikhutdinov_Car;
		shared_ptr<Shaikhutdinov_Car> Shaikhutdinov_Car(nShaikhutdinov_Car);
		warehouse.push_back(Shaikhutdinov_Car);
	}
	cout << "Успешно!" << endl;
}


void Shaikhutdinov_Warehouse::Save(CString fname)
{
	ofstream fout(fname);
	if (!fout.good()) {
		cout << "wrong input" << endl;
		fout.close();
		return;
	}
	fout.close();
	CFile file(fname, CFile::modeCreate | CFile::modeWrite);
	CArchive ar(&file, CArchive::store);
	ar << size_t(warehouse.size());
	for (auto Shaikhutdinov_Car : warehouse)
		ar << Shaikhutdinov_Car.get();

	cout << "Успешно" << endl;
}