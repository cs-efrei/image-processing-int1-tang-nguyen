#include <stdio.h>
#include <stdlib.h>

#include "bmp8.h"
#include "t_bmp8.h"
int main(void)
{
    t_bmp8 * gray_image = bmp8_loadImage("lena_gray.bmp");
    t_bmp8 * color_image = bmp8_loadImage("../lena_color.bmp");
    bmp8_printInfo(gray_image);
    bmp8_saveImage2("new_image.bmp", gray_image);
    //t_bmp8 * new_image = bmp8_loadImage2("new_image.bmp");
    //bmp8_printInfo(new_image);
    bmp8_free(gray_image);
    return 0;
}