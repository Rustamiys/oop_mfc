#pragma once
#include "utils.h"
#include "Shaikhutdinov_Car.h"
#include "Shaikhutdinov_UsedCar.h"

class Shaikhutdinov_Warehouse
{
	vector <shared_ptr<Shaikhutdinov_Car>> warehouse;
public:
	void Input();
	void Print();
	void Clear();
	void Save(CArchive &ar);
	void Load(CArchive &ar);
	void Draw(CDC* pDC);
	int MaxStr(int row, int max1);
};