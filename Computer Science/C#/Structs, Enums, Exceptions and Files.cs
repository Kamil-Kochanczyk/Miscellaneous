using System;
using System.IO;

namespace Structs_Enums_Exceptions_and_Files
{
    public class Program
    {
        enum DLC { HeartsOfStone = 1, BloodAndWine };

        private static void Main(string[] args)
        {
            Game emptyGame1;
            Game emptyGame2 = new Game();

            Game sc = new Game("Sonic Colors");
            emptyGame1 = sc;

            Game sg = new Game("Sonic Generations");
            emptyGame2 = sg;

            Console.WriteLine(emptyGame1.title);
            Console.WriteLine(emptyGame2.title);
            Console.WriteLine();

            Game.DescribeStruct();
            Console.WriteLine();

            Console.WriteLine($"{DLC.HeartsOfStone} = {(int)DLC.HeartsOfStone}");
            Console.WriteLine($"{DLC.BloodAndWine} = {(int)DLC.BloodAndWine}");
            Console.WriteLine("Which one do you choose - 1 or 2?");

            try
            {
                int chosenIndex = int.Parse(Console.ReadLine());
                DLC chosenDLC = (DLC)chosenIndex;

                switch (chosenDLC)
                {
                    case DLC.HeartsOfStone:
                        Console.WriteLine("You chose Hearts of Stone.");
                        break;
                    case DLC.BloodAndWine:
                        Console.WriteLine("You chose Blood and Wine.");
                        break;
                    default:
                        Console.WriteLine("Wrong input. Please try again.");
                        break;
                }
            }
            catch (FormatException fe)
            {
                Console.WriteLine("FormatException fe");
                Console.WriteLine(fe.Message);
            }
            catch (Exception e)
            {
                Console.WriteLine("Exception e");
                Console.WriteLine(e.Message);
            }
            finally
            {
                Console.WriteLine("This is text in finally block.");
            }

            Console.WriteLine("This is text after finally block.");

            Console.WriteLine();

            Console.ReadKey();
        }
    }

    public struct Game
    {
        public readonly string title;

        public Game(string title)
        {
            this.title = title;
        }

        public static void DescribeStruct()
        {
            Console.WriteLine("Struct:");
            Console.WriteLine("- value type");
            Console.WriteLine("- doesn't support inheritance and polymorphism");
            Console.WriteLine("- new keyword is not required");
            Console.WriteLine("- parameterless constructor cannot be defined");
            Console.WriteLine("- simpler, smaller and faster than class (mini version of class)");
            Console.WriteLine("- used usually for not complicated operations that don't change values");
        }
    }
}