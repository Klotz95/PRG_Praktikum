#include <intarray.h>
#include <iostream>
#include <cabase.h>

using namespace std;
class IntArray;

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
        for(int j = 0; j < 30; j++) {
            A1[i][j] = rand() % 10;
        }
    }

    // copy elements from A1 to A2
    for(int index = 0; index <= (30*30); index++) {
        A2->setValueAtIndex(index, A1[index/30][index%30]);
    }

    A2->arrayToStringMatrix();

    cout << "Welcome to console menu" << endl;
    cout << "Enter the following numbers to run the respective commands." <<endl;
    // menu with different options


    bool exi = false;
    int input;
    bool cinfailed = true;

     do{

        cout << "0. Exit" << endl;
        cout << "1. Change cell" << endl;
        cout << "2. Reprint" << endl;
        cout << "$ ";

        cin >> input;
        if (cin.fail() && cinfailed) {
            cout << "Invalid input. The only allowed inputs are 0, 1 or 2." << endl;
            cinfailed = !cinfailed;
            continue;
        }


        switch (input) {
        case 1:
            int x, y, cellvalue;
            cout << "Please enter the x co-ordinate of the cell: ";
            cin >> x;
            cout << "Please enter the y co-ordinate of the cell: ";
            cin >> y;
            cout << "Which value should be in the cell? ";
            cin >> cellvalue;
            A2->setValueAtIndex(x, y, cellvalue);
            ClearScreen();
            A2->arrayToStringMatrix();
        case 2:
            ClearScreen();
            A2->arrayToStringMatrix();
            break;
        case 0:
            exi = true;
            break;
        default:
             cout << "Invalid input. The only allowed inputs are 0, 1 or 2." << endl;
        }

    }while(!exi);

    ClearScreen();
    //exercise 2

    cout << "#################################################################" << endl;
    cout << "#                          exercise 2                           #" << endl;
    cout << "#################################################################" << endl;

    CAbase* cabase = new CAbase(30, 30);

    cabase->evolve();
    cabase->printUniverse();
    cabase->generationCycle();
    cabase->printUniverse();





    return 0;
}


