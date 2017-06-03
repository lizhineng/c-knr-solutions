/**
 * Exercise 1-19, page 31
 *
 * Write a function reverse(s) that reverses the
 * character string s. Use it to write a program
 * that reverses its input a line at a time.
 *
 * The C Programming Language - the second edition
 * by Brian Kernighan and Dennis Ritchie
 *
 * Author: Li Zhineng <lizhineng@gmail.com>
 * URL:    https://zhineng.li
 * File:   1-19-reverse.c
 * Date:   2017-06-03
 */

#include <stdio.h>

#define MAXLINE 1000    /* maximum input line size */

int get_line(char line[], int lim);
void reverse(char s[]);

main()
{
    int len;    /* current line length */
    char line[MAXLINE];    /* current input line */
    int i;

    while ((len = get_line(line, MAXLINE)) > 0) {
        reverse(line);
	printf("%s", line);
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

/* reverse:  reverses the character string s */
void reverse(char s[])
{
    int i, l;
    char temp;

    /* get length of s */
    for (l = 0; s[l] != '\0'; ++l)
        ;

    /* skip \n at the end of the line */
    l--;

    for (i = 0; i < l; ++i) {
        temp = s[i];
	s[i] = s[l-1];
	s[l-1] = temp;
	--l;
    }
}
