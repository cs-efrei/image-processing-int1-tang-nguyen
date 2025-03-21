
/* here is the function file*/
#include "bmp8.h"
#include <stdlib.h>
#include <stdio.h>
/*function that loads the image*/
t_bmp8 * bmp8_loadImage(const char * filename)
{
    FILE *file = fopen(filename, "rb");
    t_bmp8 *fileloc = (t_bmp8*)malloc(sizeof(t_bmp8));
    if (fileloc == NULL)
    {
        printf("Error opening file\n");
        return NULL;
    }
    fread(fileloc, sizeof(t_bmp8), 1, file);
    fileloc->dataSize = *(unsigned int*)&file[18];
    fclose(file);
    return fileloc;
}
/*function that saves the image*/
void bmp8_saveImage(const char *filename, t_bmp8 * img)
{

}
/*function that frees the image from the memory*/
void bmp8_free(t_bmp8 * img)
{

}

/* function that prints image infos*/
void bmp8_printInfo(t_bmp8 * img)
{

}