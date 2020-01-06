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


#include <iostream>
#include <cstdlib>
#include <limits> //numeric_limits

#define VIDER_BUFFER cin.ignore(numeric_limits<streamsize>::max(),'\n')

using namespace std;

int main() {

   char recommencer;
   const char RECOMMENCER_OUI = 'o';
   const char RECOMMENCER_NON = 'n';

   do {

      //INSERT PROGRAM HERE

      do {
         cout << "Voulez vous recommencer ["
                 << RECOMMENCER_OUI << "|"
                 << RECOMMENCER_NON << "] : ";
         cin >> recommencer;
         VIDER_BUFFER;
      } while (recommencer != RECOMMENCER_OUI && recommencer != RECOMMENCER_NON);

   } while (recommencer == RECOMMENCER_OUI);

   cout << "Presser [Enter] pour quitter" << endl;
   VIDER_BUFFER;
   return EXIT_SUCCESS;
}

