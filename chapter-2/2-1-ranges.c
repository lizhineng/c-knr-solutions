/**
 * Exercise 2-1, page 36
 *
 * Write a program to determine the ranges of char,
 * short, int, and long variables, both signed and
 * unsigned, by printing appropriate values from
 * standard headers and by direct computation. Harder
 * if you compute them: determine the ranges of the
 * vairous floating-point types.
 *
 * The C Programming Language - the second edition
 * by Brian Kernighan and Dennis Ritchie
 * * Author: Li Zhineng <lizhineng@gmail.com>
 * URL:    https://zhineng.li
 * File:   2-1-ranges.c
 * Date:   2017-06-06
 */

#include <stdio.h>
#include <limits.h>

main()
{
    printf("The size of char is %d\n", CHAR_BIT);
    printf("The ranges of char is %d ~ %d\n", CHAR_MIN, CHAR_MAX);
    printf("The ranges of unsigned char is %d ~ %u\n", 0, UCHAR_MAX);
    printf("The ranges of signed char is %d ~ %d\n", SCHAR_MIN, SCHAR_MAX);

    putchar('\n');

    printf("The ranges of short is %d ~ %d\n", SHRT_MIN, SHRT_MAX);
    printf("The ranges of unsigned short is %d ~ %u\n", 0, USHRT_MAX);

    putchar('\n');

    printf("The ranges of int is %d ~ %d\n", INT_MIN, INT_MAX);
    printf("The ranges of unsigned int is %d ~ %u\n", 0, UINT_MAX);

    putchar('\n');

    printf("The ranges of long is %ld ~ %ld\n", LONG_MIN, LONG_MAX);
    printf("The ranges of unsigned long is %u ~ %lu\n", 0, ULONG_MAX);

    return 0;
}
