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

using Line = std::vector<bool>;
using Plane = std::vector<Line>;
using Cube = std::vector<Plane>;

enum class Dimension {
    XY, XZ, YZ
};

Plane projectDimension(Cube&, Dimension);

void projectXY(Cube&, Plane&);

void projectXZ(Cube&, Plane&);

void projectYZ(Cube&, Plane&);

#endif //LABO_10_SCANNER_H
