//
// Created by minh- on 21/03/2025.
//
#include "t_bmp8.h"
#ifndef BMP8_H
#define BMP8_H
t_bmp8 * bmp8_loadImage(const char * filename);
void bmp8_saveImage(const char * filename, t_bmp8 * img);
void bmp8_free(t_bmp8 * img);
void bmp8_printInfo(t_bmp8 * img);
#endif //BMP8_H
