/**
 * Exercise 1-22, page 34
 *
 * Write a program to "fold" long input lines into
 * two or more shorter lines after the last non-blank
 * character that occurs before the n-th column of
 * input. Make sure your program does something
 * intelligent with very long lines, and if there are
 * no blanks or tabs before the specified column.
 *
 * The C Programming Language - the second edition
 * by Brian Kernighan and Dennis Ritchie
 *
 * Author: Li Zhineng <lizhineng@gmail.com>
 * URL:    https://zhineng.li
 * File:   1-22-fold.c
 * Date:   2017-06-05
 */

#include <stdio.h>

#define TABSIZE 8    /* the spaces that one tab contians */
#define FOLDLEN 80    /* the maximum length of the line */

main()
{
    int i;
    int c, linelen, wordlen, wslen;
    char wordbuf[FOLDLEN];

    linelen = wordlen = wslen = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t') {
            wordbuf[wordlen] = '\0';
            wslen = c == '\t' ? TABSIZE: 1;
	    if (linelen + wordlen > FOLDLEN) {
                putchar('\n');
		linelen = wordlen;
	    } else {
                linelen = linelen + wordlen;
	    }
	    printf("%s", wordbuf);
	    if (linelen + wslen > FOLDLEN) {
                putchar('\n');
		putchar(c);
		linelen = wslen;
	    } else {
                putchar(c);
                linelen = linelen + wslen;
	    }
            wordlen = 0;
        } else if (c == '\n') {
            wordbuf[wordlen] = '\0';
            if (linelen + wordlen > FOLDLEN)
                putchar('\n');
            printf("%s", wordbuf);
            putchar(c);
            linelen = wordlen = 0;
        } else {
            if (wordlen == FOLDLEN) {
                for (i = 0; i < FOLDLEN-1; ++i)
                    putchar(wordbuf[i]);
                putchar('-');
                putchar('\n');
                wordbuf[0] = wordbuf[FOLDLEN-1];
                wordlen = 1;
                linelen = 0;
	    }
	    wordbuf[wordlen] = c;
	    ++wordlen;
	}
    }

    return 0;
}
