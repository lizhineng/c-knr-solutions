/**
 * Exercise 1-14, page 24
 *
 * Write a program to print a histogram of the frequencies
 * of different characters in its input.
 *
 * The C Programming Language - the second edition
 * by Brian Kernighan and Dennis Ritchie
 *
 * Author: Li Zhineng <lizhineng@gmail.com>
 * URL:    https://zhineng.li
 * File:   1-14-frequencies-histogram.c
 * Date:   2017-06-01
 */

#include <stdio.h>

#define NUM_CHARS 128

main()
{
    int c;
    int frequencies[NUM_CHARS];
    int maxcount = 0;    /* maximum count of frequencies */
    int cc = 0;    /* current counter */
    int i, j;

    /* initial frequencies table */
    for (i = 0; i < NUM_CHARS; ++i) {
        frequencies[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        cc = ++frequencies[c];

	if (cc > maxcount) {
            maxcount = cc;
	}
    }

    /* print the horizontal histogram */
    printf("\n\nHORIZONTAL HISTOGRAM\n\n");
    printf("      +-");
    for (i = 0; i < maxcount; ++i) {
        putchar('-');
    }
    putchar('\n');
    for (i = 0; i < NUM_CHARS; ++i) { /* the row(ASCII) of the table */
        if (frequencies[i] > 0) {
            printf("%4d  | ", i);
	    for (j = 0; j < maxcount; ++j) { /* the column(count) of the table */
                if (frequencies[i] > j) {
                    putchar('*');
                }
	    }
	    putchar('\n');
	}
    }
}
