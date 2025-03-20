/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * insertionsort.h
 *
 * Code generation for function 'insertionsort'
 *
 */

#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

/* Include files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void b_insertionsort(double x[2]);

void insertionsort(int x[4], const int cmp_workspace_a[4],
                   const int cmp_workspace_b[4]);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (insertionsort.h) */
