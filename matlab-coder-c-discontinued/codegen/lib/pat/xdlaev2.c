/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * xdlaev2.c
 *
 * Code generation for function 'xdlaev2'
 *
 */

/* Include files */
#include "xdlaev2.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
double xdlaev2(double a, double b, double c, double *rt2)
{
  double ab;
  double acmn;
  double acmx;
  double adf;
  double rt1;
  rt1 = a + c;
  adf = fabs(a - c);
  ab = fabs(b + b);
  if (fabs(a) > fabs(c)) {
    acmx = a;
    acmn = c;
  } else {
    acmx = c;
    acmn = a;
  }
  if (adf > ab) {
    double b_a;
    b_a = ab / adf;
    adf *= sqrt(b_a * b_a + 1.0);
  } else if (adf < ab) {
    double b_a;
    b_a = adf / ab;
    adf = ab * sqrt(b_a * b_a + 1.0);
  } else {
    adf = ab * 1.4142135623730951;
  }
  if (rt1 < 0.0) {
    rt1 = 0.5 * (rt1 - adf);
    *rt2 = acmx / rt1 * acmn - b / rt1 * b;
  } else if (rt1 > 0.0) {
    rt1 = 0.5 * (rt1 + adf);
    *rt2 = acmx / rt1 * acmn - b / rt1 * b;
  } else {
    rt1 = 0.5 * adf;
    *rt2 = -0.5 * adf;
  }
  return rt1;
}

/* End of code generation (xdlaev2.c) */
