#include "pch.h"
#include "Shaikhutdinov_UsedCar.h"

Shaikhutdinov_UsedCar::Shaikhutdinov_UsedCar() : Shaikhutdinov_Car::Shaikhutdinov_Car() {
	number_of_owners = 1;
	mileage = 0;
}

int Shaikhutdinov_UsedCar::getLenCStr(int i)
{
	int q = Shaikhutdinov_Car::getLenCStr(i);
	if (q) {
		return q;
	}
	if (i == 5) {
		string q = to_string(mileage);
		return q.size();
	}
	else if (i == 6) {
		string q = to_string(number_of_owners);
		return q.size();
	}
}


void Shaikhutdinov_UsedCar::input() {
	Shaikhutdinov_Car::input();
	number_of_owners = GetCorrectNumber("Количество владельцев: ", 1, 1000);
	mileage = GetCorrectNumber("Пробег: ", 0.0, 10000000.0);
}


void Shaikhutdinov_UsedCar::print() {
	Shaikhutdinov_Car::print();
	cout << "Количество владельцев : " << number_of_owners << endl
		<< "Пробег: " << mileage << endl;
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