#include "matrix.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXCHAR 100

#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define YEL "\x1B[33m"
#define BLU "\x1B[34m"
#define MAG "\x1B[35m"
#define CYN "\x1B[36m"
#define WHT "\x1B[37m"
#define RESET "\x1B[0m"

Matrix* matrix_create(int row, int col) {
  Matrix* matrix = malloc(sizeof(Matrix));
  matrix->rows = row;
  matrix->cols = col;
  matrix->entries = malloc(row * sizeof(double*));
  for (int i = 0; i < row; i++) {
    matrix->entries[i] = malloc(col * sizeof(double));
  }
  return matrix;
}

void matrix_fill(Matrix* m, int n) {
  for (int i = 0; i < m->rows; i++) {
    for (int j = 0; j < m->cols; j++) {
      m->entries[i][j] = n;
    }
  }
}

void matrix_free(Matrix* m) {
  for (int i = 0; i < m->rows; i++) {
    free(m->entries[i]);
  }
  free(m->entries);
  free(m);
}

void matrix_print(Matrix* m) {
  printf("Rows: %d Columns: %d\n", m->rows, m->cols);
  for (int i = 0; i < m->rows; i++) {
    for (int j = 0; j < m->cols; j++) {
      if (m->entries[i][j] < 0.12) {
        printf(RED);
      } else if (m->entries[i][j] < 0.24) {
        printf(GRN);
      } else if (m->entries[i][j] < 0.36) {
        printf(YEL);
      } else if (m->entries[i][j] < 0.48) {
        printf(BLU);
      } else if (m->entries[i][j] < 0.6) {
        printf(MAG);
      } else if (m->entries[i][j] < 0.72) {
        printf(CYN);
      } else if (m->entries[i][j] < 0.84) {
        printf(WHT);
      } else {
        printf(RESET);
      }
      printf("% 1.3f ", m->entries[i][j]);
    }
    printf(RESET);
    printf("\n");
  }
  printf("\n");
}

Matrix* matrix_copy(Matrix* m) {
  Matrix* mat = matrix_create(m->rows, m->cols);
  for (int i = 0; i < m->rows; i++) {
    for (int j = 0; j < m->cols; j++) {
      mat->entries[i][j] = m->entries[i][j];
    }
  }
  return mat;
}

void matrix_save(Matrix* m, char* file_string) {
  FILE* file = fopen(file_string, "w");
  fprintf(file, "%d\n", m->rows);
  fprintf(file, "%d\n", m->cols);
  for (int i = 0; i < m->rows; i++) {
    for (int j = 0; j < m->cols; j++) {
      fprintf(file, "%.6f\n", m->entries[i][j]);
    }
  }
  printf("Successfully saved matrix to %s\n", file_string);
  fclose(file);
}

Matrix* matrix_load(char* file_string) {
  FILE* file = fopen(file_string, "r");
  char entry[MAXCHAR];
  fgets(entry, MAXCHAR, file);
  int rows = atoi(entry);
  fgets(entry, MAXCHAR, file);
  int cols = atoi(entry);
  Matrix* m = matrix_create(rows, cols);
  for (int i = 0; i < m->rows; i++) {
    for (int j = 0; j < m->cols; j++) {
      fgets(entry, MAXCHAR, file);
      m->entries[i][j] = strtod(entry, NULL);
    }
  }
  printf("Sucessfully loaded matrix from %s\n", file_string);
  fclose(file);
  return m;
}

double uniform_distribution(double low, double high) {
  double difference = high - low;
  int scale = 10000;
  int scaled_difference = (int)(difference * scale);
  return low + (1.0 * (rand() % scaled_difference) / scale);
}

void matrix_randomize(Matrix* m, int n) {
  double min = -1.0 / sqrt(n);
  double max = 1.0 / sqrt(n);
  for (int i = 0; i < m->rows; i++) {
    for (int j = 0; j < m->cols; j++) {
      m->entries[i][j] = uniform_distribution(min, max);
    }
  }
}

int matrix_argmax(Matrix* m) {
  double max_score = 0;
  int max_idx = 0;
  for (int i = 0; i < m->rows; i++) {
    if (m->entries[i][0] > max_score) {
      max_score = m->entries[i][0];
      max_idx = i;
    }
  }
  return max_idx;
}

Matrix* matrix_flatten(Matrix* m, int axis) {
  Matrix* mat;
  if (axis == 0) {
    mat = matrix_create(m->rows * m->cols, 1);
  } else if (axis == 1) {
    mat = matrix_create(1, m->rows * m->cols);
  } else {
    printf("Argument to matrix_flatten must be 0 or 1");
    exit(EXIT_FAILURE);
  }
  for (int i = 0; i < m->rows; i++) {
    for (int j = 0; j < m->cols; j++) {
      if (axis == 0) {
        mat->entries[i * m->cols + j][0] = m->entries[i][j];
      } else if (axis == 1) {
        mat->entries[0][i * m->cols + j] = m->entries[i][j];
      }
    }
  }
  return mat;
}
