/**
 * Exercise 1-11, page 21
 *
 * How would you test the word count program? What kinds of input are most
 * likely to uncover bugs if there are any?
 *
 * Answer: I would test the program with empty input, a word without a new
 * line, a line that only contains consecutive spaces, two words with single
 * or multiple spaces between them, one or multiple lines with or without any
 * words, a word or multiple words seperated by one space to ensure the
 * program outputs the correct word count.
 *
 * If there are any bugs out there, I think the state change of the program
 * is more likely to cause issues, so I would also carefully observe that
 * the counting is still correct when the state has been changed.
 */

#include <stdio.h>

#define IN 1   /* inside a word */
#define OUT 0  /* outside a word */

/* count lines, words, and characters in input */
int main()
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
	return 0;
}
