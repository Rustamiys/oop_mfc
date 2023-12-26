using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.ConstrainedExecution;
using System.Runtime.Remoting.Lifetime;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace lr5
{
    [Serializable]
    internal class Program
    {
        static void Main(string[] args)
        {;
            Warehouse Warehouse = new Warehouse();
            while (true)
            {
                Console.WriteLine("1) Добавить машину\n2) Удалить\n3) Очистить все\n4) Вывести все\n5) Сохранить\n6) Загрузить\n0)Выход");
                Console.Write("Выберите пункт: ");

                string input_text = Console.ReadLine();
                int num = int.TryParse(input_text, out num) ? num : -1;

                switch (num)
                {
                    case 0:
                        return;
                    case 1:
                        Console.WriteLine("1) Новая машина\n2) Б/у машины");
                        Console.Write("Выберите: ");
                        input_text = Console.ReadLine();
                        num = int.TryParse(input_text, out num) ? num : -1;
                        if (num == 1 || num == 2)
                        {
                            int empty;
                            Console.Write("Введите марку: ");
                            string make = Console.ReadLine();
                            empty = String.IsNullOrEmpty(make) ? 0 : 1;
                            Console.Write("Введите модель: ");
                            string model = Console.ReadLine();
                            empty = (empty == 0 || String.IsNullOrEmpty(model)) ? 0 : 1;
                            Console.Write("Введите мощнсть(л.с.): ");
                            input_text = Console.ReadLine();
                            int power = int.TryParse(input_text, out power) ? power : -1;
                            Console.Write("Введите объем двигателя: ");
                            input_text = Console.ReadLine();
                            double engine_capacity = double.TryParse(input_text, out engine_capacity) ? engine_capacity : -1;
                            Console.Write("Введите год производства: ");
                            input_text = Console.ReadLine();
                            int production_year = int.TryParse(input_text, out production_year) ? production_year : -1;
                            if (num == 1)
                            {
                                if (empty == 0 || power <= 0 || engine_capacity <= 0 || engine_capacity >= 10 ||
                                    production_year <= 1885 || production_year >= 2023) { Console.WriteLine("Неправильный ввод"); break; }
                                Car car = new Car(make, model, power, engine_capacity, production_year);
                                Warehouse.AddCar(car);
                            }
                            else
                            {
                                Console.Write("Введите количество владельцев: ");
                                input_text = Console.ReadLine();
                                int number_of_owners = int.TryParse(input_text, out number_of_owners) ? number_of_owners : -1;
                                Console.Write("Введите пробег: ");
                                input_text = Console.ReadLine();
                                double mileage = double.TryParse(input_text, out mileage) ? mileage : -1;
                                if (empty == 0 || power <= 0 || engine_capacity <= 0 || engine_capacity >= 10 || production_year <= 1885 || production_year >= 2023
                                    || number_of_owners < 2 || mileage < 1) { Console.WriteLine("Неправильный ввод"); break; }
                                UsedCar car = new UsedCar(make, model, power, engine_capacity, production_year, number_of_owners, mileage);
                                Warehouse.AddCar(car);
                            }
                            Console.WriteLine("Машина добавлена");
                        }
                        else
                        {
                            Console.WriteLine("Неправильный ввод");
                        }
                        break;
                    case 2:
                        if (Warehouse.warehouse.Count() == 0)
                        {
                            Console.WriteLine("Список пустой");
                            break;
                        }
                        Console.WriteLine($"Всего машин {Warehouse.warehouse.Count()}\nВведите Id машины, которую хотите удалить: ");
                        input_text = Console.ReadLine();
                        int Id = int.TryParse(input_text, out Id) ? Id : -1;
                        Warehouse.RemoveCar(Id);
                        break;
                    case 3:
                        Warehouse.Clear();
                        Console.WriteLine("Список очищен");
                        break;
                    case 4:
                        Warehouse.Print();
                        break;
                    case 5:
                        Console.Write("Введите название файла: ");
                        string fileNameSave = Console.ReadLine();
                        if (!String.IsNullOrEmpty(fileNameSave)) { Warehouse.Save(fileNameSave); }
                        else { Console.WriteLine("Неправильный ввод"); }
                        break;
                    case 6:
                        Console.Write("Введите название файла: ");
                        string fileNameLoad = Console.ReadLine();
                        if (!String.IsNullOrEmpty(fileNameLoad)) { Warehouse.Load(fileNameLoad); }
                        else { Console.WriteLine("Неправильный ввод"); }
                        break;
                        
                    default: Console.WriteLine("Попробуйте еще раз"); break;
                }
                Console.ReadKey();
                Console.Clear();
            }


        }
    }
}
