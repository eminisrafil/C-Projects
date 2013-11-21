/****************************************************************************
 * vigenere.c
 *
 * Emin Israfil
 * Computer Science 50
 * Problem Set 2
 *
 * Usage: vigenere "string "k 
 * Raise each char in a string k int
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
main(int argc, char *argv[])
{
//test that only 1 argument is entered
if((argc != 2))
{
    printf("Enter a single positive integer you big dummy!\n\n");
    return 1;
}

//takes lenght of arguement
int len = strlen(argv[1]);

int k[len];
//ensure every character is a letter
for(int i = 0; i <len; i++)
{
    //check if text is a letter 
    if(!(isalpha(argv[1][i])))

    {
        printf("%c is not a letter\n",argv[1][i]);
        printf("Enter only letters big dummy!\n\n");
        return 2;
        
        //check to see if letter is upper case
    } else if((argv[1][i]) < 91)
        {        
            k[i] = ((argv[1][i]) - 65);
            
            //if it is not upper subtract 97 
        } else
            {
            k[i]= ((argv[1][i]) - 97);
            }   
}


//receive message to code
printf("Now enter some text to encrypt: ");
string text = GetString(); 


//display i/o
printf("\rMessage    In: %s\n", text);
printf("\rMessage   Out: ");

//determine length of entered text
int len2 = strlen(text);

int k1[len2];
    for(int i = 0, j=0; i<len2; j++, i++)
        {            
            if(j == len)
                {
                j -= len;
                }
                k1[i] = k[j];
        }


//iterate through entered text to encode
for(int i = 0, j = 0; i <len2; j++, i++)
{
    //check if text is a letter 
    if(isalpha(text[i]))
    { 
        //encode it k characters and print it out
        printc(text[i], k1[j]);
    } else
        //if it isnt a letter it will not change it
    {
        printc(text[i], 0);
        j -=1;
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
        //checks to see if it is upper case and needs to be wrapped
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

