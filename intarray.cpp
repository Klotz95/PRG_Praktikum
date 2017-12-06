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

int IntArray::getIndexValue(int index) {
    return array[index];
}

void IntArray::setValueAtIndex(int index, int value){
    this->array[index] = value;
}
