/**
 * Exercise 1-20, page 34
 *
 * Write a program detab that replaces tabs in the
 * print with the proper number of blanks to space
 * to the next tab stop. Assume a fixed set of tab
 * stops, say every n columns. Should n be a variable
 * or a symbolic parameter?
 *
 * The C Programming Language - the second edition
 * by Brian Kernighan and Dennis Ritchie
 *
 * Author: Li Zhineng <lizhineng@gmail.com>
 * URL:    https://zhineng.li
 * File:   1-20-detab.c
 * Date:   2017-06-05
 */

#include <stdio.h>

#define TABSIZE 8    /* the spaces which one tab contains */

main()
{
    int i;
    int c, col, spaces;

    col = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            spaces = TABSIZE - (col % TABSIZE);
	    for (i = 0; i < spaces; ++i)
                putchar(' ');
	    col = col + spaces;
	} else {
            putchar(c);
	    ++col;
            if (c == '\n') 
                col = 0;
	}
    }

    return 0;
}
