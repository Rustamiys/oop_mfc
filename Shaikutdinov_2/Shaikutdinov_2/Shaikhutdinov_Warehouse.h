#pragma once
#include "utils.h"
#include "Shaikhutdinov_Car.h"
#include "Shaikhutdinov_UsedCar.h"

class Warehouse
{
	vector <shared_ptr<Shaikhutdinov_Car>> warehouse;
public:
	void Input();
	void Print();
	void Clear();
	void Save(CString fname);
	void Load(CString fname);
};