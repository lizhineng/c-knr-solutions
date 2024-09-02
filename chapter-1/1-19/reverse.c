#include <stdio.h>
#define MAXLINE 1000

int getln(char line[], int maxline);
void reverse(char line[], int len, char output[]);

int main()
{
	int len;
	char line[MAXLINE];
	char output[MAXLINE];

	while ((len = getln(line, MAXLINE)) > 0) {
		reverse(line, len, output);
		printf("%s", output);
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

void reverse(char s[], int len, char o[])
{
	int i, j, k;

	i = len - 1;
	j = 0;
	k = 0;
	if (s[i] == '\n') {
		k = 1;
		--i;
	}
	while (i >= 0) {
		o[j] = s[i];
		--i;
		++j;
	}
	if (k == 1) {
		o[j] = '\n';
		++j;
	}
	o[j] = '\0';
}
