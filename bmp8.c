
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
    fileloc -> width = header_ptr -> width;
    fileloc -> height = header_ptr -> height;
    fileloc->colorDepth = header_ptr -> color_depth;
    printf("width = %d, height = %d\n", header_ptr->width, header_ptr->height);
    fclose(file);
    return fileloc;
}
/*function that saves the image*/
void bmp8_saveImage(const char *filename, t_bmp8 * img)
{
    FILE *new_file = fopen("filename", "w");
    fwrite(new_file,1,sizeof(t_bmp8), img);
    fclose(new_file);
}
/*function that frees the image from the memory*/
void bmp8_free(t_bmp8 * img)
{
    free(img);
}

/* function that prints image infos*/
void bmp8_printInfo(t_bmp8 * img)
{
    printf("width = %d\n", img -> width);
    printf("height = %d\n", img -> height);
    printf("dataSize = %d\n", img -> dataSize);
    printf("colorDepth = %d\n", img -> colorDepth);
}


t_bmp8 * bmp8_loadImage2(const char * filename)
{
     FILE *file;
     t_bmp8 *fileloc;
     file = fopen(filename, "rb");
     unsigned char  header[HEADER_SIZE];
     if (file == NULL)
     {
       printf("Error open file\n");
         return NULL;
     }

    fileloc = (t_bmp8*)malloc(sizeof(t_bmp8));
    if (fileloc == NULL)
    {
        printf("Error allocation fileloc\n");
        return NULL;
    }
    fread (header, 1, HEADER_SIZE, file);

    fileloc -> width = *(unsigned int *)(header + 18);
    fileloc -> height = *(unsigned int *)(header + 22);
    fileloc -> dataSize = *(unsigned int *)(header + 34);
    fileloc -> colorDepth = *(uint16_t *)(header + 28);
    fileloc -> data = (unsigned char *) (header + HEADER_SIZE);
    //printf("color = %d\n",*(uint32_t *)(header + 46));
    //printf("color planes = %d\n",*(uint16_t *)(header + 26));
    /*printf("%d\n", &(fileloc -> data));
    printf("width = %d\n", fileloc -> width);
    printf("height = %d\n", fileloc -> height);
    printf("dataSize = %d\n", fileloc -> dataSize);
    printf("colorDepth = %d\n", fileloc -> colorDepth);*/
    return fileloc;
}

