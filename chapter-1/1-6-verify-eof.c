/**
 * Exercise 1-6, page 17
 *
 * Verify that the expression getchar() != EOF is 0 or 1.
 *
 * The C Programming Language - the second edition
 * by Brian Kernighan and Dennis Ritchie
 *
 * Author: Li Zhineng <lizhineng@gmail.com>
 * URL:    https://zhineng.li
 * File:   1-6-verify-eof.c
 * Date:   2017-05-31
 */

#include <stdio.h>

main()
{
    printf("%d\n", getchar() != EOF);
}
