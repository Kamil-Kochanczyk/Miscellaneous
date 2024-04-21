#include <stdio.h>

#define PHI 1.618
#define WRONGSQUARE(x) (x*x)
#define CORRECTSQUARE(x) ((x)*(x))
#define USELESS \
"useless"
#define VALUE 3

int main()
{
	printf("Phi: %.3f \n", PHI);
	printf("\n");

	printf("Wrong square: (2+1)^2 = %d \n", WRONGSQUARE(2 + 1));
	printf("Correct square: (2+1)^2 = %d \n", CORRECTSQUARE(2 + 1));
	printf("\n");

	printf("%s \n", USELESS);
	printf("\n");

	printf("Date: %s \n", __DATE__);
	printf("Time: %s \n", __TIME__);
	printf("File: %s \n", __FILE__);
	printf("Line: %d \n", __LINE__);
	printf("\n");

#ifdef PHI
#undef PHI
	printf("Phi has been undefined\n");
#define PHI 816.1
	printf("Phi: %.1f \n", PHI);
	printf("\n");
#endif // PHI

#ifndef E
#define E 2.718
	printf("E: %.3f \n", E);
	printf("\n");
#endif // !E

#if defined(VALUE)
	printf("Value is defined\n");
	printf("\n");
#endif

#if !defined(PI)
#define PI 3.141
	printf("Pi: %.3f \n", PI);
	printf("\n");
#endif

#if VALUE == 1
	printf("1\n");
#elif VALUE == 2
	printf("2\n");
#else
	printf("3\n");
#endif

	return 0;
}