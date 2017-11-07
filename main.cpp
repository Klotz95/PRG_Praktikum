#include <intarray.h>
#include <iostream>

using namespace std;

void ClearScreen(){
    int n;
    for (n = 0; n < 10; n++)
        printf( "\n\n\n\n\n\n\n\n\n\n" );

}


int main()
{
    int A1[30][30];
    IntArray *A2 = new IntArray(30*30);

    // fill A1 with random values between 0 and 10
    for(int i = 0; i <= 29; i++) {
        for(int j = 0; j <= 30; j++) {
            A1[i][j] = rand() % 9 +1;
            //cout << "A1[" << i << "][" << j << "]: ";
            //cout << A1[i][j]<< endl;
        }
    }

    // copy elements from A1 to A2
    for(int index = 0; index <= (30*30); index++) {
        A2->setValueAtIndex(index, A1[index/30][index%30]);
    }

    A2->arrayToStringMatrix();


    // menu with different options
    do{
        int input;
        cout << "0. Exit" << endl;
        cout << "1. Change cell" << endl;
        cout << "2. Reprint" << endl;
        cin >> input;

        if(cin.fail()) {
            cout << "cin is not a number!" << endl;
            break;
        }

        switch (input) {
        case 1:
            int cellindex, cellvalue;
            cout << "Which index has the cell? ";
            cin >> cellindex;
            cout << "Which value should be in the cell? ";
            cin >> cellvalue;
            A2->setValueAtIndex(cellindex, cellvalue);
            ClearScreen();
            A2->arrayToStringMatrix();
        case 2:
            ClearScreen();
            A2->arrayToStringMatrix();
            break;
        default:
            return 0;
        }

    }while(1);

    return 0;
}


