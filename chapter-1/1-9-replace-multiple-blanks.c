/**
 * Exercise 1-9, page 20
 *
 * Write a program to copy its input to its output,
 * replace each string of one or more blanks
 * by a single blank.
 *
 * The C Programming Language - the second edition
 * by Brian Kernighan and Dennis Ritchie
 *
 * Author: Li Zhineng <lizhineng@gmail.com>
 * URL:    https://zhineng.li
 * File:   1-9-replace-multiple-blanks.c
 * Date:   2017-06-01
 */

#include <stdio.h>

main()
{
    int c, lastchar = EOF;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (lastchar != ' ') {
	        putchar(c);
	    }
	}

	if (c != ' ') {
            putchar(c);
	}

        lastchar = c;
    }
}
