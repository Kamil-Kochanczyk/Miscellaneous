using System;
using System.Collections.Generic;

namespace Generics
{
    class Program
    {
        private static void Main(string[] args)
        {
            GenericClass<char, string> randomObject = new GenericClass<char, string>();
            randomObject.ShowTypes();
            Console.WriteLine();

            Console.WriteLine(CheckIfSameTypes<int, int>());
            Console.WriteLine(CheckIfSameTypes<int, uint>());
            Console.WriteLine(CheckIfSameTypes<int, double>());
            Console.WriteLine();

            Console.WriteLine("Generic collections:");
            Console.WriteLine("- List<T>: resizable array");
            Console.WriteLine("- Dictionary<T Key, U Value>: set of key-value pairs");
            Console.WriteLine("- SortedList<T Key, U Value>: set of key-value pairs sorted by keys");
            Console.WriteLine("- Stack<T>: last in, first out (LIFO)");
            Console.WriteLine("- Queue<T>: first in, first out (FIFO)");
            Console.WriteLine("- Hashset<T>: set of some values");
            Console.WriteLine();

            Console.ReadKey();
        }

        public static bool CheckIfSameTypes<T, U>()
        {
            return typeof(T) == typeof(U);
        }
    }

    class GenericClass<T, U>
    {
        public void ShowTypes()
        {
            Console.WriteLine($"T: {typeof(T)}");
            Console.WriteLine($"U: {typeof(U)}");
        }
    }
}