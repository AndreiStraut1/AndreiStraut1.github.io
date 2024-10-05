using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading.Tasks;
using static System.Windows.Forms.VisualStyles.VisualStyleElement.ListView;
using System.Xml.Linq;

namespace AutoPark
{
    public class Car
    {
        public int Id { get; set; }
        public string Model { get; set; }
        public string Color { get; set; }
        public int Year { get; set; }
        public int Price {  get; set; }
        public string Engine { get; set; }
        public Car() { }
        public Car(int id, string model, string color, int year, int price, string engine)
        {
            Id = id;
            Model = model;
            Color = color;
            Year = year;
            Price = price;
            Engine = engine;
        }
        public override string ToString()
        {
            return $"{Id}; {Model}; {Color}; {Year}; {Price}; {Engine}";
        }

        public override bool Equals(object obj)
        {
            if (obj == null) return false;

            if (obj == this) return true;

            if (!(obj is Car)) 
            {
                return false;
            }

            Car car = obj as Car;

            return Id == car.Id &&
                   Model == car.Model &&
                   Color == car.Color &&
                   Year == car.Year &&
                   Price == car.Price &&
                   Engine == car.Engine;

        }

    }
}
