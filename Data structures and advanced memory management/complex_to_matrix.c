#include <stdio.h>
#include <complex.h>

void ComplexToMatrix( const double complex z, double matrix[2][2] ) {
    matrix[0][0] = creal(z);
    matrix[0][1] = -cimag(z);
    matrix[1][0] = cimag(z);
    matrix[1][1] = creal(z);
}