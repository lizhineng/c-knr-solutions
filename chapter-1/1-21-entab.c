/**
 * Exercise 1-21, page 34
 *
 * Write a program entab that replaces strings of
 * blanks by the minimum number of tabs and blanks
 * to achieve the same spacing. Use the same tab
 * stops as for detab. When either a tab or a single
 * blank would suffice to reach a tab stop, which
 * should be given preference?
 *
 * The C Programming Language - the second edition
 * by Brian Kernighan and Dennis Ritchie
 *
 * Author: Li Zhineng <lizhineng@gmail.com>
 * URL:    https://zhineng.li
 * File:   1-21-entab.c
 * Date:   2017-06-05
 */

#include <stdio.h>

#define TABSIZE 8    /* the spaces which one tab contains */

main()
{
    int i;
    int c, col, blanks, numtabs;

    col = blanks = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            ++blanks;
	    ++col;
	} else {
            if (blanks == 1) {
                putchar(' ');
	    } else if (blanks > 1) {
                numtabs = col/TABSIZE - (col-blanks)/TABSIZE;
		for (i = 0; i < numtabs; ++i)
                    putchar('\t');
		if (numtabs > 0) {
                    blanks = col - (col/TABSIZE)*TABSIZE;
		}
		for (i = 0; i < blanks; ++i)
                    putchar(' ');
	    }
	    blanks = 0;
	    putchar(c);
	    ++col;
	    if (c == '\n')
                col = 0;
	}
    }

    return 0;
}
