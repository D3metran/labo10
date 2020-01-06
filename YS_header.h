//YS_header

#ifndef YS_HEADER_H
#define YS_HEADER_H
#include <vector>

using Line  = vector<bool>;
using Plane = vector<Line>;
using Cube  = vector<Plane>;

enum class Dimension {XY, XZ, YZ};

Plane affichagePlan()

#endif