/****************************************************************************
 * dictionary.c
 *
 * Emin Israfil
 * Computer Science 50
 * Problem Set 6
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "dictionary.h"

#define HSIZE 8000000
int totalsize = 0;

typedef struct node {
    char word[45];
    struct node *next;
} node;

node *htable[HSIZE];
node *one;

int hf(char *word)
{
   
    int result = 0;
    int n = strlen(word);

    for (int i = 0; i < n; i++)
        {
        result += word[i];
        }
    return result % HSIZE;
}


/*
 * Returns true if word is in dictionary else false.
 */

bool
check(const char *word)
{
    //int compare = -1;
    int i =0;
    int hv;
    int len = strlen(word);
    char lword[len+1];
     
    while(*word != '\0')
    {
        lword[i] = tolower(*word);

        word++;
        i++;
    }

    lword[i] ='\0';

    hf(lword);
    //printf(" checking: %s | ",  lword);
    
    hv = hf(lword);    
    
    node *iterator;

    if(htable[hv]==NULL){
        //printf("%s not found\n", lword);
        return false;
    } else {
        iterator = htable[hv];
        
        while(iterator !=NULL)
        {
            if(strcmp(lword,iterator->word ) ==0 )
            {
                //printf("| %s | in hv(%d)\n", lword, hv);
                return true;
            }
            //printf("\n%p --->", htable[hv]);
            //printf("iterator position: %d  %s\n",hv, iterator->word);
            iterator = iterator->next;
        }

    }
    return false;
}


/*
 * Loads dictionary into memory.  Returns true if successful else false.
 */

bool
load(const char *dictionary)
{
    
    FILE *fpdic = fopen(dictionary, "r");
    if (fpdic == NULL)
    {
        printf("Could not open %s in load.\n", dictionary);
        unload();
        return 3;
    }
    
    for(int i =0; i<HSIZE; i++)
    {
        htable[i]=NULL;
    }
    
    int hashv=0;
    while(!feof(fpdic))
    {
        one =  malloc(sizeof(node));
        if (one == NULL)
        {
            printf("ONE IS NULL!");
            unload();
            return 3;
        }
    
        fscanf(fpdic, "%s", one->word);
       
   
        if(!feof(fpdic)){
            hashv= hf(one->word);
            //printf("%s:%d:::  %p   ::::", one->word, totalsize, one->word);
            //printf("%d\n", hashv);
            
            if(htable[hashv]==NULL)
            {
                htable[hashv] = one;
               // printf("next: %p\n ",one->next);
                one->next = NULL;   
            }
            else
            {
              one->next = htable[hashv];
              htable[hashv] = one;
            }
            totalsize ++;
        }
}


fclose(fpdic);
if(totalsize>0)
    return true;
else
    return false;

}


/*
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */

unsigned int
size(void)
{
    return totalsize;
    return 0;
}


/*
 * Unloads dictionary from memory.  Returns true if successful else false.
 */

bool
unload(void)
{
    node *iterator;
    node *delete;
    for (int i = 0; i<HSIZE; i++){
        if(htable[i]!=NULL)
            {
                iterator = htable[i];
            
                while(iterator !=NULL)
                {
                    //printf("\n%p --->", htable[i]);
                    //printf("iterator position: %d  %s\n",i, iterator->word);
                    delete = iterator;
                    iterator = iterator->next;
                    free(delete);
                }
            }
    }

    free(one);
        return true;
}
