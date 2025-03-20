/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * filtfilt.c
 *
 * Code generation for function 'filtfilt'
 *
 */

/* Include files */
#include "filtfilt.h"
#include "filter.h"
#include "indexShapeCheck.h"
#include "introsort.h"
#include "pat_data.h"
#include "pat_emxutil.h"
#include "pat_types.h"
#include "rt_nonfinite.h"
#include "warning.h"
#include "cs.h"
#include "makeCXSparseMatrix.h"
#include "mwmathutil.h"
#include "solve_from_lu.h"
#include "solve_from_qr.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo
    je_emlrtRSI =
        {
            123,        /* lineNo */
            "filtfilt", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\filtfilt.m" /* pathName
                                                                          */
};

static emlrtRSInfo
    ke_emlrtRSI =
        {
            150,        /* lineNo */
            "filtfilt", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\filtfilt.m" /* pathName
                                                                          */
};

static emlrtRSInfo
    le_emlrtRSI =
        {
            505,              /* lineNo */
            "filtfiltParser", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\filtfilt.m" /* pathName
                                                                          */
};

static emlrtRSInfo
    me_emlrtRSI =
        {
            579,                     /* lineNo */
            "validateAndCastInputs", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\filtfilt.m" /* pathName
                                                                          */
};

static emlrtRSInfo
    ne_emlrtRSI =
        {
            582,                     /* lineNo */
            "validateAndCastInputs", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\filtfilt.m" /* pathName
                                                                          */
};

static emlrtRSInfo
    oe_emlrtRSI =
        {
            584,                     /* lineNo */
            "validateAndCastInputs", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\filtfilt.m" /* pathName
                                                                          */
};

static emlrtRSInfo
    pe_emlrtRSI =
        {
            174,            /* lineNo */
            "filtfiltImpl", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\filtfilt.m" /* pathName
                                                                          */
};

static emlrtRSInfo
    qe_emlrtRSI =
        {
            179,            /* lineNo */
            "filtfiltImpl", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\filtfilt.m" /* pathName
                                                                          */
};

static emlrtRSInfo
    re_emlrtRSI =
        {
            261,                             /* lineNo */
            "getCoeffsAndInitialConditions", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\filtfilt.m" /* pathName
                                                                          */
};

static emlrtRSInfo se_emlrtRSI = {
    13,       /* lineNo */
    "sparse", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\sparfun\\sparse.m" /* pathName
                                                                           */
};

static emlrtRSInfo te_emlrtRSI = {
    219,             /* lineNo */
    "sparse/sparse", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" /* pathName */
};

static emlrtRSInfo ve_emlrtRSI = {
    1450,              /* lineNo */
    "sparse/mldivide", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" /* pathName */
};

static emlrtRSInfo we_emlrtRSI =
    {
        160,                         /* lineNo */
        "CXSparseAPI/iteratedSolve", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\CXSparseAPI.m" /* pathName */
};

static emlrtRSInfo ye_emlrtRSI =
    {
        312,                      /* lineNo */
        "CXSparseAPI/iteratedLU", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\CXSparseAPI.m" /* pathName */
};

static emlrtRSInfo
    df_emlrtRSI =
        {
            309,            /* lineNo */
            "ffOneChanCat", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\filtfilt.m" /* pathName
                                                                          */
};

static emlrtRSInfo
    ef_emlrtRSI =
        {
            308,            /* lineNo */
            "ffOneChanCat", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\filtfilt.m" /* pathName
                                                                          */
};

static emlrtRSInfo
    ff_emlrtRSI =
        {
            307,            /* lineNo */
            "ffOneChanCat", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\filtfilt.m" /* pathName
                                                                          */
};

static emlrtECInfo
    emlrtECI =
        {
            -1,             /* nDims */
            304,            /* lineNo */
            5,              /* colNo */
            "ffOneChanCat", /* fName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\filtfilt.m" /* pName
                                                                          */
};

static emlrtBCInfo d_emlrtBCI =
    {
        -1,             /* iFirst */
        -1,             /* iLast */
        308,            /* lineNo */
        19,             /* colNo */
        "",             /* aName */
        "ffOneChanCat", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\filtfilt.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtBCInfo e_emlrtBCI =
    {
        -1,             /* iFirst */
        -1,             /* iLast */
        312,            /* lineNo */
        21,             /* colNo */
        "",             /* aName */
        "ffOneChanCat", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\filtfilt.m", /* pName
                                                                       */
        0 /* checkKind */
};

static emlrtECInfo
    b_emlrtECI =
        {
            -1,             /* nDims */
            312,            /* lineNo */
            5,              /* colNo */
            "ffOneChanCat", /* fName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\filtfilt.m" /* pName
                                                                          */
};

static emlrtRTEInfo
    j_emlrtRTEI =
        {
            159,            /* lineNo */
            1,              /* colNo */
            "filtfiltImpl", /* fName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\filtfilt.m" /* pName
                                                                          */
};

static emlrtRTEInfo q_emlrtRTEI = {
    13,       /* lineNo */
    1,        /* colNo */
    "sparse", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\sparfun\\sparse.m" /* pName
                                                                           */
};

static emlrtRTEInfo
    r_emlrtRTEI =
        {
            261,        /* lineNo */
            19,         /* colNo */
            "filtfilt", /* fName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\filtfilt.m" /* pName
                                                                          */
};

/* Function Declarations */
static int32_T findEffectiveFilterLen(real_T coef[3], real_T effLen_data[]);

/* Function Definitions */
static int32_T findEffectiveFilterLen(real_T coef[3], real_T effLen_data[])
{
  real_T varargin_1[3];
  real_T maxCoef;
  int32_T effLen_size;
  int32_T idx;
  int32_T ii;
  int32_T k;
  int8_T ii_data;
  boolean_T x[3];
  boolean_T exitg1;
  varargin_1[0] = muDoubleScalarAbs(coef[0]);
  varargin_1[1] = muDoubleScalarAbs(coef[1]);
  varargin_1[2] = muDoubleScalarAbs(coef[2]);
  if (!muDoubleScalarIsNaN(varargin_1[0])) {
    idx = 1;
  } else {
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 4)) {
      if (!muDoubleScalarIsNaN(varargin_1[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  if (idx == 0) {
    maxCoef = varargin_1[0];
  } else {
    maxCoef = varargin_1[idx - 1];
    ii = idx + 1;
    for (k = ii; k < 4; k++) {
      real_T d;
      d = varargin_1[k - 1];
      if (maxCoef < d) {
        maxCoef = d;
      }
    }
  }
  if (maxCoef != 0.0) {
    __m128d r;
    r = _mm_loadu_pd(&coef[0]);
    _mm_storeu_pd(&coef[0], _mm_div_pd(r, _mm_set1_pd(maxCoef)));
    coef[2] /= maxCoef;
  }
  x[0] = (coef[0] != 0.0);
  x[1] = (coef[1] != 0.0);
  x[2] = (coef[2] != 0.0);
  idx = 0;
  effLen_size = 1;
  ii = 3;
  exitg1 = false;
  while ((!exitg1) && (ii > 0)) {
    if (x[ii - 1]) {
      idx = 1;
      ii_data = (int8_T)ii;
      exitg1 = true;
    } else {
      ii--;
    }
  }
  if (idx == 0) {
    effLen_size = 0;
  }
  if (effLen_size - 1 >= 0) {
    effLen_data[0] = ii_data;
  }
  if (effLen_size == 0) {
    effLen_size = 1;
    effLen_data[0] = 0.0;
  }
  return effLen_size;
}

void filtfilt(const emlrtStack *sp, const real_T ctf[3],
              const real_T varargin_1[3], const real_T varargin_2[1800],
              real_T y[1800])
{
  static const int32_T offsets[4] = {0, 1, 2, 3};
  static const int8_T b_cidxInt[4] = {1, 1, 2, 2};
  static const int8_T b_ridxInt[4] = {1, 2, 2, 1};
  __m128d r;
  __m128d r1;
  cs_di *cxA;
  cs_din *N;
  cs_dis *S;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  emxArray_int32_T *y_colidx;
  emxArray_int32_T *y_rowidx;
  emxArray_real_T *y_d;
  real_T b_ytemp_data[1812];
  real_T ytemp_data[1812];
  real_T vals[4];
  real_T A[3];
  real_T B[3];
  real_T b_A[3];
  real_T b_B[3];
  real_T b_outBuff[2];
  real_T outBuff[2];
  real_T Letr;
  real_T tol;
  real_T val;
  real_T *y_d_data;
  int32_T sortedIndices[4];
  int32_T c;
  int32_T cptr;
  int32_T currRowIdx;
  int32_T ridx;
  int32_T *y_colidx_data;
  int32_T *y_rowidx_data;
  int8_T cidxInt[4];
  int8_T ridxInt[4];
  boolean_T exitg1;
  boolean_T p;
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
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  st.site = &je_emlrtRSI;
  b_st.site = &le_emlrtRSI;
  c_st.site = &me_emlrtRSI;
  d_st.site = &n_emlrtRSI;
  p = true;
  cptr = 0;
  exitg1 = false;
  while ((!exitg1) && (cptr < 1800)) {
    if ((!muDoubleScalarIsInf(varargin_2[cptr])) &&
        (!muDoubleScalarIsNaN(varargin_2[cptr]))) {
      cptr++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &f_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:filtfilt:expectedFinite", 3, 4, 12, "input signal");
  }
  c_st.site = &ne_emlrtRSI;
  d_st.site = &n_emlrtRSI;
  p = true;
  cptr = 0;
  exitg1 = false;
  while ((!exitg1) && (cptr < 3)) {
    if ((!muDoubleScalarIsInf(ctf[cptr])) &&
        (!muDoubleScalarIsNaN(ctf[cptr]))) {
      cptr++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &f_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:filtfilt:expectedFinite", 3, 4, 36,
        "input number 1, filter coefficients,");
  }
  c_st.site = &oe_emlrtRSI;
  d_st.site = &n_emlrtRSI;
  p = true;
  cptr = 0;
  exitg1 = false;
  while ((!exitg1) && (cptr < 3)) {
    if ((!muDoubleScalarIsInf(varargin_1[cptr])) &&
        (!muDoubleScalarIsNaN(varargin_1[cptr]))) {
      cptr++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &f_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:filtfilt:expectedFinite", 3, 4, 36,
        "input number 2, filter coefficients,");
  }
  st.site = &ke_emlrtRSI;
  if (varargin_1[0] == 0.0) {
    emlrtErrorWithMessageIdR2018a(&st, &j_emlrtRTEI,
                                  "signal:filtfilt:ZeroA0Coeffs",
                                  "signal:filtfilt:ZeroA0Coeffs", 0);
  }
  b_st.site = &pe_emlrtRSI;
  B[0] = ctf[0];
  B[1] = ctf[1];
  B[2] = ctf[2];
  findEffectiveFilterLen(B, (real_T *)&val);
  B[0] = varargin_1[0];
  B[1] = varargin_1[1];
  B[2] = varargin_1[2];
  findEffectiveFilterLen(B, (real_T *)&tol);
  Letr = muDoubleScalarMax(1.0, 3.0 * (muDoubleScalarMax(val, tol) - 1.0));
  r = _mm_set1_pd(varargin_1[0]);
  _mm_storeu_pd(&B[0], _mm_div_pd(_mm_loadu_pd(&ctf[0]), r));
  _mm_storeu_pd(&A[0], _mm_div_pd(_mm_loadu_pd(&varargin_1[0]), r));
  B[2] = ctf[2] / varargin_1[0];
  A[2] = varargin_1[2] / varargin_1[0];
  vals[0] = A[1] + 1.0;
  vals[1] = A[2];
  vals[2] = 1.0;
  vals[3] = -1.0;
  r = _mm_loadu_pd(&A[1]);
  r1 = _mm_loadu_pd(&B[1]);
  _mm_storeu_pd(&outBuff[0], _mm_sub_pd(r1, _mm_mul_pd(_mm_set1_pd(B[0]), r)));
  c_st.site = &re_emlrtRSI;
  d_st.site = &se_emlrtRSI;
  emxInit_real_T(&d_st, &y_d, 1, &r_emlrtRTEI);
  emxInit_int32_T(&d_st, &y_colidx, &r_emlrtRTEI);
  emxInit_int32_T(&d_st, &y_rowidx, &r_emlrtRTEI);
  _mm_storeu_si128(
      (__m128i *)&sortedIndices[0],
      _mm_add_epi32(
          _mm_add_epi32(_mm_set1_epi32(0),
                        _mm_loadu_si128((const __m128i *)&offsets[0])),
          _mm_set1_epi32(1)));
  introsort(sortedIndices);
  c = y_d->size[0];
  y_d->size[0] = 4;
  emxEnsureCapacity_real_T(&d_st, y_d, c, &q_emlrtRTEI);
  y_d_data = y_d->data;
  cidxInt[0] = b_cidxInt[sortedIndices[0] - 1];
  ridxInt[0] = b_ridxInt[sortedIndices[0] - 1];
  cidxInt[1] = b_cidxInt[sortedIndices[1] - 1];
  ridxInt[1] = b_ridxInt[sortedIndices[1] - 1];
  cidxInt[2] = b_cidxInt[sortedIndices[2] - 1];
  ridxInt[2] = b_ridxInt[sortedIndices[2] - 1];
  cidxInt[3] = b_cidxInt[sortedIndices[3] - 1];
  ridxInt[3] = b_ridxInt[sortedIndices[3] - 1];
  c = y_colidx->size[0];
  y_colidx->size[0] = 3;
  emxEnsureCapacity_int32_T(&d_st, y_colidx, c, &q_emlrtRTEI);
  y_colidx_data = y_colidx->data;
  y_colidx_data[1] = 0;
  y_colidx_data[2] = 0;
  y_colidx_data[0] = 1;
  c = y_rowidx->size[0];
  y_rowidx->size[0] = 4;
  emxEnsureCapacity_int32_T(&d_st, y_rowidx, c, &q_emlrtRTEI);
  y_rowidx_data = y_rowidx->data;
  y_rowidx_data[0] = 0;
  y_rowidx_data[1] = 0;
  y_rowidx_data[2] = 0;
  y_rowidx_data[3] = 0;
  cptr = 0;
  for (c = 0; c < 2; c++) {
    while ((cptr + 1 <= 4) && (cidxInt[cptr] == c + 1)) {
      y_rowidx_data[cptr] = ridxInt[cptr];
      cptr++;
    }
    y_colidx_data[c + 1] = cptr + 1;
  }
  y_d_data[0] = vals[sortedIndices[0] - 1];
  y_d_data[1] = vals[sortedIndices[1] - 1];
  y_d_data[2] = vals[sortedIndices[2] - 1];
  y_d_data[3] = vals[sortedIndices[3] - 1];
  e_st.site = &te_emlrtRSI;
  cptr = 1;
  for (c = 0; c < 2; c++) {
    ridx = y_colidx_data[c];
    y_colidx_data[c] = cptr;
    while (ridx < y_colidx_data[c + 1]) {
      val = 0.0;
      currRowIdx = y_rowidx_data[ridx - 1];
      while ((ridx < y_colidx_data[c + 1]) &&
             (y_rowidx_data[ridx - 1] == currRowIdx)) {
        val += y_d_data[ridx - 1];
        ridx++;
      }
      if (val != 0.0) {
        y_d_data[cptr - 1] = val;
        y_rowidx_data[cptr - 1] = currRowIdx;
        cptr++;
      }
    }
  }
  y_colidx_data[2] = cptr;
  c_st.site = &re_emlrtRSI;
  d_st.site = &ve_emlrtRSI;
  e_st.site = &we_emlrtRSI;
  cxA = makeCXSparseMatrix(y_colidx_data[2] - 1, 2, 2, &y_colidx_data[0],
                           &y_rowidx_data[0], &y_d_data[0]);
  S = cs_di_sqr(2, cxA, 0);
  N = cs_di_lu(cxA, S, 1);
  cs_di_spfree(cxA);
  if (N == NULL) {
    f_st.site = &ye_emlrtRSI;
    warning(&f_st);
    cs_di_sfree(S);
    cs_di_nfree(N);
    cxA = makeCXSparseMatrix(y_colidx_data[2] - 1, 2, 2, &y_colidx_data[0],
                             &y_rowidx_data[0], &y_d_data[0]);
    S = cs_di_sqr(2, cxA, 1);
    N = cs_di_qr(cxA, S);
    cs_di_spfree(cxA);
    qr_rank_di(N, &tol);
    solve_from_qr_di(N, S, (double *)&outBuff[0], 2, 2);
    cs_di_sfree(S);
    cs_di_nfree(N);
  } else {
    solve_from_lu_di(N, S, (double *)&outBuff[0], 2);
    cs_di_sfree(S);
    cs_di_nfree(N);
  }
  emxFree_int32_T(&e_st, &y_rowidx);
  emxFree_int32_T(&e_st, &y_colidx);
  emxFree_real_T(&e_st, &y_d);
  b_st.site = &qe_emlrtRSI;
  val = 2.0 * varargin_2[0];
  tol = 2.0 * varargin_2[1799];
  cptr = ((int32_T)(Letr + 1.0) - (int32_T)(1800.0 - Letr)) + 3599;
  ridx = (int32_T)(Letr + 1.0) - 2;
  for (c = 0; c <= ridx; c++) {
    b_ytemp_data[c] = val - varargin_2[((int32_T)(Letr + 1.0) - c) - 1];
  }
  for (c = 0; c < 1800; c++) {
    b_ytemp_data[(c + (int32_T)(Letr + 1.0)) - 1] = varargin_2[c];
  }
  ridx = 1799 - (int32_T)(1800.0 - Letr);
  for (c = 0; c <= ridx; c++) {
    b_ytemp_data[(c + (int32_T)(Letr + 1.0)) + 1799] =
        tol - varargin_2[1798 - c];
  }
  c = (int32_T)(2.0 * Letr + 1800.0);
  if (c != cptr) {
    emlrtSubAssignSizeCheck1dR2017a(c, cptr, &emlrtECI, &b_st);
  }
  r = _mm_loadu_pd(&outBuff[0]);
  _mm_storeu_pd(&b_outBuff[0], _mm_mul_pd(r, _mm_set1_pd(b_ytemp_data[0])));
  b_B[0] = B[0];
  b_B[1] = B[1];
  b_B[2] = B[2];
  b_A[0] = A[0];
  b_A[1] = A[1];
  b_A[2] = A[2];
  c_st.site = &ff_emlrtRSI;
  currRowIdx =
      filter(&c_st, b_B, b_A, b_ytemp_data, cptr, b_outBuff, ytemp_data);
  if (currRowIdx < 1) {
    emlrtDynamicBoundsCheckR2012b(currRowIdx, 1, currRowIdx, &d_emlrtBCI,
                                  &b_st);
  }
  c_st.site = &ef_emlrtRSI;
  indexShapeCheck();
  cptr = currRowIdx - 1;
  for (c = 0; c <= cptr; c++) {
    b_ytemp_data[c] = ytemp_data[(currRowIdx - c) - 1];
  }
  if (currRowIdx - 1 >= 0) {
    memcpy(&ytemp_data[0], &b_ytemp_data[0],
           (uint32_T)currRowIdx * sizeof(real_T));
  }
  r = _mm_loadu_pd(&outBuff[0]);
  _mm_storeu_pd(&outBuff[0], _mm_mul_pd(r, _mm_set1_pd(ytemp_data[0])));
  ridx = currRowIdx - 1;
  if (ridx >= 0) {
    memcpy(&b_ytemp_data[0], &ytemp_data[0],
           (uint32_T)(ridx + 1) * sizeof(real_T));
  }
  c_st.site = &df_emlrtRSI;
  currRowIdx =
      filter(&c_st, B, A, b_ytemp_data, currRowIdx, outBuff, ytemp_data);
  c = (int32_T)((real_T)currRowIdx - Letr);
  if ((c < 1) || (c > currRowIdx)) {
    emlrtDynamicBoundsCheckR2012b(c, 1, currRowIdx, &e_emlrtBCI, &b_st);
  }
  cptr = (c - (int32_T)(Letr + 1.0)) + 1;
  if (cptr != 1800) {
    emlrtSubAssignSizeCheck1dR2017a(1800, cptr, &b_emlrtECI, &b_st);
  }
  for (cptr = 0; cptr < 1800; cptr++) {
    y[cptr] = ytemp_data[(c - cptr) - 1];
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (filtfilt.c) */
