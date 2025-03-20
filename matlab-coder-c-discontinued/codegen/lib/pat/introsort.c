/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * introsort.c
 *
 * Code generation for function 'introsort'
 *
 */

/* Include files */
#include "introsort.h"
#include "insertionsort.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void introsort(int x[4], const int cmp_workspace_a[4],
               const int cmp_workspace_b[4])
{
  insertionsort(x, cmp_workspace_a, cmp_workspace_b);
}

/* End of code generation (introsort.c) */
