#pragma once

#include "../matrix/matrix.h"

/**
 * @brief Image with a type Matrix* data structure and a label.
 */
typedef struct {
  Matrix* img_data;
  int label;
} Img;

/**
 * @brief Reads and formats images from a csv file to Img type matrices.
 * @param file_string Name of the file with the images.
 * @param number_of_imgs Maximum number of images to be read.
 * @return A pointer of images read from the csv file specified.
 */
Img** csv_to_imgs(char*, int);

/**
 * @brief Prints the matrix in the image with the label.
 * @param img Image to be printed.
 */
void img_print(Img*);

/**
 * @brief Completely frees the image and its matrix.
 * @param img Image to be freed.
 */
void img_free(Img*);

/**
 * @brief Completely frees multiple images and its matrices.
 * @param img Images to be freed.
 * @param n Number of images to be freed.
 */
void imgs_free(Img**, int);
