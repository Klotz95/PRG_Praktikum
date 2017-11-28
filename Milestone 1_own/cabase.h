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
    void setActualStateOfCell(int x, int y, int alive);
    void setNewStateOfCell(int x, int y, int alive);
    int getNx();
    int getNy();
    int getActualStateOfCell(int x, int y);
    int getNewStateOfCell(int x, int y);
    void generationCycle();
    void evolve();
    void printUniverse();
    int east(int x, int y);
    int west(int x, int y);
    int north(int x, int y);
    int south(int x, int y);
    int northeast(int x, int y);
    int southeast(int x, int y);
    int northwest(int x, int y);
    int southwest(int x, int y);
private:
    IntArray* actualArray;
    IntArray* newArray;
    int Nx;
    int Ny;
    int countNeighbour(int x, int y);
    void evolutionRules(int x, int y);
};

#endif // CABASE_H
