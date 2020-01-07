/*
-----------------------------------------------------------------------------------
Laboratoire : <nn>
Fichier     : <nom du fichier>.cpp
Auteur(s)   : Yannick Schaufelberger
Date        : <jj.mm.aaaa>

But         : <Que fait le code? Clair, concis et exhaustif>

Remarque(s) : <Lister les problèmes du code>

Compilateur : MinGW-g++ 6.3.0
-----------------------------------------------------------------------------------
 */

#include "YS_header.h"
#include <iostream>
#include <cstdlib>
#include <limits> //numeric_limits

#define VIDER_BUFFER cin.ignore(numeric_limits<streamsize>::max(),'\n')

using namespace std;

int main() {


   Cube CubeTest = {
      {
         {false, false, false, false, false},
         {false, false, false, false, false},
         {false, false, true, false, false},
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

   Cube userScan = input();

   for (size_t i = 0; i < userScan.size(); ++i) {
      displayPlane(layerCube(userScan, Dimension::YZ, i + 1));
      cout << endl;
   }

   /*
   displayPlane(layerCube(CubeTest, Dimension::XY, 3));
   cout << endl;
   displayPlane(layerCube(CubeTest, Dimension::XZ, 3));
   cout << endl;
   displayPlane(layerCube(CubeTest, Dimension::YZ, 3));
    */


   cout << "Presser [Enter] pour quitter" << endl;
   VIDER_BUFFER;
   return EXIT_SUCCESS;
}

