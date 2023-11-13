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

int Shaikhutdinov_Car::getLenCStr(int i)
{
	if (i == 0) { return make.GetLength(); }
	else if (i == 1) { return model.GetLength(); }
	else if (i == 2) {
		string q = to_string(engine_capacity);
		return q.size();
	}
	else if (i == 3) { 
		string q = to_string(power);
		return q.size();
	}
	else if (i == 4) { 
		string q = to_string(production_year);
		return q.size();
	}
	return 0;
}


void Shaikhutdinov_Car::input() {
	string make1;
	string model1;

	cin.clear();
	cin.ignore(1024, '\n');
	cout << "����� ����������: ";
	getline(cin, make1);
	cout << "������ ����������: ";
	getline(cin, model1);
	power = GetCorrectNumber("�������� (�.�): ", 0, 10000);
	engine_capacity = GetCorrectNumber("����� ���������(�): ", 0.1, 10.0);
	production_year = GetCorrectNumber("��� �������: ", 1800, 2023);
	make = make1.c_str();
	model = model1.c_str();
}


void Shaikhutdinov_Car::print() {
	cout << "�����: " << make << endl
		<< "������: " << model << endl
		<< "��������: " << power << endl
		<< "����� ���������: " << engine_capacity << endl
		<< "��� �������: " << production_year << endl;
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