/**
 * Exercise 2-5, page 48
 *
 * Write the function any(s1, s2), which returns the
 * first location in the string s1 where any character
 * from the string s2 occurs, or -1 if s1 contains no
 * characters from s2. (The standard library funciton
 * strpbrk does the same job but returns a pointer to
 * the location.)
 *
 * The C Programming Language - the second edition
 * by Brian Kernighan and Dennis Ritchie
 *
 * File:   2-5-any.c
 * Author: Li Zhineng <lizhineng@gmail.com>
 * URL:    https://zhineng.li
 * Date:   2017-06-11
 */

#include <stdio.h>

int any(char s1[], char s2[]);

main()
{
    char s1[] = "abcdef";
    char s2[] = "cde";
    printf("%d\n", any(s1, s2));
    return 0;
}

/* any:  returns the first location in s1 where any
         character from s2 occurs, or -1 if s1 contains
	 no characters from s2. */
int any(char s1[], char s2[])
{
    int i, j;

    for (i = 0; s1[i] != '\0'; i++)
        for (j = 0; s2[j] != '\0'; j++)
            if (s1[i] == s2[j])
                return i;
    return -1;
}
