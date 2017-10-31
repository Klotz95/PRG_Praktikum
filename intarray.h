#ifndef INTARRAY_H
#define INTARRAY_H


class IntArray
{
public:
    IntArray( int len );
    void setLength( double len );
    double getLength( void );
private:
    int length;
    int* array;
};

#endif // INTARRAY_H
