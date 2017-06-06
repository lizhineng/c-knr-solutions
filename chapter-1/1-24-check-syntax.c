/**
 * Exercise 1-24, page 34
 *
 * Write a program to check C program for rudimentary
 * syntax errors like unblanced parentheses, brackets
 * and braces. Don't forget about quotes, both single
 * and double, escape sequences, and comments. (This
 * propgram is hard if you do it in full generality.)
 *
 * The C Programming Language - the second edition
 * by Brian Kernighan and Dennis Ritchie
 *
 * Author: Li Zhineng <lizhineng@gmail.com>
 * URL:    https://zhineng.li
 * File:   1-24-check-syntax.c
 * Date:   2017-06-06
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
    int parentheses, brackets, braces;

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
	        } else if (c == '[') {
                    ++brackets;
		} else if (c == ']') {
                    --brackets;
		} else if (c == '{') {
                    ++braces;
		} else if (c == '}') {
                    --braces;
		} else if (c == '(') {
                    ++parentheses;
		} else if (c == ')') {
                    --parentheses;
		}
	    }
	} else if (state == QUOTE) {
            /* within a quote */
            if (c == '\\')
                state = LITERAL;
            else if (c == quote)
                state = PROGRAM;
	} else if (state == LITERAL) {
            /* within quoted string or char constant, following \ */
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
                state = PROGRAM;
	    } else if (c == '*' && slc == 0) {
                /* in multiple-line comment */
                state = STAR;
	    }
	}
    }

    if (state != PROGRAM) {
        printf("Something wrong happend.\n");
    } else if (parentheses != 0) {
        printf("Mismathcing parentheses.\n");
    } else if (brackets != 0) {
        printf("Mismathcing brackets.\n");
    } else if (braces != 0) {
        printf("Mismathcing braces.\n");
    } else {
        printf("Syntax appears to be correct.\n");
    }

    return 0;
}
