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
#include "pat_types.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"
#include <emmintrin.h>
#include <string.h>

/* Function Definitions */
void b_filter(const emxArray_real_T *b, const double x[1799], double y[1799])
{
  const double *b_data;
  int j;
  int k;
  int nb;
  b_data = b->data;
  nb = b->size[1];
  memset(&y[0], 0, 1799U * sizeof(double));
  if ((b->size[1] << 1) <= 1799) {
    for (k = 0; k < nb; k++) {
      int naxpy;
      int scalarLB;
      int vectorUB;
      naxpy = k + 1;
      scalarLB = ((((1799 - k) / 2) << 1) + k) + 1;
      vectorUB = scalarLB - 2;
      for (j = naxpy; j <= vectorUB; j += 2) {
        __m128d r;
        r = _mm_loadu_pd(&y[j - 1]);
        _mm_storeu_pd(&y[j - 1],
                      _mm_add_pd(r, _mm_mul_pd(_mm_set1_pd(b_data[k]),
                                               _mm_loadu_pd(&x[(j - k) - 1]))));
      }
      for (j = scalarLB; j < 1800; j++) {
        y[j - 1] += b_data[k] * x[(j - k) - 1];
      }
    }
  } else {
    int i;
    int naxpy;
    int nx_m_nb;
    int vectorUB;
    if (b->size[1] < 1799) {
      nx_m_nb = 1799 - b->size[1];
    } else {
      nx_m_nb = 0;
    }
    for (k = 0; k < nx_m_nb; k++) {
      int scalarLB;
      scalarLB = (nb / 2) << 1;
      vectorUB = scalarLB - 2;
      for (j = 0; j <= vectorUB; j += 2) {
        __m128d r;
        i = k + j;
        r = _mm_loadu_pd(&y[i]);
        _mm_storeu_pd(&y[i],
                      _mm_add_pd(r, _mm_mul_pd(_mm_set1_pd(x[k]),
                                               _mm_loadu_pd(&b_data[j]))));
      }
      for (j = scalarLB; j < nb; j++) {
        vectorUB = k + j;
        y[vectorUB] += x[k] * b_data[j];
      }
    }
    naxpy = 1798 - nx_m_nb;
    i = nx_m_nb + 1;
    for (k = i; k < 1800; k++) {
      for (j = 0; j <= naxpy; j++) {
        vectorUB = (k + j) - 1;
        y[vectorUB] += x[k - 1] * b_data[j];
      }
      naxpy--;
    }
  }
}

int filter(double b[3], double a[3], const double x_data[], int x_size,
           const double zi[2], double y_data[])
{
  int j;
  int k;
  int y_size;
  if ((!rtIsInf(a[0])) && (!rtIsNaN(a[0])) && (!(a[0] == 0.0)) &&
      (a[0] != 1.0)) {
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
  memset(&y_data[2], 0, (unsigned int)(x_size - 2) * sizeof(double));
  for (k = 0; k < x_size; k++) {
    double as;
    int a_tmp;
    int naxpy;
    int y_tmp;
    a_tmp = x_size - k;
    if (a_tmp <= 3) {
      naxpy = a_tmp;
    } else {
      naxpy = 3;
    }
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
