/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * filter.c
 *
 * Code generation for function 'filter'
 *
 */

/* Include files */
#include "filter.h"
#include "eml_int_forloop_overflow_check.h"
#include "pat_data.h"
#include "pat_types.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <stddef.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo mf_emlrtRSI = {
    271,      /* lineNo */
    "filter", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\datafun\\filter.m" /* pathName
                                                                           */
};

static emlrtRSInfo nf_emlrtRSI = {
    285,      /* lineNo */
    "filter", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\datafun\\filter.m" /* pathName
                                                                           */
};

static emlrtRSInfo of_emlrtRSI = {
    298,      /* lineNo */
    "filter", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\datafun\\filter.m" /* pathName
                                                                           */
};

static emlrtRSInfo pf_emlrtRSI = {
    306,      /* lineNo */
    "filter", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\datafun\\filter.m" /* pathName
                                                                           */
};

static emlrtRSInfo qf_emlrtRSI = {
    310,      /* lineNo */
    "filter", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\datafun\\filter.m" /* pathName
                                                                           */
};

static emlrtRSInfo rf_emlrtRSI = {
    324,      /* lineNo */
    "filter", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\datafun\\filter.m" /* pathName
                                                                           */
};

static emlrtRSInfo sf_emlrtRSI = {
    328,      /* lineNo */
    "filter", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\datafun\\filter.m" /* pathName
                                                                           */
};

static emlrtRTEInfo k_emlrtRTEI = {
    152,      /* lineNo */
    5,        /* colNo */
    "filter", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\datafun\\filter.m" /* pName
                                                                           */
};

static emlrtRTEInfo l_emlrtRTEI = {
    154,      /* lineNo */
    5,        /* colNo */
    "filter", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\datafun\\filter.m" /* pName
                                                                           */
};

static emlrtRTEInfo m_emlrtRTEI = {
    87,       /* lineNo */
    15,       /* colNo */
    "filter", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\datafun\\filter.m" /* pName
                                                                           */
};

/* Function Definitions */
void b_filter(const emlrtStack *sp, const emxArray_real_T *b,
              const real_T x[1799], real_T y[1799])
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack st;
  const real_T *b_data;
  int32_T j;
  int32_T k;
  int32_T nb;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_data = b->data;
  if (b->size[1] == 0) {
    emlrtErrorWithMessageIdR2018a(sp, &m_emlrtRTEI,
                                  "Coder:toolbox:filter_notVectorInputB",
                                  "Coder:toolbox:filter_notVectorInputB", 0);
  }
  nb = b->size[1];
  memset(&y[0], 0, 1799U * sizeof(real_T));
  if ((b->size[1] << 1) <= 1799) {
    st.site = &mf_emlrtRSI;
    if (b->size[1] > 2147483646) {
      b_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (k = 0; k < nb; k++) {
      if ((b_data[k] == 0.0) || (1799 - k <= 32)) {
        int32_T naxpy;
        int32_T scalarLB;
        scalarLB = ((((1799 - k) / 2) << 1) + k) + 1;
        naxpy = scalarLB - 2;
        for (j = k + 1; j <= naxpy; j += 2) {
          __m128d r;
          r = _mm_loadu_pd(&y[j - 1]);
          _mm_storeu_pd(
              &y[j - 1],
              _mm_add_pd(r, _mm_mul_pd(_mm_set1_pd(b_data[k]),
                                       _mm_loadu_pd(&x[(j - k) - 1]))));
        }
        for (j = scalarLB; j < 1800; j++) {
          y[j - 1] += b_data[k] * x[(j - k) - 1];
        }
      } else {
        st.site = &nf_emlrtRSI;
        if (1799 - k >= 1) {
          n_t = (ptrdiff_t)(1799 - k);
          incx_t = (ptrdiff_t)1;
          incy_t = (ptrdiff_t)1;
          daxpy(&n_t, (real_T *)&b_data[k], (real_T *)&x[0], &incx_t, &y[k],
                &incy_t);
        }
      }
    }
  } else {
    int32_T i;
    int32_T naxpy;
    int32_T nx_m_nb;
    int32_T y_tmp;
    if (b->size[1] < 1799) {
      nx_m_nb = 1799 - b->size[1];
    } else {
      nx_m_nb = 0;
    }
    st.site = &of_emlrtRSI;
    for (k = 0; k < nx_m_nb; k++) {
      if ((x[k] == 0.0) || (nb <= 32)) {
        int32_T scalarLB;
        st.site = &pf_emlrtRSI;
        if (nb > 2147483646) {
          b_st.site = &o_emlrtRSI;
          check_forloop_overflow_error(&b_st);
        }
        scalarLB = (nb / 2) << 1;
        naxpy = scalarLB - 2;
        for (j = 0; j <= naxpy; j += 2) {
          __m128d r;
          i = k + j;
          r = _mm_loadu_pd(&y[i]);
          _mm_storeu_pd(&y[i],
                        _mm_add_pd(r, _mm_mul_pd(_mm_set1_pd(x[k]),
                                                 _mm_loadu_pd(&b_data[j]))));
        }
        for (j = scalarLB; j < nb; j++) {
          y_tmp = k + j;
          y[y_tmp] += x[k] * b_data[j];
        }
      } else {
        st.site = &qf_emlrtRSI;
        n_t = (ptrdiff_t)nb;
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        daxpy(&n_t, (real_T *)&x[k], (real_T *)&b_data[0], &incx_t, &y[k],
              &incy_t);
      }
    }
    naxpy = 1799 - nx_m_nb;
    i = nx_m_nb + 1;
    for (k = i; k < 1800; k++) {
      real_T d;
      d = x[k - 1];
      if ((d == 0.0) || (naxpy <= 32)) {
        st.site = &rf_emlrtRSI;
        if (naxpy > 2147483646) {
          b_st.site = &o_emlrtRSI;
          check_forloop_overflow_error(&b_st);
        }
        for (j = 0; j < naxpy; j++) {
          y_tmp = (k + j) - 1;
          y[y_tmp] += d * b_data[j];
        }
      } else {
        st.site = &sf_emlrtRSI;
        n_t = (ptrdiff_t)naxpy;
        incx_t = (ptrdiff_t)1;
        incy_t = (ptrdiff_t)1;
        daxpy(&n_t, (real_T *)&x[k - 1], (real_T *)&b_data[0], &incx_t,
              &y[k - 1], &incy_t);
      }
      naxpy--;
    }
  }
}

int32_T filter(const emlrtStack *sp, real_T b[3], real_T a[3],
               const real_T x_data[], int32_T x_size, const real_T zi[2],
               real_T y_data[])
{
  int32_T j;
  int32_T k;
  int32_T y_size;
  if (muDoubleScalarIsInf(a[0]) || muDoubleScalarIsNaN(a[0])) {
    emlrtErrorWithMessageIdR2018a(
        sp, &k_emlrtRTEI,
        "Coder:MATLAB:filter_firstElementOfDenominatorFilterNotFinite",
        "Coder:MATLAB:filter_firstElementOfDenominatorFilterNotFinite", 0);
  } else if (a[0] == 0.0) {
    emlrtErrorWithMessageIdR2018a(
        sp, &l_emlrtRTEI,
        "Coder:MATLAB:filter_firstElementOfDenominatorFilterZero",
        "Coder:MATLAB:filter_firstElementOfDenominatorFilterZero", 0);
  } else if (a[0] != 1.0) {
    __m128d r;
    __m128d r1;
    r = _mm_loadu_pd(&b[0]);
    r1 = _mm_set1_pd(a[0]);
    _mm_storeu_pd(&b[0], _mm_div_pd(r, r1));
    b[2] /= a[0];
    r = _mm_loadu_pd(&a[1]);
    _mm_storeu_pd(&a[1], _mm_div_pd(r, r1));
    a[0] = 1.0;
  }
  y_size = x_size;
  y_data[0] = zi[0];
  y_data[1] = zi[1];
  memset(&y_data[2], 0, (uint32_T)(x_size - 2) * sizeof(real_T));
  for (k = 0; k < x_size; k++) {
    real_T as;
    int32_T a_tmp;
    int32_T naxpy;
    int32_T y_tmp;
    a_tmp = x_size - k;
    naxpy = muIntScalarMin_sint32(a_tmp, 3);
    for (j = 0; j < naxpy; j++) {
      y_tmp = k + j;
      y_data[y_tmp] += x_data[k] * b[j];
    }
    if (a_tmp - 1 < 2) {
      naxpy = a_tmp - 2;
    } else {
      naxpy = 1;
    }
    as = -y_data[k];
    for (j = 0; j <= naxpy; j++) {
      y_tmp = (k + j) + 1;
      y_data[y_tmp] += as * a[j + 1];
    }
  }
  return y_size;
}

/* End of code generation (filter.c) */
