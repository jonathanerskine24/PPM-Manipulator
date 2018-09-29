#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ppm.h"

////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char **argv) {
	ppmPic *origPic, *newPic;

	if (argc != 3) {
		printf("Usage: ./a.out <option> ppm-file\n");
		return 1;
	}

	printf("reading the original image...\n");
	origPic = readPic(argv[2]);
	if (origPic == NULL) {
		printf("File %s could not be read\n", argv[2]);
		// return 1;
	}

	if (strcmp(argv[1], "rotateLeft") == 0) {
		printf("rotating the image to the left...\n");
		newPic = rotateLeft(origPic);
		writePic(newPic, argv[2]);
	}
	else if (strcmp(argv[1], "rotateRight") == 0) {
		printf("rotating the image to the right...\n");
		newPic = rotateRight(origPic);
		writePic(newPic, argv[2]);
	}
	else if (strcmp(argv[1], "flipVertical") == 0) {
		printf("flipping the image vertically...\n");
		newPic = flipVertical(origPic);
		writePic(newPic, argv[2]);
	}
	else if (strcmp(argv[1], "flipHorizontal") == 0) {
		printf("flipping the image horizontally...\n");
		newPic = flipHorizontal(origPic);
		writePic(newPic, argv[2]);
	}
	else if (strcmp(argv[1], "invert") == 0) {
		printf("inverting the image...\n");
		newPic = invert(origPic);
		writePic(newPic, argv[2]);
	}
	else if (strcmp(argv[1], "duplicate") == 0) {
		printf("duplicating the image...\n");
		newPic = duplicate(origPic);
		writePic(newPic, argv[2]);
	}
	else {
		printf("%s is an invalid option...\n", argv[1]);
	}

	return 0;
}
