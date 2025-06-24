/**
 * Exercise 1-21, page 21
 *
 * Write a program entab that replaces strings of blanks by the minimum number
 * of tabs and blanks to achive the same spacing. Use the same tab stops as
 * for detab. When either a tab or a single blank would suffice to reach a tab
 * stop, which should be given preference?
 */

#include <stdio.h>

#define MAXLINE 1000
#define TABSTOP 8

int getln(char s[], int lim);
void entab(char s[], int len, char output[]);

int main()
{
	int len;
	char line[MAXLINE];
	char output[MAXLINE];

	while ((len = getln(line, MAXLINE)) > 0) {
		entab(line, len, output);
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

void entab(char s[], int len, char output[])
{
	int i, j;
	int nc, ns;

	i = j = 0;
	nc = ns = 0;
	while (i<len && (output[j] = s[i])!=EOF) {
		if (nc == TABSTOP)
			nc = 0;
		if (output[j] == ' ') {
			++ns;
			if (nc==TABSTOP-1 && ns > 0) {
				j = j - (ns - 1);
				output[j] = '\t';
				ns = 0;
			}
		} else {
			ns = 0;
		}
		++nc;
		++j;
		++i;
	}
	output[j] = '\0';
}
