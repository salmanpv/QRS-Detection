/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * filtfilt.h
 *
 * Code generation for function 'filtfilt'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "covrt.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void filtfilt(const emlrtStack *sp, const real_T ctf[3],
              const real_T varargin_1[3], const real_T varargin_2[1800],
              real_T y[1800]);

/* End of code generation (filtfilt.h) */
