/**
 * Exercise 1-23, page 34
 *
 * Write a program to remove all comments from a C
 * program. Don't forget to handle quoted strings
 * and character constants properly. C comments
 * do not nest.
 *
 * The C Programming Language - the second edition
 * by Brian Kernighan and Dennis Ritchie
 *
 * Author: Li Zhineng <lizhineng@gmail.com>
 * URL:    https://zhineng.li
 * File:   1-23-remove-comments.c
 * Date:   2017-06-05
 */

#include <stdio.h>

#define PROGRAM 0
#define QUOTE   1
#define LITERAL 2
#define SLASH   3
#define STAR    4
#define COMMENT 5

main()
{
    int c, state;
    int slc;    /* is single-line comment */
    char quote;    /* record the quote style */

    slc = 1;
    state = PROGRAM;
    while ((c = getchar()) != EOF) {
        /* within the program code */
        if (state == PROGRAM) {
            if (c == '/') {
                state = SLASH;
	    } else {
                if (c == '\'' || c == '"') {
                    /* start of a quote of character constant */
                    state = QUOTE;
	       	    quote = c;
	        }
                putchar(c);
	    }
	} else if (state == QUOTE) {
            /* within a quote */
            if (c == '\\')
                state = LITERAL;
            else if (c == quote)
                state = PROGRAM;
            putchar(c);
	} else if (state == LITERAL) {
            /* within quoted string or char constant, following \ */
            putchar(c);
	    state = QUOTE;
	} else if (state == SLASH) {
            /* follwing a slash */
            if (c == '*' || c == '/') {
                state = COMMENT;

		if (c == '*')
                    slc = 0;
                else if (c == '/')
                    slc = 1;
	    } else {
                putchar('/');
		putchar(c);
		state = PROGRAM;
	    }
	} else if (state == STAR) {
            /* leading with a star */
            if (c == '/') {
                state = PROGRAM;
	    } else if (c != '*')
                state = COMMENT;
	} else if (state == COMMENT) {
            /* within a comment */
	    if (c == '\n' && slc) {
		putchar(c);
                state = PROGRAM;
	    } else if (c == '*' && slc == 0) {
                /* in multiple-line comment */
                state = STAR;
	    }
	}
    }

    return 0;
}
