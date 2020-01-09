/*  ----------------------------------------------------------------------------
Labo         : Labo_10
File         : LABO_10_Ackermann_Schaufelberger_main.cpp
Author(s)    : Yannick Schaufelberger et Simon Ackermann
Date         : 07.01.2020
Purpose      : Manipuler le resultat d'un scan 3D
Remarks(s)   :
Compiler     : MinGW-g++ 6.3.0
--------------------------------------------------------------------------------  */

#include <iostream>
#include <cstdlib>
#include <limits> //numeric_limits
#include "scanner.h"

#define EMPTY_BUFFER cin.ignore(numeric_limits<streamsize>::max(),'\n')

using namespace std;

int main() {

   Volume userScan = inputScanUser();
   for (size_t i = 0; i < userScan.size(); i++) {
      cout << copyLayerFromVolume(userScan, Dimension::YZ, i + 1) << endl;
   }

   Volume cubeTest = {
      {
         {false, false, false, false, false},
         {false, false, true, false, false},
         {false, false, false, false, false},
         {false, false, false, false, false},
         {false, false, false, false, false}
      },
      {
         {false, false, false, false, false},
         {false, false, false, false, false},
         {false, false, true, false, false},
         {false, false, false, false, false},
         {false, false, false, false, false}
      },
      {
         {false, false, false, false, false},
         {false, false, true, false, false},
         {false, false, true, false, false},
         {false, false, false, false, false},
         {false, false, false, false, true}
      },
      {
         {false, false, false, false, false},
         {false, false, false, false, false},
         {false, false, false, false, false},
         {false, false, false, false, false},
         {false, false, false, false, false}
      },
      {
         {false, false, false, false, false},
         {false, false, false, false, false},
         {false, false, false, true, true},
         {false, false, false, false, false},
         {false, false, false, false, false}
      }
   };

   cout << "Projection sur XY" << endl;
   cout << projectDimension(cubeTest, Dimension::XY) << endl;

   cout << "Projection sur XZ" << endl;
   cout << projectDimension(cubeTest, Dimension::XZ) << endl;

   cout << "Projection sur YZ" << endl;
   cout << projectDimension(cubeTest, Dimension::YZ) << endl;

   cout << "Presser [Enter] pour quitter" << endl;
   EMPTY_BUFFER;
   return EXIT_SUCCESS;
}

