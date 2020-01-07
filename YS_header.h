//YS_header

#ifndef YS_HEADER_H
#define YS_HEADER_H
#include <vector>
#include <string>
#include <iostream>

using namespace std;

using Line = vector<bool>;
using Plane = vector<Line>;
using Cube = vector<Plane>;

enum class Dimension {
   XY, XZ, YZ
};

Plane layerCube(Cube scanner, Dimension dimension, int layer);

void displayPlane(Plane display);

#endif