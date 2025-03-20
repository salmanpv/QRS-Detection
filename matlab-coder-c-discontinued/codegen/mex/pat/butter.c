/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * butter.c
 *
 * Code generation for function 'butter'
 *
 */

/* Include files */
#include "butter.h"
#include "eig.h"
#include "mrdivide_helper.h"
#include "pat_data.h"
#include "rt_nonfinite.h"
#include "warning.h"
#include "mwmathutil.h"
#include <emmintrin.h>

/* Variable Definitions */
static emlrtRSInfo f_emlrtRSI = {
    20,       /* lineNo */
    "butter", /* fcnName */
    "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\butter.m" /* pathName
                                                                            */
};

static emlrtRSInfo g_emlrtRSI = {
    31,           /* lineNo */
    "butterImpl", /* fcnName */
    "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\butter.m" /* pathName
                                                                            */
};

static emlrtRSInfo h_emlrtRSI = {
    60,           /* lineNo */
    "butterImpl", /* fcnName */
    "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\butter.m" /* pathName
                                                                            */
};

static emlrtRSInfo i_emlrtRSI = {
    64,           /* lineNo */
    "butterImpl", /* fcnName */
    "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\butter.m" /* pathName
                                                                            */
};

static emlrtRSInfo j_emlrtRSI = {
    71,           /* lineNo */
    "butterImpl", /* fcnName */
    "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\butter.m" /* pathName
                                                                            */
};

static emlrtRSInfo k_emlrtRSI = {
    81,           /* lineNo */
    "butterImpl", /* fcnName */
    "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\butter.m" /* pathName
                                                                            */
};

static emlrtRSInfo l_emlrtRSI = {
    102,          /* lineNo */
    "butterImpl", /* fcnName */
    "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\butter.m" /* pathName
                                                                            */
};

static emlrtRSInfo m_emlrtRSI = {
    36,                          /* lineNo */
    "classicalIIRFiltersParser", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\+signal\\+internal\\+"
    "classicaliirfilters\\classicalIIRFiltersParser."
    "m" /* pathName */
};

static emlrtRSInfo p_emlrtRSI = {
    16,     /* lineNo */
    "poly", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\polyfun\\poly.m" /* pathName
                                                                         */
};

static emlrtRSInfo q_emlrtRSI = {
    20,         /* lineNo */
    "mldivide", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\ops\\mldivide.m" /* pathName
                                                                         */
};

static emlrtRSInfo r_emlrtRSI = {
    42,      /* lineNo */
    "mldiv", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\ops\\mldivide.m" /* pathName
                                                                         */
};

static emlrtRSInfo v_emlrtRSI = {
    63,      /* lineNo */
    "lp2bp", /* fcnName */
    "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\lp2bp.m" /* pathName
                                                                           */
};

static emlrtRSInfo w_emlrtRSI = {
    64,      /* lineNo */
    "lp2bp", /* fcnName */
    "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\lp2bp.m" /* pathName
                                                                           */
};

static emlrtRSInfo
    x_emlrtRSI =
        {
            166,        /* lineNo */
            "bilinear", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\bilinear.m" /* pathName
                                                                          */
};

static emlrtRSInfo
    y_emlrtRSI =
        {
            167,        /* lineNo */
            "bilinear", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\bilinear.m" /* pathName
                                                                          */
};

static emlrtRSInfo
    ab_emlrtRSI =
        {
            168,        /* lineNo */
            "bilinear", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\bilinear.m" /* pathName
                                                                          */
};

static emlrtRSInfo
    bb_emlrtRSI =
        {
            169,        /* lineNo */
            "bilinear", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\bilinear.m" /* pathName
                                                                          */
};

static emlrtRSInfo cb_emlrtRSI = {
    20,                /* lineNo */
    "mrdivide_helper", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\mrdivide_"
    "helper.m" /* pathName */
};

static emlrtRTEInfo c_emlrtRTEI = {
    138,                         /* lineNo */
    1,                           /* colNo */
    "classicalIIRFiltersParser", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\+signal\\+internal\\+"
    "classicaliirfilters\\classicalIIRFiltersParser."
    "m" /* pName */
};

static emlrtRTEInfo d_emlrtRTEI = {
    13,     /* lineNo */
    9,      /* colNo */
    "sqrt", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m" /* pName
                                                                       */
};

static emlrtRTEInfo e_emlrtRTEI = {
    14,                 /* lineNo */
    37,                 /* colNo */
    "validatepositive", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validatepositive.m" /* pName */
};

static emlrtRTEInfo g_emlrtRTEI = {
    40,            /* lineNo */
    9,             /* colNo */
    "vector_poly", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\polyfun\\poly.m" /* pName
                                                                         */
};

/* Function Definitions */
void butter(const emlrtStack *sp, const real_T Wn[2], real_T varargout_1[3],
            real_T varargout_2[3])
{
  __m128d b_r1;
  __m128d r;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack st;
  creal_T c[3];
  creal_T b_p[2];
  creal_T x[2];
  real_T ad[4];
  real_T t1[4];
  real_T t2[4];
  real_T u[2];
  real_T unusedExpr[2];
  real_T Wn1;
  real_T a21;
  real_T a22;
  real_T a22_tmp;
  real_T b_x_re;
  real_T x_re;
  real_T zWn_im;
  real_T zWn_re;
  int32_T r1;
  int32_T r2;
  boolean_T varargin_1[2];
  boolean_T exitg1;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &f_emlrtRSI;
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
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  b_st.site = &g_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  d_st.site = &n_emlrtRSI;
  p = true;
  r1 = 0;
  exitg1 = false;
  while ((!exitg1) && (r1 < 2)) {
    if (!(Wn[r1] <= 0.0)) {
      r1++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &e_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedPositive",
        "MATLAB:butter:expectedPositive", 3, 4, 2, "Wn");
  }
  d_st.site = &n_emlrtRSI;
  p = true;
  r1 = 0;
  exitg1 = false;
  while ((!exitg1) && (r1 < 2)) {
    if ((!muDoubleScalarIsInf(Wn[r1])) && (!muDoubleScalarIsNaN(Wn[r1]))) {
      r1++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &f_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:butter:expectedFinite", 3, 4, 2, "Wn");
  }
  varargin_1[0] = (Wn[0] >= 1.0);
  varargin_1[1] = (Wn[1] >= 1.0);
  p = false;
  r1 = 0;
  exitg1 = false;
  while ((!exitg1) && (r1 < 2)) {
    if (varargin_1[r1]) {
      p = true;
      exitg1 = true;
    } else {
      r1++;
    }
  }
  if (p) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &c_emlrtRTEI,
        "signal:classicaliirfilters:freqMustBeWithinUnitInterval",
        "signal:classicaliirfilters:freqMustBeWithinUnitInterval", 0);
  }
  u[0] = 4.0 * muDoubleScalarTan(3.1415926535897931 * Wn[0] / 2.0);
  u[1] = 4.0 * muDoubleScalarTan(3.1415926535897931 * Wn[1] / 2.0);
  zWn_im = u[1] - u[0];
  b_st.site = &h_emlrtRSI;
  Wn1 = u[0] * u[1];
  if (Wn1 < 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &d_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
        "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
  }
  Wn1 = muDoubleScalarSqrt(Wn1);
  b_st.site = &i_emlrtRSI;
  c_st.site = &v_emlrtRSI;
  d_st.site = &n_emlrtRSI;
  if (muDoubleScalarIsInf(Wn1) || muDoubleScalarIsNaN(Wn1)) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &f_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:lp2bp:expectedFinite", 3, 4, 19, "input number 5, Wo,");
  }
  c_st.site = &w_emlrtRSI;
  d_st.site = &n_emlrtRSI;
  if (muDoubleScalarIsInf(zWn_im) || muDoubleScalarIsNaN(zWn_im)) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &f_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:lp2bp:expectedFinite", 3, 4, 19, "input number 6, Bw,");
  }
  b_st.site = &j_emlrtRSI;
  t2[1] = 0.0;
  t2[2] = 0.0;
  ad[0] = Wn1 * (-1.0 / (Wn1 / zWn_im)) * 0.5 / 2.0;
  ad[2] = Wn1 * 0.5 / 2.0;
  t2[0] = 1.0;
  ad[1] = -Wn1 * 0.5 / 2.0;
  t2[3] = 1.0;
  ad[3] = Wn1 * 0.0 * 0.5 / 2.0;
  r = _mm_loadu_pd(&t2[0]);
  b_r1 = _mm_loadu_pd(&ad[0]);
  _mm_storeu_pd(&t1[0], _mm_add_pd(r, b_r1));
  _mm_storeu_pd(&t2[0], _mm_sub_pd(r, b_r1));
  r = _mm_loadu_pd(&t2[2]);
  b_r1 = _mm_loadu_pd(&ad[2]);
  _mm_storeu_pd(&t1[2], _mm_add_pd(r, b_r1));
  _mm_storeu_pd(&t2[2], _mm_sub_pd(r, b_r1));
  c_st.site = &x_emlrtRSI;
  d_st.site = &q_emlrtRSI;
  e_st.site = &r_emlrtRSI;
  f_st.site = &s_emlrtRSI;
  zWn_im = muDoubleScalarAbs(t2[1]);
  zWn_re = muDoubleScalarAbs(t2[0]);
  if (zWn_im > zWn_re) {
    r1 = 1;
    r2 = 0;
  } else {
    r1 = 0;
    r2 = 1;
  }
  a21 = t2[r2] / t2[r1];
  a22_tmp = t2[r1 + 2];
  a22 = t2[r2 + 2] - a21 * a22_tmp;
  if ((a22 == 0.0) || (t2[r1] == 0.0)) {
    g_st.site = &t_emlrtRSI;
    h_st.site = &u_emlrtRSI;
    warning(&h_st);
  }
  x_re = (t1[r2] - t1[r1] * a21) / a22;
  ad[1] = x_re;
  ad[0] = (t1[r1] - x_re * a22_tmp) / t2[r1];
  b_x_re = t1[r1 + 2];
  x_re = (t1[r2 + 2] - b_x_re * a21) / a22;
  ad[3] = x_re;
  ad[2] = (b_x_re - x_re * a22_tmp) / t2[r1];
  c_st.site = &y_emlrtRSI;
  d_st.site = &q_emlrtRSI;
  e_st.site = &r_emlrtRSI;
  f_st.site = &s_emlrtRSI;
  if (zWn_im > zWn_re) {
    r1 = 1;
    r2 = 0;
  } else {
    r1 = 0;
    r2 = 1;
  }
  if ((t2[r2 + 2] - t2[r2] / t2[r1] * t2[r1 + 2] == 0.0) || (t2[r1] == 0.0)) {
    g_st.site = &t_emlrtRSI;
    h_st.site = &u_emlrtRSI;
    warning(&h_st);
  }
  c_st.site = &ab_emlrtRSI;
  u[0] = 0.70710678118654757;
  u[1] = 0.0;
  d_st.site = &cb_emlrtRSI;
  mrdiv(&d_st, u, t2, unusedExpr);
  c_st.site = &bb_emlrtRSI;
  u[0] = 1.0;
  u[1] = 0.0;
  d_st.site = &cb_emlrtRSI;
  mrdiv(&d_st, u, t2, unusedExpr);
  b_st.site = &k_emlrtRSI;
  eig(&b_st, ad, b_p);
  zWn_im = 2.0 * muDoubleScalarAtan2(Wn1, 4.0);
  if (zWn_im * 0.0 == 0.0) {
    zWn_re = muDoubleScalarCos(zWn_im);
    zWn_im = muDoubleScalarSin(zWn_im);
  } else if (zWn_im == 0.0) {
    zWn_re = rtNaN;
    zWn_im = 0.0;
  } else {
    zWn_re = rtNaN;
    zWn_im = rtNaN;
  }
  x[0].re = zWn_re - b_p[0].re;
  x[0].im = zWn_im - b_p[0].im;
  x[1].re = zWn_re - b_p[1].re;
  x[1].im = zWn_im - b_p[1].im;
  b_x_re = x[0].re * x[1].re - x[0].im * x[1].im;
  a22 = x[0].re * x[1].im + x[0].im * x[1].re;
  x_re = (zWn_re - 1.0) * (zWn_re - -1.0) - zWn_im * zWn_im;
  a22_tmp = (zWn_re - 1.0) * zWn_im + zWn_im * (zWn_re - -1.0);
  if (a22_tmp == 0.0) {
    if (a22 == 0.0) {
      b_x_re /= x_re;
    } else if (b_x_re == 0.0) {
      b_x_re = 0.0;
    } else {
      b_x_re /= x_re;
    }
  } else if (x_re == 0.0) {
    if (b_x_re == 0.0) {
      b_x_re = a22 / a22_tmp;
    } else if (a22 == 0.0) {
      b_x_re = 0.0;
    } else {
      b_x_re = a22 / a22_tmp;
    }
  } else {
    zWn_im = muDoubleScalarAbs(x_re);
    a21 = muDoubleScalarAbs(a22_tmp);
    if (zWn_im > a21) {
      zWn_im = a22_tmp / x_re;
      b_x_re = (b_x_re + zWn_im * a22) / (x_re + zWn_im * a22_tmp);
    } else if (a21 == zWn_im) {
      if (x_re > 0.0) {
        zWn_re = 0.5;
      } else {
        zWn_re = -0.5;
      }
      if (a22_tmp > 0.0) {
        Wn1 = 0.5;
      } else {
        Wn1 = -0.5;
      }
      b_x_re = (b_x_re * zWn_re + a22 * Wn1) / zWn_im;
    } else {
      zWn_im = x_re / a22_tmp;
      b_x_re = (zWn_im * b_x_re + a22) / (a22_tmp + zWn_im * x_re);
    }
  }
  b_st.site = &l_emlrtRSI;
  c_st.site = &p_emlrtRSI;
  if (muDoubleScalarIsInf(b_p[0].re) || muDoubleScalarIsInf(b_p[0].im) ||
      (muDoubleScalarIsNaN(b_p[0].re) || muDoubleScalarIsNaN(b_p[0].im))) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &g_emlrtRTEI, "Coder:toolbox:nonfiniteValuesNotSupported",
        "Coder:toolbox:nonfiniteValuesNotSupported", 0);
  }
  if (muDoubleScalarIsInf(b_p[1].re) || muDoubleScalarIsInf(b_p[1].im) ||
      (muDoubleScalarIsNaN(b_p[1].re) || muDoubleScalarIsNaN(b_p[1].im))) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &g_emlrtRTEI, "Coder:toolbox:nonfiniteValuesNotSupported",
        "Coder:toolbox:nonfiniteValuesNotSupported", 0);
  }
  c[0].re = 1.0;
  c[0].im = 0.0;
  for (r2 = 0; r2 < 2; r2++) {
    zWn_im = b_p[r2].re;
    zWn_re = b_p[r2].im;
    a21 = c[r2].im;
    a22_tmp = c[r2].re;
    c[r2 + 1].re = -zWn_im * a22_tmp - -zWn_re * a21;
    c[r2 + 1].im = -zWn_im * a21 + -zWn_re * a22_tmp;
    for (r1 = r2 + 1; r1 >= 2; r1--) {
      c[1].re -= zWn_im * c[0].re - zWn_re * c[0].im;
      c[1].im -= zWn_im * c[0].im + zWn_re * c[0].re;
    }
  }
  varargout_2[0] = c[0].re;
  varargout_1[0] = b_x_re;
  varargout_2[1] = c[1].re;
  varargout_1[1] = b_x_re * 0.0;
  varargout_2[2] = c[2].re;
  varargout_1[2] = -b_x_re;
}

/* End of code generation (butter.c) */
