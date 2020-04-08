#ifndef INTGRANDE_H
#define INTGRANDE_H

#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

class IntGrande {
    friend ostream &operator<<(ostream &, const IntGrande &);
public:
    IntGrande(long = 0);
    IntGrande(const char *); /*constructor de conversion*/
    IntGrande(const IntGrande& orig); /*constructor de copia*/
    virtual ~IntGrande(); /*destructor*/
    IntGrande operator+(const IntGrande &);
    IntGrande operator+(int);
    IntGrande operator+(const char *);
    IntGrande operator-(const IntGrande &);
    IntGrande operator-(int);
    IntGrande operator-(const char *);
    IntGrande operator*(const IntGrande &);
    IntGrande operator*(int);
    IntGrande operator*(const char *);
    IntGrande operator/(const IntGrande &);
    IntGrande operator/(int);
    IntGrande operator/(const char *);
private:
    short entero[30];
};

#endif /* INTGRANDE_H */


