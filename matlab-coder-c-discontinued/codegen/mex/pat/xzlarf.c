/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * xzlarf.c
 *
 * Code generation for function 'xzlarf'
 *
 */

/* Include files */
#include "xzlarf.h"
#include "eml_int_forloop_overflow_check.h"
#include "pat_data.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo jc_emlrtRSI = {
    50,       /* lineNo */
    "xzlarf", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzlarf.m" /* pathName */
};

static emlrtRSInfo kc_emlrtRSI = {
    68,       /* lineNo */
    "xzlarf", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzlarf.m" /* pathName */
};

static emlrtRSInfo lc_emlrtRSI = {
    75,       /* lineNo */
    "xzlarf", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzlarf.m" /* pathName */
};

static emlrtRSInfo mc_emlrtRSI = {
    103,      /* lineNo */
    "ilazlc", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzlarf.m" /* pathName */
};

static emlrtRSInfo nc_emlrtRSI = {
    74,      /* lineNo */
    "xgemv", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xgemv.m" /* pathName */
};

/* Function Definitions */
void xzlarf(const emlrtStack *sp, int32_T m, real_T tau, real_T C[4],
            real_T work[2])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  int32_T i;
  int32_T ijA;
  int32_T lastc;
  int32_T lastv;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  if (tau != 0.0) {
    lastv = m;
    i = m;
    while ((lastv > 0) && (C[i] == 0.0)) {
      lastv = 0;
      i--;
    }
    st.site = &jc_emlrtRSI;
    lastc = 1;
    b_st.site = &mc_emlrtRSI;
    if (lastv + 3 > 2147483646) {
      c_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    i = 4;
    int32_T exitg1;
    do {
      exitg1 = 0;
      if (i <= lastv + 3) {
        if (C[3] != 0.0) {
          exitg1 = 1;
        } else {
          i++;
        }
      } else {
        lastc = 0;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  } else {
    lastv = 0;
    lastc = 0;
  }
  if (lastv > 0) {
    st.site = &kc_emlrtRSI;
    b_st.site = &bc_emlrtRSI;
    if (lastc != 0) {
      c_st.site = &dc_emlrtRSI;
      work[0] = 0.0;
      c_st.site = &nc_emlrtRSI;
      work[0] += C[1] * C[3];
    }
    st.site = &lc_emlrtRSI;
    b_st.site = &ec_emlrtRSI;
    c_st.site = &fc_emlrtRSI;
    d_st.site = &gc_emlrtRSI;
    if (!(-tau == 0.0)) {
      i = 4;
      e_st.site = &hc_emlrtRSI;
      for (lastv = 0; lastv < lastc; lastv++) {
        real_T temp;
        temp = work[0];
        if (temp != 0.0) {
          temp *= -tau;
          e_st.site = &ic_emlrtRSI;
          if (i > 2147483646) {
            f_st.site = &o_emlrtRSI;
            check_forloop_overflow_error(&f_st);
          }
          for (ijA = i; ijA <= i; ijA++) {
            C[ijA - 1] += C[(ijA - i) + 1] * temp;
          }
        }
        i += 2;
      }
    }
  }
}

/* End of code generation (xzlarf.c) */
