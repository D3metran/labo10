/*  ----------------------------------------------------------------------------
Labo         : Labo_10
File         : LABO_10_Ackermann_Schaufelberger_scanner.h
Author(s)    : Hugo Mendes et Simon Ackermann
Date         : 07..2020
Purpose      : Functions related to matrix manipulation
Remarks(s)   :
Compiler     : g++ 7.4.0
--------------------------------------------------------------------------------  */
#ifndef LABO_10_SCANNER_H
#define LABO_10_SCANNER_H

#include <vector>
#include <iostream>

using Line = std::vector<bool>;
using Plane = std::vector<Line>;
using Volume = std::vector<Plane>;

enum class Dimension {
    XY, XZ, YZ
};

Plane projectDimension(Volume&, Dimension);

void projectXY(Volume&, Plane&);

void projectXZ(Volume&, Plane&);

void projectYZ(Volume&, Plane&);

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

#endif //LABO_10_SCANNER_H
