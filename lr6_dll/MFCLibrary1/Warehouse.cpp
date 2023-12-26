#include "pch.h"
#include "Warehouse.h"
#include <algorithm>
#include <memory>
#include <functional>

Warehouse::Warehouse() {

}

Warehouse::~Warehouse() {

}

void Warehouse::Clear()
{
	warehouse.clear();
}

void Warehouse::Add(shared_ptr<Car> car) {
	warehouse.push_back(car);
}

bool Warehouse::Load(const char* filename)
{
	try {
		CFile file(CString(filename), CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		size_t t;
		ar >> t;
		for (int i = 0; i < t; i++)
		{
			Car* nCar;
			ar >> nCar;
			shared_ptr<Car> Car(nCar);
			warehouse.push_back(Car);
		}
		ar.Close();
		file.Close();
		return true;
	}
	catch (exception) {
		return false;
	}
}

bool Warehouse::Save(const char* filename)
{
	try {
		CFile file(CString(filename), CFile::modeCreate | CFile::modeWrite);
		CArchive ar(&file, CArchive::store);
		ar << size_t(warehouse.size());
		for (auto Car : warehouse)
			ar << Car.get();
		ar.Close();
		file.Close();
		return true;
	}
	catch (exception) {
		return false;
	}
}

int Warehouse::Size() {
	return warehouse.size();
}

bool Warehouse::EraseCar(int i) {
	try {
		warehouse.erase(warehouse.begin() + i);
		return true;
	}
	catch (exception) {
		return false;
	}
}

shared_ptr<Car> Warehouse::GetCar(int id) {
	return warehouse[id];
}


void Warehouse::InsertObj(shared_ptr<Car> car, int n) {
	warehouse.erase(warehouse.begin() + n);
	warehouse.insert(warehouse.begin() + n, car);
}
