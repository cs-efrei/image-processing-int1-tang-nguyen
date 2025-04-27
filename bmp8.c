
/* here is the function file*/
#include "bmp8.h"
#include "t_bmp8.h"
#include <stdlib.h>
#include <stdio.h>

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

/* function that transforms an image into its negative version */
void bmp8_negative(t_bmp8 * img) {
    for (int i = 0; i < (int)img->dataSize; i++) {
        img->data[i] = 255 - img->data[i];  // Inverts the brightness
    }
}

/* function that adjusts the brightness of an image */
void bmp8_brightness(t_bmp8 * img, int value)
{
    for (int i = 0; i < (int)img->dataSize; i++) {
        int new_val = img->data[i] + value;

        // Makes sure the value (pixel) stays between 0 (black) - 255 (white) //
        if (new_val > 255) new_val = 255;
        if (new_val < 0) new_val = 0;
        img->data[i] = (char)new_val; // Inverts the brightness
    }
}

/* function that applies a threshold to convert the image to black and white */
void bmp8_threshold(t_bmp8 * img, int threshold)
{
    for (int i = 0; i < (int)img->dataSize; i++) {
        if (img->data[i] >= threshold) {
            img->data[i] = 255; // Sets to white
        } else {
            img->data[i] = 0; // Sets to black
        }
    }
}

/* function that applies a filter (convolution) to a grayscale image */
void bmp8_applyFilter(t_bmp8 * img, float ** kernel, int kernelSize) {
    int k = kernelSize / 2; // Gets the index of the kernel's center (for a 3x3 kernel, k=1)

    char *new_data = (char *)malloc(img->dataSize); // Allocates memory for new pixel data after filtering
    if (new_data == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    // Copies the original image first (borders unchanged)
    for (int i = 0; i < (int)img->dataSize; i++) {
        new_data[i] = img->data[i];
    }
    // Loop over the image (border pixels excluded)
    for (int y = k; y < (int)img->height - k; y++) {
        for (int x = k; x < (int)img->width - k; x++) {
            float sum = 0.0; // Will store the result

            // Loop over the kernel matrix
            for (int i = -k; i <= k; i++) {
                for (int j = -k; j <= k; j++) {
                    int xi = x + j; // horizontal coordinate
                    int yi = y + i; // vertical coordinate

                    char pixel = img->data[yi * img->width + xi]; // Pixel value from original image
                    float weight = kernel[i + k][j + k]; // Weight from kernel
                    sum += pixel * weight;
                }
            }
            // Result between 0 and 255
            if (sum > 255) sum = 255;
            if (sum < 0) sum = 0;

            new_data[y * img->width + x] = (char)(sum); // Saves the computed value
        }
    }
    // Copies the filtered pixels into the original image structure
    for (int i = 0; i < (int)img->dataSize; i++) {
        img->data[i] = new_data[i];
    }
    free(new_data);
}