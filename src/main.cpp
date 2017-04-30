#include "common_header.h"

vector<MeasurementPackage> buildMeasurementPack() {
    /*******************************************************************************
     *  Set Measurements															 *
     *******************************************************************************/
    vector<MeasurementPackage> measurement_pack_list;

    // hardcoded input file with laser and radar measurements
    string measurement_file_path = "/Users/ahararwala/code-learning/udacity-sdce/projects/term2/examples/kalman_filter/src/obj_pose-laser-radar-synthetic-input.txt";
    ifstream in_file(measurement_file_path.c_str(), ios_base::in);

    if (!in_file.is_open()) {
        cout << "Cannot open input file: " << measurement_file_path << endl;
    }

    string line;
    // set i to get only first 3 measurments
    int i = 0;
    while (getline(in_file, line) && (i <= 3)) {
        MeasurementPackage meas_package;

        istringstream iss(line);
        string sensor_type;
        iss >> sensor_type;    //reads first element from the current line
        long timestamp;
        if (sensor_type.compare("L") == 0) {    //laser measurement
            //read measurements
            meas_package.sensor_type_ = MeasurementPackage::LASER;
            meas_package.raw_measurements_ = VectorXd(2);
            float x;
            float y;
            iss >> x;
            iss >> y;
            meas_package.raw_measurements_ << x, y;
            iss >> timestamp;
            meas_package.timestamp_ = timestamp;
            measurement_pack_list.push_back(meas_package);

        } else if (sensor_type.compare("R") == 0) {
            //Skip Radar measurements
            continue;
        }
        i++;

    }

    if (in_file.is_open()) {
        in_file.close();
    }
    return measurement_pack_list;
}

void track(const vector<MeasurementPackage> &measurement_pack_list) {//Create a Tracking instance
    Tracking tracking;

    //call the ProcessingMeasurement() function for each measurement
    size_t N = measurement_pack_list.size();
    for (size_t k = 0;
         k < N; ++k) {    //start filtering from the second frame (the speed is unknown in the first frame)
        tracking.ProcessMeasurement(measurement_pack_list[k]);
    }
}

/**
 * Kalman filter measurements for Laser
 */
//int main() {
//    vector<MeasurementPackage> measurement_pack_list = buildMeasurementPack();
//    track(measurement_pack_list);
//    return 0;
//}

/**
 * Compute Jacobian for non-linear transform (Radar data)
 */
int main() {
    return computeJacobain();
}


