/**
 * Exercise 1-4, page 13
 *
 * Write a program to print the corresponding Celsius
 * to Fahrenheit table.
 *
 * The C Programming Language - the second edition
 * by Brian Kernighan and Dennis Ritchie
 *
 * Author: Li Zhineng <lizhineng@gmail.com>
 * URL:    https://zhineng.li
 * File:   1-4-celsius-to-fahrenheit.c
 * Date:   2017-05-31
 */

#include <stdio.h>

/* print Celsius-Fahrenheit table
    for celsius = 0, 20, ..., 300; floating-point version */
main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;    /* lower limit of temperature table */
    upper = 300;  /* upper limit */
    step = 20;    /* step size */

    /* table heading */
    printf("  C      F\n");

    celsius = lower;
    while (celsius <= upper) {
        fahr = celsius * (9.0/5.0) + 32;
	printf("%3.0f %6.1f\n", celsius, fahr);
	celsius = celsius + step;
    }
}
