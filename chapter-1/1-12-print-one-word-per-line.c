/**
 * Exercise 1-12, page 21
 *
 * Write a program that prints its input one word per line.
 *
 * The C Programming Language - the second edition
 * by Brian Kernighan and Dennis Ritchie
 *
 * Author: Li Zhineng <lizhineng@gmail.com>
 * URL:    https://zhineng.li
 * File:   1-12-print-one-word-per-line.c
 * Date:   2017-06-01
 */

#include <stdio.h>

main()
{
    int c, inspace;

    inspace = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (inspace == 0) {
                putchar('\n');
                inspace = 1;
	    }
        } else {
            putchar(c);
	    inspace = 0;
	}
    }
}
