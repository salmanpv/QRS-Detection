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
#include "introsort.h"
#include "pat_emxutil.h"
#include "pat_types.h"
#include "rt_nonfinite.h"
#include "cs.h"
#include "makeCXSparseMatrix.h"
#include "rt_nonfinite.h"
#include "solve_from_lu.h"
#include "solve_from_qr.h"
#include <emmintrin.h>
#include <math.h>
#include <string.h>

/* Function Declarations */
static int findEffectiveFilterLen(double coef[3], double effLen_data[]);

/* Function Definitions */
static int findEffectiveFilterLen(double coef[3], double effLen_data[])
{
  double varargin_1[3];
  double maxCoef;
  int effLen_size;
  int idx;
  int ii;
  int k;
  signed char ii_data;
  boolean_T x[3];
  boolean_T exitg1;
  varargin_1[0] = fabs(coef[0]);
  varargin_1[1] = fabs(coef[1]);
  varargin_1[2] = fabs(coef[2]);
  if (!rtIsNaN(varargin_1[0])) {
    idx = 1;
  } else {
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 4)) {
      if (!rtIsNaN(varargin_1[k - 1])) {
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
      double d;
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
      ii_data = (signed char)ii;
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

void filtfilt(const double ctf[3], const double varargin_1[3],
              const double varargin_2[1800], double y[1800])
{
  static const int cidxInt[4] = {1, 1, 2, 2};
  static const int offsets[4] = {0, 1, 2, 3};
  static const int ridxInt[4] = {1, 2, 2, 1};
  __m128d r;
  __m128d r1;
  cs_di *cxA;
  cs_din *N;
  cs_dis *S;
  emxArray_int32_T *y_colidx;
  emxArray_int32_T *y_rowidx;
  emxArray_real_T *y_d;
  double b_ytemp_data[1812];
  double ytemp_data[1812];
  double vals[4];
  double A[3];
  double B[3];
  double b_outBuff[2];
  double outBuff[2];
  double Letr;
  double tol;
  double val;
  double *y_d_data;
  int sortedIndices[4];
  int c;
  int cptr;
  int currRowIdx;
  int ridx;
  int *y_colidx_data;
  int *y_rowidx_data;
  signed char b_cidxInt[4];
  signed char b_ridxInt[4];
  B[0] = ctf[0];
  B[1] = ctf[1];
  B[2] = ctf[2];
  findEffectiveFilterLen(B, (double *)&val);
  B[0] = varargin_1[0];
  B[1] = varargin_1[1];
  B[2] = varargin_1[2];
  findEffectiveFilterLen(B, (double *)&tol);
  Letr = fmax(1.0, 3.0 * (fmax(val, tol) - 1.0));
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
  emxInit_real_T(&y_d, 1);
  emxInit_int32_T(&y_colidx);
  emxInit_int32_T(&y_rowidx);
  _mm_storeu_si128(
      (__m128i *)&sortedIndices[0],
      _mm_add_epi32(
          _mm_add_epi32(_mm_set1_epi32(0),
                        _mm_loadu_si128((const __m128i *)&offsets[0])),
          _mm_set1_epi32(1)));
  introsort(sortedIndices, cidxInt, ridxInt);
  currRowIdx = y_d->size[0];
  y_d->size[0] = 4;
  emxEnsureCapacity_real_T(y_d, currRowIdx);
  y_d_data = y_d->data;
  b_cidxInt[0] = (signed char)cidxInt[sortedIndices[0] - 1];
  b_ridxInt[0] = (signed char)ridxInt[sortedIndices[0] - 1];
  b_cidxInt[1] = (signed char)cidxInt[sortedIndices[1] - 1];
  b_ridxInt[1] = (signed char)ridxInt[sortedIndices[1] - 1];
  b_cidxInt[2] = (signed char)cidxInt[sortedIndices[2] - 1];
  b_ridxInt[2] = (signed char)ridxInt[sortedIndices[2] - 1];
  b_cidxInt[3] = (signed char)cidxInt[sortedIndices[3] - 1];
  b_ridxInt[3] = (signed char)ridxInt[sortedIndices[3] - 1];
  currRowIdx = y_colidx->size[0];
  y_colidx->size[0] = 3;
  emxEnsureCapacity_int32_T(y_colidx, currRowIdx);
  y_colidx_data = y_colidx->data;
  y_colidx_data[1] = 0;
  y_colidx_data[2] = 0;
  y_colidx_data[0] = 1;
  currRowIdx = y_rowidx->size[0];
  y_rowidx->size[0] = 4;
  emxEnsureCapacity_int32_T(y_rowidx, currRowIdx);
  y_rowidx_data = y_rowidx->data;
  y_rowidx_data[0] = 0;
  y_rowidx_data[1] = 0;
  y_rowidx_data[2] = 0;
  y_rowidx_data[3] = 0;
  cptr = 0;
  for (c = 0; c < 2; c++) {
    while ((cptr + 1 <= 4) && (b_cidxInt[cptr] == c + 1)) {
      y_rowidx_data[cptr] = b_ridxInt[cptr];
      cptr++;
    }
    y_colidx_data[c + 1] = cptr + 1;
  }
  y_d_data[0] = vals[sortedIndices[0] - 1];
  y_d_data[1] = vals[sortedIndices[1] - 1];
  y_d_data[2] = vals[sortedIndices[2] - 1];
  y_d_data[3] = vals[sortedIndices[3] - 1];
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
  cxA = makeCXSparseMatrix(y_colidx_data[2] - 1, 2, 2, &y_colidx_data[0],
                           &y_rowidx_data[0], &y_d_data[0]);
  S = cs_di_sqr(2, cxA, 0);
  N = cs_di_lu(cxA, S, 1);
  cs_di_spfree(cxA);
  if (N == NULL) {
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
  emxFree_int32_T(&y_rowidx);
  emxFree_int32_T(&y_colidx);
  emxFree_real_T(&y_d);
  val = 2.0 * varargin_2[0];
  tol = 2.0 * varargin_2[1799];
  cptr = (int)(Letr + 1.0) - 2;
  for (currRowIdx = 0; currRowIdx <= cptr; currRowIdx++) {
    ytemp_data[currRowIdx] =
        val - varargin_2[((int)(Letr + 1.0) - currRowIdx) - 1];
  }
  for (currRowIdx = 0; currRowIdx < 1800; currRowIdx++) {
    ytemp_data[(currRowIdx + (int)(Letr + 1.0)) - 1] = varargin_2[currRowIdx];
  }
  cptr = 1799 - (int)(1800.0 - Letr);
  for (currRowIdx = 0; currRowIdx <= cptr; currRowIdx++) {
    ytemp_data[(currRowIdx + (int)(Letr + 1.0)) + 1799] =
        tol - varargin_2[1798 - currRowIdx];
  }
  double b_A[3];
  double b_B[3];
  r = _mm_loadu_pd(&outBuff[0]);
  _mm_storeu_pd(&b_outBuff[0], _mm_mul_pd(r, _mm_set1_pd(ytemp_data[0])));
  b_B[0] = B[0];
  b_B[1] = B[1];
  b_B[2] = B[2];
  b_A[0] = A[0];
  b_A[1] = A[1];
  b_A[2] = A[2];
  ridx = filter(b_B, b_A, ytemp_data,
                ((int)(Letr + 1.0) - (int)(1800.0 - Letr)) + 3599, b_outBuff,
                b_ytemp_data);
  cptr = ridx - 1;
  for (currRowIdx = 0; currRowIdx <= cptr; currRowIdx++) {
    ytemp_data[currRowIdx] = b_ytemp_data[(ridx - currRowIdx) - 1];
  }
  if (ridx - 1 >= 0) {
    memcpy(&b_ytemp_data[0], &ytemp_data[0],
           (unsigned int)ridx * sizeof(double));
  }
  r = _mm_loadu_pd(&outBuff[0]);
  _mm_storeu_pd(&outBuff[0], _mm_mul_pd(r, _mm_set1_pd(b_ytemp_data[0])));
  cptr = ridx - 1;
  if (cptr >= 0) {
    memcpy(&ytemp_data[0], &b_ytemp_data[0],
           (unsigned int)(cptr + 1) * sizeof(double));
  }
  ridx = filter(B, A, ytemp_data, ridx, outBuff, b_ytemp_data);
  currRowIdx = (int)((double)ridx - Letr);
  for (cptr = 0; cptr < 1800; cptr++) {
    y[cptr] = b_ytemp_data[(currRowIdx - cptr) - 1];
  }
}

/* End of code generation (filtfilt.c) */
