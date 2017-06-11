/**
 * Exercise 2-4, page 48
 *
 * Write an alternate version of squeeze(s1, s2)
 * that deletes each character in s1 that matches
 * any characters in the string s2. 
 *
 * The C Programming Language - the second edition
 * by Brian Kernighan and Dennis Ritchie
 *
 * File:   2-4-squeeze.c
 * Author: Li Zhineng <lizhineng@gmail.com>
 * URL:    https://zhineng.li
 * Date:   2017-06-11
 */

#include <stdio.h>

void squeeze(char s1[], char s2[]);

main()
{
    char s1[] = "abcdef";
    char s2[] = "bdf";
    squeeze(s1, s2);
    printf("%s\n", s1);
    return 0;
}

/* squeeze:  delete all characters from s1 that matches any in s2. */
void squeeze(char s1[], char s2[])
{
    int i, j, k;
    int instr2;

    for (i = j = 0; s1[i] != '\0'; i++) {
        instr2 = 0;
        for (k = 0; s2[k] != '\0' && !instr2; k++) {
            if (s1[i] == s2[k])
                instr2 = 1;
        }
	if (!instr2)
            s1[j++] = s1[i];
    }
    s1[j] = '\0';
}
