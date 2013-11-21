/****************************************************************************
 * pennies.c
 *
 * Emin Israfil
 * Computer Science 50
 * Problem Set 2
 *
 * Count change
 ***************************************************************************/
#include <cs50.h>
#include <stdio.h>
#include <math.h>

int
main(void)
{
    printf("How many days: ");
    int days = GetInt();

//  printf("You entered: %d days \n", days);
    
while(!((days>27)&&(days<32))){
   printf("Try Entering a valid number:");
   days = GetInt();

}

    printf("You selected %d days\n", days);


    
    printf("How many pennies: ");
    int pen = GetInt();
    printf("You entered %d pennies\n", pen);
    
    printf("You get %d pennies for the first day for %d days =", pen, days);
    float total = pen * pow(2,(days)); 
    printf("%f\n", total);

}
