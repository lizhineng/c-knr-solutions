/**
 * Exercise 1-23, page 34
 *
 * Write a program to remove all comments from a C program.
 * Don't forget to handle quoted strings and character constants properly.
 * C comments do not nest.
 */

#include <stdio.h>

#define CODE 0
#define SINGLE_LINE_COMMENT 1
#define MULTILINE_COMMENT 2

int main()
{
	char c;
	int state, quote;
	int slash, asterisk;

	state = CODE;
	quote = 0;
	slash = asterisk = 0;

	while ((c = getchar()) != EOF) {
		if (quote == 0 && c == '/') {
			if (state == CODE) {
				if (slash) {
					state = SINGLE_LINE_COMMENT;
					slash = 0;
				} else {
					slash = 1;
				}
			} else if (state == MULTILINE_COMMENT && asterisk) {
				state = CODE;
				asterisk = 0;
			}
		} else if (quote == 0 && c == '*') {
			if (state == CODE && slash) {
				state = MULTILINE_COMMENT;
				slash = 0;
			} else if (state == MULTILINE_COMMENT) {
				asterisk = 1;
			} else {
				putchar(c);
			}
		} else {
			if (state == SINGLE_LINE_COMMENT && c == '\n') {
				state = CODE;
				putchar(c);
			} else if (state == MULTILINE_COMMENT) {
				asterisk = 0;
			} else if (state == CODE) {
				if (slash) {
					putchar('/');
					slash = 0;
				} else if (c == '"') {
					if (quote) {
						quote = 0;
					} else {
						quote = 1;
					}
				}
				putchar(c);
			}
		}
	}

	return 0;
}
