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
	void setMake(CString make);
	void setModel(CString model);
	void setEngineCapacity(float engine_capacity);
	void setPower(int power);
	void setProductionYear(int production_year);

	CString getMake();
	CString getModel();
	float getEngineCapacity();
	int getPower();
	int getProductionYear();

	virtual void input();
	virtual void print();


private:
	float engine_capacity;
	int power;
	int production_year;
	CString make;
	CString model;
};

