#ifndef INTARRAY_H
#define INTARRAY_H
using namespace std;

class IntArray
{
public:
    IntArray(int len);
    ~IntArray();
    void setLength( double len );
    double getLength( void );
    void arrayToStringMatrix();
    int getIndexValue(int index);
    void setValueAtIndex(int index, int value);

private:
    int length;
    int* array;
};

#endif // INTARRAY_H
