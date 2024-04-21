using System;

namespace BasicConcepts
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello world!");

            string myName;
            myName = "Kamil";
            Console.WriteLine("My name is " + myName + ".");    // Concatenation

            byte myAge = 19;
            Console.WriteLine("I am {0} years old.", myAge);    // Placeholder

            char character1 = 'C', character2;
            character2 = '#';
            Console.WriteLine($"My favourite programming language is {character1}{character2}.");   // Interpolation

            Console.WriteLine();

            string userName;
            Console.Write("Enter your name: ");
            userName = Console.ReadLine();
            Console.WriteLine($"Hello {userName}, nice to meet you!");

            Console.WriteLine();

            var unknownVariable = false;
            Console.WriteLine(unknownVariable);

            Console.WriteLine();

            const double e = 2.7182818284;
            Console.WriteLine($"e = {e}");

            Console.WriteLine();

            Console.WriteLine(69 + 42);
            Console.WriteLine(69 - 42);
            Console.WriteLine(69 * 42);
            Console.WriteLine(69 / 42);
            Console.WriteLine(69d / 42D);
            Console.WriteLine((int)(69.0 / 42.0));
            Console.WriteLine(69 % 42);

            Console.WriteLine();

            int x = 520;
            x += 69;
            x -= 42;
            x *= 10;
            x /= 8;
            x %= 5;
            Console.WriteLine($"x = {x}");

            Console.WriteLine();

            int y, z;
            y = 69;
            z = 42;
            Console.WriteLine($"Preincrementation: y = {++y}\nPredecrementation: z = {--z}");
            Console.WriteLine($"Postincrementation: y = {y++}\nPostdecrementation: z = {z--}");

            Console.WriteLine();

            Console.ReadKey();
        }
    }
}

// .NET Framework = CLR + FCL

/* Built-in data types:
 * bool
 * byte
 * sbyte
 * short
 * ushort
 * int
 * uint
 * long
 * ulong
 * float
 * double
 * decimal
 * char
 * string
*/

/* Suffixes:
 * uint - u/U
 * long - l/L
 * ulong - ul/UL
 * float - f/F
 * decimal - m/M
*/