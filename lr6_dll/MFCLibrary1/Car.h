#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <Windows.h>
#include <vector>
#include <afx.h>

using namespace std;

class Car : public CObject
{
public:
	DECLARE_SERIAL(Car);
	virtual void Serialize(CArchive& ar);
	Car();
	virtual ~Car();
	float engine_capacity;
	int power;
	int production_year;
	CString make;
	CString model;
};