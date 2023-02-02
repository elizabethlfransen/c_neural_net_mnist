#!/bin/bash

OUTPUT_DIR=data
URLS=(
  http://yann.lecun.com/exdb/mnist/train-images-idx3-ubyte.gz
  http://yann.lecun.com/exdb/mnist/train-labels-idx1-ubyte.gz
  http://yann.lecun.com/exdb/mnist/t10k-images-idx3-ubyte.gz
  http://yann.lecun.com/exdb/mnist/t10k-labels-idx1-ubyte.gz
)

mkdir -p data
pushd data || exit
for val in "${URLS[@]}"; do
 curl -O -J "$val"
done
gzip -d -f ./*.gz

popd || exit