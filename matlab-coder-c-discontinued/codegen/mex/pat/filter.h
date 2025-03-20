/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * filter.h
 *
 * Code generation for function 'filter'
 *
 */

#pragma once

/* Include files */
#include "pat_types.h"
#include "rtwtypes.h"
#include "covrt.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void b_filter(const emlrtStack *sp, const emxArray_real_T *b,
              const real_T x[1799], real_T y[1799]);

int32_T filter(const emlrtStack *sp, real_T b[3], real_T a[3],
               const real_T x_data[], int32_T x_size, const real_T zi[2],
               real_T y_data[]);

/* End of code generation (filter.h) */
