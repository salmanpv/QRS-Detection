/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * xzgebal.c
 *
 * Code generation for function 'xzgebal'
 *
 */

/* Include files */
#include "xzgebal.h"
#include "eml_int_forloop_overflow_check.h"
#include "pat_data.h"
#include "rt_nonfinite.h"
#include "xnrm2.h"
#include "xscal.h"
#include "xswap.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo jd_emlrtRSI = {
    39,        /* lineNo */
    "xzgebal", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzgebal.m" /* pathName */
};

static emlrtRSInfo kd_emlrtRSI = {
    55,        /* lineNo */
    "xzgebal", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzgebal.m" /* pathName */
};

static emlrtRSInfo ld_emlrtRSI = {
    74,        /* lineNo */
    "xzgebal", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzgebal.m" /* pathName */
};

static emlrtRSInfo md_emlrtRSI = {
    76,        /* lineNo */
    "xzgebal", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzgebal.m" /* pathName */
};

static emlrtRSInfo nd_emlrtRSI = {
    92,        /* lineNo */
    "xzgebal", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzgebal.m" /* pathName */
};

static emlrtRSInfo od_emlrtRSI = {
    95,        /* lineNo */
    "xzgebal", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzgebal.m" /* pathName */
};

static emlrtRSInfo pd_emlrtRSI = {
    119,       /* lineNo */
    "xzgebal", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzgebal.m" /* pathName */
};

static emlrtRSInfo qd_emlrtRSI = {
    120,       /* lineNo */
    "xzgebal", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzgebal.m" /* pathName */
};

static emlrtRSInfo rd_emlrtRSI = {
    170,       /* lineNo */
    "xzgebal", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzgebal.m" /* pathName */
};

/* Function Definitions */
int32_T xzgebal(const emlrtStack *sp, real_T A[4], int32_T *ihi,
                real_T scale[2])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T b_scale;
  int32_T b_i;
  int32_T exitg5;
  int32_T i;
  int32_T ilo;
  int32_T ix;
  int32_T iy;
  int32_T k;
  int32_T kend;
  boolean_T converged;
  boolean_T notdone;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  scale[0] = 1.0;
  scale[1] = 1.0;
  ilo = 1;
  *ihi = 2;
  notdone = true;
  do {
    exitg5 = 0;
    if (notdone) {
      int32_T exitg4;
      notdone = false;
      kend = *ihi;
      do {
        exitg4 = 0;
        if (kend > 0) {
          boolean_T exitg6;
          converged = false;
          st.site = &jd_emlrtRSI;
          i = 0;
          exitg6 = false;
          while ((!exitg6) && (i <= *ihi - 1)) {
            if ((i + 1 == kend) || (!(A[(kend + (i << 1)) - 1] != 0.0))) {
              i++;
            } else {
              converged = true;
              exitg6 = true;
            }
          }
          if (converged) {
            kend--;
          } else {
            scale[*ihi - 1] = kend;
            if (kend != *ihi) {
              st.site = &kd_emlrtRSI;
              xswap(&st, *ihi, A, ((kend - 1) << 1) + 1, ((*ihi - 1) << 1) + 1);
              b_scale = A[kend - 1];
              A[kend - 1] = A[*ihi - 1];
              A[*ihi - 1] = b_scale;
              b_scale = A[kend + 1];
              A[kend + 1] = A[*ihi + 1];
              A[*ihi + 1] = b_scale;
            }
            exitg4 = 1;
          }
        } else {
          exitg4 = 2;
        }
      } while (exitg4 == 0);
      if (exitg4 == 1) {
        if (*ihi == 1) {
          ilo = 1;
          *ihi = 1;
          exitg5 = 1;
        } else {
          *ihi = 1;
          notdone = true;
        }
      }
    } else {
      notdone = true;
      while (notdone) {
        boolean_T exitg6;
        notdone = false;
        st.site = &ld_emlrtRSI;
        kend = ilo;
        exitg6 = false;
        while ((!exitg6) && (kend <= *ihi)) {
          boolean_T exitg7;
          converged = false;
          st.site = &md_emlrtRSI;
          i = ilo;
          exitg7 = false;
          while ((!exitg7) && (i <= *ihi)) {
            if ((i == kend) || (!(A[(i + ((kend - 1) << 1)) - 1] != 0.0))) {
              i++;
            } else {
              converged = true;
              exitg7 = true;
            }
          }
          if (converged) {
            kend++;
          } else {
            scale[ilo - 1] = kend;
            if (kend != ilo) {
              b_i = (ilo - 1) << 1;
              st.site = &nd_emlrtRSI;
              xswap(&st, *ihi, A, ((kend - 1) << 1) + 1, b_i + 1);
              ix = (b_i + kend) - 1;
              iy = (b_i + ilo) - 1;
              st.site = &od_emlrtRSI;
              b_st.site = &sd_emlrtRSI;
              c_st.site = &td_emlrtRSI;
              if (3 - ilo > 2147483646) {
                d_st.site = &o_emlrtRSI;
                check_forloop_overflow_error(&d_st);
              }
              b_i = (uint8_T)(3 - ilo);
              for (k = 0; k < b_i; k++) {
                kend = k << 1;
                i = ix + kend;
                b_scale = A[i];
                kend += iy;
                A[i] = A[kend];
                A[kend] = b_scale;
              }
            }
            ilo++;
            notdone = true;
            exitg6 = true;
          }
        }
      }
      converged = false;
      exitg5 = 2;
    }
  } while (exitg5 == 0);
  if (exitg5 != 1) {
    boolean_T exitg3;
    exitg3 = false;
    while ((!exitg3) && (!converged)) {
      int32_T exitg2;
      converged = true;
      st.site = &pd_emlrtRSI;
      i = ilo - 1;
      do {
        exitg2 = 0;
        if (i + 1 <= *ihi) {
          real_T absxk;
          real_T c;
          real_T r;
          real_T t;
          kend = (*ihi - ilo) + 1;
          iy = i << 1;
          st.site = &qd_emlrtRSI;
          c = xnrm2(&st, kend, A, iy + ilo);
          ix = ((ilo - 1) << 1) + i;
          r = 0.0;
          if (kend >= 1) {
            if (kend == 1) {
              r = muDoubleScalarAbs(A[ix]);
            } else {
              b_scale = 3.3121686421112381E-170;
              kend = ix + 3;
              for (k = ix + 1; k <= kend; k += 2) {
                absxk = muDoubleScalarAbs(A[k - 1]);
                if (absxk > b_scale) {
                  t = b_scale / absxk;
                  r = r * t * t + 1.0;
                  b_scale = absxk;
                } else {
                  t = absxk / b_scale;
                  r += t * t;
                }
              }
              r = b_scale * muDoubleScalarSqrt(r);
            }
          }
          kend = 0;
          if ((*ihi > 1) &&
              (muDoubleScalarAbs(A[iy + 1]) > muDoubleScalarAbs(A[iy]))) {
            kend = 1;
          }
          b_scale = muDoubleScalarAbs(A[kend + iy]);
          if (3 - ilo < 1) {
            kend = -2;
          } else {
            kend = -1;
            if ((3 - ilo > 1) &&
                (muDoubleScalarAbs(A[ix + 2]) > muDoubleScalarAbs(A[ix]))) {
              kend = 0;
            }
          }
          absxk = muDoubleScalarAbs(A[i + ((kend + ilo) << 1)]);
          if ((c == 0.0) || (r == 0.0)) {
            i++;
          } else {
            real_T f;
            real_T s;
            int32_T exitg1;
            t = r / 2.0;
            f = 1.0;
            s = c + r;
            do {
              exitg1 = 0;
              if ((c < t) &&
                  (muDoubleScalarMax(f, muDoubleScalarMax(c, b_scale)) <
                   4.9896007738368E+291) &&
                  (muDoubleScalarMin(r, muDoubleScalarMin(t, absxk)) >
                   2.0041683600089728E-292)) {
                if (muDoubleScalarIsNaN(((((c + f) + b_scale) + r) + t) +
                                        absxk)) {
                  exitg1 = 1;
                } else {
                  f *= 2.0;
                  c *= 2.0;
                  b_scale *= 2.0;
                  r /= 2.0;
                  t /= 2.0;
                  absxk /= 2.0;
                }
              } else {
                t = c / 2.0;
                while ((t >= r) &&
                       (muDoubleScalarMax(r, absxk) < 4.9896007738368E+291) &&
                       (muDoubleScalarMin(muDoubleScalarMin(f, c),
                                          muDoubleScalarMin(t, b_scale)) >
                        2.0041683600089728E-292)) {
                  f /= 2.0;
                  c /= 2.0;
                  t /= 2.0;
                  b_scale /= 2.0;
                  r *= 2.0;
                  absxk *= 2.0;
                }
                if ((!(c + r >= 0.95 * s)) &&
                    ((!(f < 1.0)) || (!(scale[i] < 1.0)) ||
                     (!(f * scale[i] <= 1.0020841800044864E-292))) &&
                    ((!(f > 1.0)) || (!(scale[i] > 1.0)) ||
                     (!(scale[i] >= 9.9792015476736E+291 / f)))) {
                  b_scale = 1.0 / f;
                  scale[i] *= f;
                  kend = ix + 1;
                  b_i = (ix + ((2 - ilo) << 1)) + 1;
                  for (k = kend; k <= b_i; k += 2) {
                    A[k - 1] *= b_scale;
                  }
                  st.site = &rd_emlrtRSI;
                  xscal(&st, *ihi, f, A, iy + 1);
                  converged = false;
                }
                exitg1 = 2;
              }
            } while (exitg1 == 0);
            if (exitg1 == 1) {
              exitg2 = 2;
            } else {
              i++;
            }
          }
        } else {
          exitg2 = 1;
        }
      } while (exitg2 == 0);
      if (exitg2 != 1) {
        exitg3 = true;
      }
    }
  }
  return ilo;
}

/* End of code generation (xzgebal.c) */
