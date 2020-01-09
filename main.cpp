/*
-----------------------------------------------------------------------------------
Laboratoire : <nn>it
Fichier     : <nom du fichier>.cpp
Auteur(s)   : Yannick Schaufelberger
Date        : <jj.mm.aaaa>

But         : <Que fait le code? Clair, concis et exhaustif>

Remarque(s) : <Lister les problÃ¨mes du code>

Compilateur : MinGW-g++ 6.3.0
-----------------------------------------------------------------------------------
 */

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

   Volume CubeTest = {
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

    Plane projection = projectDimension(CubeTest, Dimension::XY);

    cout << projection << endl;

   cout << "Presser [Enter] pour quitter" << endl;
   EMPTY_BUFFER;
   return EXIT_SUCCESS;
}

