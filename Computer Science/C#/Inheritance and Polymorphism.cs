using System;

namespace Inheritance_and_Polymorphism
{
    class Program
    {
        private static void Main(string[] args)
        {
            Character character = new Character();
            character.Name = "Kamil";
            character.Age = 19u;
            //character.LightSaberSkill = 0u;
            //character.ForceSkill = 0u;
            //character.PresentCharacter();
            Console.WriteLine();

            Jedi jedi = new Jedi("", 0u, 0u, 0u);
            jedi.Name = "Anakin Skywalker";
            jedi.Age = 22u;
            jedi.LightSaberSkill = 8u;
            jedi.ForceSkill = 9u;
            jedi.PresentJedi();
            Console.WriteLine();

            Console.WriteLine($"Number of created characters: {Character.Counter}");
            Console.WriteLine($"Number of created jedis: {Jedi.Counter}");
            Console.WriteLine();

            Shape shape = new Shape();
            shape.PresentShape();
            Console.WriteLine();

            Triangle triangle = new Triangle(3.0, 4.0, 5.0);
            triangle.PresentShape();
            Console.WriteLine();

            Shape shapeTriangle = new Triangle(6.0, 8.0, 10.0);
            shapeTriangle.PresentShape();
            Console.WriteLine();

            //Triangle triangleShape = new Shape();

            Circle circle = new Circle(Math.PI);
            circle.PresentShape();
            Console.WriteLine();

            Shape shapeCircle = new Circle(Math.E);
            shapeCircle.PresentShape();
            Console.WriteLine();

            //Circle circleShape = new Shape();

            Shape[] shapes = { shape, triangle, shapeTriangle, circle, shapeCircle };

            foreach (var item in shapes)
            {
                item.PresentShape();
            }
            Console.WriteLine();

            //Transformer transformer = new Transformer();

            Autobot autobot = new Autobot();
            autobot.Present();
            Console.WriteLine();

            Transformer transformerAutobot = new Autobot();
            transformerAutobot.Present();
            Console.WriteLine();

            Decepticon decepticon = new Decepticon();
            decepticon.Name = "Megatron";
            decepticon.Color = "Gray";
            decepticon.Planet = "Cybertron";
            Decepticon.PresentDecepticon(decepticon);
            Console.WriteLine();

            decepticon.ChangeColor("Pink");
            decepticon.InhabitNewPlanet("Earth");
            Decepticon.PresentDecepticon(decepticon);
            Console.WriteLine();

            Car.Engine carEngine = new Car.Engine("Diesel");
            Car car = new Car("Chevrolet", "Aveo", carEngine);
            car.PresentCar();
            car.Start();
            Console.WriteLine();

            Console.ReadKey();
        }
    }

    class Character
    {
        public string Name { get; set; }

        public uint Age { get; set; }

        public static uint Counter { get; private set; }

        static Character()
        {
            Counter = 0;
        }

        public Character()
        {
            Console.WriteLine("Character constructor has been called.");
            Counter++;
        }

        protected void PresentCharacter()
        {
            Console.WriteLine($"Name: {this.Name}");
            Console.WriteLine($"Age: {this.Age}");
        }
    }

    sealed class Jedi : Character
    {
        public uint LightSaberSkill { get; set; }

        public uint ForceSkill { get; set; }

        public Jedi(string name, uint age, uint lightSaberSkill, uint forceSkill)
        {
            Console.WriteLine("Jedi constructor has been called.");
            this.Name = name;
            this.Age = age;
            this.LightSaberSkill = lightSaberSkill;
            this.ForceSkill = forceSkill;
        }

        public void PresentJedi()
        {
            this.PresentCharacter();
            Console.WriteLine($"Light saber skill: {this.LightSaberSkill}");
            Console.WriteLine($"Force skill: {this.ForceSkill}");
        }
    }

    class Shape
    {
        public virtual double Perimeter
        {
            get
            {
                return 0.0;
            }
        }

        public virtual double Area
        {
            get
            {
                return 0.0;
            }
        }

        public virtual void PresentShape()
        {
            Console.WriteLine("This shape is undefined.");
            Console.WriteLine($"Perimeter: {this.Perimeter}");
            Console.WriteLine($"Area: {this.Area}");
        }
    }

    class Triangle : Shape
    {
        public double A { get; private set; }

        public double B { get; private set; }

        public double C { get; private set; }

        public override double Perimeter
        {
            get
            {
                return A + B + C;
            }
        }

        public override double Area
        {
            get
            {
                double p = (A + B + C) / 2;
                return Math.Sqrt(p * (p - A) * (p - B) * (p - C));
            }
        }

        public Triangle(double a, double b, double c)
        {
            bool triangle = true;

            if (a > 0.0 && b > 0.0 && c > 0.0)
            {
                if (a + b > c && a + c > b && b + c > a)
                {
                    this.A = a;
                    this.B = b;
                    this.C = c;
                }
                else
                {
                    Console.WriteLine("Triangle inequality theorem is not met.");
                    triangle = false;
                }
            }
            else
            {
                Console.WriteLine("Triangle side is less than or equal to 0.");
                triangle = false;
            }

            if (!triangle)
            {
                this.A = this.B = this.C = 1.0;
                Console.WriteLine("Default values have been assigned.");
            }
        }

        public override void PresentShape()
        {
            Console.WriteLine("This shape is a triangle.");
            Console.WriteLine($"Perimeter: {this.Perimeter}");
            Console.WriteLine($"Area: {this.Area}");
        }
    }

    class Circle : Shape
    {
        public double R { get; private set; }

        public override double Perimeter
        {
            get
            {
                return 2 * Math.PI * R;
            }
        }

        public override double Area
        {
            get
            {
                return Math.PI * R * R;
            }
        }

        public Circle(double r)
        {
            this.R = (r > 0.0) ? r : 1.0;
        }

        public override void PresentShape()
        {
            Console.WriteLine("This shape is a circle.");
            Console.WriteLine($"Perimeter (circumference): {this.Perimeter}");
            Console.WriteLine($"Area: {this.Area}");
        }
    }

    abstract class Transformer
    {
        public abstract string Race { get; }

        public abstract void Present();
    }

    class Autobot : Transformer
    {
        public override string Race
        {
            get
            {
                return "Autobot";
            }
        }

        public override void Present()
        {
            Console.WriteLine($"Race: {this.Race}");
        }
    }

    interface IRobot
    {
        string Name { get; set; }

        string Color { get; set; }

        void ChangeColor(string color);
    }

    interface IAlien
    {
        string Name { get; set; }

        string Planet { get; set; }

        void InhabitNewPlanet(string planet);
    }

    class Decepticon : IRobot, IAlien
    {
        public string Name { get; set; }

        public string Color { get; set; }

        public string Planet { get; set; }

        public void ChangeColor(string color)
        {
            this.Color = color;
        }

        public void InhabitNewPlanet(string planetName)
        {
            this.Planet = planetName;
        }

        public static void PresentDecepticon(Decepticon decepticon)
        {
            Console.WriteLine($"Name: {decepticon.Name}");
            Console.WriteLine($"Color: {decepticon.Color}");
            Console.WriteLine($"Planet: {decepticon.Planet}");
        }
    }

    class Car
    {
        public string Make { get; private set; }

        public string Name { get; private set; }

        public Engine CarEngine { get; private set; }

        public Car(string make, string name, Engine carEngine)
        {
            this.Make = make;
            this.Name = name;
            this.CarEngine = carEngine;
        }

        public void PresentCar()
        {
            Console.WriteLine($"Make: {this.Make}");
            Console.WriteLine($"Name: {this.Name}");
            Console.WriteLine($"Car engine type: {this.CarEngine.Type}");
        }

        public void Start()
        {
            this.CarEngine.Start();
            Console.WriteLine("Good to go.");
        }

        public class Engine
        {
            public string Type { get; private set; }

            public Engine(string type)
            {
                this.Type = type;
            }

            public void Start()
            {
                Console.WriteLine("Brum, brum.");
            }
        }
    }
}

// Parent Constructor -> Child Constructor -> Child Destructor -> Parent Destructor