//
// Created by nigelmann on 07.01.20.
//
#include "scanner.h"
#include <iostream>

using namespace std;


Plane projectDimension(Cube& scan, Dimension dimension) {
    Plane projection;
    switch (dimension) {
        case Dimension::XY:
            projectXY(scan, projection);
            break;
        case Dimension::XZ:

            break;
        case Dimension::YZ:

            break;
    }

    return projection;
}

void projectXY(Cube& scan, Plane& projection) {
    const size_t X_SIZE = scan.size();
    projection.resize(X_SIZE);
    for (size_t x = 0; x < X_SIZE; ++x) {
        const size_t Y_SIZE = scan.at(x).size();
        projection.at(x).resize(Y_SIZE);
        for (size_t y = 0; y < Y_SIZE; ++y) {
            const size_t Z_SIZE = scan.at(x).at(y).size();
            for (size_t z = 0; z < Y_SIZE; ++z) {
                if (scan[x][y][z]) {
                    projection[x][y] = true;
                    break;
                }
            }
        }
    }
}
