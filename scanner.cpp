//
// Created by nigelmann on 07.01.20.
//
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

            break;
        case Dimension::YZ:

            break;
    }

    return projection;
}

void projectXY(Volume& scan, Plane& projection) {
    const size_t X_SIZE = scan.size();
    projection.resize(X_SIZE);
    for (size_t x = 0; x < X_SIZE; ++x) {
        const size_t Y_SIZE = scan.at(x).size();
        projection.at(x).resize(Y_SIZE);
        for (size_t y = 0; y < Y_SIZE; ++y) {
            const size_t Z_SIZE = scan.at(x).at(y).size();
            for (size_t z = 0; z < Y_SIZE; ++z) {
                if (scan[x][y][z]) {
                    projection[x][y] = true;
                    break;
                }
            }
        }
    }
}


Plane layerVolume(Volume volume, Dimension dimension, size_t layer) {

    Plane output;

    size_t sizeX = volume.size();
    size_t sizeY = volume.at(0).size();
    size_t sizeZ = volume.at(0).at(0).size();

    switch (dimension) {

        case Dimension::XY:

            if (layer > sizeZ) break;

            output.resize(sizeX, Line(sizeY, false));

            for (size_t x = 0; x < sizeX; ++x)
                for (size_t y = 0; y < sizeY; ++y)
                    output[x][y] = volume[x][y][layer - 1];

            break;

        case Dimension::XZ:

            if (layer > sizeY) break;

            output.resize(sizeX, Line(sizeZ, false));

            for (size_t x = 0; x < sizeX; ++x)
                for (size_t z = 0; z < sizeZ; ++z)
                    output[x][z] = volume[x][layer - 1][z];


            break;

        case Dimension::YZ:

            if (layer > sizeX) break;

            output.resize(sizeY, Line(sizeZ, false));

            for (size_t y = 0; y < sizeY; ++y)
                for (size_t z = 0; z < sizeZ; ++z)
                    output[y][z] = volume[layer - 1][y][z];

            break;

    }

    return output;

}

Volume inputScanUser() {

    unsigned int dimensionX, dimensionY, dimensionZ;

    //Boucle de saisie des dimensions du scan
    do {
        if (cin.fail()) {
            cin.clear();
            EMPTY_BUFFER;
        }
        cout << "Entrez les valeurs des 3 dimensions du scan (nombres entiers > 0) : ";
        cin >> dimensionX >> dimensionY >> dimensionZ;

    } while (cin.fail());
    EMPTY_BUFFER;

    Volume scanVolume(dimensionX, Plane(dimensionY, Line(dimensionZ, false)));
    char tmp;

    //Remplissage ligne par ligne du scan
    for (size_t x = 0; x < dimensionX; ++x) {
        for (size_t y = 0; y < dimensionY; ++y) {
            cout << "Entrez " << dimensionZ << " booleens (0 ou 1) : ";
            cin;
            for (size_t z = 0; z < dimensionZ; ++z) {
                do {
                    tmp = (char) getchar();
                } while (tmp == ' ' || tmp == '\n');
                scanVolume.at(x).at(y).at(z) = (tmp != '0');
            }
            EMPTY_BUFFER;
        }
        cout << "couche " << x + 1 << " terminee" << endl;
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
    os << '[';
    for (auto i = plane.begin(); i != plane.end(); ++i) {
        os << *i;
        if (i != plane.end() - 1)
            os << ", ";
    }
    os << ']';
    return os;
}