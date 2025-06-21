/**
 * Exercise 1-15, page 27
 *
 * Rewrite the temperature conversion program of Section 1.2
 * to use a function for conversion.
 */

#include <stdio.h>

int fahr2celsius(int fahr)
{
	return (5.0/9.0)*(fahr-32);
}

int main()
{
	int fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	fahr = lower;
	while (fahr <= upper) {
		printf("%d\t%d\n", fahr, fahr2celsius(fahr));
		fahr = fahr + step;
	}

	return 0;
}
