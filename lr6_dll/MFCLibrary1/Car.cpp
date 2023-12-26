#include "pch.h"
#include "Car.h"

Car::Car() {
	engine_capacity = 0;
	power = 0;
	production_year = 0;
	make = L"";
	model = L"";
}

Car::~Car()
{
}


void Car::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
		ar << make << model
		<< power << engine_capacity << production_year;
	else
		ar >> make >> model >> power >> engine_capacity >> production_year;
}
IMPLEMENT_SERIAL(Car, CObject, 0);
