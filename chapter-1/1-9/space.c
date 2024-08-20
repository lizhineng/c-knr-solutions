#include <stdio.h>

/* I get it, we can refactor with `else` to simplify the code, but with the
 * process of the book, we haven't encountered `else` yet. */
int main()
{
	int c, s;

	s = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			if (s == 0) {
				putchar(c);
			}
			s = 1;
		}

		if (c != ' ') {
			s = 0;
			putchar(c);
		}
	}

	return 0;
}
