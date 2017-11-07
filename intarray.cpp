#include "intarray.h"
#include <iostream>
using namespace std;

IntArray::IntArray(int len)
{
    this->length = len;
    this->array = new int[len];
}

double IntArray::getLength( void ) {
   return length;
}

void IntArray::arrayToStringMatrix(){
    for(int i = 0; i <= (30*30-1); i++) {
        cout << this->array[i] << " ";
        if(((i+1)%30)==0 and i > 0) {
            cout << endl;
        }
    }
    cout << endl;
}

int IntArray::getIndexValue(int val) {
    return array[val];
}

void IntArray::setValueAtIndex(int index, int value){
    array[index] = value;
}
