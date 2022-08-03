#!/bin/sh
curl -Z --output-dir data \
	-sO 'https://pjreddie.com/media/files/mnist_train.csv' \
	-sO 'https://pjreddie.com/media/files/mnist_test.csv'
