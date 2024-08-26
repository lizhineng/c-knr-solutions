#include <stdio.h>
#define MAXLINE 1000

int getln(char line[], int maxline);
int trim(char s[], int len);

int main()
{
	int len;
	char line[MAXLINE];
	int tlen;

	while ((len = getln(line, MAXLINE)) > 0) {
		tlen = trim(line, len);
		if (tlen > 0)
			printf("%s", line);
	}
	return 0;
}

int getln(char s[], int lim)
{
	int c, i;

	for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

int trim(char s[], int len)
{
	int i;
	int nl;

	nl = 0;
	i = len;
	while (i>0 && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] == '\0')) {
		if (s[i] == '\n')
			nl = 1;
		s[i] = '\0';
		--i;
	}
	if (i > 0) {
		if (nl == 1)
			s[++i] = '\n';
		s[++i] = '\0';
	}
	return i;
}
