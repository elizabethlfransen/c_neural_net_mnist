cmake_minimum_required(VERSION 3.24)
project(c_neural_net_mnist C)

set(CMAKE_C_STANDARD 11)

add_executable(c_neural_net_mnist main.c mnist.c mnist.h io_util.c io_util.h render.c render.h)
