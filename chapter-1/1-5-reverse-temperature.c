/**
 * Exercise 1-5, page 14
 *
 * Modify the temperature conversion program to
 * print the table in reverse order, that is,
 * from 300 degrees to 0.
 *
 * The C Programming Language - the second edition
 * by Brian Kernighan and Dennis Ritchie
 *
 * Author: Li Zhineng <lizhineng@gmail.com>
 * URL:    https://zhineng.li
 * File:   1-5-reverse-temperature.c
 * Date:   2017-05-31
 */

#include <stdio.h>

/* print Fahrenheit-Celsius table */
main()
{
    int fahr;

    /* table heading */
    printf("  F      C\n");

    for (fahr = 300; fahr >= 0; fahr = fahr - 20) {
	printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
    }
}
