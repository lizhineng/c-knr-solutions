/**
 * Exercise 1-24, page 24
 *
 * Write a program to check a C program for rudimentary syntax errors like
 * unbalanced parentheses, brackets and braces. Don't forget about quotes,
 * both single and double, escape sequences and comments. (This program is
 * hard if you do it in full generality.)
 */

#include <stdio.h>

int main()
{
	char c, p;
	int parentheses, brackets, braces;
	int squote, dquote;
	int comments;

	parentheses = brackets = braces = 0;
	squote = dquote = 0;
	comments = 0;

	while ((c = getchar()) != EOF) {
		if (c == '(')
			++parentheses;
		else if (c == ')')
			--parentheses;
		else if (c == '[')
			++brackets;
		else if (c == ']')
			--brackets;
		else if (c == '{')
			++braces;
		else if (c == '}')
			--braces;
		else if (comments == 0 && dquote == 0 && c == '\'')
			squote = (squote + 1) % 2;
		else if (comments == 0 && squote == 0 && c == '"')
			dquote = (dquote + 1) % 2;
		else if (p == '/' && c == '*')
			++comments;
		else if (p == '*' && c == '/')
			--comments;

		p = c;
	}

	if (parentheses != 0
		|| brackets != 0
		|| braces != 0
		|| squote != 0
		|| dquote != 0
		|| comments != 0)
		printf("The program contains syntax errors.\n");

	return 0;
}
