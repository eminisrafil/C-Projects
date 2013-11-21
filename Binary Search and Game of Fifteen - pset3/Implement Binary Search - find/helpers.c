/**************************************************************************** 
 * helpers.c
 *
 * Emin Israfil
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 ***************************************************************************/
       
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "helpers.h"


/*
 * Returns true if value is in array of n values, else false.
 */

bool 
search(int value, int array[], int n)
{
//store answer
int ans;
//send parameters to binary search
ans = bisearch(array, value, 0, n);


//return result
if(ans ==true)
    return true;
else
    return false;

}


//recursive binary search. Returns true or false
bool 
bisearch(int array[],int value, int low, int high)
{
	
	//if the low is greater than high, the value is not in the array
	if(high < low) 
		return false;
	//find midpoint
	int mid;
	mid = ((high + low) / 2);
	//call recursive function with a new high point
	if(array[mid] > value) {
		return bisearch(array, value, low, mid - 1);
    //call recursive function with a new low
	} else if(array[mid] < value) {
		return bisearch(array, value, mid + 1, high);
	//if the value is  less or greater than midpoint value that means it must equal it (trichotomy law)
	} else {
		return true;
	}
}








/*quit


 * Sorts array of n values.
 */

void 
sort(int values[], int n)
{
    // TODO: implement an O(n^2) sort

int temp;
int temp2;

for(int j = 0; j<n; j++)
{
temp = values[j];
temp2 = 0;
for(int i = 0; i< n; i++)
{
    if(temp < values[i])
        {
        temp2 = temp;
        temp = values[i];
        values[i] = temp2;
        values[j] = temp;    
        }
} 
}


for(int i = 0; i< n; i++)
printf("\n %d: value %d", i ,values[i]);


printf("\n value of N %d\n", n);
    return;
}
