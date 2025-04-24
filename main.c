#include <stdio.h>

#include "bmp8.h"
#include "t_bmp8.h"
int main(void)
{
    bmp8_loadImage2("lena_gray.bmp");
    //printf("%d",sizeof(t_header));
    bmp8_loadImage2("../lena_color.bmp");
    return 0;
}