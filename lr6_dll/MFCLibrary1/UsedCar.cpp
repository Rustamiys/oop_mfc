#include "pch.h"
#include "UsedCar.h"

UsedCar::UsedCar() : Car::Car() {
	number_of_owners = 1;
	mileage = 0;
}


void UsedCar::Serialize(CArchive& ar)
{
	Car::Serialize(ar);
	if (ar.IsStoring())
		ar << number_of_owners << mileage;
	else
		ar >> number_of_owners >> mileage;
}
IMPLEMENT_SERIAL(UsedCar, Car, 0);
