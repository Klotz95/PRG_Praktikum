#include "cabase.h"
#include "intarray.h"
#include <iostream>

CAbase::CAbase(int nx, int ny) {
    int arrayLength = nx * ny;
    this->actualArray = new IntArray(arrayLength);
    this->newArray = new IntArray(arrayLength);
    setNx(nx);
    setNy(ny);

}

void CAbase::setNx(int nx) {
    this->Nx = nx;
}


void CAbase::setNy(int ny) {
    this->Ny = ny;
}

void CAbase::setActualStateOfCell(int x, int y, int alive) {
    this->actualArray->setValueAtIndex(x, y, alive);
}
void CAbase::setNewStateOfCell(int x, int y, int alive) {
    this->newArray->setValueAtIndex(x, y, alive);
}
int CAbase::getNx() {
    return this->Nx;
}
int CAbase::getNy() {
    return this->Ny;
}
int CAbase::getActualStateOfCell(int x, int y) {
    return this->actualArray->getIndexValue(x,y);
}
int CAbase::getNewStateOfCell(int x, int y) {
    return this->newArray->getIndexValue(x,y);
}

void CAbase::generationCycle() {
    for(int x = 0; x < this->Nx; x++) {
        for(int y = 0; y < this->Ny; y++) {
            evolutionRules(x, y);
        }
    }

}

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

int CAbase::countNeighbour(int x, int y) {

    // attention for the corners!
    return this->east(x,y) + this->west(x,y) + this->north(x,y) + this->south(x,y)
            + this->northeast(x,y) + this->northwest(x,y) + this->southeast(x,y) + this->southwest(x,y);

}

int CAbase::east(int x, int y) {
    if (x == this->Nx - 1) {
        return 0;
    }
    else {
        return this->actualArray->getIndexValue(x + 1 , y);
    }
}

int CAbase::west(int x, int y) {
    if (x == 0) {
        return 0;
    }
    else {
        return this->actualArray->getIndexValue(x - 1 , y);
    }
}

int CAbase::north(int x, int y) {
    if (y == 0) {
        return 0;
    }
    else {
        return this->actualArray->getIndexValue(x, y - 1);
    }
}

int CAbase::south(int x, int y) {
    if (y == this->Ny - 1) {
        return 0;
    }
    else {
        return this->actualArray->getIndexValue(x, y + 1);
    }
}

int CAbase::northwest(int x, int y) {
    if (x == 0 || y == 0) {
        return 0;
    }
    else {
        return this->actualArray->getIndexValue(x - 1, y - 1);
    }
}

int CAbase::northeast(int x, int y) {
    if (y == 0 || x == this->Nx - 1) {
        return 0;
    }
    else {
        return this->actualArray->getIndexValue(x + 1, y - 1);
    }
}

int CAbase::southeast(int x, int y) {
    if (y == this->Ny - 1 || x == this->Nx - 1) {
        return 0;
    }
    else {
        return this->actualArray->getIndexValue(x + 1, y + 1);
    }
}

int CAbase::southwest(int x, int y) {
    if (y == this->Ny - 1 || x == 0) {
        return 0;
    }
    else {
        return this->actualArray->getIndexValue(x - 1, y + 1);
    }
}



void CAbase::evolve() {
    for(int index = 0; index <= (30*30); index++) {
        this->actualArray->setValueAtIndex(index, rand() % 2);
    }
}

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
