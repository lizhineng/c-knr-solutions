/**
 * Exercise 1-12, page 21
 *
 * Write a program that prints its input one word per line.
 */

#include <stdio.h>

int main()
{
	int c, d;

	d = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			if (d == 0) {
				putchar('\n');
			}
			d = 1;
		} else {
			d = 0;
			putchar(c);
		}
	}

	return 0;
}
