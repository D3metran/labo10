//YS_header

#ifndef YS_HEADER_H
#define YS_HEADER_H
#include <vector>
#include <iostream>

using Line = std::vector<bool>;
using Plane = std::vector<Line>;
using Volume = std::vector<Plane>;

enum class Dimension {
   XY, XZ, YZ
};

Plane layerVolume(Volume volume, Dimension dimension, size_t layer);

Volume inputScanUser();

/**
 * Surcharge << pour Line
 * @param os
 * @param vecteur
 */
std::ostream& operator<<(std::ostream& os, const Line& line);
/** 
 * Surcharge << pour Plane
 *  @param os
 * @param matrice
 */
std::ostream& operator<<(std::ostream& os, const Plane& plane);

#endif