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
#include "rt_nonfinite.h"

/* Function Definitions */
void b_insertionsort(double x[2])
{
  double xc;
  int idx;
  xc = x[1];
  idx = 1;
  if (xc < x[0]) {
    x[1] = x[0];
    idx = 0;
  }
  x[idx] = xc;
}

void insertionsort(int x[4], const int cmp_workspace_a[4],
                   const int cmp_workspace_b[4])
{
  int k;
  for (k = 0; k < 3; k++) {
    int idx;
    int xc;
    boolean_T exitg1;
    xc = x[k + 1] - 1;
    idx = k;
    exitg1 = false;
    while ((!exitg1) && (idx + 1 >= 1)) {
      int i;
      boolean_T varargout_1;
      i = cmp_workspace_a[x[idx] - 1];
      if (cmp_workspace_a[xc] < i) {
        varargout_1 = true;
      } else if (cmp_workspace_a[xc] == i) {
        varargout_1 = (cmp_workspace_b[xc] < cmp_workspace_b[x[idx] - 1]);
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
    x[idx + 1] = xc + 1;
  }
}

/* End of code generation (insertionsort.c) */
