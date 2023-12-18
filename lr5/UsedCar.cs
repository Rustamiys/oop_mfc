using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lr5
{
    [Serializable]
    public class UsedCar:Car
    {
        public int number_of_owners { get; set; }
        public double mileage { get; set; }
        public UsedCar(
        string _make,
        string _model,
        int _power,
        double _engine_capacity,
        int _production_year,
        int _number_of_owners,
        double _mileage) : 
        base(
        _make,
        _model,
        _power,
        _engine_capacity,
        _production_year) 
        {
            number_of_owners = _number_of_owners;
            mileage = _mileage;
        }
        public UsedCar() { }
        public override void Print()
        {
            Console.WriteLine($@"Машина({this.Id})
Марка: {this.make}
Модель: {this.model}
Мощность(л.с.): {this.power}
Объем двигателя(л): {this.engine_capacity}
Год производства: {this.production_year}
Количество владельцев: {number_of_owners}
Пробег: {this.mileage}");
        }
    }
}
