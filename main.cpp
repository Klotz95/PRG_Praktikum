#include <intarray.h>
#include <iostream>

using namespace std;

int main()
{
    int A1[30][30];
    IntArray *A2 = new IntArray(30*30);

    cout << "The length of the array is: " << A2->getLength() << endl;

    // fill A1 with random values between 0 and 10
    for(int i = 0; i <= 29; i++) {
        for(int j = 0; j <= 29; j++) {
            A1[i][j] = rand() % 9 +1;
            //cout << "A1[" << i << "][" << j << "]: ";
            //cout << A1[i][j]<< endl;
        }
    }

    // copy elements from A1 to A2
    for(int i = 0; i <= (30*30)-1; i++) {
        A2[i] = A1[i/30][i%30];
    }

    A2->arrayToStringMatrix();


    return 0;
}


