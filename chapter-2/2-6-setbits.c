/**
 * Exercise 2-6, page 49
 *
 * Write a function setbits(x,p,n,y) that returns x with
 * the n bits that begin at position p set to the rightmost
 * n bits of y, leaving other bit unchanged.
 *
 * The C Programming Language - the second edition
 * by Brian Kernighan and Dennis Ritchie
 *
 * File:   2-6-setbits.c
 * Author: Li Zhineng <lizhineng@gmail.com>
 * URL:    https://zhineng.li
 * Date:   2017-06-16
 */

#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

main()
{
    printf("%u\n", setbits(170, 4, 3, 7));
    return 0;
}

/* setbits:  returns x with the n bits that begin at postiion p
             set to the rightmost n bits of y, leaving other bit
	     unchanged. */
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    return (x&~((~(~0<<n))<<(p+1-n))) | ((y&~(~0<<n))<<(p+1-n));
}
