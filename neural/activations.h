#pragma once

#include "../matrix/matrix.h"

/**
 * @brief Sigmoid function.
 * @param input Input to the sigmoid function.
 * @return Result from the function 1.0/(1+exp(-1*input)).
 */
double sigmoid(double input);

Matrix* sigmoidPrime(Matrix* m);

Matrix* softmax(Matrix* m);
