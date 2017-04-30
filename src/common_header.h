#ifndef KALMANFILTER_COMMON_HEADER_H
#define KALMANFILTER_COMMON_HEADER_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include "Eigen/Dense"
#include "measurement_package.h"
#include "tracking.h"

using namespace std;
using Eigen::MatrixXd;
using Eigen::VectorXd;
using std::vector;


int computeJacobain();

int compute_RMSE();

#endif //KALMANFILTER_COMMON_HEADER_H
