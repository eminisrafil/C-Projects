/****************************************************************************
 * hello.c
 *
 * Emin Israfil
 * Computer Science 50
 * Problem Set 2
 *
 * Say Hi
 ***************************************************************************/
#include <cs50.h>
#include <stdio.h>


//getString() - convenience method in cs50.h 
int
main(void)
{
    printf("word please: ");
    string s = getString();
    printf("%s\n", s);
}
