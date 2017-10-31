#include "intarray.h"

IntArray::IntArray(int len)
{
    this->length = len;
    this->array = new int[len];
}

/*
 *Unnecessary
 * void IntArray::setLength( double len ) {
 *  length = len;
 * }
 */

double IntArray::getLength( void ) {
   return length;
}
