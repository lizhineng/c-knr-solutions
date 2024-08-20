#include <stdio.h>

#define MAX_LENGTH 10
#define MARK "#"

int main()
{
	int c, len;
	int i, j;
	int nword[MAX_LENGTH + 1];

	for (i = 0; i <= MAX_LENGTH; ++i)
		nword[i] = 0;

	len = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			if (len > 0)
				++nword[len];
			len = 0;
		} else {
			if (len < MAX_LENGTH)
				++len;
		}
	}

	for (i = 1; i <= MAX_LENGTH; ++i) {
		if (i == MAX_LENGTH)
			printf("%2d+: ", i);
		else
			printf("%3d: ", i);
		for (j = 0; j < nword[i]; ++j)
			printf("%s", MARK);
		putchar('\n');
	}

	return 0;
}
