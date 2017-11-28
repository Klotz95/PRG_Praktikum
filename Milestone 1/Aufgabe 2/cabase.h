#ifndef CABASE_H
#define CABASE_H
#include <iostream>
#include <stdlib.h>

using namespace std;

/**
 * AUFGABE 2a
 */
class CAbase{

    /**
     * AUFGABE 2c
     */
private:
    int *currentRound;
    int *nextRound;
    int Nx;
    int Ny;

public:
    /**
     * AUFGABE 2b
     */
    CAbase(int Nx,int Ny){
        this->Nx = Nx;
        this->Ny = Ny;
        currentRound = new int[Nx*Ny];
        nextRound = new int[Nx*Ny];
        clearNextRound();
        clearCurrentRound();
    }
    ~CAbase(){
        delete []nextRound;
        delete []currentRound;
    }

    void fillRandomValues(){
        srand(time(NULL));
        for(int i = 0; i < Nx; i++) {
            for(int j = 0; j < Ny; j++){
                currentRound[i*30+j] = rand() % 2;//Feld besteht aus Nullen und Einsen
            }
        }
    }

    void clearCurrentRound(){
        for(int i = 0; i < Nx; i++) {
            for(int j = 0; j < Ny; j++){
                currentRound[i*30+j] = 0;
            }
        }
    }

    void clearNextRound(){
        for(int i = 0; i < Nx; i++) {
            for(int j = 0; j < Ny; j++){
                nextRound[i*30+j] = 0;
            }
        }
    }

    /**
     * AUFGABE 2d
     */
    void setCellCurrent(int x,int y, int value){
        currentRound[x*30+y] = value;
    }

    void setCellNext(int x,int y, int value){
        nextRound[x*30+y] = value;
    }

    void setNx(int Nx){
        this->Nx = Nx;
    }


    void setNy(int Ny){
        this->Ny = Ny;
    }

    int getCellNext(int x, int y){
        if((x >= 0) && (y >= 0) && (y < Ny) && (x < Nx)){
            return nextRound[x*30+y];
        }else{
            return 0;
        }

    }

    int getCellCurrent(int x, int y){
        if((x >= 0) && (y >= 0) && (y < Ny) && (x < Nx)){
            return currentRound[x*30+y];
        }else{
            return 0;
        }
    }

    int getNx(){
        return Nx;
    }

    int getNy(){
        return Ny;
    }
    /**
     * AUFGABE 2e
     */
    void advanceGameOfLife(){
        int livingNeighbours;
        for(int i = 0; i < Nx; ++i){
            for(int j = 0; j < Ny; ++j){
                livingNeighbours = 0;
                //Hier wird im Prinzip ein Block aus 9 Zellen geprüft
                //Jede Zelle hat 9 Nachbarn --> Block aus 9 Zellen
                for(int k = i - 1; k <= i+1; ++k){
                    for(int l = j - 1; l <= j + 1; ++l){
                        if((k >= 0) && (l >= 0) && (l < Ny) && (k < Nx)){
                            if(getCellCurrent(k,l) == 1){
                                livingNeighbours++;
                            }
                        }
                        //Torusförmig
                        if(k < 0){
                            if(getCellCurrent(Nx-1,l) == 1){
                                livingNeighbours++;
                            }
                        }
                        if(k >= Nx){
                            if(getCellCurrent(0,l) == 1){
                                livingNeighbours++;
                            }
                        }
                        if(l < 0){
                            if(getCellCurrent(k,Ny-1) == 1){
                                livingNeighbours++;
                            }
                        }
                        if(l >= Ny){
                            if(getCellCurrent(k,0) == 1){
                                livingNeighbours++;
                            }
                        }
                    }
                }
                //Eigene Zelle wird übersprungen
                if(getCellCurrent(i,j) == 1){
                    livingNeighbours--;
                }

                //----------------------------------------------------------
                //Die Bedingungen
                //Jede lebende Zelle mit weniger als zwei Nachbarn stirbt (Unterbevölkerung)
                //Jede Zelle mit mehr als drei Nachbarn stirbt ebenfalls (Überbevölkerung).
                if((getCellCurrent(i,j) == 1) && (livingNeighbours < 2 || livingNeighbours > 3)){
                    setCellNext(i,j,0);
                }
                //Jede Zelle mit zwei oder drei Nachbarn überlebt.
                if((getCellCurrent(i,j) == 1) && (livingNeighbours == 2 || livingNeighbours == 3)){
                    setCellNext(i,j,1);
                }
                //Eine tote Zelle mit genau zwei Nachbarn bleibt weiterhin tot
                if((getCellCurrent(i,j) == 0) && (livingNeighbours == 2)){
                    setCellNext(i,j,0);
                }
                //Jede tote Zelle mit genau drei Nachbarn wird wiedergeboren
                if((getCellCurrent(i,j) == 0) && (livingNeighbours == 3)){
                    setCellNext(i,j,1);
                }
            }
        }

        //Neue Generation wird zur aktuellen Generation
        for(int i = 0; i < Nx; i++) {
            for(int j = 0; j < Ny; j++){
                currentRound[i*30+j] = nextRound[i*30+j];
            }
        }
        //Neue Generation wird für nächste Generation geleert
        clearNextRound();


    }

    //Aktuelle Generation printen
    void printCurrentRound(){
        for(int i = 0; i < Nx+2;++i){
            cout << "* ";
        }
        cout << endl;
        for(int i = 0; i < Nx; ++i){
            cout << "* ";
            for(int j = 0; j < Ny; ++j){
                if(getCellCurrent(i,j) == 1){
                    cout << "* " ;
                }else{
                    cout << "  ";
                }
            }
            cout << "*";
            cout << endl;
        }
        for(int i = 0; i < Nx+2;++i){
            cout << "* ";
        }
    }

    void resizeField(int Nx,int Ny){
        setNx(Nx);
        setNy(Ny);
        delete []currentRound;
        delete []nextRound;
        currentRound = new int[Nx*Ny];
        nextRound = new int[Nx*Ny];
        clearCurrentRound();
        clearNextRound();
    }

};

#endif // CABASE_H
