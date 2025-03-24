#include <stdio.h>

#include "bmp8.h"
#include "t_bmp8.h"
int main(void)
{
    bmp8_loadImage("lena_gray.bmp");
    //printf("%d",sizeof(t_header));
    return 0;
}