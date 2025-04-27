#ifndef BMP24_H
#define BMP24_H

#include <stdio.h>
#include <stdint.h>
#include "t_bmp24.h"

t_pixel ** bmp24_allocateDataPixels(int width, int height);
void bmp24_freeDataPixels(t_pixel ** pixels, int height);

t_bmp24 * bmp24_allocate(int width, int height, int colorDepth);
void bmp24_free(t_bmp24 * img);

t_bmp24 * bmp24_loadImage(const char * filename);
void bmp24_saveImage(t_bmp24 * img, const char * filename);

void bmp24_readPixelValue(t_bmp24 * img, int x, int y, FILE * file);
void bmp24_readPixelData(t_bmp24 * img, FILE * file);
void bmp24_writePixelValue(t_bmp24 * img, int x, int y, FILE * file);
void bmp24_writePixelData(t_bmp24 * img, FILE *  file);

// Image processing
void bmp24_negative(t_bmp24 * img);
void bmp24_grayscale(t_bmp24 * img);
void bmp24_brightness(t_bmp24 * img, int value);

// Convolution
t_pixel bmp24_convolution(t_bmp24 * img, int x, int y, float ** kernel, int kernelSize);
void bmp24_boxBlur(t_bmp24 * img);
void bmp24_gaussianBlur(t_bmp24 * img);
void bmp24_outline(t_bmp24 * img);
void bmp24_emboss(t_bmp24 * img);
void bmp24_sharpen(t_bmp24 * img);

#endif // BMP24_H
