// Shaikutdinov_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include "framework.h"
#include "Shaikutdinov_2.h"
#include "utils.h"
#include "Shaikhutdinov_Car.h"
#include "Shaikhutdinov_Warehouse.h"
#include "Shaikhutdinov_UsedCar.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Единственный объект приложения

CWinApp theApp;

using namespace std;

void printMenu() {
	cout << "1. Добавить автомобиль" << endl
		<< "2. Вывести автомобили" << endl
		<< "3. Сохранить автомобили в файл" << endl
		<< "4. Считать автомобили из файла" << endl
		<< "5. Удалить все автомобили" << endl
		<< "0. Выход из программы" << endl;
}

int main()
{
    int nRetCode = 0;

    HMODULE hModule = ::GetModuleHandle(nullptr);

    if (hModule != nullptr)
    {
        // инициализировать MFC, а также печать и сообщения об ошибках про сбое
        if (!AfxWinInit(hModule, nullptr, ::GetCommandLine(), 0))
        {
            // TODO: вставьте сюда код для приложения.
            wprintf(L"Критическая ошибка: сбой при инициализации MFC\n");
            nRetCode = 1;
        }
        else
        {
            // TODO: вставьте сюда код для приложения.
			std::locale::global(std::locale("Russian_Russia.1251"));
			SetConsoleCP(1251);
			SetConsoleOutputCP(1251);
			Warehouse warehouse;

			while (true) {
				system("cls");
				printMenu();
				switch (GetCorrectNumber("Введите цифру(0-5): ", 0, 5))
				{
				case 0:
					return 0;

				case 1:
					warehouse.Input();
					break;

				case 2:
					warehouse.Print();
					break;

				case 3:
				{
					cout << "Filename: ";
					cin.clear();
					cin.ignore(1024, '\n');
					string filename;
					getline(cin, filename);
					CString fname(filename.c_str());
					warehouse.Save(fname);
					break;
				}
				case 4:
				{
					cout << "Filename: ";
					cin.clear();
					cin.ignore(1024, '\n');
					string filename;
					getline(cin, filename);
					CString fname(filename.c_str());
					warehouse.Load(fname);
					break;
				}
				case 5:
					warehouse.Clear();
					break;
				
				default:
					cout << "ERROR!" << endl;
				}
				system("pause");
			}
        }
    }
    else
    {
        // TODO: измените код ошибки в соответствии с потребностями
        wprintf(L"Критическая ошибка: сбой GetModuleHandle\n");
        nRetCode = 1;
    }

    return nRetCode;
}
