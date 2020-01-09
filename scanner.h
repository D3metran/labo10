/*  ----------------------------------------------------------------------------
Labo         : Labo_10
File         : LABO_10_Ackermann_Schaufelberger_scanner.h
Author(s)    : Simon Ackermann et Yannick Schaufelberger
Date         : 06.01.2020
Purpose      : Manipuler le resultat d'un scan 3D
Remarks(s)   : Le scan est supposé être un parallépipède rectangle
Compiler     : MinGW-g++ 6.3.0
--------------------------------------------------------------------------------  */
#ifndef LABO_10_SCANNER_H
#define LABO_10_SCANNER_H

#include <vector>
#include <iostream>

using Line   = std::vector<bool>;
using Plane  = std::vector<Line>;
using Volume = std::vector<Plane>;

enum class Dimension {
   XY, XZ, YZ
};

/**
 * @brief projette la dimension sur un plan
 * @param volume
 * @param dimension
 * @return
 */
Plane projectDimension(Volume& volume, Dimension dimension);

/**
 * @brief projette la dimension XY sur un plan
 * @param volume
 * @param plane
 */
void projectXY(Volume& volume, Plane& plane);

/**
 * @brief projette la dimension XZ sur un plan
 * @param volume
 * @param plane
 */
void projectXZ(Volume& volume, Plane& plane);

/**
 * @brief projette la dimension YZ sur un plan
 * @param volume
 * @param plane
 */
void projectYZ(Volume& volume, Plane& plane);

/**
 * @brief copie une couche d'un volume
 * @param volume le volume dont la couche sera copie
 * @param dimension la dimension par laquelle on regarde le volume
 * @param layer le numero de la couche (la n-ème couche)
 * @return 
 */
Plane copyLayerFromVolume(Volume& volume, Dimension dimension, size_t layer);

/**
 * @brief copie une couche de la dimension XY
 * @param volume
 * @param layer
 * @param plane
 */
void copyXYLayerFromVolume(Volume& volume, size_t layer, Plane& plane);

/**
 * @brief copie une couche de la dimension XZ
 * @param volume
 * @param layer
 * @param plane
 */
void copyXZLayerFromVolume(Volume& volume, size_t layer, Plane& plane);

/**
 * @brief copie une couche de la dimension YZ
 * @param volume
 * @param layer
 * @param plane
 */
void copyYZLayerFromVolume(Volume& volume, size_t layer, Plane& plane);

/**
 * @brief demande des dimensions à l'utilisateur, crée un volume en conséquence
 *        et demande à l'utilisateur de le remplir
 * @remark toute entrée autre que 0 est considérée comme 1
 * @return le volume crée et rempli
 */
Volume inputScanUser();

/**
 * @brief Surcharge << pour Line
 * @param os
 * @param vecteur
 */
std::ostream& operator<<(std::ostream& os, const Line& line);
/**
 * @brief Surcharge << pour Plane
 * @param os
 * @param matrice
 */
std::ostream& operator<<(std::ostream& os, const Plane& plane);

#endif //LABO_10_SCANNER_H