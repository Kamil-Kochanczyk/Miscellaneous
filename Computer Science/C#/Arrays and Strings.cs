using System;

namespace Arrays_and_Strings
{
    class Program
    {
        private static void Main(string[] args)
        {
            string[] bookTitles;
            bookTitles = new string[7];
            bookTitles[0] = "The Lion, the Witch and the Wardrobe";
            bookTitles[1] = "Prince Caspian";
            bookTitles[2] = "The Voyage of the Dawn Treader";
            bookTitles[3] = "The Silver Chair";
            bookTitles[4] = "The Horse and His Boy";
            bookTitles[5] = "The Magician's Nephew";
            bookTitles[6] = "The Last Battle";
            Console.WriteLine(bookTitles[2]);
            Console.WriteLine();

            string[] movieTitles = new string[3];
            movieTitles[0] = "The Chronicles of Narnia: The Lion, the Witch and the Wardrobe";
            movieTitles[1] = "The Chronicles of Narnia: Prince Caspian";
            movieTitles[2] = "The Chronicles of Narnia: The Voyage of the Dawn Treader";
            Console.WriteLine(movieTitles[0]);
            Console.WriteLine();

            short[] favouriteNumbers = new short[8] { 520, 69, 42, 10, 8, 6, 5, 3 };
            char[] favouriteLetters = new char[] { 'C', 'D', 'E', 'K' };
            string[] favouriteInstruments = { "Violin", "Cello", "Erhu" };

            for (int i = 0; i < 8; i++)
            {
                Console.WriteLine(favouriteNumbers[i]);
            }
            Console.WriteLine();

            for (int i = 1; i <= favouriteLetters.Length; i++)
            {
                Console.WriteLine(favouriteLetters[i - 1]);
            }
            Console.WriteLine();

            foreach (var instrument in favouriteInstruments)
            {
                Console.WriteLine(instrument);
            }
            Console.WriteLine();

            char[,] tictactoe = { { 'O', 'O', 'X' }, { 'O', 'X', 'O' }, { 'X', 'O', 'O' } };    // [3, 3]
            int[,,] randomArray = { { { -520, -69, -42, -10 } }, { { -8, -6, -5, -3 } } };  // [2, 1, 4]

            for (int i = 0; i < tictactoe.GetLength(0); i++)
            {
                for (int j = 0; j < tictactoe.GetLength(1); j++)
                {
                    Console.Write(tictactoe[i, j]);
                }
                Console.WriteLine();
            }
            Console.WriteLine();

            foreach (var number in randomArray)
            {
                Console.WriteLine(number);
            }
            Console.WriteLine();

            string[][] children =
            {
                new string[] { "Peter", "Susan", "Edmund", "Lucy" },
                new string[] { "Peter", "Susan", "Edmund", "Lucy" },
                new string[] { "Edmund", "Lucy", "Eustace" },
                new string[] { "Eustace", "Jill" },
                new string[] { "Shasta", "Aravis" },
                new string[] { "Digory", "Polly" },
                new string[] { "Eustace", "Jill" }
            };

            foreach (var array in children)
            {
                foreach (var child in array)
                {
                    Console.WriteLine(child);
                }
            }
            Console.WriteLine();

            byte[][,] ratingsAndPositions =
            {
                new byte[,] { { 8, 1 }, { 7, 2 }, { 7, 3 } },
                new byte[,] { { 7, 4 }, { 7, 5 } },
                new byte[,] { { 6, 6 }, { 5, 7 } }
            };

            for (int i = 0; i < ratingsAndPositions.Length; i++)
            {
                for (int j = 0; j < ratingsAndPositions[i].GetLength(0); j++)
                {
                    for (int k = 0; k < ratingsAndPositions[i].GetLength(1); k++)
                    {
                        Console.Write(ratingsAndPositions[i][j, k]);
                    }
                    Console.WriteLine();
                }
                Console.WriteLine();
            }
            Console.WriteLine();

            int[,,][] insaneJaggedArray =
            {
                {
                    {
                        new int[] { 520, 69, 42 },
                        new int[] { 10, 8, 6 },
                        new int[] { 5, 3 }
                    },
                    {
                        new int[] { -520, -69, -42 },
                        new int[] { -10, -8, -6 },
                        new int[] { -5, -3 }
                    }
                },
                {
                    {
                        new int[] { 520, 69, 42 },
                        new int[] { 10, 8, 6 },
                        new int[] { 5, 3 }
                    },
                    {
                        new int[] { -5, -3 },
                        new int[] { -10, -8, -6 },
                        new int[] { -520, -69, -42 }
                    }
                },
                {
                    {
                        new int[] { 520, 69, 42 },
                        new int[] { 10, 8, 6 },
                        new int[] { 5, 3 }
                    },
                    {
                        new int[] { 0 },
                        new int[] { 0, 0 },
                        new int[] { 0, 0, 0 }
                    }
                }
            };

            for (int i = 0; i < insaneJaggedArray.GetLength(0); i++)
            {
                for (int j = 0; j < insaneJaggedArray.GetLength(1); j++)
                {
                    for (int k = 0; k < insaneJaggedArray.GetLength(2); k++)
                    {
                        foreach (var number in insaneJaggedArray[i, j, k])
                        {
                            Console.Write(number);
                        }
                        Console.WriteLine();
                    }
                    Console.WriteLine();
                }
                Console.WriteLine();
            }
            Console.WriteLine();

            string text1 = "string <=> char[]";
            for (int i = 0; i < text1.Length; i++)
            {
                Console.WriteLine(text1[i]);
            }
            Console.WriteLine();

            string text2 = "Strings are arrays of characters.";
            foreach (char letter in text2)
            {
                Console.WriteLine(letter);
            }
            Console.WriteLine();

            Console.ReadKey();
        }
    }
}