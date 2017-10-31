#include <intarray.h>
#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

int main()
{
    int A1[30][30];
    IntArray *A2 = new IntArray(30*30);

    cout << "The length of the array is: " << A2->getLength() << endl;

    // fill A1 with random values between 0 and 10
    for(int i = 0; i <= 30; i++) {
        for(int j = 0; j <= 30; j++) {
            A1[i][j] = rand() % 9 +1;
            // cout << "A1[" << i << "][" << j << "]: ";
            // cout << A1[i][j]<< endl;
        }
    }

    // copy elements from A1 to A2
    for(int i = 0; i <= 30*30; i++) {
        memcpy(A2, A1[i], sizeof(A2));
    }


    //&A2[0] = 1;
    //for(int i = 0; i <= 30*30; i++) {
        cout << &A2[0] << " a" << endl;
    //}

    return 0;
}
