#ifndef CABASE_H
#define CABASE_H
#include <intarray.h>


class CAbase
{
public:
    CAbase(int nx, int ny);    // ctor
    ~CAbase();   // dtor

    void setNx(int Nx);
    void setNy(int Ny);


    int getNx();
    int getNy();


    void generationCycle();
    void evolve(int mode, int direction);
    void printUniverse();
    int east(int x, int y);
    int west(int x, int y);
    int north(int x, int y);
    int south(int x, int y);
    int northeast(int x, int y);
    int southeast(int x, int y);
    int northwest(int x, int y);
    int southwest(int x, int y);
    int getdim();
    void randomfield();
    int getX(int index);
    int getY(int index);
    int returnIndex(int x, int y);
    bool reachedBorder(int index);
    void printSnakeUniverse();
    void emptyAndPutHead(int index);
    void setHeadIndex(int index);
    int getHeadIndex();
    void moveHead(int direction, int mode);
private:
    IntArray* actualArray;
    IntArray* newArray;
    int Nx;
    int Ny;
    int HeadIndex;
    int countNeighbour(int x, int y);
    void evolutionRules(int x, int y);
};

#endif // CABASE_H
