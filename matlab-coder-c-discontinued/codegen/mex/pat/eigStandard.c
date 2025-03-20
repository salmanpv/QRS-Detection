/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * eigStandard.c
 *
 * Code generation for function 'eigStandard'
 *
 */

/* Include files */
#include "eigStandard.h"
#include "eml_int_forloop_overflow_check.h"
#include "pat_data.h"
#include "rt_nonfinite.h"
#include "xdlanv2.h"
#include "xzgebal.h"
#include "xzgehrd.h"
#include "xzlascl.h"
#include "mwmathutil.h"
#include <emmintrin.h>

/* Variable Definitions */
static emlrtRSInfo qc_emlrtRSI = {
    337,       /* lineNo */
    "xdlahqr", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xdlahqr.m" /* pathName */
};

static emlrtRSInfo cd_emlrtRSI = {
    34,            /* lineNo */
    "eigStandard", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\matfun\\private\\eigStan"
    "dard.m" /* pathName */
};

static emlrtRSInfo dd_emlrtRSI = {
    54,      /* lineNo */
    "xgeev", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgeev.m" /* pathName */
};

static emlrtRSInfo ed_emlrtRSI = {
    49,       /* lineNo */
    "xdgeev", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xdgeev.m" /* pathName */
};

static emlrtRSInfo fd_emlrtRSI = {
    67,       /* lineNo */
    "xdgeev", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xdgeev.m" /* pathName */
};

static emlrtRSInfo gd_emlrtRSI = {
    73,       /* lineNo */
    "xdgeev", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xdgeev.m" /* pathName */
};

static emlrtRSInfo hd_emlrtRSI = {
    130,      /* lineNo */
    "xdgeev", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xdgeev.m" /* pathName */
};

static emlrtRSInfo id_emlrtRSI = {
    131,      /* lineNo */
    "xdgeev", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xdgeev.m" /* pathName */
};

static emlrtRSInfo he_emlrtRSI = {
    16,        /* lineNo */
    "xdlahqr", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xdlahqr.m" /* pathName */
};

static emlrtRSInfo ie_emlrtRSI = {
    33,        /* lineNo */
    "xdlahqr", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xdlahqr.m" /* pathName */
};

/* Function Definitions */
void eigStandard(const emlrtStack *sp, const real_T A[4], creal_T V[2])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T a__1[4];
  real_T wi[2];
  real_T aa;
  real_T absxk;
  real_T anrm;
  real_T cfrom1;
  real_T ctoc;
  real_T d;
  real_T mul;
  real_T sn;
  int32_T b_i;
  int32_T k;
  boolean_T exitg1;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &cd_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &dd_emlrtRSI;
  a__1[0] = A[0];
  a__1[1] = A[1];
  a__1[2] = A[2];
  a__1[3] = A[3];
  anrm = 0.0;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 4)) {
    absxk = muDoubleScalarAbs(A[k]);
    if (muDoubleScalarIsNaN(absxk)) {
      anrm = rtNaN;
      exitg1 = true;
    } else {
      if (absxk > anrm) {
        anrm = absxk;
      }
      k++;
    }
  }
  if (muDoubleScalarIsInf(anrm) || muDoubleScalarIsNaN(anrm)) {
    V[0].re = rtNaN;
    V[0].im = 0.0;
    V[1].re = rtNaN;
    V[1].im = 0.0;
  } else {
    real_T wr[2];
    real_T cscale;
    int32_T i;
    int32_T ilo;
    boolean_T guard1;
    boolean_T scalea;
    cscale = anrm;
    scalea = false;
    guard1 = false;
    if ((anrm > 0.0) && (anrm < 6.7178761075670888E-139)) {
      scalea = true;
      cscale = 6.7178761075670888E-139;
      guard1 = true;
    } else if (anrm > 1.4885657073574029E+138) {
      scalea = true;
      cscale = 1.4885657073574029E+138;
      guard1 = true;
    }
    if (guard1) {
      boolean_T notdone;
      absxk = anrm;
      ctoc = cscale;
      notdone = true;
      while (notdone) {
        __m128d r;
        __m128d r1;
        cfrom1 = absxk * 2.0041683600089728E-292;
        aa = ctoc / 4.9896007738368E+291;
        if ((cfrom1 > ctoc) && (ctoc != 0.0)) {
          mul = 2.0041683600089728E-292;
          absxk = cfrom1;
        } else if (aa > absxk) {
          mul = 4.9896007738368E+291;
          ctoc = aa;
        } else {
          mul = ctoc / absxk;
          notdone = false;
        }
        r = _mm_loadu_pd(&a__1[0]);
        r1 = _mm_set1_pd(mul);
        _mm_storeu_pd(&a__1[0], _mm_mul_pd(r, r1));
        r = _mm_loadu_pd(&a__1[2]);
        _mm_storeu_pd(&a__1[2], _mm_mul_pd(r, r1));
      }
    }
    c_st.site = &ed_emlrtRSI;
    ilo = xzgebal(&c_st, a__1, &k, wr);
    c_st.site = &fd_emlrtRSI;
    xzgehrd(&c_st, a__1, ilo, k);
    c_st.site = &gd_emlrtRSI;
    d_st.site = &he_emlrtRSI;
    if (ilo - 1 > 2147483646) {
      e_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }
    i = (uint8_T)(ilo - 1);
    for (b_i = 0; b_i < i; b_i++) {
      wr[b_i] = a__1[b_i + (b_i << 1)];
      wi[b_i] = 0.0;
    }
    if (k + 1 <= 2) {
      wr[1] = a__1[3];
      wi[1] = 0.0;
    }
    if (ilo == k) {
      wr[ilo - 1] = a__1[(ilo + ((ilo - 1) << 1)) - 1];
      wi[ilo - 1] = 0.0;
    } else {
      real_T smlnum;
      d_st.site = &ie_emlrtRSI;
      if ((ilo <= k - 3) && (k - 3 > 2147483646)) {
        e_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(&e_st);
      }
      smlnum = 2.2250738585072014E-308 *
               ((real_T)((k - ilo) + 1) / 2.2204460492503131E-16);
      for (b_i = k - 1; b_i + 1 >= ilo; b_i = k - 2) {
        k = b_i + 1;
        exitg1 = false;
        while ((!exitg1) && (k > ilo)) {
          d = muDoubleScalarAbs(a__1[1]);
          if (d <= smlnum) {
            exitg1 = true;
          } else {
            absxk = muDoubleScalarAbs(a__1[3]);
            if (d <=
                2.2204460492503131E-16 * (muDoubleScalarAbs(a__1[0]) + absxk)) {
              cfrom1 = muDoubleScalarAbs(a__1[2]);
              ctoc = muDoubleScalarAbs(a__1[0] - a__1[3]);
              aa = muDoubleScalarMax(absxk, ctoc);
              absxk = muDoubleScalarMin(absxk, ctoc);
              ctoc = aa + absxk;
              if (muDoubleScalarMin(d, cfrom1) *
                      (muDoubleScalarMax(d, cfrom1) / ctoc) <=
                  muDoubleScalarMax(smlnum, 2.2204460492503131E-16 *
                                                (absxk * (aa / ctoc)))) {
                exitg1 = true;
              } else {
                k = 1;
              }
            } else {
              k = 1;
            }
          }
        }
        if (k > ilo) {
          a__1[1] = 0.0;
        }
        if (k == b_i + 1) {
          wr[b_i] = a__1[b_i + (b_i << 1)];
          wi[b_i] = 0.0;
        } else if (k == b_i) {
          int32_T i1;
          i = b_i << 1;
          d = a__1[i];
          absxk = a__1[b_i];
          i1 = b_i + i;
          ctoc = a__1[i1];
          d_st.site = &qc_emlrtRSI;
          wr[0] = xdlanv2(&a__1[0], &d, &absxk, &ctoc, &wi[0], &cfrom1, &mul,
                          &aa, &sn);
          wr[b_i] = cfrom1;
          wi[b_i] = mul;
          a__1[i] = d;
          a__1[b_i] = absxk;
          a__1[i1] = ctoc;
        }
      }
    }
    if (scalea) {
      c_st.site = &hd_emlrtRSI;
      xzlascl(cscale, anrm, wr);
      c_st.site = &id_emlrtRSI;
      xzlascl(cscale, anrm, wi);
    }
    V[0].re = wr[0];
    V[0].im = wi[0];
    V[1].re = wr[1];
    V[1].im = wi[1];
  }
}

/* End of code generation (eigStandard.c) */
