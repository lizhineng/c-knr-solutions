/**
 * Exercise 1-8, page 20
 *
 * Write a program to count blanks, tabas and new lines.
 *
 * The C Programming Language - the second edition
 * by Brian Kernighan and Dennis Ritchie
 *
 * Author: Li Zhineng <lizhineng@gmail.com>
 * URL:    https://zhineng.li
 * File:   1-8-count-blanks-tabs-newlines.c
 * Date:   2017-06-01
 */

#include <stdio.h>

main()
{
    int c, blanks, tabs, newlines;
    int done = 0;
    int lastchar = 0;

    blanks = 0;
    tabs = 0;
    newlines = 0;

    while (done == 0) {
        c = getchar();

        if (c == ' ') {
            ++blanks;
	}

	if (c == '\t') {
            ++tabs;
	}

	if (c == '\n') {
            ++newlines;
	}

	if (c == EOF) {
            if (lastchar != '\n') {
                ++newlines;
	    }

	    done = 1;
	}

	lastchar = c;
    }

    printf("Counting result:\n");
    printf("blanks: %d\n", blanks);
    printf("tabs: %d\n", tabs);
    printf("newlines: %d\n", newlines);
}
