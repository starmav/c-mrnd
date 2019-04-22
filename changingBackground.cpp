#define _CRT_SECURE_NO_WARNINGS
#include "qdbmp.h"
#include <stdlib.h>
#include <string.h>
#include<stdio.h>
#include<conio.h>
int main(){
	UCHAR	r, g, b;
	UCHAR	r1, g1, b1;
	UINT	width, height;
	UINT	x, y;
	BMP* bmp;
	BMP* bmp1;
	BMP* bmp2;
	bmp = BMP_ReadFile("pic1.bmp");
	bmp1 = BMP_ReadFile("pic2.bmp");
	bmp2 = BMP_ReadFile("pic3.bmp");
	BMP_CHECK_ERROR(stdout, -1);

	width = BMP_GetWidth(bmp);
	height = BMP_GetHeight(bmp);

	for (x = 0; x < width;++x )
	{
		for (y = 0; y < height;++y )
		{
			/* Get pixel's RGB values */
			BMP_GetPixelRGB(bmp, x, y, &r, &g, &b);
			BMP_GetPixelRGB(bmp1, x, y, &r1, &g1, &b1);
			if ((r != r1)||(g!=g1)||(b!=b1)){
				BMP_SetPixelRGB(bmp2, x, y, r1, g1, b1);
				printf("changed");
			}
			
		}
	
	}

	BMP_WriteFile(bmp2,"pic4.bmp");

	BMP_Free(bmp);
	return 0;
}