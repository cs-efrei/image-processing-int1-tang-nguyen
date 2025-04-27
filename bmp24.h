#ifndef BMP24_H
#define BMP24_H

#include <stdio.h>
#include <stdint.h>
#include "t_bmp24.h"

// Offsets for the BMP header
#define BITMAP_MAGIC 0x00 // offset 0
#define BITMAP_SIZE 0x02 // offset 2
#define BITMAP_OFFSET 0x0A // offset 10
#define BITMAP_WIDTH 0x12 // offset 18
#define BITMAP_HEIGHT 0x16 // offset 22
#define BITMAP_DEPTH 0x1C // offset 28
#define BITMAP_SIZE_RAW 0x22 // offset 34

// Magical number for BMP files
#define BMP_TYPE 0x4D42 // 'BM' in hexadecimal

// Header sizes
#define HEADER_SIZE 0x0E // 14 octets
#define INFO_SIZE 0x28 // 40 octets

// Constant for the color depth
#define DEFAULT_DEPTH 0x18 // 24

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
