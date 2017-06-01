/**
 * Exercise 1-15, page 27
 *
 * Rewrite the temperature conversion program of Section 1.2
 * to use a function for conversion.
 *
 * The C Programming Language - the second edition
 * by Brian Kernighan and Dennis Ritchie
 *
 * Author: Li Zhineng <lizhineng@gmail.com>
 * URL:    https://zhineng.li
 * File:   1-15-f2c-function.c
 * Date:   2017-06-01
 */

#include <stdio.h>

float f2c(float f);

main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    /* table heading */
    printf("  F      C\n");
    fahr = lower;
    while (fahr <= upper) {
        celsius = f2c(fahr);
	printf("%3.0f %6.1f\n", fahr, celsius);
	fahr = fahr + step;
    }

    return 0;
}

float f2c(float f)
{
    return (5.0 / 9.0) * (f - 32.0);
}
