/**
 * Exercise 1-11, page 21
 *
 * How would you test the word count program?
 * What kind of input are most likely to uncover
 * bugs if there are any?
 *
 * Solution:
 *  1) test input zero character
 *  2) test input one word without newline
 *  3) test input multiple words with newline
 *  4) test input with multiple spaces without newline
 *  5) test input with multiple empty newlines
 *
 * The C Programming Language - the second edition
 * by Brian Kernighan and Dennis Ritchie
 *
 * Author: Li Zhineng <lizhineng@gmail.com>
 * URL:    https://zhineng.li
 * File:   1-11-test-word-count-program.c
 * Date:   2017-06-01
 */

#include <stdio.h>

#define IN  1    /* inside a word */
#define OUT 0    /* outside a word */

/* count lines, words and characters in input */
main()
{
    int c, nl, nw, nc, state;

    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF) {
        ++nc;
	if (c == '\n')
            ++nl;
	if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
	else if (state == OUT) {
            state = IN;
            ++nw;
	}
    }
    printf("%d %d %d\n", nl, nw, nc);
}
