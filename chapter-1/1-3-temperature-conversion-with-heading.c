/**
 * Exercise 1-3
 *
 * Modify the temperature conversion program to print
 * a heading above the table.
 *
 * The C Programming Language - the second edition
 * by Brian Kernighan and Dennis Ritchie
 *
 * Author: Li Zhineng <lizhineng@gmail.com>
 * URL:    https://zhineng.li
 * File:   1-3-temperature-conversion-with-heading.c
 * Date:   2017-05-31
 */

#include <stdio.h>

/* print Fahrenheit-Celsius table
    for fahr = 0, 20, ..., 300; floating-point version */
main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;    /* lower limit of temperature table */
    upper = 300;  /* upper limit */
    step = 20;    /* step size */

    /* table heading */
    printf("  F      C\n");

    fahr = lower;
    while (fahr <= upper) {
        celsius = (5.0/9.0) * (fahr-32.0);
	printf("%3.0f %6.1f\n", fahr, celsius);
	fahr = fahr + step;
    }
}
