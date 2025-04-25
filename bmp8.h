//
// Created by minh- on 21/03/2025.
//
#ifndef BMP8_H
#define BMP8_H
#include <stdint.h>

#define HEADER_SIZE 54
#define COLOR_TABLE_SIZE 1024


#pragma pack(2)
typedef struct
{
    uint16_t signature;
    uint32_t file_size;
    uint16_t reserved_1;
    uint16_t reserved_2;
    uint32_t offset;
    uint32_t header_size;
    uint32_t width;
    uint32_t height;
    uint16_t color_planes;
    uint16_t color_depth;
    uint32_t compression;
    uint32_t data_size;
    uint32_t horizontal_resolution;
    uint32_t vertical_resolution;
    uint32_t number_of_colors;
    uint32_t important_colors;
}t_header;


t_bmp8 * bmp8_loadImage(const char * filename);
void bmp8_saveImage(const char * filename, t_bmp8 * img);
void bmp8_saveImage2(const char * filename, t_bmp8 * img);
void bmp8_free(t_bmp8 * img);
void bmp8_printInfo(t_bmp8 * img);
void bmp8_negative(t_bmp8 * img);
void bmp8_brightness(t_bmp8 * img, int value);
void bmp8_threshold(t_bmp8 * img, int threshold);


#endif //BMP8_H
