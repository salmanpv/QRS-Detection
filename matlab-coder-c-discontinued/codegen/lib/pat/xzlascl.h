/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * xzlascl.h
 *
 * Code generation for function 'xzlascl'
 *
 */

#ifndef XZLASCL_H
#define XZLASCL_H

/* Include files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void b_xzlascl(double cfrom, double cto, int m, double A[2], int iA0);

void c_xzlascl(double cfrom, double cto, int m, double *A);

void xzlascl(double cfrom, double cto, double A[4]);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (xzlascl.h) */
