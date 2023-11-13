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
	int getLenCStr(int i);


private:
	float engine_capacity;
	int power;
	int production_year;
	CString make;
	CString model;
};
