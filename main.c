#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "matrix/matrix.h"
#include "matrix/ops.h"
#include "neural/activations.h"
#include "neural/nn.h"
#include "util/img.h"

int main() {
  srand(time(NULL));
  char* matrix_file_name = "matrix_mTest1.txt";
  char* images_file_name = "./data/mnist_test.csv";
  int number_of_images = 10;

  /*
    Matrix* mTest1 = matrix_create(28, 28);
    matrix_randomize(mTest1, 2);
    matrix_print(mTest1);
    matrix_save(mTest1, matrix_file_name);
    Matrix* mTest2 = matrix_load(matrix_file_name);
    matrix_print(mTest2);
    matrix_free(mTest1);
    matrix_free(mTest2);
  */

  /*
    Img** images = csv_to_imgs(images_file_name, number_of_images);
    for (int i = 0; i < 10; i++) {
      img_print(images[i]);
    }
    imgs_free(images, number_of_images);
  */

  // TRAINING
  //  int number_imgs = 10000;
  //  Img** imgs = csv_to_imgs("./data/mnist_test.csv", number_imgs);
  //  NeuralNetwork* net = network_create(784, 300, 10, 0.1);
  //  network_train_batch_imgs(net, imgs, number_imgs);
  //  network_save(net, "testing_net");

  // PREDICTING
  // int number_imgs = 3000;
  // Img** imgs = csv_to_imgs("data/mnist_test.csv", number_imgs);
  // NeuralNetwork* net = network_load("testing_net");
  // double score = network_predict_imgs(net, imgs, 1000);
  // printf("Score: %1.5f\n", score);

  // imgs_free(imgs, number_imgs);
  // network_free(net);
  return 0;
}
