#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <Windows.h>
#include <vector>


using namespace std;

template <typename T>
T GetCorrectNumber(string text, T min, T max) {
	cout << text;
	T number;
	cin >> number;
	if (max <= min) return max;
	while (true) {
		if (cin.fail() || number < min || number > max) {
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "«начение должно удовлетвор€ть промежутку (" << min << "-" << max << "): ";
			cin >> number;
		}
		else {
			return number;
		}
	}
}