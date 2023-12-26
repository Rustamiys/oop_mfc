using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace lr5
{
    [Serializable]
    public class Warehouse
    {
        public List<Car> warehouse = new List<Car>();
        public void AddCar(Car car)
        {
            car.Id = warehouse.Count == 0 ? 1 : warehouse[warehouse.Count - 1].Id + 1;
            warehouse.Add(car);
        }
        public void RemoveCar(int id)
        {
            bool flag = true;
            for (int i = 0; i < warehouse.Count; i++)
            {
                if (warehouse[i].Id == id)
                {
                    flag = false;
                    warehouse.RemoveAt(i);
                    break;
                }
            }
            if (flag)
            {
                Console.WriteLine("Нет такой машины!");
            }
        }
        public void Print()
        {
            for (int i = 0; i < warehouse.Count; i++)
            {
                warehouse[i].Print();
            }
        }
        public void Save(string fileName)
        {
            XmlSerializer serializer = new XmlSerializer(typeof(List<Car>));
            try
            {
                using (FileStream fs = new FileStream(fileName + ".xml", FileMode.Create))
                {
                    serializer.Serialize(fs, warehouse);
                }
                Console.WriteLine("Успешно");
            }
            catch
            {
                Console.WriteLine("Возникли ошибки");
            }

        }
        public void Load(string fileName)
        {
            warehouse.Clear();
            XmlSerializer serializer = new XmlSerializer(typeof(List<Car>));
            try
            {
                using (FileStream fs = new FileStream(fileName + ".xml", FileMode.Open))
                {
                    warehouse = (List<Car>)serializer.Deserialize(fs);
                }
                Console.WriteLine("Успешно");
            }
            catch
            {
                Console.WriteLine("Возникли ошибки");
            }
        }
        public void Clear()
        {
            warehouse.Clear();
        }
    }
}
