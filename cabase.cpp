#include "cabase.h"
#include "intarray.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>



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


int CAbase::getNx() {
    return this->Nx;
}
int CAbase::getNy() {
    return this->Ny;
}





int CAbase::getdim() {
    return (this->getNx() * this->getNx());
}

int CAbase::returnIndex(int x, int y) {
    return (y*this->Nx + x);
}

int CAbase::getX(int index) {
    return (index % (this->Nx));
}

int CAbase::getY(int index) {
    return (index / (this->Nx));
}


void CAbase::randomfield() {
    int value;
    srand(time(0));
    for(int i = 0; i< (this->Nx * this->Nx); i++) {
        value = rand() % 6;
        this->actualArray->setValueAtIndex(i, value);
    }

}

bool CAbase::reachedBorder(int x, int y, int indexvalue) {
    if (y == 0 && indexvalue == 2) {
        return true;
    }
    else if ((y == this->Nx - 1) && indexvalue == 4) {
        return true;
    }
    else if ((x == 0) && indexvalue == 5) {
        return true;
    }
    else if ((x == this->Nx - 1) && indexvalue == 3) {
        return true;
    }
    else {
        return false;
    }

}


void CAbase::evolve(int mode) {
     int dim = this->Nx;
     int x, y, indexvalue;
     bool gameEnd;
     //while(true) {
         for(int index = 0; index < (this->getdim()); index++) {
             indexvalue = this->actualArray->getIndexValue(index);
             y = index / dim;
             x = index % dim;

            int index_new;
            //The positioning of the indexvalues in the new array stops if the game is in border mode
            //and the cell moves into the border.
            if (this->reachedBorder(x, y, indexvalue) && mode == 1) {
                cout << "You have reached the border" << endl;
                gameEnd = true;
                break;
            }
             switch (indexvalue) {
                case 0:
                 if (this->newArray->getIndexValue(index) == NULL) {
                 //To not let the index value be overwritten by 0.
                    this->newArray->setValueAtIndex(index, 0);

                 }
                 case 1:
                    if (this->newArray->getIndexValue(index) == NULL) {
                    //To not let the index value be overwritten by 1.
                       this->newArray->setValueAtIndex(index, 1);
                   }

                //if Cases are written to consider the border of the field.
                case 2: //2 is up
                    if (y == 0) {
                      index_new = this->returnIndex(x, dim - 1);
                      }
                    else {
                      index_new = this->returnIndex(x, y - 1);
                    }
                    this->newArray->setValueAtIndex(index_new, 2);
                case 4: //4 is down
                    if (y == dim - 1) {
                         index_new = this->returnIndex(x, 0);
                    }
                    else {
                    index_new = this->returnIndex(x, y + 1);
                    }
                    this->newArray->setValueAtIndex(index_new, 4);

                case 3: //3 is right
                    if (x == dim - 1) {
                        index_new = this->returnIndex(0, y);
                    }
                     else {
                         index_new = this->returnIndex(x+1, y);
                    }
                    this->newArray->setValueAtIndex(index_new, 3);


                case 5: //5 is left
                    if (x == 0){
                        index_new = this->returnIndex(dim - 1, y);
                    }
                    else {
                        index_new = this->returnIndex(x-1, y);
                    }
                    this->newArray->setValueAtIndex(index_new, 5);
            }

             }



     }


   //}


void CAbase::printUniverse(){

    for(int i = 0; i <= (this->Nx*this->Ny -1); i++) {

        if(((i)%this->Ny) == 0) {
            cout << "# ";
        }

        if(this->actualArray->getIndexValue(i) > 0) {
            cout << this->actualArray->getIndexValue(i) << " ";
        } else if (this->actualArray->getIndexValue(i)  == 0) {
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

    for(int i = 0; i <= (this->Nx*2)+2; i++) {
        cout << "#";
    }
    cout << endl;


    for(int i = 0; i <= (this->Nx*this->Ny -1); i++) {

        if(((i)%this->Ny) == 0) {
            cout << "# ";
        }

        if(this->newArray->getIndexValue(i) > 0) {
            cout << this->newArray->getIndexValue(i) << " ";
        } else if (this->newArray->getIndexValue(i)  == 0) {
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

    for(int i = 0; i <= (this->Nx*2)+2; i++) {
        cout << "#";
    }
    cout << endl;






}
