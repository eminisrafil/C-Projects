/****************************************************************************
 * caesar.c
 *
 * Emin Israfil
 * Computer Science 50
 * Problem Set 2
 *
 * Encrypt Message
 ***************************************************************************/

#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>


//function prototype prints chars
void printc(char, int);

int
main(int argc, char *argv[]){
//test that only 1 argument enters & that it's larger than 0
if((argc != 2) || (atoi(argv[1]) < 1) ) 
{
    printf("Enter a single positive integer you big dummy!\n\n");
    return 1;
}

//convert input into useable number
int k = atoi(argv[1]) %26;


//receive message to code
printf("Now enter some text to encrypt: ");
string text = GetString(); 
printf("Message   In: %s\n", text);


//determin length of entered text
int len = strlen(text);
printf("Message  Out: ");



//iterate through string text
for(int i = 0; i <len; i++)
{
    //check if text is a letter 
    if(isalpha(text[i]))
    { 
        //encode it k characters and print it out
        printc(text[i], k);
    } else
        //if it isnt a letter it will not change it
    {
        printc(text[i], 0);
    }
}

printf("\n\n");
}




//Function to print our encrypted message
void printc(char textin, int a)
{   
    //catches all the text that needs to be wrapped
    if((isupper(textin) && ((textin + a)> 90)) || ((!(isupper(textin))) && ((textin + a)> 122)))
    {   
        //checks to see if it is upper case and needs to be wapped
        if(isupper(textin) && ((textin + a)> 90))
            {            
            //subtract 26 to bring it back to the begining of the alphabet            
            a -= 26;
            printf("%c", textin + a);
            }
        
        //checks to see if it is lower case and needs to be wrapped
        if((!(isupper(textin))) && ((textin + a)> 122))
            {
            a -= 26;
            printf("%c", textin + a);
            }    
    }   //prints special characters, spaces, and characters that do not need to be wrapped
        else
        printf("%c", textin + a);
}

