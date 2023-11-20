#pragma once
#include "utils.h"
#include <afx.h>

class Shaikhutdinov_Car : public CObject
{
public:
	DECLARE_SERIAL(Shaikhutdinov_Car);
	virtual void Serialize(CArchive& ar);
	Shaikhutdinov_Car();
	virtual ~Shaikhutdinov_Car();

	virtual void input();
	virtual void print();
	CString getCStr(int i);
	virtual void Draw(CDC* pDC, int& i, vector<double> vec, double line_size, double y0);
	int x;

private:
	float engine_capacity;
	int power;
	int production_year;
	CString make;
	CString model;
};
