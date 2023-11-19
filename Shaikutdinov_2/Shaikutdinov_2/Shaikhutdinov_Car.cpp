#include "pch.h"
#include "Shaikhutdinov_Car.h"



Shaikhutdinov_Car::Shaikhutdinov_Car() {
	engine_capacity = 0;
	power = 0;
	production_year = 0;
	make;
	model;
}

Shaikhutdinov_Car::~Shaikhutdinov_Car()
{
}

void Shaikhutdinov_Car::setMake(CString make) { this->make=make; }
void Shaikhutdinov_Car::setModel(CString model) { this->model=model; }
void Shaikhutdinov_Car::setEngineCapacity(float engine_capacity) { this->engine_capacity = engine_capacity; }
void Shaikhutdinov_Car::setPower(int power) { this->power = power; }
void Shaikhutdinov_Car::setProductionYear(int production_year) { this->production_year = production_year; }


CString Shaikhutdinov_Car::getMake() { return this->make; }
CString Shaikhutdinov_Car::getModel() { return this->model; }
float Shaikhutdinov_Car::getEngineCapacity() { return this->engine_capacity; }
int Shaikhutdinov_Car::getPower() { return this->power; }
int Shaikhutdinov_Car::getProductionYear() { return this->production_year; }

void Shaikhutdinov_Car::input() {
	string make1;
	string model1;
	
	cin.clear();
	cin.ignore(1024, '\n');
	cout << "Марка автомобиля: ";
	getline(cin, make1);
	cout << "Модель автомобиля: ";
	getline(cin, model1);
	power = GetCorrectNumber("Мощность (л.с): ", 0, 10000);
	engine_capacity = GetCorrectNumber("Объем двигателя(л): ", 0.1, 10.0);
	production_year = GetCorrectNumber("Год выпуска: ", 1800, 2023);
	make = make1.c_str();
	model = model1.c_str();
}


void Shaikhutdinov_Car::print() {
	cout << "Марка: " << make << endl
		<< "Модель: " << model << endl
		<< "Мощность: " << power << endl
		<< "Объем двигателя: " << engine_capacity << endl
		<< "Год выпуска: " << production_year << endl;
}

void Shaikhutdinov_Car::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
		ar << make << model
		<< power << engine_capacity << production_year;
	else
		ar >> make >> model >> power >> engine_capacity >> production_year;
}
IMPLEMENT_SERIAL(Shaikhutdinov_Car, CObject, 0);
