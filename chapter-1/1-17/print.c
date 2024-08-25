#include <stdio.h>
#define MAXLINE 1000

int getln(char line[], int maxline);

int main()
{
	int len;
	int truncate = 0;
	char line[MAXLINE];

	while ((len = getln(line, MAXLINE)) > 0) {
		if (truncate || len > 80) {
			printf("%s", line);
		}
		if (line[len-1] == '\n')
			truncate = 0;
		else
			truncate = 1;
	}
	return 0;
}

int getln(char s[], int lim)
{
	int c, i;

	for (i = 0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}
