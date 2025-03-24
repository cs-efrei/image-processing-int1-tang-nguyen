
/* here is the function file*/
#include "bmp8.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
/*function that loads the image*/
t_bmp8 * bmp8_loadImage(const char * filename)
{
    FILE *file;
    t_bmp8 *fileloc;
    t_header *header_ptr;
    file = fopen(filename, "rb");
    if (file == NULL)
    {
        printf("Error open file\n");
        perror("Error opening file: ");
        return NULL;
    }

    fileloc = (t_bmp8*)malloc(sizeof(t_bmp8));
    if (fileloc == NULL)
    {
        printf("Error allocation fileloc\n");
        return NULL;
    }

    fread(fileloc->header,1,HEADER_SIZE, file);
    header_ptr = (t_header*)fileloc->header;
    printf("width = %d, height = %d\n", header_ptr->width, header_ptr->height);
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

