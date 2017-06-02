/**
 * Exercise 1-17, page 31
 *
 * Write a program to print all input lines that are
 * longer than 80 characters.
 *
 * The C Programming Language - the second edition
 * by Brian Kernighan and Dennis Ritchie
 *
 * Author: Li Zhineng <lizhineng@gmail.com>
 * URL:    https://zhineng.li
 * File:   1-17-print-lines-more-than-80-chars.c
 * Date:   2017-06-02
 */

#include <stdio.h>

#define PRINTLEN 3    /* the minimum length of line should print */

int get_line(char line[], int maxline);

/* print lines line */
main()
{
    int len;    /* current line length */
    char line[PRINTLEN + 1];    /* current input line */
    int longline = 0;

    while ((len = get_line(line, PRINTLEN+1)) > 0)
    {
	if (line[len-1] != '\n') {
            printf("%s", line);
	    longline = 1;
	} else if (longline) {
            printf("%s", line);
            longline = 0;
	}
    }

    return 0;
}

/* get_line: read a line into s, return length */
int get_line(char s[], int lim)
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
