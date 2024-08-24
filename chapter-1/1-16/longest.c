#include <stdio.h>
#define MAXLINE 1000

int getln(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
	int len;
	int max;
	int last;
	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0;
	last = 0;
	while ((len = getln(line, MAXLINE)) > 0) {
		if (len > max) {
			if (last == 0)
				copy(longest, line);
			if (line[len-1] == '\n') {
				if (last == 0)
					max = len;
				else
					max = last + len;
				last = 0;
			} else {
				last = last + len;
			}
		}
	}
	if (max > 0) {
		printf("%d\n", max);
		printf("%s", longest);
	}
	return 0;
}

int getln(char s[], int lim)
{
	int c, i;

	for (i=0; i<lim-1 && (c = getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

void copy(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
