#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "util/img.h"
#include "neural/activations.h"
#include "neural/nn.h"
#include "matrix/matrix.h"
#include "matrix/ops.h"

int main() {
	srand(time(NULL));
	// TRAINING
	// Img** imgs = csv_to_imgs("data/mnist_train.csv", 30000);
	// NeuralNetwork* net = network_create(784, 300, 10, 0.1);
	// network_train_batch_imgs(net, imgs, 30000);
	// network_save(net, "testing_net");

	// PREDICTING
	Img** imgs = csv_to_imgs("data/mnist_test.csv", 2);
	img_print(imgs[1]);
	NeuralNetwork* net = network_load("testing_net");
	Matrix *m = network_predict_img(net, imgs[1]);
	printf("Prediction from Network: %d", matrix_argmax(m));

	return 0;
}
