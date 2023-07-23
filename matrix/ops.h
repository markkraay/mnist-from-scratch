#pragma once

#include "matrix.h"

/**
 * @brief Checks if two matrices have the same number of rows and columns.
 * @param m1 First matrix to be checked.
 * @param m2 Second matrix to be checked.
 * @return 1 if matrices have the same dimensions, 0 if not.
 */
int check_dimensions(Matrix*, Matrix*);

/**
 * @brief Multiplies each matching index entry of a matrix with another.
 * @param m1 First matrix.
 * @param m2 Second matrix.
 * @return Matrix with entries multiplied by m1*m2.
 */
Matrix* multiply(Matrix*, Matrix*);

/**
 * @brief Adds each matching index entry of a matrix with another.
 * @param m1 First matrix.
 * @param m2 Second matrix.
 * @return Matrix with entries added by m1+m2.
 */
Matrix* add(Matrix*, Matrix*);

/**
 * @brief Subtracts each matching index entry of a matrix with another.
 * @param m1 First matrix.
 * @param m2 Second matrix.
 * @return Matrix with entries subtracted m1-m2.
 */
Matrix* subtract(Matrix*, Matrix*);

/**
 * @brief Does the dot matrix multiplication between the inputs.
 * @param m1 First matrix.
 * @param m2 Second matrix.
 * @return Result matrix of the dot multiplication by m1.m2.
 */
Matrix* dot(Matrix*, Matrix*);

/**
 * @brief Applies a function to each of the entries in the input matrix.
 * @param func Function to be applied to the entries.
 * @param m Matrix to be copied and transformed.
 * @return Matrix with each of its entries transformed by the function inputed.
 */
Matrix* apply(double (*)(double), Matrix*);

/**
 * @brief Gets a matrix equal to the input matrix multiplied by a number.
 * @param n Number to multiply each entry of the matrix.
 * @param m Matrix to be copied and scaled.
 * @return Scaled matrix.
 */
Matrix* scale(double, Matrix*);

/**
 * @brief Gets a matrix equal to the input matrix added by a number.
 * @param n Number to add each entry of the matrix.
 * @param m Matrix to be copied and scaled.
 * @return Scaled matrix.
 */
Matrix* addScalar(double, Matrix*);

/**
 * @brief Creates matrix with the rows and columns transposed from a matrix.
 * @param m Matrix to be copied and transposed.
 * @return Matrix with its rows as the input matrix's columns and vice versa.
 */
Matrix* transpose(Matrix*);
