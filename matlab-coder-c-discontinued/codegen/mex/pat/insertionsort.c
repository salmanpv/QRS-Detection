/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * insertionsort.c
 *
 * Code generation for function 'insertionsort'
 *
 */

/* Include files */
#include "insertionsort.h"
#include "pat_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void insertionsort(int32_T x[4])
{
  static const int8_T a[4] = {1, 1, 2, 2};
  static const int8_T b[4] = {1, 2, 2, 1};
  int32_T k;
  for (k = 0; k < 3; k++) {
    int32_T idx;
    int32_T xc;
    boolean_T exitg1;
    xc = x[k + 1];
    idx = k;
    exitg1 = false;
    while ((!exitg1) && (idx + 1 >= 1)) {
      int32_T aj;
      int32_T i;
      boolean_T varargout_1;
      aj = a[x[idx] - 1];
      i = a[xc - 1];
      if (i < aj) {
        varargout_1 = true;
      } else if (i == aj) {
        varargout_1 = (b[xc - 1] < b[x[idx] - 1]);
      } else {
        varargout_1 = false;
      }
      if (varargout_1) {
        x[idx + 1] = x[idx];
        idx--;
      } else {
        exitg1 = true;
      }
    }
    x[idx + 1] = xc;
  }
}

/* End of code generation (insertionsort.c) */
