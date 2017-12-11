#include <intarray.h>
#include <iostream>
#include <cabase.h>
#include <stdlib.h>
#include <time.h>


using namespace std;
class IntArray;

void ClearScreen(){
    int n;
    for (n = 0; n < 10; n++)
        printf( "\n\n\n\n\n\n\n\n\n\n" );

}

void PrepareFieldSnake(CAbase* somefield) {
    srand(time(0));
    int index = rand() % (somefield->getdim()); //index randomly chosen from 0 to array length - 1
    cout << index << endl;
    somefield->emptyAndPutHead(index);
    cout << "after Head function" << endl;
}

int main(){
    int dim, mode, direction;

    cout << "Please enter the dimesion of the board." << endl;
    cin >> dim;
    cout << "Please enter the game mode. 0 - torus mode, 1 - border mode ";
    cin >> mode;
    cout << "Please enter the direction of the snake head" << endl;
    cin >> direction;

    CAbase* field= new CAbase(dim, dim);
    cout << "Cabase" << endl;
    PrepareFieldSnake(field);
    cout <<"before print" << endl;
    field->moveHead(direction, mode);

}




