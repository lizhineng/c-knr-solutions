/**
 * Exercise 1-10, page 20
 *
 * Write a program to copy its input to its output,
 * replacing each tab by \t, each backspace by \b,
 * and each backslash by \\. This makes tabs and
 * backspaces visible in an unambiguous way.
 *
 * The C Programming Language - the second edition
 * by Brian Kernighan and Dennis Ritchie
 *
 * Author: Li Zhineng <lizhineng@gmail.com>
 * URL:    https://zhineng.li
 * File:   1-10-make-unambiguous-way.c
 * Date:   2017-06-01
 */

#include <stdio.h>

main()
{
    int c, d;

    while ((c = getchar()) != EOF) {
        d = 0;

        if (c == '\t') {
            putchar('\\');
            putchar('t');
	    d = 1;
	}

	if (c == '\b') {
            putchar('\\');
            putchar('b');
	    d = 1;
	}

	if (c == '\\') {
            putchar('\\');
            putchar('\\');
	    d = 1;
	}

	if (d == 0) {
            putchar(c);
	}
    }
}
