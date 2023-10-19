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
	string make;
	string model;
	
	cin.clear();
	cin.ignore(1024, '\n');
	cout << "Марка автомобиля: ";
	getline(cin, make);
	cout << "Модель автомобиля: ";
	getline(cin, model);
	int power = GetCorrectNumber("Мощность (л.с): ", 0, 10000);
	float engine_capacity = GetCorrectNumber("Объем двигателя(л): ", 0.1, 10.0);
	int production_year = GetCorrectNumber("Год выпуска: ", 1800, 2023);
	CString make1(make.c_str());
	CString model1(model.c_str());
	setMake(make1);
	setModel(model1);
	setEngineCapacity(engine_capacity);
	setPower(power);
	setProductionYear(production_year);
}


void Shaikhutdinov_Car::print() {
	cout << "Марка: " << getMake() << endl
		<< "Модель: " << getModel() << endl
		<< "Мощность: " << getPower() << endl
		<< "Объем двигателя: " << getEngineCapacity() << endl
		<< "Год выпуска: " << getProductionYear() << endl;
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
