/**
 * Exercise 1-22, page 34
 *
 * Write a program to "fold" long input lines into two or more shorter lines
 * after the last non-blank character that occurs before the n-th column of
 * input. Make sure your program does something intelligent with very long
 * lines, and if there are no blanks or tabs before the specified column.
 */

#include <stdio.h>

#define MAXLINE 1000
#define FOLD 76

int getword(char s[], int lim);

int main()
{
	int len, nc;
	char word[MAXLINE];

	nc = 0;
	while ((len = getword(word, MAXLINE)) > 0) {
		if (nc>0 && nc+len>FOLD) {
			putchar('\n');
			nc = 0;
		}
		printf("%s", word);
		if (word[len-1] == '\n')
			nc = 0;
		else
			nc = nc + len;
	}

	return 0;
}

int getword(char s[], int lim)
{
	int i, c;

	for (i=0; i<lim-1 && (c=getchar())!=EOF && c!=' ' && c!='\t' && c!='\n'; ++i)
	  s[i] = c;

	if (c==' ' || c=='\t' || c=='\n') {
		s[i] = c;
		++i;
	}

	s[i] = '\0';

	return i;
}
