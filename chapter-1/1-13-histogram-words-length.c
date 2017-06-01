/**
 * Exercise 1-13, page 24
 *
 * Write a program to print a histogram of the lengths of words
 * in its input. It is easy to draw the histogram with the bars
 * horizontal; a vertical oreientation is more challenging.
 *
 * The C Programming Language - the second edition
 * by Brian Kernighan and Dennis Ritchie
 *
 * Author: Li Zhineng <lizhineng@gmail.com>
 * URL:    https://zhineng.li
 * File:   1-13-histogram-words-length.c
 * Date:   2017-06-01
 */

#include <stdio.h>

#define MAXWORDLEN 10

main()
{
    int c;    /* current character */
    int count[MAXWORDLEN + 1];    /* words length counting table */
    int maxlen = 0;    /* the maximum word's length */
    int maxcount = 0;    /* the maximum count of the length */
    int nc = 0;    /* characters count */
    int cc = 0;    /* current counter */
    int done = 0;
    int i, j;

    /* initial the counting table */
    for (i = 0; i <= MAXWORDLEN; ++i) {
        count[i] = 0;
    }

    /* counting the word's length */
    while (done == 0) {
        c = getchar();

	if (done == 0) {
            if (c == ' ' || c == '\t' || c == '\n' || c == EOF) {
                if (nc <= MAXWORDLEN) {
		    if (nc > 0) {
                        cc = ++count[nc - 1];
		    }
	        } else {
                    cc = ++count[MAXWORDLEN];
		}

		/* compare with the maxlen */
		if (nc > maxlen) {
                    maxlen = nc;
		}

		/* compoare with the maxcount */
		if (cc > maxcount) {
                    maxcount = cc;
		}

                nc = 0;
	    } else {
                ++nc;
	    }
        }

        if (c == EOF) {
            done = 1;
	}
    }

    /* print the horizontal histogram */
    printf("\n\nHORIZONTAL HISTOGRAM\n\n");
    printf("      +");
    for (i = 0; i <= maxcount; ++i) {
        putchar('-');
    }
    putchar('\n');
    for (i = 0; i <= MAXWORDLEN; ++i) {
        if (i == MAXWORDLEN) {
            printf(">%3d  | ", MAXWORDLEN);
	} else {
            printf("%4d  | ", i + 1);
	}

	for (j = 0; j < maxcount; ++j) {
            if (count[i] > j) {
                putchar('*');
	    }
	}
	putchar('\n');
    }

    /* print the vertical histogram */
    printf("\n\nVERTIVAL HISTOGRAM\n\n");
    for (i = maxcount; i > 0; --i) { /* row of the histogram */
        printf("%4d  | ", i);
	for (j = 0; j <= MAXWORDLEN; ++j) { /* column of the histogram */
            if (count[j] >= i) {
                printf("*  ");
	    } else {
                printf("   ");
	    }
	}
	putchar('\n');
    }
    printf("      +");
    for (i = 0; i <= MAXWORDLEN; ++i) {
        printf("---");
    }
    printf("\n       ");
    for (i = 0; i < MAXWORDLEN; ++i) {
        printf("%2d ", i + 1);
    }
    printf(">%d\n", MAXWORDLEN);
}
