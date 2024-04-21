using System;

namespace Classes_and_Objects
{
    class Program
    {
        private static void Main(string[] args)
        {
            Book tvotdt = new Book();

            tvotdt.author = "Clive Staples Lewis";
            Console.WriteLine($"Author: {tvotdt.author}");

            tvotdt.Title = "The Voyage of the Dawn Treader";
            Console.WriteLine($"Title: {tvotdt.Title}");

            Console.WriteLine($"Pages: {tvotdt.Pages}");
            tvotdt.Pages = 248;
            Console.WriteLine($"Pages: {tvotdt.Pages}");
            tvotdt.Pages = -248;
            Console.WriteLine($"Pages: {tvotdt.Pages}");

            tvotdt.Year = 1952;
            Console.WriteLine($"Publication year: {tvotdt.Year}");

            Console.WriteLine();

            Book pc = new Book("Clive Staples Lewis", "Prince Caspian", 224, 1951);
            pc.ShowInfo();

            Console.ReadKey();
        }
    }

    class Book
    {
        public string author;
        private string _title;
        private short _pages = 0;

        public string Title
        {
            get
            {
                return _title;
            }

            set
            {
                _title = value;
            }
        }

        public short Pages
        {
            get
            {
                return _pages;
            }

            set
            {
                if (value < 0)
                {
                    _pages = 0;
                }
                else
                {
                    _pages = value;
                }
            }
        }

        public short Year { get; set; }

        public Book()
        {
            Console.WriteLine("Object of type Book has been created.");
        }

        public Book(string author, string title, short pages, short year)
        {
            this.author = author;
            this.Title = title;
            this.Pages = pages;
            this.Year = year;
        }

        public void ShowInfo()
        {
            Console.WriteLine($"Author: {this.author}");
            Console.WriteLine($"Title: {this.Title}");
            Console.WriteLine($"Pages: {this.Pages}");
            Console.WriteLine($"Year: {this.Year}");
        }
    }
}

// value type - stack, reference type - heap