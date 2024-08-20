#include <stdio.h>

#define ASCII_PRINTABLE_FIRST 32
#define ASCII_PRINTABLE_LAST 127
#define ASCII_PRINTABLE_SIZE ASCII_PRINTABLE_LAST - ASCII_PRINTABLE_FIRST + 1
#define MARK "#"

int main()
{
	int c, i, j;
	int table[ASCII_PRINTABLE_SIZE];

	for (i = 0; i < ASCII_PRINTABLE_SIZE; ++i)
		table[i] = 0;

	while ((c = getchar()) != EOF)
		if (c >= ASCII_PRINTABLE_FIRST && c <= ASCII_PRINTABLE_LAST)
			++table[c-ASCII_PRINTABLE_FIRST];

	for (i = 0; i < ASCII_PRINTABLE_SIZE; ++i) {
		if (table[i] > 0) {
			printf("%c: ", i + ASCII_PRINTABLE_FIRST);
			for (j = 0; j < table[i]; ++j)
				printf("%s", MARK);
			putchar('\n');
		}
	}

	return 0;
}
