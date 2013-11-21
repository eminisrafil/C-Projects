/****************************************************************************
 * greedy.c
 *
 * Emin Israfil
 * Computer Science 50
 * Problem Set 2
 *
 * Make Change
 ***************************************************************************/

#include <cs50.h>
#include <stdio.h>
#include <math.h>

int
main(void)
{
    int coins = 0;
    int q = 0;
    int d = 0;
    int n = 0;
    int p = 0;

    printf("How much change are you owed sir?\n");
    float owedf = GetFloat();
    int owed = owedf * 100 +.5;
    printf("******************* \n");
    printf("Test: value of owedf: %f\n", owedf);
    printf("Test: value of owed: %d\n", owed);
    printf("******************* \n");
while(!(owed>-1))
{
   printf("Try Entering a valid number:");
   owed = GetFloat();
}

while (owed >= 25) 
{
    owed = owed - 25;
    coins++;
    q += 1;
}
 
while (owed >= 10) 
{
    owed = owed - 10;
    coins++;
    d += 1;
} 

while (owed >= 5) 
{
    owed = owed - 5;
    coins++;
    n += 1;
}

while (owed >= 1) 
{
    owed = owed - 1;
    coins++;
    p += 1;
}

 printf("Number of quarters = %d \n", q);
 printf("Number of dimes = %d \n", d);
 printf("Number of nickles = %d \n", n);
 printf("Number of pennies = %d \n", p);
 printf("Total number of coins = %d \n", coins);

}
