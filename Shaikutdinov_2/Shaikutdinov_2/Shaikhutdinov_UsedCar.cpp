#include "pch.h"
#include "Shaikhutdinov_UsedCar.h"

Shaikhutdinov_UsedCar::Shaikhutdinov_UsedCar() : Shaikhutdinov_Car::Shaikhutdinov_Car() {
	number_of_owners = 1;
	mileage = 0;
}

int Shaikhutdinov_UsedCar::getNumberOfOwners() { return this->mileage;}
float Shaikhutdinov_UsedCar::getMileage() { return this->number_of_owners;}

void Shaikhutdinov_UsedCar::setNumberOfOwners(int number_of_owners) { this->number_of_owners = number_of_owners; }
void Shaikhutdinov_UsedCar::setMileage(float mileage) { this->mileage = mileage; }

void Shaikhutdinov_UsedCar::input(){
	Shaikhutdinov_Car::input();
	number_of_owners = GetCorrectNumber("Количество владельцев: ", 1, 1000);
	mileage = GetCorrectNumber("Пробег: ", 0.0, 10000000.0);
}


void Shaikhutdinov_UsedCar::print(){
	Shaikhutdinov_Car::print();
	cout << "Количество владельцев : " << getNumberOfOwners() << endl
		<< "Пробег: " << getMileage() << endl;
}

void Shaikhutdinov_UsedCar::Serialize(CArchive& ar)
{
	Shaikhutdinov_Car::Serialize(ar);
	if (ar.IsStoring())
		ar << number_of_owners << mileage;
	else
		ar >> number_of_owners >> mileage;
}
IMPLEMENT_SERIAL(Shaikhutdinov_UsedCar, Shaikhutdinov_Car, 0);
