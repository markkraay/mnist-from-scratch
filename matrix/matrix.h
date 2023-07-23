#pragma once

/**
 * @brief Matrix with type double entries and its number of rows and columns.
 */
typedef struct {
  double** entries;
  int rows;
  int cols;
} Matrix;

/**
 * @brief Creates an empty matrix with type double entries.
 * @param row Number of rows.
 * @param col Number of columns.
 * @return An empty matrix with the number of entries for the rows and columns.
 */
Matrix* matrix_create(int, int);

/**
 * @brief Fills a matrix with one type int value.
 * @param m The matrix to be filled.
 * @param n The value for each entry in the matrix.
 */
void matrix_fill(Matrix*, int);

/**
 * @brief Completely frees the matrix malloc'd space.
 * @param m Matrix to be freed.
 */
void matrix_free(Matrix*);

/**
 * @brief Prints number of rows and columns and all entries of a matrix.
 * @param m Matrix to be printed.
 */
void matrix_print(Matrix*);

/**
 * @brief Creates new matrix with all entries equal to input.
 * @param m Inputed matrix to be copied.
 * @return A matrix with all entries equal to the input matrix.
 */
Matrix* matrix_copy(Matrix*);

/**
 * @brief Saves all the content of a matrix in a file.
 * @param m Matrix to be saved.
 * @param file_string Name of the file in which matrix will be saved.
 */
void matrix_save(Matrix*, char*);

/**
 * @brief Reads a file and loads matrix saved in it.
 * @param file_string Name of the file containing the matrix.
 * @return A matrix with all entries from the file.
 */
Matrix* matrix_load(char*);

/**
 * @brief Gets a number from an uniform distribution between low and high.
 * @param low Lowest random number possible.
 * @param high Highest random number possible.
 * @return Double type random number between low and high.
 */
double uniform_distribution(double, double);

/**
 * @brief Fills a matrix with random numbers between a function of the input.
 * @param m Matrix to be filled with random numbers.
 * @param n Number where entries are between -1/sqrt(n) and 1/sqrt(n).
 */
void matrix_randomize(Matrix*, int);

/**
 * @brief Gets the first maximum entry of a Mx1 matrix's index.
 * @param m Mx1 matrix to be checked.
 * @return The index of the first maximum entry of the input matrix.
 */
int matrix_argmax(Matrix*);

/**
 * @brief Gets a one-dimension matrix with all entries from the input matrix.
 * @param m Input matrix.
 * @param axis Flatten mode: 0 for a one-column matrix, 1 for a one-row matrix.
 * @return A one-dimension matrix with all the entries from the input matrix.
 */
Matrix* matrix_flatten(Matrix*, int);
