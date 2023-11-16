#include "pch.h"
#include "Shaikhutdinov_UsedCar.h"

Shaikhutdinov_UsedCar::Shaikhutdinov_UsedCar() : Shaikhutdinov_Car::Shaikhutdinov_Car() {
	number_of_owners = 1;
	mileage = 0;
}

CString Shaikhutdinov_UsedCar::getCStr(int i)
{
	CString stringT;
	if (i<5) {
		return Shaikhutdinov_Car::getCStr(i);
	}
	else if (i == 5) {
		stringT.Format(L"%i", number_of_owners);
		return stringT;
	}
	else if (i == 6) {
		stringT.Format(L"%f", mileage);
		return stringT;
	}
}

void Shaikhutdinov_UsedCar::Draw(CDC* pDC, int& i, vector<int> vec)
{
	
	CString stringT;
	stringT.Format(L"%i", number_of_owners);
	pDC->TextOutW(vec[5], 30 + 20 * i, stringT);
	stringT.Format(L"%f", mileage);
	pDC->TextOutW(vec[6], 30 + 20 * i, stringT);
	Shaikhutdinov_Car::Draw(pDC, i, vec);
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