#pragma once
#include "utils.h"
#include "Shaikhutdinov_Car.h"
class Shaikhutdinov_UsedCar : public Shaikhutdinov_Car
{
public:
	DECLARE_SERIAL(Shaikhutdinov_UsedCar);
	Shaikhutdinov_UsedCar();

	CString getCStr(int i);

	void input();
	void print();
	void Serialize(CArchive& ar);
	void Draw(CDC* pDC, int& i, vector<double> vec, double line_size, double y0);

private:
	int number_of_owners;
	float mileage;
};
