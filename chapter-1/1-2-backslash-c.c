/**
 * Exercise 1-2
 *
 * Experiment to find out what happens when prints's argument string contains \c,
 * where c is some character not listed above.
 *
 * The C Programming Language - the second edition
 * by Brian Kernighan and Dennis Ritchie
 *
 * Author: Li Zhineng <lizhineng@gmail.com>
 * URL:    https://zhineng.li
 * File:   1-2-backslash-c.c
 * Date:   2017-01-01
 */

#include <stdio.h>

main()
{
    printf("hello, world\n\c");
}
