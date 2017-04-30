project(KalmanFilter)

cmake_minimum_required(VERSION 3.5)

add_definitions(-std=c++0x)

set(sources src/main.cpp src/kalman_filter.cpp src/kalman_filter.h src/tracking.cpp src/tracking.h src/measurement_package.h src/CalculateJacobian.cpp src/common_header.h)

add_executable(KalmanFilter ${sources})