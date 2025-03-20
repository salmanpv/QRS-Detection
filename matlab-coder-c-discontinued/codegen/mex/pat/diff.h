/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * diff.h
 *
 * Code generation for function 'diff'
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
void b_diff(const emlrtStack *sp, const emxArray_real_T *x, emxArray_real_T *y);

void diff(const real_T x[1800], real_T y[1799]);

/* End of code generation (diff.h) */
