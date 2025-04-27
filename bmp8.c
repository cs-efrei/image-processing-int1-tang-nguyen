
/* here is the function file*/
#include "bmp8.h"
#include "t_bmp8.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <strings.h>

#define OFFSET_WIDTH 18
#define OFFSET_HEIGHT 22
#define OFFSET_DATA_SIZE 34
#define OFFSET_COLOR_DEPTH 28

/*function that loads the image*/
t_bmp8 * bmp8_loadImage(const char * filename)
{
    FILE *file; // creates a variable of type FILE
    t_bmp8 *fileloc; // creates a variable of type t_bmp8
    file = fopen(filename, "rb"); // open the file
    uint8_t *image_ptr; // initializing a pointer that will allow us to run through akk the data of the image

    if (file == NULL)// case if we can't open the file
    {
        printf("Error open file\n");
        return NULL;
    }//

    fileloc = (t_bmp8*)malloc(sizeof(t_bmp8)); //allocating some memory to store every information required by the t_bmp8 format
    if (fileloc == NULL)// if we can't allocate that memory
    {
        printf("Error allocation fileloc\n");
        return NULL;
    }//
    // filling all the information
    fread (fileloc->header, 1, HEADER_SIZE, file); // read the header only then fill all the information that are in the header
    fileloc -> width = *(unsigned int *)(fileloc -> header + OFFSET_WIDTH);// information in the header
    fileloc -> height = *(unsigned int *)(fileloc -> header + OFFSET_HEIGHT); // information in the header
    fileloc -> dataSize = *(unsigned int *)(fileloc -> header + OFFSET_DATA_SIZE); // information in the header
    fileloc -> colorDepth = *(uint16_t *)(fileloc -> header + OFFSET_COLOR_DEPTH); // information in the header
    fread (fileloc->colorTable, 1, COLOR_TABLE_SIZE, file); // reads the colorTable which is 1024 octets long
    image_ptr = (uint8_t*)malloc(fileloc -> dataSize); //allocates some memory in order to store all the data in an array
    fread(image_ptr, 1, fileloc -> dataSize, file);// fills the allocated memory
    fileloc -> data = (unsigned char *)image_ptr; // filling fileloc -> data
    return fileloc;
}
/*function that saves the image*/
void bmp8_saveImage(const char *filename, t_bmp8 *img)
{
    FILE *new_file = fopen(filename, "wb"); // opening the new file we're copying into
    if (new_file == NULL) { // case if we can't open the file
        perror("Failed to open file");
        return;
    }
    // copying every "big parts" into the new file
    printf("Saving image...\n");
    fwrite(img->header, sizeof(unsigned char), HEADER_SIZE, new_file);
    fwrite(img->colorTable, sizeof(unsigned char), COLOR_TABLE_SIZE, new_file);
    fwrite(img->data, sizeof(unsigned char), img->dataSize, new_file);

    printf("Image saved\n");
    fclose(new_file); //closing the new file
}
/*function that frees the image from the memory*/
void bmp8_free(t_bmp8 * img)
{
    free((void *)img->data);// since we have 2 malloc, we free 2 times, img->data before since we can't do it all the way around.
    free((void*)img); // finally freeing our image
}

/* function that prints image infos*/
void bmp8_printInfo(t_bmp8 * img)
{
    //printing every informations
    printf("width = %d\n", img -> width);
    printf("height = %d\n", img -> height);
    printf("colorDepth = %d\n", img -> colorDepth);
    printf("dataSize = %d\n", img -> dataSize);
    printf("data = 0x%lx\n", img -> data);

}
