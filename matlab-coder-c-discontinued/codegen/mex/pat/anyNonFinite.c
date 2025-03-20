/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * anyNonFinite.c
 *
 * Code generation for function 'anyNonFinite'
 *
 */

/* Include files */
#include "anyNonFinite.h"
#include "pat_data.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Function Definitions */
boolean_T anyNonFinite(const real_T x[4])
{
  int32_T k;
  boolean_T p;
  p = true;
  for (k = 0; k < 4; k++) {
    if (p) {
      real_T d;
      d = x[k];
      if (muDoubleScalarIsInf(d) || muDoubleScalarIsNaN(d)) {
        p = false;
      }
    } else {
      p = false;
    }
  }
  return !p;
}

/* End of code generation (anyNonFinite.c) */
