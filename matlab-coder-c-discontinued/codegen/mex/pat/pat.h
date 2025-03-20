/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * pat.h
 *
 * Code generation for function 'pat'
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
void pat(const emlrtStack *sp, const real_T ecg_signal[1800], real_T fs,
         emxArray_real_T *heart_rate, emxArray_real_T *r_peaks);

/* End of code generation (pat.h) */
