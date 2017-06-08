/**
 * Exercise 2-3, page 46
 *
 * Write the function htoi(s), which converts a
 * string of hexadecimal digits (including an
 * optional 0x or 0X) into its equivalent interger
 * value. The allowable digits are 0 through 9,
 * a through f, and A through F.
 *
 * The C Programming Language - the second edition
 * by Brian Kernighan and Dennis Ritchie
 *
 * File:   2-3-htoi.c
 * Author: Li Zhineng <lizhineng@gmail.com>
 * URL:    https://zhineng.li
 * Date:   2017-06-08
 */

#include <stdio.h>

int htoi(char s[]);

main()
{
    char s[1024];
    int i, c;
    for (i = 0; (c = getchar()) != '\n'; ++i)
        s[i] = c;
    s[i] = '\0';
    printf("%s: %d\n", s, htoi(s));
    return 0;
}

/* htoi:  converts hexadicimal string s to integer */
int htoi(char s[])
{
    int i;
    int c, n;

    n = 0;
    for (i = 0; (c = s[i]) != '\0'; ++i) {
        n *= 16;
	if (i == 0 && c == '0') {
            /* drop the 0x or 0X from the starting */
            c = s[++i];
	    if (c != 'x' && c != 'X')
                --i;
        } else if (c >= '0' && c <= '9')
            /* c is a numerical digit */
            n += c - '0';
        else if (c >= 'a' && c <= 'f')
            /* c is a letter between 'a' - 'f' */
            n += 10 + (c - 'a');
        else if (c >= 'A' && c <= 'F')
            /* c is a letter between 'A' - 'F' */
            n += 10 + (c - 'A');
	else
            /* invalid input */
            return n;
    }
    return n;
}
