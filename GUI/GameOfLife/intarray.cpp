#include "intarray.h"
#include <iostream>
using namespace std;

/*
 * Author: Daniel Holzinger
 *
 */

/**
 * @brief IntArray::IntArray
 * @param len
 */
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

int IntArray::getIndexValue(int index) {
    return array[index];
}

int IntArray::getIndexValue(int x, int y) {
    int index = y*30+x;
    return getIndexValue(index);
}

void IntArray::setValueAtIndex(int x, int y, int value){
    int index = y*30+x;
    setValueAtIndex(index,value);
}

void IntArray::setValueAtIndex(int index, int value){
    this->array[index] = value;
}
