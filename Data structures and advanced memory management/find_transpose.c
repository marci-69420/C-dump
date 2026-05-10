#include <stdio.h>
#include <stdlib.h>

void FindTranspose(long double* pldbl, const size_t nRows, const size_t nCols) {
    long double* pldblTransposed = (long double*)malloc(nRows * nCols * sizeof(long double));
    
    if (pldblTransposed == NULL) {
        return;
    }

    for (size_t i = 0; i < nRows; i++) {
        for (size_t j = 0; j < nCols; j++) {
            pldblTransposed[j * nRows + i] = pldbl[i * nCols + j];
        }
    }

    size_t totalElements = nRows * nCols;
    for (size_t k = 0; k < totalElements; k++) {
        pldbl[k] = pldblTransposed[k];
    }

    free(pldblTransposed);
}