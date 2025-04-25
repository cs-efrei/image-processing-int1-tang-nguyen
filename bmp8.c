
/* here is the function file*/
#include "bmp8.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <strings.h>

#define OFFSET_WIDTH 18
#define OFFSET_HEIGHT 22
#define OFFSET_DATA_SIZE 34
#define OFFSET_COLOR_DEPTH 28

/*function that loads the image*/

/*function that saves the image*/
void bmp8_saveImage(const char *filename, t_bmp8 * img)
{
    FILE *new_file = fopen(filename, "wb");
    printf("Saving image...\n");
    for (int y = 0; y < img->dataSize; y++)
    {
      printf("%d", img->data[y]);
    }
    fwrite(img->data,sizeof(int),img->dataSize, new_file);
    printf("Image saved\n");
    fclose(new_file);
}
/*function that frees the image from the memory*/
void bmp8_free(t_bmp8 * img)
{
    free((void *)img->data);
    free((void*)img);
}

/* function that prints image infos*/
void bmp8_printInfo(t_bmp8 * img)
{
    printf("width = %d\n", img -> width);
    printf("height = %d\n", img -> height);
    printf("colorDepth = %d\n", img -> colorDepth);
    printf("dataSize = %d\n", img -> dataSize);
    printf("data = 0x%lx\n", img -> data);

}


t_bmp8 * bmp8_loadImage(const char * filename)
{
     FILE *file;
     t_bmp8 *fileloc;
     file = fopen(filename, "rb");
     uint8_t *image_ptr;

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

    fread (fileloc->header, 1, HEADER_SIZE, file);
    fileloc -> width = *(unsigned int *)(fileloc -> header + OFFSET_WIDTH);
    fileloc -> height = *(unsigned int *)(fileloc -> header + OFFSET_HEIGHT);
    fileloc -> dataSize = *(unsigned int *)(fileloc -> header + OFFSET_DATA_SIZE);
    fileloc -> colorDepth = *(uint16_t *)(fileloc -> header + OFFSET_COLOR_DEPTH);
    fread (fileloc->colorTable, 1, COLOR_TABLE_SIZE, file);
    image_ptr = (uint8_t*)malloc(fileloc -> dataSize);
    fread(image_ptr, 1, fileloc -> dataSize, file);
    fileloc -> data = (unsigned char *)image_ptr;
    return fileloc;
}
void bmp8_negative(t_bmp8 * img)
{

}


void bmp8_brightness(t_bmp8 * img, int value)
{

}


void bmp8_threshold(t_bmp8 * img, int threshold)
{

}

void bmp8_saveImage2(const char *filename, t_bmp8 *img)
{
    FILE *new_file = fopen(filename, "wb");
    if (new_file == NULL) {
        perror("Failed to open file");
        return;
    }

    printf("Saving image...\n");


    fwrite(img->header, sizeof(unsigned char), HEADER_SIZE, new_file);


    fwrite(img->colorTable, sizeof(unsigned char), COLOR_TABLE_SIZE, new_file);


    fwrite(img->data, sizeof(unsigned char), img->dataSize, new_file);

    printf("Image saved\n");
    fclose(new_file);
}