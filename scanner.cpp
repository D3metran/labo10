/*  ----------------------------------------------------------------------------
Labo         : Labo_10
File         : LABO_10_Ackermann_Schaufelberger_scanner.cpp
Author(s)    : Simon Ackermann et Yannick Schaufelberger
Date         : 06.01.2020
Purpose      : Manipuler le resultat d'un scan 3D
Remarks(s)   : Le scan est supposé être un parallépipède rectangle
Compiler     : MinGW-g++ 6.3.0
--------------------------------------------------------------------------------  */
#include "scanner.h"
#include <iostream>
#include <limits>

using namespace std;
#define EMPTY_BUFFER cin.ignore(numeric_limits<streamsize>::max(),'\n')

Plane projectDimension(Volume& scan, Dimension dimension) {

   Plane projection;

   switch (dimension) {
      case Dimension::XY:
         projectXY(scan, projection);
         break;
      case Dimension::XZ:
         projectXZ(scan, projection);
         break;
      case Dimension::YZ:
         projectYZ(scan, projection);
         break;
   }

   return projection;
}

void projectXY(Volume& scan, Plane& projection) {

   const size_t X_SIZE = scan.size(),
                Y_SIZE = scan.at(0).size(),
                Z_SIZE = scan.at(0).at(0).size();

   projection.resize(X_SIZE, Line(Y_SIZE));

   for (size_t x = 0; x < X_SIZE; ++x) {
      for (size_t y = 0; y < Y_SIZE; ++y) {
         for (size_t z = 0; z < Z_SIZE; ++z) {
            if (scan[x][y][z]) {
               projection[x][y] = true;
               break;
            }
         }
      }
   }
}

void projectXZ(Volume& scan, Plane& projection) {

   const size_t X_SIZE = scan.size(),
                Y_SIZE = scan.at(0).size(),
                Z_SIZE = scan.at(0).at(0).size();

   projection.resize(X_SIZE, Line(Z_SIZE));

   for (size_t x = 0; x < X_SIZE; ++x) {
      for (size_t z = 0; z < Z_SIZE; ++z) {
         for (size_t y = 0; y < Y_SIZE; ++y) {
            if (scan[x][y][z]) {
               projection[x][z] = true;
               break;
            }
         }
      }
   }
}

void projectYZ(Volume& scan, Plane& projection) {

   const size_t X_SIZE = scan.size(),
                Y_SIZE = scan.at(0).size(),
                Z_SIZE = scan.at(0).at(0).size();

   projection.resize(Y_SIZE, Line(Z_SIZE));

   for (size_t y = 0; y < Y_SIZE; ++y) {
      for (size_t z = 0; z < Z_SIZE; ++z) {
         for (size_t x = 0; x < X_SIZE; ++x) {
            if (scan[x][y][z]) {
               projection[y][z] = true;
               break;
            }
         }
      }
   }
}

Plane copyLayerFromVolume(Volume& volume, Dimension dimension, size_t layer) {

   const size_t SIZE_X = volume.size(),
                SIZE_Y = volume.at(0).size(),
                SIZE_Z = volume.at(0).at(0).size();

   Plane outputLayer;

   switch (dimension) {
      case Dimension::XY:
         if (layer > SIZE_Z) break;
         copyXYLayerFromVolume(volume, layer, outputLayer);
         break;
      case Dimension::XZ:
         if (layer > SIZE_Y) break;
         copyXZLayerFromVolume(volume, layer, outputLayer);
         break;
      case Dimension::YZ:
         if (layer > SIZE_X) break;
         copyYZLayerFromVolume(volume, layer, outputLayer);
         break;
   }

   return outputLayer;

}

void copyXYLayerFromVolume(Volume& volume, size_t layer, Plane& plane) {

   const size_t SIZE_X = volume.size(),
                SIZE_Y = volume.at(0).size();

   plane.resize(SIZE_X, Line(SIZE_Y, false));

   for (size_t x = 0; x < SIZE_X; ++x) {
      for (size_t y = 0; y < SIZE_Y; ++y) {
         plane[x][y] = volume[x][y][layer - 1];
      }
   }
}

void copyXZLayerFromVolume(Volume& volume, size_t layer, Plane& plane) {

   const size_t SIZE_X = volume.size(),
                SIZE_Z = volume.at(0).at(0).size();

   plane.resize(SIZE_X, Line(SIZE_Z, false));

   for (size_t x = 0; x < SIZE_X; ++x) {
      for (size_t z = 0; z < SIZE_Z; ++z) {
         plane[x][z] = volume[x][layer - 1][z];
      }
   }
}

void copyYZLayerFromVolume(Volume& volume, size_t layer, Plane& plane) {

   const size_t SIZE_Y = volume.at(0).size(),
                SIZE_Z = volume.at(0).at(0).size();

   plane.resize(SIZE_Y, Line(SIZE_Z, false));

   for (size_t y = 0; y < SIZE_Y; ++y) {
      for (size_t z = 0; z < SIZE_Z; ++z) {
         plane[y][z] = volume[layer - 1][y][z];
      }
   }
}

Volume inputScanUser() {

   const int MAX_SIZE = 20;

   int dimensionX, dimensionY, dimensionZ;

   do {
      if (cin.fail()) {
         cin.clear();
         EMPTY_BUFFER;
      }
      cout << "Separez chacune des entree par un espace ou un retour a la ligne" << endl
           << "Entrez les valeurs des 3 dimensions une par une du scan (nombres entiers [1 - "
           << MAX_SIZE << "]) : ";
      cin >> dimensionX >> dimensionY >> dimensionZ;

   } while (
           cin.fail() ||
           ((dimensionX <= 0 || dimensionX >= MAX_SIZE) 
               && cout << "Première dimension incorrecte"  << endl) ||
           ((dimensionY <= 0 || dimensionY >= MAX_SIZE) 
               && cout << "Deuxième dimension incorrecte"  << endl) ||
           ((dimensionZ <= 0 || dimensionZ >= MAX_SIZE) 
               && cout << "Troisieme dimension incorrecte" << endl)
           );
   EMPTY_BUFFER;

   Volume scanVolume(dimensionX, Plane(dimensionY, Line(dimensionZ, false)));
   char tmp;

   for (size_t x = 0; x < (size_t) dimensionX; ++x) {
      for (size_t y = 0; y < (size_t) dimensionY; ++y) {
         cout << "Entrez " << dimensionZ << " booleens (0 ou 1) : ";
         cin;
         for (size_t z = 0; z < (size_t) dimensionZ; ++z) {
            do {
               tmp = (char) getchar();
            } while (tmp == ' ' || tmp == '\n');
            scanVolume.at(x).at(y).at(z) = (tmp != '0');
         }
         EMPTY_BUFFER;
      }
      cout << "Couche " << x + 1 << " terminee" << endl;
   }

   return scanVolume;

}

ostream& operator<<(ostream& os, const Line& line) {
   os << '[';
   for (auto i = line.begin(); i != line.end(); ++i) {
      os << *i;
      if (i != line.end() - 1)
         os << ", ";
   }
   os << ']';
   return os;
}

ostream& operator<<(ostream& os, const Plane& plane) {
   for (auto i = plane.begin(); i != plane.end(); ++i) {
      os << *i;
      os << endl;
   }
   return os;
}