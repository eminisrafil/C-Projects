/****************************************************************************
 * copy.c
 *
 * Emin Israfil
 * Computer Science 50
 * Problem Set 5
 *
 * Copies a BMP piece by piece, just because.
 ***************************************************************************/
#include <ctype.h>   
#include <string.h>   
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bmp.h"


int
main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: copy infile outfile\n");
        return 1;
    }
    
    
    //	is second arguement	an	integer	
    for	(int i	=	0,	n	=	strlen(argv[1]);	i	<	n;	i++)	
    if	(!isdigit(argv[1][i]))	
        return	2;
    
    //convert input to integer
    int n;
    n = atoi(argv[1]);
    //make sure n is between 1-100
    if((n<1) || (n>100))
    {
        printf("Enter a number between 1 and 100 dumbt\n");
        return 3;
    }
    
    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];

    // open input file 
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 4;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 5;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);
    
    //update dimension info in the header and new padding
    bi.biWidth *= n;
    bi.biHeight *= n;
    int paddingout = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    bf.bfSize = 54 + (bi.biWidth * bi.biHeight * 3) + (paddingout *3); 


    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // determine padding for scanlines
    int padding =  (4 - ((bi.biWidth/n) * sizeof(RGBTRIPLE)) % 4) % 4;
    

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
            
            
        // iterate over pixels in scanline
        for (int j = 0; j < bi.biWidth/n; j++)
        {
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            //repeat each pixel n times horizontally
            for(int k =0; k<n; k++)
            {
            // write RGB triple to outfile
                fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
            }
        }

        // skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);

        // then add it back (to demonstrate how)
        for (int k = 0; k < paddingout; k++)
            fputc(0x00, outptr);
            
        //repeat each row vertically n times| Set file pointer back to beginning of the scanline of the file being read
        if((i % n) <(n-1))
          fseek(inptr, -(((bi.biWidth/n)*3) +padding), SEEK_CUR);   
                
    }
 


    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
