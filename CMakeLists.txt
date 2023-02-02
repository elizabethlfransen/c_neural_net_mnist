cmake_minimum_required(VERSION 3.24)
project(c_neural_net_mnist C)

set(CMAKE_C_STANDARD 11)

find_package(Curses REQUIRED)
add_executable(c_neural_net_mnist main.c mnist.c mnist.h io_util.c io_util.h app/app.c app/app.h app/state.c app/state.h app/data_viewer.c app/data_viewer.h app/colors.h app/colors.c)
target_link_libraries(c_neural_net_mnist ${CURSES_LIBRARIES})
