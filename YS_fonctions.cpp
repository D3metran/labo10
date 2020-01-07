#include "YS_header.h"

Plane layerCube(Cube scanner, Dimension dimension, int layer) {

   Plane output;
   layer--;

   switch (dimension) {

      case Dimension::XY:

         output.resize(scanner.size());
         for (size_t i = 0; i < scanner.size(); ++i) {
            output.at(i).resize(scanner.at(i).size());
            for (size_t j = 0; j < scanner.at(i).size(); ++j)
               output[i][j] = scanner[i][j][layer];
         }

         break;

      case Dimension::XZ:

         output.resize(scanner.size());
         for (size_t i = 0; i < scanner.size(); ++i) {
            output.at(i).resize(scanner.at(i).at(layer).size());
            for (size_t j = 0; j < scanner.at(i).at(layer).size(); ++j)
               output[i][j] = scanner[i][layer][j];
         }

         break;

      case Dimension::YZ:

         output.resize(scanner.at(layer).size());
         for (size_t i = 0; i < scanner.size(); ++i) {
            output.at(i).resize(scanner.at(layer).at(i).size());
            for (size_t j = 0; j < scanner.at(layer).at(i).size(); ++j)
               output[i][j] = scanner[layer][i][j];
         }

         break;

      default:

         //On fait quoi en default ? On ignore le cas ?

         break;

   }

   return output;

}

void displayPlane(Plane display) {

   for (size_t i = 0; i < display.size(); ++i) {
      for (size_t j = 0; j < display.at(i).size(); ++j) {
         cout << (display[i][j] ? "X" : "O");
      }
      cout << endl;
   }

}