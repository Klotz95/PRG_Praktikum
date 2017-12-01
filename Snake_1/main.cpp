#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;


int main(){
    int bordermode;
    int eingabe;
    int dim;
    bool stopLoop = false;

    cout << "Gib die Dimension an" << endl;
    cin >> dim;
    int A1[dim-1][dim-1];
    srand(time(0)); // needed to create random numbers (seed random)
    int x = rand() % (dim-1);
    int y = rand() % (dim-1);


    cout << "Bitte gib den Raendermodus an! 0 = Torus, 1 = mit Rand" << endl;
    cin >> bordermode;
    cout << "x = " << x << " und y = " << y << endl;
    A1[x][y] = 1;
    do{
        cout << "Gib die Richtung an!";
        cin >> eingabe;
        switch(eingabe){
            case 0: stopLoop = true; cout << "Das Programm wird beendet" << endl; break;
            case 2: A1[x][y] = 0; A1[x+1][y] = 1; x++;
                if (x == dim){
                    if (bordermode == 1){
                        cout << "Der Rand wurde erreicht, das Spiel wird nun beendet" << endl; stopLoop = true;}
                    else
                        x = 0;}
                cout << "x = " << x << ", y = " << y << endl; // Platzhalter, hier kommt noch die komplette Matrix hin
                break;

            case 4: A1[x][y] = 0; A1[x][y-1] = 1; y--;
                if (y == -1){
                    if (bordermode == 1){
                        cout << "Der Rand wurde erreicht, das Spiel wird nun beendet" << endl; stopLoop = true;}
                    else
                        y = dim-1;}
                cout << "x = " << x << ", y = " << y << endl;
                break;

            case 6: A1[x][y] = 0; A1[x][y+1] = 1; y++;
                if (y == dim){
                    if (bordermode == 1){
                        cout << "Der Rand wurde erreicht, das Spiel wird nun beendet" << endl; stopLoop = true;}
                    else
                        y = 0;}
                cout << "x = " << x << ", y = " << y << endl;
                break;

            case 8: A1[x][y] = 0; A1[x-1][y] = 1; x--;
                if (x == -1){
                    if (bordermode == 1){
                        cout << "Der Rand wurde erreicht, das Spiel wird nun beendet" << endl; stopLoop = true;}
                    else
                        x = dim-1;}
                cout << "x = " << x << ", y = " << y << endl;
                break;

            default: cout << "Bitte eine Richtung (2,4,6 oder 8) angeben!" << endl; break;
        }
    } while(stopLoop == false);

}


