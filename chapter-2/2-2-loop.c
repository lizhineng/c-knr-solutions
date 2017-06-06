/**
 * Exercise 2-2, page 42
 *
 * Write a loop equivalent to the for loop above
 * without using && or ||.
 *
 * The C Programming Language - the second edition
 * by Brian Kernighan and Dennis Ritchie
 *
 * File:   2-2-loop.c
 * Author: Li Zhineng <lizhineng@gmail.com>
 * URL:    https://zhineng.li
 * Date:   2017-06-06
 */

#include <stdio.h>

#define LIMIT 512

main()
{
    int i;
    int c, lim;
    char s[LIMIT];
    
    lim = LIMIT;
    i = 0;
    while (i < lim - 1) {
        c = getchar();
        if (c == '\n')
            lim = 0;    /* we haven't encountered breaks yet. */
	else if (c == EOF)
            lim = 0;
        else
            s[i++] = c;
    }
    s[i] = '\0';
    printf("%s\n", s);

    return 0;
}
