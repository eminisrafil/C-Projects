#include <cs50.h>
#include <stdio.h>
#include <string.h>

int
main(void)
{

//stores alternating lyrics
string word[20] = {"one" , "two" , "three", "four", "five", "six", "seven", "eight", "nine", "ten", "thumb", "shoe", "knee", "door", "hive", "stick", "heaven", "gate", "spine", "again"};

//itterates through string array
for(int i = 0; i <10; i++)
{
//prints out lyrics. Second line is offset by 10
    printf("This old man, he played %s\n\rHe played knick-knack on my %s\n\r", word[i], word[i+10]);
    printf ("Knick-knack paddywhack, give your dog a bone\n\rThis old man came rolling home\n\n\r");
}
}
