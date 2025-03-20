/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * xzgehrd.c
 *
 * Code generation for function 'xzgehrd'
 *
 */

/* Include files */
#include "xzgehrd.h"
#include "eml_int_forloop_overflow_check.h"
#include "pat_data.h"
#include "rt_nonfinite.h"
#include "xnrm2.h"
#include "xscal.h"
#include "xzlarf.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo wb_emlrtRSI = {
    50,        /* lineNo */
    "xzgehrd", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzgehrd.m" /* pathName */
};

static emlrtRSInfo xb_emlrtRSI = {
    58,        /* lineNo */
    "xzgehrd", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzgehrd.m" /* pathName */
};

static emlrtRSInfo yb_emlrtRSI = {
    84,       /* lineNo */
    "xzlarf", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzlarf.m" /* pathName */
};

static emlrtRSInfo ac_emlrtRSI = {
    91,       /* lineNo */
    "xzlarf", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzlarf.m" /* pathName */
};

static emlrtRSInfo cc_emlrtRSI = {
    58,      /* lineNo */
    "xgemv", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xgemv.m" /* pathName */
};

static emlrtRSInfo sc_emlrtRSI = {
    71,        /* lineNo */
    "xzlarfg", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzlarfg.m" /* pathName */
};

static emlrtRSInfo yd_emlrtRSI = {
    28,        /* lineNo */
    "xzgehrd", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzgehrd.m" /* pathName */
};

static emlrtRSInfo ae_emlrtRSI = {
    37,        /* lineNo */
    "xzgehrd", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzgehrd.m" /* pathName */
};

static emlrtRSInfo be_emlrtRSI = {
    46,        /* lineNo */
    "xzgehrd", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzgehrd.m" /* pathName */
};

static emlrtRSInfo ce_emlrtRSI = {
    81,        /* lineNo */
    "xzlarfg", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzlarfg.m" /* pathName */
};

static emlrtRSInfo de_emlrtRSI = {
    68,        /* lineNo */
    "xzlarfg", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzlarfg.m" /* pathName */
};

static emlrtRSInfo ee_emlrtRSI = {
    53,        /* lineNo */
    "xzlarfg", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzlarfg.m" /* pathName */
};

static emlrtRSInfo fe_emlrtRSI = {
    41,        /* lineNo */
    "xzlarfg", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzlarfg.m" /* pathName */
};

static emlrtRSInfo ge_emlrtRSI = {
    20,        /* lineNo */
    "xzlarfg", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzlarfg.m" /* pathName */
};

/* Function Definitions */
void xzgehrd(const emlrtStack *sp, real_T a[4], int32_T ilo, int32_T ihi)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack st;
  real_T work[2];
  int32_T i;
  int32_T ia;
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
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  if ((ihi - ilo) + 1 > 1) {
    st.site = &yd_emlrtRSI;
    if (ilo - 1 > 2147483646) {
      b_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    work[0] = 0.0;
    work[1] = 0.0;
    st.site = &ae_emlrtRSI;
    if ((ilo <= ihi - 1) && (ihi - 1 > 2147483646)) {
      b_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (i = ilo; i < ihi; i++) {
      real_T alpha1;
      real_T d;
      real_T tau;
      real_T xnorm;
      int32_T knt;
      alpha1 = a[1];
      st.site = &be_emlrtRSI;
      tau = 0.0;
      if (ihi - 1 > 0) {
        b_st.site = &ge_emlrtRSI;
        xnorm = xnrm2(&b_st, 0, a, 2);
        if (xnorm != 0.0) {
          d = a[1];
          xnorm = muDoubleScalarHypot(d, xnorm);
          if (d >= 0.0) {
            xnorm = -xnorm;
          }
          if (muDoubleScalarAbs(xnorm) < 1.0020841800044864E-292) {
            knt = 0;
            do {
              knt++;
              b_st.site = &fe_emlrtRSI;
              c_st.site = &wd_emlrtRSI;
              d_st.site = &xd_emlrtRSI;
              xnorm *= 9.9792015476736E+291;
              alpha1 *= 9.9792015476736E+291;
            } while ((muDoubleScalarAbs(xnorm) < 1.0020841800044864E-292) &&
                     (knt < 20));
            b_st.site = &ee_emlrtRSI;
            xnorm = xnrm2(&b_st, 0, a, 2);
            xnorm = muDoubleScalarHypot(alpha1, xnorm);
            if (alpha1 >= 0.0) {
              xnorm = -xnorm;
            }
            tau = (xnorm - alpha1) / xnorm;
            b_st.site = &de_emlrtRSI;
            xscal(&b_st, 0, 1.0 / (alpha1 - xnorm), a, 2);
            b_st.site = &sc_emlrtRSI;
            for (lastv = 0; lastv < knt; lastv++) {
              xnorm *= 1.0020841800044864E-292;
            }
            alpha1 = xnorm;
          } else {
            tau = (xnorm - d) / xnorm;
            b_st.site = &ce_emlrtRSI;
            xscal(&b_st, 0, 1.0 / (d - xnorm), a, 2);
            alpha1 = xnorm;
          }
        }
      }
      a[1] = 1.0;
      st.site = &wb_emlrtRSI;
      if (tau != 0.0) {
        boolean_T exitg2;
        lastv = ihi - 1;
        knt = ihi;
        while ((lastv > 0) && (a[knt - 1] == 0.0)) {
          lastv = 0;
          knt--;
        }
        lastc = ihi;
        exitg2 = false;
        while ((!exitg2) && (lastc > 0)) {
          int32_T exitg1;
          ia = lastc + 1;
          do {
            exitg1 = 0;
            if (ia + 1 <= (lastc + ((lastv - 1) << 1)) + 2) {
              if (a[ia] != 0.0) {
                exitg1 = 1;
              } else {
                ia += 2;
              }
            } else {
              lastc--;
              exitg1 = 2;
            }
          } while (exitg1 == 0);
          if (exitg1 == 1) {
            exitg2 = true;
          }
        }
      } else {
        lastv = 0;
        lastc = 0;
      }
      if (lastv > 0) {
        __m128d r;
        __m128d r1;
        int32_T vectorUB;
        b_st.site = &yb_emlrtRSI;
        c_st.site = &bc_emlrtRSI;
        if (lastc != 0) {
          d_st.site = &dc_emlrtRSI;
          if (lastc > 2147483646) {
            e_st.site = &o_emlrtRSI;
            check_forloop_overflow_error(&e_st);
          }
          knt = (uint8_T)lastc;
          memset(&work[0], 0, (uint32_T)knt * sizeof(real_T));
          knt = lastc + 2;
          d_st.site = &cc_emlrtRSI;
          if (lastc + 2 > 2147483646) {
            e_st.site = &o_emlrtRSI;
            check_forloop_overflow_error(&e_st);
          }
          lastv = (knt - 2) / 2 * 2 + 3;
          vectorUB = lastv - 2;
          for (ia = 3; ia <= vectorUB; ia += 2) {
            r = _mm_loadu_pd(&a[ia - 1]);
            r = _mm_mul_pd(r, _mm_set1_pd(a[1]));
            r1 = _mm_loadu_pd(&work[ia - 3]);
            r = _mm_add_pd(r1, r);
            _mm_storeu_pd(&work[ia - 3], r);
          }
          for (ia = lastv; ia <= knt; ia++) {
            work[ia - 3] += a[ia - 1] * a[1];
          }
        }
        b_st.site = &ac_emlrtRSI;
        c_st.site = &ec_emlrtRSI;
        d_st.site = &fc_emlrtRSI;
        e_st.site = &gc_emlrtRSI;
        if (!(-tau == 0.0)) {
          f_st.site = &hc_emlrtRSI;
          d = a[1];
          if (d != 0.0) {
            xnorm = d * -tau;
            knt = lastc + 2;
            f_st.site = &ic_emlrtRSI;
            if (lastc + 2 > 2147483646) {
              g_st.site = &o_emlrtRSI;
              check_forloop_overflow_error(&g_st);
            }
            lastv = (knt - 2) / 2 * 2 + 3;
            vectorUB = lastv - 2;
            for (lastc = 3; lastc <= vectorUB; lastc += 2) {
              r = _mm_loadu_pd(&work[lastc - 3]);
              r = _mm_mul_pd(r, _mm_set1_pd(xnorm));
              r1 = _mm_loadu_pd(&a[lastc - 1]);
              r = _mm_add_pd(r1, r);
              _mm_storeu_pd(&a[lastc - 1], r);
            }
            for (lastc = lastv; lastc <= knt; lastc++) {
              a[lastc - 1] += work[lastc - 3] * xnorm;
            }
          }
        }
      }
      st.site = &xb_emlrtRSI;
      xzlarf(&st, ihi - 1, tau, a, work);
      a[1] = alpha1;
    }
  }
}

/* End of code generation (xzgehrd.c) */
