using System;

namespace Methods
{
    class Program
    {
        private static void Main(string[] args)
        {
            WriteMethodDefinition();
            Console.WriteLine();

            byte age;
            bool isAdult;
            Console.WriteLine("How old are you?");
            age = byte.Parse(Console.ReadLine());
            isAdult = CheckIfSomeoneIsAdult(age);
            if (isAdult)
            {
                Console.WriteLine("You're adult.");
            }
            else
            {
                Console.WriteLine("You're not adult.");
            }
            Console.WriteLine();

            Calculate(520d, 69d);
            Calculate(42d, 10d, '-');
            Calculate(operation: '*', y: 5d, x: 8d);
            Calculate(-6d, -3d, '/');
            Calculate(0d, 0d, '/');
            Calculate(0.123456789, 0.123456789, '^');
            Console.WriteLine();

            int xValue = 10, yValue = 8, zValue = 5;
            PassByValue(xValue, yValue, zValue);
            Console.WriteLine($"xValue = {xValue}, yValue = {yValue}, zValue = {zValue}");

            int xRef = 10, yRef = 8, zRef = 5;
            PassByRef(ref xRef, ref yRef, ref zRef);
            Console.WriteLine($"xRef = {xRef}, yRef = {yRef}, zRef = {zRef}");

            int xOut, yOut, zOut;
            PassByOut(out xOut, out yOut, out zOut);
            Console.WriteLine($"xOut = {xOut}, yOut = {yOut}, zOut = {zOut}");

            Console.WriteLine();

            OverloadedMethod('C');
            OverloadedMethod("C");
            Console.WriteLine();

            int x, y, gcd;
            Console.WriteLine("Enter two integer numbers. None of them can be equal to 0.");
            Console.Write("x = ");
            x = int.Parse(Console.ReadLine());
            Console.Write("y = ");
            y = int.Parse(Console.ReadLine());
            gcd = GreatestCommonDivisor(x, y);
            Console.WriteLine($"gcd(x, y) = gcd({x}, {y}) = {gcd}");
            Console.WriteLine();

            Console.ReadKey();
        }

        public static void WriteMethodDefinition()
        {
            Console.WriteLine("[Modifiers] Type Name([Arguments])");
            Console.WriteLine("{\n\t[Body]\n}");
        }

        public static bool CheckIfSomeoneIsAdult(byte age)
        {
            return ((age >= 18) ? true : false);
        }

        public static void Calculate(double x, double y, char operation = '+')
        {
            switch (operation)
            {
                case '+':
                    Console.WriteLine($"{x} + {y} = {x + y}");
                    break;
                case '-':
                    Console.WriteLine($"{x} - {y} = {x - y}");
                    break;
                case '*':
                    Console.WriteLine($"{x} * {y} = {x * y}");
                    break;
                case '/':
                    if (y != 0)
                    {
                        Console.WriteLine($"{x} / {y} = {x / y}");
                    }
                    else
                    {
                        Console.WriteLine("Dividing by zero is undefined.");
                    }
                    break;
                default:
                    Console.WriteLine("Wrong operation.");
                    break;
            }
        }

        public static void PassByValue(int x, int y, int z)
        {
            x = 520;
            y = 69;
            z = 42;
        }

        public static void PassByRef(ref int x, ref int y, ref int z)
        {
            x = 520;
            y = 69;
            z = 42;
        }

        public static void PassByOut(out int x, out int y, out int z)
        {
            x = 520;
            y = 69;
            z = 42;
        }

        public static void OverloadedMethod(char input)
        {
            Console.WriteLine("You called char verion.");
            Console.WriteLine($"input = \'{input}\'");
        }

        public static void OverloadedMethod(string input)
        {
            Console.WriteLine("You called string version.");
            Console.WriteLine($"input = \"{input}\"");
        }

        public static int GreatestCommonDivisor(int x, int y)
        {
            if (x % y == 0)
            {
                return Math.Abs(y);
            }
            else
            {
                return GreatestCommonDivisor(y, x % y);
            }
        }
    }
}

/* Access modifiers:
 * public
 * private
 * protected
 * internal
 * protected internal
 * private protected
*/

/* Behaviour modifiers:
 * static
 * new
 * virtual
 * override
 * sealed
 * abstract
*/