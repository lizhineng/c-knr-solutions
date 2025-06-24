/**
 * Exercise 1-20, page 34
 *
 * Write a program detab that replaces tabs in the input with the proper
 * number of blanks to space to the next tab stop. Assume a fixed set of
 * tab stops, say every n columns. Should n be a variable or a symbolic
 * paramters?
 */

#include <stdio.h>

#define MAXLINE 1000
#define TABSTOP 8

int getln(char s[], int lim);
void detab(char line[], int len, char output[]);

int main()
{
	int len;
	char line[MAXLINE];
	char output[MAXLINE];

	while ((len = getln(line, MAXLINE)) > 0) {
		detab(line, len, output);
		printf("%s", output);
	}

	return 0;
}

int getln(char s[], int lim)
{
	int i, c;

	for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

void detab(char s[], int size, char output[])
{
	int i, j, k;
	int nc = 0;

	i = j = 0;
	while (i<size && (output[j] = s[i])!=EOF) {
		if (nc == TABSTOP)
			nc = 0;
		if (output[j] == '\t') {
			for (k = 0; k<TABSTOP-nc; ++k) {
				output[j] = ' ';
				++j;
			}
			nc = 0;
		} else {
			++j;
			++nc;
		}
		++i;
	}
	output[j] = '\0';
}
