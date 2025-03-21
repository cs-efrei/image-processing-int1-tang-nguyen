//
// Created by minh- on 21/03/2025.
//

#ifndef T_BMP8_H
#define T_BMP8_H
typedef struct {
    unsigned char header[54];
    unsigned char colorTable[1024];
    unsigned char * data;
    unsigned int width;
    unsigned int height;
    unsigned int colorDepth;
    unsigned int dataSize;
} t_bmp8;
#endif //T_BMP8_H
