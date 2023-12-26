#pragma once
#include "Car.h"

class UsedCar : public Car
{
public:
	DECLARE_SERIAL(UsedCar);
	UsedCar();
	void Serialize(CArchive& ar);
	int number_of_owners;
	float mileage;
};
