/**
 * Exercise 1-18, page 31
 *
 * Write a program to remove trailing blanks and
 * tabs from each line of input, and to delete
 * entirely blank lines.
 *
 * The C Programming Language - the second edition
 * by Brian Kernighan and Dennis Ritchie
 *
 * Author: Li Zhineng <lizhineng@gmail.com>
 * URL:    https://zhineng.li
 * File:   1-18-trim-trailing-blanks.c
 * Date:   2017-06-03
 */

#include <stdio.h>

#define MAXLINE 1000    /* maximum input line size */

int get_line(char line[], int lim);

main()
{
    int len;    /* current line length */
    char line[MAXLINE + 1];    /* current input line */
    int i;

    while ((len = get_line(line, MAXLINE + 1)) != 0) {
	if (len > 1) {
            for (i = len - 1; line[i] == ' ' || line[i]=='\t' || line[i] == '\n'; --i)
                ;
	    line[++i] = '\n';
	    line[++i] = '\0';
	    printf("%s", line);
	}
    }

    return 0;
}

/* get_line:  read a line into s, return length */
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
