/****************************************************************************
 * bsearch.c
 *
 * Emin Israfil
 * Computer Science 50
 * Problem Set 3
 *
 * Binary Search
 ***************************************************************************/

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

bool bisearch(int[],int, int, int);

int 
main(void)
{

int low = 0;
int high = 5;
int valueb = 1000;

int arrayb[5] = {1,2,3,4,5};
bool ans;

arrayb[5] = 6;

for(int i = 0; i<=5; i++)
printf("%d :: %d\n",i, arrayb[i]);

ans = bisearch(arrayb, valueb, low, high);



if(ans == true)
printf("true\n");
else
printf("false\n");
}

bool 
bisearch(int array[],int value, int low, int high)
{
	int mid;
	
	if(high < low) {
		return false;
	}
	
	mid = ((high + low) / 2);
	if(array[mid] > value) {
		return bisearch(array, value, low, mid - 1);
	} else if(array[mid] < value) {
		return bisearch(array, value, mid + 1, high);
	} else {
		return true;
	}
	printf("it should finish main no?");
}
/*
int bisearch(int arrayb[], int valueb, int low, int high)
{   //shows that value is not present


    if(high<low)
        {
        return -1;
        }       
     //find middle   
    int mid = low + ((high - low) / 2); 
    
    //shift left
    if(valueb < arrayb[mid])
        {        
        bisearch(arrayb, valueb, low, (mid-1));
        }        
    //shift right
    else if (valueb >arrayb[mid])
        {        
        bisearch(arrayb, valueb, (mid+1), high);
        }
    else 
        {
        return mid;
        }
        
if(arrayb[mid]==valueb)
    return mid;
else
    return -2;
}       
*/
