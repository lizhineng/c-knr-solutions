#include <stdio.h>

#define MAX_LENGTH 10
#define MARK "#"

int main()
{
	int c, len, max;
	int i, j;
	int nword[MAX_LENGTH + 1];

	for (i = 0; i <= MAX_LENGTH; ++i)
		nword[i] = 0;

	max = len = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			if (len > 0)
				++nword[len];
			if (nword[len] > max)
				max = nword[len];
			len = 0;
		} else {
			if (len < MAX_LENGTH)
				++len;
		}
	}

	for (i = 1; i <= max; ++i) {
		for (j = 1; j <= MAX_LENGTH; ++j) {
			if (max - nword[j] < i)
				printf("%4s ", MARK);
			else
				printf("%4s ", " ");
		}
		putchar('\n');
	}

	/** print the legend */
	for (i = 1; i <= MAX_LENGTH; ++i) {
		if (i == MAX_LENGTH)
			printf("%3d+ ", i);
		else
			printf("%4d ", i);
	}
	putchar('\n');

	return 0;
}
