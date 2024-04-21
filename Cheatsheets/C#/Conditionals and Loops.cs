using System;

namespace Conditionals_and_Loops
{
    class Program
    {
        static void Main()
        {
            int x;
            bool booleanVariable;

            x = 10;
            booleanVariable = (x < 8) && (++x > 5);
            Console.WriteLine($"x = {x}, booleanVariable = {booleanVariable}");

            x = 10;
            booleanVariable = (x < 8) & (++x > 5);
            Console.WriteLine($"x = {x}, booleanVariable = {booleanVariable}");

            x = 10;
            booleanVariable = (x >= 8) || (++x <= 5);
            Console.WriteLine($"x = {x}, booleanVariable = {booleanVariable}");

            x = 10;
            booleanVariable = (x >= 8) | (++x <= 5);
            Console.WriteLine($"x = {x}, booleanVariable = {booleanVariable}");

            x = 10;
            booleanVariable = (!(x == 520) && (x != 69)) || (x == 42);
            Console.WriteLine($"x = {x}, booleanVariable = {booleanVariable}");

            Console.WriteLine();

            string language;
            Console.WriteLine("What is your favourite programming language?");
            language = Console.ReadLine();
            if (language == "C#")
            {
                Console.WriteLine("This is my favourite programming language too!");
            }
            Console.WriteLine();

            string instrument;
            Console.WriteLine("What is your favourite musical instrument?");
            instrument = Console.ReadLine();
            if (instrument == "Violin" || instrument == "Cello" || instrument == "Erhu")
            {
                Console.WriteLine("This is my favourite musical instrument too!");
            }
            else
            {
                Console.WriteLine("Nice!");
            }
            Console.WriteLine();

            byte part;
            string title;

            Console.WriteLine("Which part of \'The Chronicles of Narnia\' film series do you choose? (1-3)");
            part = byte.Parse(Console.ReadLine());

            if (part == 1)
            {
                title = "The Chronicles of Narnia: The Lion, the Witch and the Wardrobe";
            }
            else if (part == 2)
            {
                title = "The Chronicles of Narnia: Prince Caspian";
            }
            else if (part == 3)
            {
                title = "The Chronicles of Narnia: The Voyage of the Dawn Treader";
            }
            else
            {
                title = String.Empty;
            }

            if (title != String.Empty)
            {
                Console.WriteLine($"You chose part {part}, which is \'{title}\'.");

                if (title == "The Chronicles of Narnia: The Lion, the Witch and the Wardrobe")
                {
                    Console.WriteLine("This is my favourite part of the film series!");
                }
            }
            else
            {
                Console.WriteLine("Something's wrong!");
            }

            Console.WriteLine();

            Console.WriteLine("Which part of \'The Chronicles of Narnia\' book series do you choose? (1-7)");
            part = Convert.ToByte(Console.ReadLine());

            switch (part)
            {
                case 1:
                    title = "The Lion, the Witch and the Wardrobe";
                    break;
                case 2:
                    title = "Prince Caspian";
                    break;
                case 3:
                    title = "The Voyage of the Dawn Treader";
                    break;
                case 4:
                    title = "The Silver Chair";
                    break;
                case 5:
                    title = "The Horse and His Boy";
                    break;
                case 6:
                    title = "The Magician's Nephew";
                    break;
                case 7:
                    title = "The Last Battle";
                    break;
                default:
                    title = String.Empty;
                    break;
            }

            if (title != String.Empty)
            {
                Console.WriteLine($"You chose part {part}, which is \'{title}\'.");

                if (title == "The Voyage of the Dawn Treader")
                {
                    Console.WriteLine("This is my favourite part of the book series!");
                }
            }
            else
            {
                Console.WriteLine("Something's wrong!");
            }

            Console.WriteLine();

            char portion;
            float price = 0f;
            Console.WriteLine("Choose a portion of ice cream.\nS - Small\nM - Medium\nL - Large");
            portion = char.Parse(Console.ReadLine());
            switch (portion)
            {
                case 'S':
                case 's':
                    price += 5.55f;
                    break;
                case 'M':
                case 'm':
                    price += 8.88f;
                    goto case 'S';
                case 'L':
                case 'l':
                    price += 10.10f;
                    goto case 'S';
                default:
                    price = '\0';
                    break;
            }
            if (price != '\0')
            {
                Console.WriteLine($"You have to pay {price} for that portion.");
            }
            else
            {
                Console.WriteLine("Something's wrong!");
            }
            Console.WriteLine();

            double number;
            string description;
            Console.WriteLine("Write any number.");
            number = double.Parse(Console.ReadLine());
            description = (number == 0) ? "zero" : ((number < 0) ? "negative" : "positive");
            Console.WriteLine($"Your number is {description}.");
            Console.WriteLine();

            byte rows;
            Console.WriteLine("Enter number of rows.");
            rows = byte.Parse(Console.ReadLine());
            for (int i = 1; i <= rows; i++)
            {
                for (int j = 1; j <= rows + i - 1; j++)
                {
                    if (j > rows - i)
                    {
                        Console.Write("*");
                    }
                    else
                    {
                        Console.Write(" ");
                    }
                }
                Console.WriteLine();
            }
            Console.WriteLine();

            Random r = new Random();
            int sum = 0, counter = 0;
            while (sum < 1000000)
            {
                sum += r.Next(0, 1000000);
                counter++;
            }
            Console.WriteLine($"It took {counter} iterations to get sum of random numbers greater than or equal to 1000000.");
            Console.WriteLine();

            uint accountBalance = 1000000u, withdrawnMoney = 0u, wantedMoney;
            Console.WriteLine("To exit the loop enter 0 or take all the money.");
            Console.WriteLine();
            do
            {
                Console.WriteLine("How much money do you want?");
                wantedMoney = uint.Parse(Console.ReadLine());

                if (wantedMoney > accountBalance)
                {
                    wantedMoney = accountBalance;
                }

                withdrawnMoney += wantedMoney;
                Console.WriteLine($"Withdrawn money: {withdrawnMoney}");

                accountBalance -= wantedMoney;
                Console.WriteLine($"Account balance: {accountBalance}");

                Console.WriteLine();
            } while (wantedMoney != 0u && accountBalance > 0u);

            int y = 0;
            for (; y <= 9; )
            {
                if (y == 7)
                {
                    break;
                }
                Console.Write(y);
                y++;
            }
            Console.WriteLine();

            for (int z = 0, _z0 = 9; z <= 9 && _z0 >= 0; z++, _z0--)
            {
                if (z == 7 || _z0 == 7)
                {
                    continue;
                }
                Console.Write(z);
                Console.Write(_z0);
            }
            Console.WriteLine();

            Console.ReadKey();
        }
    }
}