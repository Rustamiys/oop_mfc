#pragma once
#include "Car.h"
#include "UsedCar.h"

class Warehouse
{
	vector <shared_ptr<Car>> warehouse;
public:
	~Warehouse();
	Warehouse();
	void Clear();
	void Add(shared_ptr<Car> car);
	bool Save(const char* filename);
	bool Load(const char* filename);
	int Size();
	shared_ptr<Car> GetCar(int id);
	bool EraseCar(int i);
};

