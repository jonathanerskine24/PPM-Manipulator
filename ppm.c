#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ppm.h"

//////////////////////////////////////////////////////////////////////////////////////

ppmPic *readPic(char *fileName) {
	char temp[2];
	FILE *pic = fopen(fileName, "r");
	fscanf(pic, "%s", temp);

	ppmPic *image = malloc(sizeof(ppmPic));
	fscanf(pic, "%d", &image->cols);
	fscanf(pic, "%d", &image->rows);
	fscanf(pic, "%d", &image->colors);

	image->pixels = malloc(sizeof(Pixel *) * (image->rows));
	for (int i = 0; i<image->rows; i++) 
		image->pixels[i] = malloc(sizeof(Pixel) * (image->cols));
	
	for (int a = 0; a<image->rows; a++) {
		for (int b = 0; b<image->cols; b++) {
			fscanf(pic, "%d", &image->pixels[a][b].red);
			fscanf(pic, "%d", &image->pixels[a][b].green);
			fscanf(pic, "%d", &image->pixels[a][b].blue);
		} 
	}

	return image;
}

void writePic(ppmPic *myPic, char *fileName) {
	char newFileName[100] = {};
	int len = strlen(fileName);
	strncpy(newFileName, fileName, (len-4));
	strcat(newFileName, "-NEW.ppm\0");
	FILE *new = fopen(newFileName, "w");
	fprintf(new, "P3\n%d %d\n%d\n", myPic->cols, myPic->rows, myPic->colors);
	for (int a = 0; a<myPic->rows; a++) {
		for (int b = 0; b<myPic->cols; b++) {
			fprintf(new, "%d ", myPic->pixels[a][b].red);
			fprintf(new, "%d ", myPic->pixels[a][b].green);
			fprintf(new, "%d ", myPic->pixels[a][b].blue);
		}
		fprintf(new, "\n ");
	}
}

ppmPic *rotateLeft(ppmPic *image) {
	ppmPic *rotatedImage = malloc(sizeof(ppmPic));
	rotatedImage->cols = image->rows;
	rotatedImage->rows = image->cols;
	rotatedImage->colors = image->colors;

	rotatedImage->pixels = malloc(sizeof(Pixel *) * (rotatedImage->rows));
	for (int i = 0; i<rotatedImage->rows; i++) 
		rotatedImage->pixels[i] = malloc(sizeof(Pixel) * (rotatedImage->cols));

	for (int a = 0; a<rotatedImage->rows; a++) {
		for (int b = 0; b<rotatedImage->cols; b++) {
			rotatedImage->pixels[a][b].red = image->pixels[b][(rotatedImage->rows - 1) - a].red; 
			rotatedImage->pixels[a][b].green = image->pixels[b][(rotatedImage->rows - 1) - a].green;
			rotatedImage->pixels[a][b].blue = image->pixels[b][(rotatedImage->rows - 1) - a].blue;
		}
	}
	return rotatedImage;
}

ppmPic *rotateRight(ppmPic *image) {
	ppmPic *rotatedImage = malloc(sizeof(ppmPic));
	rotatedImage->cols = image->rows;
	rotatedImage->rows = image->cols;
	rotatedImage->colors = image->colors;

	rotatedImage->pixels = malloc(sizeof(Pixel *) * (rotatedImage->rows));
	for (int i = 0; i<rotatedImage->rows; i++) 
		rotatedImage->pixels[i] = malloc(sizeof(Pixel) * (rotatedImage->cols));

	for (int a = 0; a<rotatedImage->rows; a++) {
		for (int b = 0; b<rotatedImage->cols; b++) {
			rotatedImage->pixels[a][b].red = image->pixels[(rotatedImage->cols - 1) - b][a].red;
			rotatedImage->pixels[a][b].green = image->pixels[(rotatedImage->cols - 1) - b][a].green;
			rotatedImage->pixels[a][b].blue = image->pixels[(rotatedImage->cols - 1) - b][a].blue;
		}
	}
	return rotatedImage;
}

ppmPic *flipHorizontal(ppmPic *image) {
	ppmPic *flippedImage = malloc(sizeof(ppmPic));
	flippedImage->cols = image->cols;
	flippedImage->rows = image->rows;
	flippedImage->colors = image->colors;

	flippedImage->pixels = malloc(sizeof(Pixel *) * (flippedImage->rows));
	for (int i = 0; i<flippedImage->rows; i++) 
		flippedImage->pixels[i] = malloc(sizeof(Pixel) * (flippedImage->cols));

	for (int a = 0; a<flippedImage->rows; a++) {
		for (int b = 0; b<flippedImage->cols; b++) {
			flippedImage->pixels[a][b].red = image->pixels[a][(flippedImage->cols - 1) - b].red;
			flippedImage->pixels[a][b].green = image->pixels[a][(flippedImage->cols - 1) - b].green;
			flippedImage->pixels[a][b].blue = image->pixels[a][(flippedImage->cols - 1) - b].blue;
		}
	}
	return flippedImage;
}

ppmPic *flipVertical(ppmPic *image) {
	ppmPic *flippedImage = malloc(sizeof(ppmPic));
	flippedImage->cols = image->cols;
	flippedImage->rows = image->rows;
	flippedImage->colors = image->colors;

	flippedImage->pixels = malloc(sizeof(Pixel *) * (flippedImage->rows));
	for (int i = 0; i<flippedImage->rows; i++) 
		flippedImage->pixels[i] = malloc(sizeof(Pixel) * (flippedImage->cols));

	for (int a = 0; a<flippedImage->rows; a++) {
		for (int b = 0; b<flippedImage->cols; b++) {
			flippedImage->pixels[a][b].red = image->pixels[(flippedImage->rows -1) - a][b].red;
			flippedImage->pixels[a][b].green = image->pixels[(flippedImage->rows -1) - a][b].green;
			flippedImage->pixels[a][b].blue = image->pixels[(flippedImage->rows -1) - a][b].blue;
		}
	}
	return flippedImage;
}

ppmPic *invert(ppmPic *image) {
	for (int a = 0; a<image->rows; a++) {
		for (int b = 0; b<image->cols; b++) {
			image->pixels[a][b].red = 255 - image->pixels[a][b].red;
			image->pixels[a][b].green = 255 - image->pixels[a][b].green;
			image->pixels[a][b].blue = 255 - image->pixels[a][b].blue;
		}
	}
	return image;
}

ppmPic *duplicate(ppmPic *thePic) {
	return thePic;
}


