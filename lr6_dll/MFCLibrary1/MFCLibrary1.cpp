#include "pch.h"
#include "framework.h"
#include "Warehouse.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

Warehouse warehouse;

struct car_struct {
	char make[256];
	char model[256];
	int power;
	float engine_capacity;
	int production_year;
	int number_of_owners;
	float mileage;
};

extern	"C"
{
	_declspec(dllexport) bool WarehouseLoad(const char* filename) {
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		return warehouse.Load(filename);
	}

	_declspec(dllexport) bool WarehouseSave(const char* filename) {
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		return warehouse.Save(filename);
	}

	_declspec(dllexport) bool __stdcall WarehouseDeleteCar(int id) {
		return warehouse.EraseCar(id);
	}

	_declspec(dllexport) void __stdcall WarehouseUpdateCar(car_struct& car, int id) {
		warehouse.GetCar(id)->make = car.make;
		warehouse.GetCar(id)->model = car.model;
		warehouse.GetCar(id)->power = car.power;
		warehouse.GetCar(id)->engine_capacity = car.engine_capacity;
		warehouse.GetCar(id)->production_year = car.production_year;
		if (!car.mileage) {
			shared_ptr<UsedCar> ptr = std::dynamic_pointer_cast<UsedCar>(warehouse.GetCar(id));
			ptr->number_of_owners = car.number_of_owners;
			ptr->mileage = car.mileage;
		}
	}

	_declspec(dllexport) void __stdcall WarehouseClear() {
		warehouse.Clear();
	}

	_declspec(dllexport) void __stdcall WarehouseAddCar(car_struct& car) {
		if (car.mileage!=0) {
			UsedCar* newCar = new UsedCar;
			newCar->number_of_owners = car.number_of_owners;
			newCar->mileage = car.mileage;
			newCar->make = car.make;
			newCar->model = car.model;
			newCar->power = car.power;
			newCar->engine_capacity = car.engine_capacity;
			newCar->production_year = car.production_year;
			shared_ptr<Car> pCar(newCar);
			warehouse.Add(pCar);
		}
		else {
			Car* newCar = new Car;
			newCar->make = car.make;
			newCar->model = car.model;
			newCar->power = car.power;
			newCar->engine_capacity = car.engine_capacity;
			newCar->production_year = car.production_year;
			shared_ptr<Car> pCar(newCar);
			warehouse.Add(pCar);
		}
	}

	_declspec(dllexport) void __stdcall WarehouseInsertCar(car_struct& car, int id) {
		if (car.mileage != 0) {
			UsedCar* newCar = new UsedCar;
			newCar->number_of_owners = car.number_of_owners;
			newCar->mileage = car.mileage;
			newCar->make = car.make;
			newCar->model = car.model;
			newCar->power = car.power;
			newCar->engine_capacity = car.engine_capacity;
			newCar->production_year = car.production_year;
			shared_ptr<Car> pCar(newCar);
			warehouse.InsertObj(pCar, id);
		}
		else {
			Car* newCar = new Car;
			newCar->make = car.make;
			newCar->model = car.model;
			newCar->power = car.power;
			newCar->engine_capacity = car.engine_capacity;
			newCar->production_year = car.production_year;
			shared_ptr<Car> pCar(newCar);
			warehouse.InsertObj(pCar, id);
			warehouse.InsertObj(pCar, id);

		}
	}

	_declspec(dllexport) void __stdcall WarehouseGetCar(car_struct& car, int id)
	{
		CString unicodestr = warehouse.GetCar(id)->make;
		CStringA charstr(unicodestr);
		strcpy_s(car.make, charstr);
		unicodestr = warehouse.GetCar(id)->model;
		charstr = unicodestr;
		strcpy_s(car.model, charstr);

		car.power = warehouse.GetCar(id)->power;
		car.engine_capacity = warehouse.GetCar(id)->engine_capacity;
		car.production_year = warehouse.GetCar(id)->production_year;

		shared_ptr<UsedCar> ptr = dynamic_pointer_cast<UsedCar>(warehouse.GetCar(id));
		if (ptr) {
			car.mileage = ptr->mileage;
			car.number_of_owners = ptr->number_of_owners;
		}

	}

	_declspec(dllexport) int __stdcall WarehouseSize()
	{
		return warehouse.Size();
	}
}