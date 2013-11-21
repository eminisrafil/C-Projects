/****************************************************************************
 * recover.c
 *
 * Emin Israfil
 * Computer Science 50
 * Problem Set 5
 *
 * Recovers JPEGs from a forensic image.
 ***************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

//Buffer used to store data being read from memory card
char BUFFER[512];
//Size of FAT JPEG coding block 
int BLOCK = 512;
//Pathto corrupted memory card image
char CARDPATH[] = {"/home/cs50/pset5/card.raw"};
//Define the size on 1 byte to store JPEG header info 
typedef uint8_t BYTE; 
//Store jpeg start "signatures"
BYTE jpeg1[] = { 0xff, 0xd8, 0xff, 0xe0 };
BYTE jpeg2[] = { 0xff, 0xd8, 0xff, 0xe1 };
//Keep count of number of photos found
int i =0;

int
main(void){
    //Create pointer to RAW card image
    FILE *fp = fopen(CARDPATH, "r");
    //check that it successfully opened
    if (fp == NULL)
    {
        printf("Could not open \n");
        return 1;
    }
    //Create pointer to new file
    FILE *outptr = NULL;
   
   //Continue looking for JPEG signatures until end of file     
   while (!(feof(fp))) 
    {
        //Read 1 standard FAT block of memory at a time and store it in buffer
        fread(&BUFFER, BLOCK, 1, fp);
        
        //Check to see if the first four bytes of the buffer correspond to a JPEG       
        int m = memcmp(BUFFER, jpeg2, 4);
        int n = memcmp(BUFFER, jpeg1, 4);
        
        //If signature is found
        if((n ==0) || (m ==0))
            {
            //close any file that may be open or being written to byt outptr
            if(outptr != NULL)
                fclose(outptr);
                
            //format the file name ### 
            char filename[4];
            sprintf(filename, "%03d", i);
         
            //open a new file for writting and check that it opened successfully
            outptr = fopen(filename, "w+");
            if (outptr == NULL)
                {
                fclose(fp);
                fprintf(stderr, "Could not create \n");
                return 3;
                }
            //write 1st block of memory to the newly opened file    
            fwrite(&BUFFER, BLOCK, 1, outptr);              
            //keep track of the number of new files created and what to name them
            i++;
            }else if((i>0))
                {
                //Because JPEG's are stored contigusly, write remaining blocks of memory to the file. 
                fwrite(&BUFFER, BLOCK, 1, outptr);
                }
  

    }
    //close open files and tell user that the program has finished
     fclose(fp);
     fclose(outptr);
     printf("Done. We found %d pictures\n", i);


}    

