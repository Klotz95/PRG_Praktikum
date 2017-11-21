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



    string input;
    int command;
    bool exi = true;


     do{
        cout << "0. Exit" << endl;
        cout << "1. Change cell" << endl;
        cout << "2. Reprint" << endl;
        cout << "$ ";
        cin >> input;
        try
          {
            string x_string, y_string, cv_string;
            int x, y, cellvalue;
            command = stoi(input); //cause an exception to throw
            switch (command) {
            case 1:
                cout << "Please enter the x co-ordinate of the cell: ";
                cin >> x_string;
                x = stoi(x_string);
                cout << "Please enter the y co-ordinate of the cell: ";
                cin >> y_string;
                y = stoi(y_string);
                cout << "Which value should be in the cell? ";
                cin >> cv_string;
                cellvalue = stoi(cv_string);
                A2->setValueAtIndex(x, y, cellvalue);
                ClearScreen();
                A2->arrayToStringMatrix();
            case 2:
                ClearScreen();
                A2->arrayToStringMatrix();
            case 0:
                exi = false;
                break;
            default:
                printf( "\n\n" );
                cout << "Invalid input. The only allowed inputs are 0, 1 or 2. Please enter the command again." << endl;
        }
     }

    catch (invalid_argument& e) {
        printf( "\n\n");
        cout << "You have entered a string. Please enter only integers." << endl;
        continue;
     }

    }while(exi);

    ClearScreen();
    //exercise 2

    cout << "#################################################################" << endl;
    cout << "#                          exercise 2                           #" << endl;
    cout << "#################################################################" << endl;

    CAbase* cabase = new CAbase(30, 30);


    cabase->evolve();
    cabase->printUniverse();
    exi = true;
    do{

       cout << "0. Exit" << endl;
       cout << "1. Evolve" << endl;
       cout << "2. Set alive cell" << endl;
       cout << "3. Reprint" << endl;
       cout << "4. Resize" << endl;
       cout << "$ ";
       cin >> input;
       try {
            command = stoi(input); //cause an exception to throw
            string x_string, y_string;
            int x, y, cellvalue;
            cellvalue = 1;

            switch (command) {
            case 1:
                cabase->evolve();
                ClearScreen();
                cabase->printUniverse();
            case 2:
                cout << "Please enter the x co-ordinate of the cell: ";
                cin >> x_string;
                x = stoi(x_string);
                cout << "Please enter the y co-ordinate of the cell: ";
                cin >> y_string;
                y = stoi(y_string);
                cabase->setActualStateOfCell(x, y, cellvalue);
                ClearScreen();
                cabase->printUniverse();
            case 3:
                ClearScreen();
                cabase->printUniverse();
                break;
            case 0:
                exi = false;
                break;
            case 4:
                cout << "Enter your universe width:";
                cin >> x;
                cout << "Enter your universe height:";
                cin >> y;
                cabase->setNx(x);
                cabase->setNy(y);
                cabase->printUniverse();
                break;
            default:
                cout << "Invalid input. The only allowed inputs are 0, 1, 2, 3 or 4." << endl;
       }
     }
       catch (invalid_argument& e) {
           printf( "\n\n");
           cout << "You have entered a string. Please enter only integers." << endl;
           continue;
       }
   }while(exi);
    return 0;
}


