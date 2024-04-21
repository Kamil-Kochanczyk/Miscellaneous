using System;

namespace More_on_Classes
{
    class Program
    {
        private static void Main(string[] args)
        {
            Movie movie = new Movie();
            //movie.title = "Me Before You";
            Console.WriteLine(movie.title);
            //movie.year = 2016;
            Console.WriteLine(movie.year);
            Console.WriteLine();

            movie = new Movie("Me Before You", 2016);
            Console.WriteLine(movie.title);
            Console.WriteLine(movie.year);
            Console.WriteLine();

            Console.WriteLine($"First movie was created in {MovieInfo.FIRSTMOVIEYEAR}.");
            Console.WriteLine();

            Console.WriteLine("Available ratings for the movies are shown below.");
            MovieInfo.ShowAvailableRatings();
            Console.WriteLine();

            Movie[] moviesNull = null;
            MovieSeries movieSeriesNull = new MovieSeries(moviesNull);
            movieSeriesNull.PresentMovieSeries();
            Console.WriteLine();

            Movie[] movies0 = new Movie[0];
            MovieSeries movieSeries0 = new MovieSeries(movies0);
            movieSeries0.PresentMovieSeries();
            Console.WriteLine();

            Movie[] movies = new Movie[3];
            MovieSeries movieSeries = new MovieSeries(movies);
            movieSeries.PresentMovieSeries();
            Console.WriteLine();

            Movie[] prequels = new Movie[3];
            prequels[0] = new Movie("Star Wars: Episode I - The Phantom Menace", 1999);
            prequels[1] = new Movie("Star Wars: Episode II - Attack of the Clones", 2002);
            prequels[2] = new Movie("Star Wars: Episode III - Revenge of the Sith", 2005);
            MovieSeries newTrilogy = new MovieSeries(prequels);

            Movie[] classics = new Movie[3];
            classics[0] = new Movie("Star Wars: Episode IV - A New Hope", 1977);
            classics[1] = new Movie("Star Wars: Episode V - The Empire Strikes Back", 1980);
            classics[2] = new Movie("Star Wars: Episode VI - Return of the Jedi", 1983);
            MovieSeries originalTrilogy = new MovieSeries(classics);

            MovieSeries starWars = newTrilogy + originalTrilogy;
            starWars.PresentMovieSeries();
            Console.WriteLine();

            Console.WriteLine($"starWars[-100] is \"{starWars[-100]}\".");
            Console.WriteLine($"starWars[100] is \"{starWars[100]}\".");
            Console.WriteLine($"My favourite movie is \"{starWars[3]}\".");
            Console.WriteLine();

            /*
            Console.WriteLine($"starWars[1] = \"{starWars[1]}\".");

            starWars[-100] = "-100";
            Console.WriteLine($"starWars[-100] = \"{starWars[-100]}\".");
            Console.WriteLine($"starWars[1] = \"{starWars[1]}\".");

            starWars[100] = "100";
            Console.WriteLine($"starWars[100] = \"{starWars[100]}\".");
            Console.WriteLine($"starWars[1] = \"{starWars[1]}\".");

            starWars[3] = "3";
            Console.WriteLine($"starWars[3] = \"{starWars[3]}\".");
            Console.WriteLine();
            */

            Console.WriteLine($"Number of created objects of type Movie: {Movie.Counter}");

            Console.ReadKey();
        }
    }

    class Movie
    {
        public readonly string title = "Unknown";
        public readonly ushort year;
        private static int _counter;

        public static int Counter
        {
            get
            {
                return _counter;
            }

            private set
            {
                _counter = value;
            }
        }

        static Movie()
        {
            Console.WriteLine("Type Movie has been accessed.");
            Counter = 0;
        }

        public Movie()
        {
            Counter++;
            Console.WriteLine("Object of type Movie has been created.");
        }

        public Movie(string title, ushort year)
        {
            this.title = title;
            this.year = year;
            Counter++;
            Console.WriteLine("Object of type Movie has been created.");
        }

        ~Movie()
        {
            Console.Clear();
            Console.WriteLine("Object of type Movie has been deleted.");
            Console.ReadKey();
        }

        public void PresentMovie()
        {
            Console.WriteLine($"Title: {this.title}");
            Console.WriteLine($"Year: {this.year}");
        }
    }

    class MovieSeries
    {
        private Movie[] _moviesInSeries;

        public Movie[] MoviesInSeries
        {
            get
            {
                return _moviesInSeries;
            }

            set
            {
                if (value == null || value.Length == 0)
                {
                    _moviesInSeries = new Movie[1] { new Movie() };
                }
                else
                {
                    _moviesInSeries = value;
                }
            }
        }

        public MovieSeries(Movie[] moviesInSeries)
        {
            this.MoviesInSeries = moviesInSeries;
        }

        public string this[int part]
        {
            get
            {
                int index = (part < 1 || part > this.MoviesInSeries.Length) ? 0 : part - 1;
                return this.MoviesInSeries[index].title;
            }

            /*
            set
            {
                int index = (part < 1 || part > this.MoviesInSeries.Length) ? 0 : part - 1;
                this.MoviesInSeries[index].title = value;
            }
            */
        }

        public static MovieSeries operator+ (MovieSeries movieSeries1, MovieSeries movieSeries2)
        {
            Movie[] moviesInSeries1 = movieSeries1.MoviesInSeries;
            Movie[] moviesInSeries2 = movieSeries2.MoviesInSeries;
            Movie[] merged = new Movie[moviesInSeries1.Length + moviesInSeries2.Length];

            for (int index = 0; index < merged.Length; index++)
            {
                if (index < moviesInSeries1.Length)
                {
                    merged[index] = moviesInSeries1[index];
                }
                else
                {
                    merged[index] = moviesInSeries2[index - moviesInSeries1.Length];
                }
            }

            return new MovieSeries(merged);
        }

        public void PresentMovieSeries()
        {
            foreach (var movie in this.MoviesInSeries)
            {
                if (movie != null)
                {
                    movie.PresentMovie();
                }
                else
                {
                    Console.WriteLine("Null movie in series");
                }
            }
        }
    }

    static class MovieInfo
    {
        public const int FIRSTMOVIEYEAR = 1888;
        private static double[] _availableRatings;

        public static double[] AvailableRatings
        {
            get
            {
                return _availableRatings;
            }

            private set
            {
                _availableRatings = value;
            }
        }

        static MovieInfo()
        {
            double lowestRating = 1.0, highestRating = 5.0, interval = 0.5;

            int numberOfAvailableRatings = (int)(((highestRating - lowestRating) / interval) + 1);

            AvailableRatings = new double[numberOfAvailableRatings];

            for (double index = 0.0, rating = lowestRating; index < AvailableRatings.Length; index++, rating += interval)
            {
                AvailableRatings[(int)index] = rating;
            }
        }

        public static void ShowAvailableRatings()
        {
            foreach (var rating in AvailableRatings)
            {
                Console.WriteLine(rating);
            }
        }
    }
}