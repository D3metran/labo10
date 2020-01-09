//YS_header

#ifndef YS_HEADER_H
#define YS_HEADER_H
#include <vector>
#include <iostream>

using Line = std::vector<bool>;
using Plane = std::vector<Line>;
using Cube = std::vector<Plane>;

enum class Dimension {
   XY, XZ, YZ
};

Plane layerCube(Cube scanner, Dimension dimension, size_t layer);

void displayPlane(Plane display);

Cube inputScanUser();

#endif