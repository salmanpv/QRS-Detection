/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * eig.c
 *
 * Code generation for function 'eig'
 *
 */

/* Include files */
#include "eig.h"
#include "anyNonFinite.h"
#include "eigStandard.h"
#include "pat_data.h"
#include "rt_nonfinite.h"
#include "warning.h"
#include "xdlanv2.h"
#include "lapacke.h"
#include "mwmathutil.h"
#include <stddef.h>

/* Variable Definitions */
static emlrtRSInfo eb_emlrtRSI = {
    81,    /* lineNo */
    "eig", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\matfun\\eig.m" /* pathName
                                                                       */
};

static emlrtRSInfo fb_emlrtRSI = {
    127,   /* lineNo */
    "eig", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\matfun\\eig.m" /* pathName
                                                                       */
};

static emlrtRSInfo gb_emlrtRSI = {
    135,   /* lineNo */
    "eig", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\matfun\\eig.m" /* pathName
                                                                       */
};

static emlrtRSInfo hb_emlrtRSI = {
    143,   /* lineNo */
    "eig", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\matfun\\eig.m" /* pathName
                                                                       */
};

static emlrtRSInfo lb_emlrtRSI = {
    13,                     /* lineNo */
    "eigHermitianStandard", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\matfun\\private\\eigHerm"
    "itianStandard.m" /* pathName */
};

static emlrtRSInfo mb_emlrtRSI = {
    40,                     /* lineNo */
    "eigHermitianStandard", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\matfun\\private\\eigHerm"
    "itianStandard.m" /* pathName */
};

static emlrtRSInfo nb_emlrtRSI = {
    8,         /* lineNo */
    "xsyheev", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xsyheev.m" /* pathName */
};

static emlrtRSInfo ob_emlrtRSI = {
    61,              /* lineNo */
    "ceval_xsyheev", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xsyheev.m" /* pathName */
};

static emlrtRSInfo qb_emlrtRSI = {
    10,                         /* lineNo */
    "eigSkewHermitianStandard", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\matfun\\private\\eigSkew"
    "HermitianStandard.m" /* pathName */
};

static emlrtRSInfo rb_emlrtRSI = {
    19,                             /* lineNo */
    "eigRealSkewSymmetricStandard", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\matfun\\private\\eigReal"
    "SkewSymmetricStandard.m" /* pathName */
};

static emlrtRTEInfo h_emlrtRTEI = {
    48,          /* lineNo */
    13,          /* colNo */
    "infocheck", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\infocheck.m" /* pName */
};

static emlrtRTEInfo i_emlrtRTEI = {
    45,          /* lineNo */
    13,          /* colNo */
    "infocheck", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\infocheck.m" /* pName */
};

/* Function Definitions */
void eig(const emlrtStack *sp, const real_T A[4], creal_T V[2])
{
  static const char_T fname[13] = {'L', 'A', 'P', 'A', 'C', 'K', 'E',
                                   '_', 'd', 's', 'y', 'e', 'v'};
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T T[4];
  real_T W[2];
  real_T aa;
  real_T bb;
  real_T cs;
  real_T d;
  real_T d1;
  real_T d2;
  real_T s;
  real_T sn;
  int32_T i;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &eb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  if (anyNonFinite(A)) {
    V[0].re = rtNaN;
    V[0].im = 0.0;
    V[1].re = rtNaN;
    V[1].im = 0.0;
  } else {
    int32_T exitg1;
    int32_T k;
    boolean_T exitg2;
    boolean_T p;
    p = true;
    k = 0;
    exitg2 = false;
    while ((!exitg2) && (k < 2)) {
      i = 0;
      do {
        exitg1 = 0;
        if (i <= k) {
          if (!(A[i + (k << 1)] == A[k + (i << 1)])) {
            p = false;
            exitg1 = 1;
          } else {
            i++;
          }
        } else {
          k++;
          exitg1 = 2;
        }
      } while (exitg1 == 0);
      if (exitg1 == 1) {
        exitg2 = true;
      }
    }
    if (p) {
      ptrdiff_t n_t;
      st.site = &fb_emlrtRSI;
      b_st.site = &lb_emlrtRSI;
      c_st.site = &nb_emlrtRSI;
      T[0] = A[0];
      T[1] = A[1];
      T[2] = A[2];
      T[3] = A[3];
      n_t = (ptrdiff_t)2;
      n_t = LAPACKE_dsyev(102, 'N', 'L', n_t, &T[0], n_t, &W[0]);
      d_st.site = &ob_emlrtRSI;
      if ((int32_T)n_t < 0) {
        if ((int32_T)n_t == -1010) {
          emlrtErrorWithMessageIdR2018a(&d_st, &i_emlrtRTEI, "MATLAB:nomem",
                                        "MATLAB:nomem", 0);
        } else {
          emlrtErrorWithMessageIdR2018a(&d_st, &h_emlrtRTEI,
                                        "Coder:toolbox:LAPACKCallErrorInfo",
                                        "Coder:toolbox:LAPACKCallErrorInfo", 5,
                                        4, 13, &fname[0], 12, (int32_T)n_t);
        }
      }
      V[0].re = W[0];
      V[0].im = 0.0;
      V[1].re = W[1];
      V[1].im = 0.0;
      if ((int32_T)n_t != 0) {
        b_st.site = &mb_emlrtRSI;
        b_warning(&b_st);
      }
    } else {
      p = true;
      k = 0;
      exitg2 = false;
      while ((!exitg2) && (k < 2)) {
        i = 0;
        do {
          exitg1 = 0;
          if (i <= k) {
            if (!(A[i + (k << 1)] == -A[k + (i << 1)])) {
              p = false;
              exitg1 = 1;
            } else {
              i++;
            }
          } else {
            k++;
            exitg1 = 2;
          }
        } while (exitg1 == 0);
        if (exitg1 == 1) {
          exitg2 = true;
        }
      }
      if (p) {
        st.site = &gb_emlrtRSI;
        b_st.site = &qb_emlrtRSI;
        c_st.site = &rb_emlrtRSI;
        if (anyNonFinite(A)) {
          T[1] = 0.0;
        } else {
          T[0] = A[0];
          T[1] = A[1];
          T[2] = A[2];
          T[3] = A[3];
          for (i = 1; i + 1 >= 1; i = k - 2) {
            k = i + 1;
            exitg2 = false;
            while ((!exitg2) && (k > 1)) {
              d = muDoubleScalarAbs(T[1]);
              if (d <= 2.0041683600089728E-292) {
                exitg2 = true;
              } else {
                bb = muDoubleScalarAbs(T[3]);
                if (d <=
                    2.2204460492503131E-16 * (muDoubleScalarAbs(T[0]) + bb)) {
                  d1 = muDoubleScalarAbs(T[2]);
                  s = muDoubleScalarAbs(T[0] - T[3]);
                  aa = muDoubleScalarMax(bb, s);
                  bb = muDoubleScalarMin(bb, s);
                  s = aa + bb;
                  if (muDoubleScalarMin(d, d1) *
                          (muDoubleScalarMax(d, d1) / s) <=
                      muDoubleScalarMax(2.0041683600089728E-292,
                                        2.2204460492503131E-16 *
                                            (bb * (aa / s)))) {
                    exitg2 = true;
                  } else {
                    k = 1;
                  }
                } else {
                  k = 1;
                }
              }
            }
            if (k > 1) {
              T[1] = 0.0;
            }
            if ((k != i + 1) && (k == i)) {
              int32_T b_i;
              int32_T i1;
              b_i = i << 1;
              d = T[b_i];
              bb = T[i];
              i1 = i + b_i;
              s = T[i1];
              xdlanv2(&T[0], &d, &bb, &s, &aa, &d1, &d2, &cs, &sn);
              T[b_i] = d;
              T[i] = bb;
              T[i1] = s;
              if (i + 1 < 2) {
                T[2] = cs * T[2] + sn * T[2];
              }
            }
          }
        }
        i = 1;
        while (i <= 2) {
          if ((i != 2) && (T[1] != 0.0)) {
            bb = muDoubleScalarAbs(T[1]);
            V[0].re = 0.0;
            V[0].im = bb;
            V[1].re = 0.0;
            V[1].im = -bb;
            i = 3;
          } else {
            V[i - 1].re = 0.0;
            V[i - 1].im = 0.0;
            i++;
          }
        }
      } else {
        st.site = &hb_emlrtRSI;
        eigStandard(&st, A, V);
      }
    }
  }
}

/* End of code generation (eig.c) */
