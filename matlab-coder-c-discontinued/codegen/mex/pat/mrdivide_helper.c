/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * mrdivide_helper.c
 *
 * Code generation for function 'mrdivide_helper'
 *
 */

/* Include files */
#include "mrdivide_helper.h"
#include "pat_data.h"
#include "rt_nonfinite.h"
#include "warning.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo db_emlrtRSI = {
    42,      /* lineNo */
    "mrdiv", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\mrdivide_"
    "helper.m" /* pathName */
};

/* Function Definitions */
void mrdiv(const emlrtStack *sp, const real_T A[2], const real_T B[4],
           real_T Y[2])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T a21;
  real_T a22;
  real_T a22_tmp;
  int32_T r1;
  int32_T r2;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &db_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &s_emlrtRSI;
  if (muDoubleScalarAbs(B[1]) > muDoubleScalarAbs(B[0])) {
    r1 = 1;
    r2 = 0;
  } else {
    r1 = 0;
    r2 = 1;
  }
  a21 = B[r2] / B[r1];
  a22_tmp = B[r1 + 2];
  a22 = B[r2 + 2] - a21 * a22_tmp;
  if ((a22 == 0.0) || (B[r1] == 0.0)) {
    c_st.site = &t_emlrtRSI;
    d_st.site = &u_emlrtRSI;
    warning(&d_st);
  }
  Y[r1] = A[0] / B[r1];
  Y[r2] = (0.0 - Y[r1] * a22_tmp) / a22;
  Y[r1] -= Y[r2] * a21;
}

/* End of code generation (mrdivide_helper.c) */
