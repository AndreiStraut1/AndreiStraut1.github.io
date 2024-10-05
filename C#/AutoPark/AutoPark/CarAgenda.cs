using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AutoPark
{
    public class CarAgenda
    {
        public List<Car> Cars;
        public CarAgenda() 
        {
            Cars = new List<Car>();
        }

        public void Add(Car car) 
        {
            if (!Cars.Contains(car))
            {
                Cars.Add(car); 
            }
        }

        public void Remove(Car car)
        {
            if(Cars.Contains(car))
            {
                Cars.Remove(car);
            }
        }

        public override string ToString()
        {
            string result = string.Empty; //""

            foreach (Car contact in Cars)
            {
                result = result + contact.ToString() + "\n";
            }

            return result;
        }

        public void SaveOnDisk()
        {
            File.WriteAllText("CarAgenda.txt", this.ToString());
            
        }

        public void LoadFromDisk()
        {
            if (File.Exists("CarAgenda.txt"))
            {
                Cars.Clear();

                var text = File.ReadAllText("CarAgenda.txt");

                var lines = text.Split('\n'); //toate liniile
                //$"{Id}; {Name}; {Email}; {Phone}; {Address}";
                foreach (var carText in lines)
                {

                    var values = carText.Split(new char[] { ';' });

                    if (values.Length != 6) { continue; }

                    Car car = new Car();
                    car.Id = int.Parse(values[0]);
                    car.Model = values[1].Trim();
                    car.Color = values[2].Trim();
                    car.Year = int.Parse(values[3]);
                    car.Price = int.Parse(values[4]);
                    car.Engine = values[5].Trim();
                    Cars.Add(car);
                }
            }
        }
    }
}
