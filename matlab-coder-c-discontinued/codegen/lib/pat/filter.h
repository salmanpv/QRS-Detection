/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * filter.h
 *
 * Code generation for function 'filter'
 *
 */

#ifndef FILTER_H
#define FILTER_H

/* Include files */
#include "pat_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void b_filter(const emxArray_real_T *b, const double x[1799], double y[1799]);

int filter(double b[3], double a[3], const double x_data[], int x_size,
           const double zi[2], double y_data[]);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (filter.h) */
