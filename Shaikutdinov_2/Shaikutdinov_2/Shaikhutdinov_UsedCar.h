#pragma once
#include "utils.h"
#include "Shaikhutdinov_Car.h"
class Shaikhutdinov_UsedCar: public Shaikhutdinov_Car
{
public:
	DECLARE_SERIAL(Shaikhutdinov_UsedCar);
	Shaikhutdinov_UsedCar();
	int getNumberOfOwners();
	float getMileage();

	void setNumberOfOwners(int number_of_owners);
	void setMileage(float mileage);
	void input();
	void print();
	virtual void Serialize(CArchive& ar) override;

private:
	int number_of_owners;
	float mileage;
};

