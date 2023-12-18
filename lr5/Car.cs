using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;
using static System.Net.Mime.MediaTypeNames;

namespace lr5
{
    [Serializable]
    [XmlInclude(typeof(UsedCar))]
    public class Car
    {
        public int Id { get; set; }
        public string make { get; set; }
        public string model { get; set; }
        public int power { get; set; }
        public double engine_capacity { get; set; }
        public int production_year { get; set; }
        public Car(
            string _make,
            string _model,
            int _power,
            double _engine_capacity,
            int _production_year)
        { 
            this.make = _make;
            this.model = _model;
            this.power = _power;
            this.engine_capacity = _engine_capacity;
            this.production_year = _production_year;
        }
        public Car() { }
        public virtual void Print()
        {
            Console.WriteLine($@"Машина({this.Id})
Марка: {this.make}
Модель: {this.model}
Мощность(л.с.): {this.power}
Объем двигателя(л): {this.engine_capacity}
Год производства: {this.production_year}");
        }
    }
}
