/* here is the function file*/
#include "bmp24.h"
#include "t_bmp24.h"
#include <stdlib.h>
#include <stdio.h>

/* function that allocates memory for the pixel array */
t_pixel ** bmp24_allocateDataPixels(int width, int height) {

}

/* function that frees memory of the pixel array */
void bmp24_freeDataPixels(t_pixel ** pixels, int height) {

}

/* function that allocates memory for the t_bmp24 image structure */
t_bmp24 * bmp24_allocate(int width, int height, int colorDepth) {

}

/* function that frees the memory of a t_bmp24 image */
void bmp24_free(t_bmp24 * img) {

}

/* function that loads a 24-bit BMP image from a file */
t_bmp24 * bmp24_loadImage(const char * filename) {

}

/* function that saves a 24-bit BMP image into a file */
void bmp24_saveImage(t_bmp24 * img, const char * filename) {

}

/* function that reads one pixel from the file and stores it at (x, y) */
void bmp24_readPixelValue(t_bmp24 * img, int x, int y, FILE * file) {

}

/* function that reads all pixel data from the file into the image */
void bmp24_readPixelData(t_bmp24 * img, FILE * file) {

}

/* function that writes one pixel from (x, y) into the file */
void bmp24_writePixelValue(t_bmp24 * img, int x, int y, FILE * file) {

}

/* function that writes all pixel data into the file from the image */
void bmp24_writePixelData(t_bmp24 * img, FILE * file) {

}

/* function that inverts the colors of the image (negative) */
void bmp24_negative(t_bmp24 * img) {

}

/* function that converts the color image into grayscale */
void bmp24_grayscale(t_bmp24 * img) {

}

/* function that changes the brightness of the image */
void bmp24_brightness(t_bmp24 * img, int value) {

}

/* function that applies convolution at one pixel (returns a new pixel) */
t_pixel bmp24_convolution(t_bmp24 * img, int x, int y, float ** kernel, int kernelSize) {

}

/* function that applies box blur filter (smoothes the image) */
void bmp24_boxBlur(t_bmp24 * img) {

}

/* function that applies Gaussian blur filter (smoother blur) */
void bmp24_gaussianBlur(t_bmp24 * img) {

}

/* function that applies outline detection filter */
void bmp24_outline(t_bmp24 * img) { a

}

/* function that applies emboss effect */
void bmp24_emboss(t_bmp24 * img) {

}

/* function that applies sharpen filter (make edges sharper) */
void bmp24_sharpen(t_bmp24 * img) {

}