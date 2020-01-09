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

/**
 * copie une couche d'un volume
 * @param volume le volume dont la couche sera copie
 * @param dimension la dimension par laquelle on regarde le volume
 * @param layer le numero de la couche (la n-Ã¨me couche)
 * @return 
 */
Plane copyLayerFromVolume(Volume volume, Dimension dimension, size_t layer);

/**
 * Demande des dimensions Ã  l'utilisateur, crÃ©e un volume en consÃ©quence
 * et demande Ã  l'utilisateur de le remplir
 * @return le volume crÃ©e et rempli
 */
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
