#include "cabase.h"
#include "intarray.h"
#include <iostream>

/*
 * Author: Daniel Holzinger
 *
 */

/**
 * this constructor gets the x and y length of the coordinate system.
 * @brief CAbase::CAbase
 * @param nx the length of the x
 * @param ny the length of the y
 */
CAbase::CAbase(int nx, int ny) {
    int arrayLength = nx * ny;
    this->actualArray = new IntArray(arrayLength);
    this->newArray = new IntArray(arrayLength);
    setNx(nx);
    setNy(ny);

}

/**
 * sets the nx
 * @brief CAbase::setNx
 * @param nx
 */
void CAbase::setNx(int nx) {
    this->Nx = nx;
}

/**
 * sets the ny
 * @brief CAbase::setNy
 * @param ny
 */
void CAbase::setNy(int ny) {
    this->Ny = ny;
}

/**
 * you can set the value of a specific cell by its x and y
 * of the actual array
 * @brief CAbase::setActualStateOfCell
 * @param x position x
 * @param y position y
 * @param alive value of the cell
 */
void CAbase::setActualStateOfCell(int x, int y, int alive) {
    this->actualArray->setValueAtIndex(x, y, alive);
}

/**
 * you can set the value of a specific cell by its x and y
 * of the new array
 * @brief CAbase::setActualStateOfCell
 * @param x position x
 * @param y position y
 * @param alive value of the cell
 */
void CAbase::setNewStateOfCell(int x, int y, int alive) {
    this->newArray->setValueAtIndex(x, y, alive);
}
/**
 * @brief CAbase::getNx
 * @return nx
 */
int CAbase::getNx() {
    return this->Nx;
}

/**
 * @brief CAbase::getNy
 * @return ny
 */
int CAbase::getNy() {
    return this->Ny;
}

/**
 * @brief CAbase::getActualStateOfCell
 * @param x
 * @param y
 * @return the value of the x,y position of the actual array
 */
int CAbase::getActualStateOfCell(int x, int y) {
    return this->actualArray->getIndexValue(x,y);
}

/**
 * @brief CAbase::getActualStateOfCell
 * @param x
 * @param y
 * @return the value of the x,y position of the new array
 */
int CAbase::getNewStateOfCell(int x, int y) {
    return this->newArray->getIndexValue(x,y);
}

/**
 * use the rules of the game of life for every cell
 * @brief CAbase::generationCycle
 */
void CAbase::generationCycle() {
    for(int x = 0; x < this->Nx; x++) {
        for(int y = 0; y < this->Ny; y++) {
            evolutionRules(x, y);
        }
    }

}

/**
 * rules of the game of life for 1 cell
 * @brief CAbase::evolutionRules
 * @param x
 * @param y
 */
void CAbase::evolutionRules(int x, int y) {
    int cNeighbour = countNeighbour(x, y);
    if( cNeighbour < 2 || cNeighbour > 3) {
        // underpopulation or overpopulation
        // the cell die
        this->setNewStateOfCell(x, y, 0);
    } else if(this->actualArray->getIndexValue(x,y) == 0 && cNeighbour == 3) {
        // reborn
        this->setNewStateOfCell(x, y, 1);
    }
    // TODO: this case is not needed?
    //else if(this->actualArray->getIndexValue(x,y) == 1 && (cNeighbour == 3 || cNeighbour == 2)) {
}

/**
 * count the neighbours of one cell, needed for the rules
 * @brief CAbase::countNeighbour
 * @param x
 * @param y
 * @return
 */
int CAbase::countNeighbour(int x, int y) {

    // attention for the corners!
    if((y != 0 && y != this->Ny) && (x != 0 && x != this->Nx)) {
        return    this->actualArray->getIndexValue(x-1, y-1)
                + this->actualArray->getIndexValue(x, y-1)
                + this->actualArray->getIndexValue(x+1, y-1)
                + this->actualArray->getIndexValue(x-1, y)
                + this->actualArray->getIndexValue(x+1, y)
                + this->actualArray->getIndexValue(x-1, y+1)
                + this->actualArray->getIndexValue(x, y+1)
                + this->actualArray->getIndexValue(x+1, y+1);
    }
}

/**
 * set random values
 * @brief CAbase::evolve
 */
void CAbase::evolve() {
    for(int index = 0; index <= (30*30); index++) {
        this->actualArray->setValueAtIndex(index, rand() % 2);
    }
}

/**
 * print the matrix
 * @brief CAbase::printUniverse
 */
void CAbase::printUniverse(){
    for(int i = 0; i <= (this->Nx*2)+2; i++) {
        cout << "#";
    }
    cout << endl;
    for(int i = 0; i <= (this->Nx*this->Ny -1); i++) {

        if(((i)%this->Ny) == 0) {
            cout << "# ";
        }

        if(this->actualArray->getIndexValue(i) == 1) {
            cout << "*" << " ";
        } else {
            cout << " " << " ";
        }
        if(((i+1)%this->Nx)==0 && i > 0) {
            cout << "#" << endl;
        }
    }
    for(int i = 0; i <= (this->Nx*2)+2; i++) {
        cout << "#";
    }
    cout << endl;
}
