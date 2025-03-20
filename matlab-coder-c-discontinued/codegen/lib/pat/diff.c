/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * diff.c
 *
 * Code generation for function 'diff'
 *
 */

/* Include files */
#include "diff.h"
#include "pat_emxutil.h"
#include "pat_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void b_diff(const emxArray_real_T *x, emxArray_real_T *y)
{
  const double *x_data;
  double work_data;
  double *y_data;
  int dimSize;
  int m;
  x_data = x->data;
  dimSize = x->size[0];
  m = y->size[0];
  y->size[0] = x->size[0] - 1;
  emxEnsureCapacity_real_T(y, m);
  y_data = y->data;
  work_data = x_data[0];
  for (m = 2; m <= dimSize; m++) {
    double tmp2;
    tmp2 = work_data;
    work_data = x_data[m - 1];
    y_data[m - 2] = work_data - tmp2;
  }
}

void diff(const double x[1800], double y[1799])
{
  double work;
  int m;
  work = x[0];
  for (m = 0; m < 1799; m++) {
    double tmp2;
    tmp2 = work;
    work = x[m + 1];
    y[m] = work - tmp2;
  }
}

/* End of code generation (diff.c) */
