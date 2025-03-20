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
#include "eigStandard.h"
#include "rt_nonfinite.h"
#include "xdlahqr.h"
#include "xdsterf.h"
#include "xzgehrd.h"
#include "xzlascl.h"
#include "rt_nonfinite.h"
#include <emmintrin.h>
#include <math.h>

/* Function Definitions */
void butter(const double Wn[2], double varargout_1[3], double varargout_2[3])
{
  __m128d r;
  __m128d r1;
  creal_T c[3];
  creal_T b_x[2];
  creal_T p[2];
  creal_T x[2];
  double ad[4];
  double t1[4];
  double t2[4];
  double u[2];
  double Wn1;
  double a21;
  double a22;
  double absx;
  double d;
  double x_im;
  int b_r1;
  int i;
  int r2;
  boolean_T iscale;
  u[0] = 4.0 * tan(3.1415926535897931 * Wn[0] / 2.0);
  u[1] = 4.0 * tan(3.1415926535897931 * Wn[1] / 2.0);
  Wn1 = sqrt(u[0] * u[1]);
  t2[1] = 0.0;
  t2[2] = 0.0;
  ad[0] = Wn1 * (-1.0 / (Wn1 / (u[1] - u[0]))) * 0.5 / 2.0;
  ad[2] = Wn1 * 0.5 / 2.0;
  t2[0] = 1.0;
  ad[1] = -Wn1 * 0.5 / 2.0;
  t2[3] = 1.0;
  ad[3] = Wn1 * 0.0 * 0.5 / 2.0;
  r = _mm_loadu_pd(&t2[0]);
  r1 = _mm_loadu_pd(&ad[0]);
  _mm_storeu_pd(&t1[0], _mm_add_pd(r, r1));
  _mm_storeu_pd(&t2[0], _mm_sub_pd(r, r1));
  r = _mm_loadu_pd(&t2[2]);
  r1 = _mm_loadu_pd(&ad[2]);
  _mm_storeu_pd(&t1[2], _mm_add_pd(r, r1));
  _mm_storeu_pd(&t2[2], _mm_sub_pd(r, r1));
  if (fabs(t2[1]) > fabs(t2[0])) {
    b_r1 = 1;
    r2 = 0;
  } else {
    b_r1 = 0;
    r2 = 1;
  }
  a21 = t2[r2] / t2[b_r1];
  absx = t2[b_r1 + 2];
  a22 = t2[r2 + 2] - a21 * absx;
  d = (t1[r2] - t1[b_r1] * a21) / a22;
  ad[1] = d;
  ad[0] = (t1[b_r1] - d * absx) / t2[b_r1];
  x_im = t1[b_r1 + 2];
  d = (t1[r2 + 2] - x_im * a21) / a22;
  ad[3] = d;
  ad[2] = (x_im - d * absx) / t2[b_r1];
  iscale = true;
  for (b_r1 = 0; b_r1 < 4; b_r1++) {
    if (iscale) {
      d = ad[b_r1];
      if (rtIsInf(d) || rtIsNaN(d)) {
        iscale = false;
      }
    } else {
      iscale = false;
    }
  }
  if (!iscale) {
    p[0].re = rtNaN;
    p[0].im = 0.0;
    p[1].re = rtNaN;
    p[1].im = 0.0;
  } else {
    int exitg1;
    boolean_T exitg2;
    iscale = true;
    r2 = 0;
    exitg2 = false;
    while ((!exitg2) && (r2 < 2)) {
      i = 0;
      do {
        exitg1 = 0;
        if (i <= r2) {
          if (!(ad[i + (r2 << 1)] == ad[r2 + (i << 1)])) {
            iscale = false;
            exitg1 = 1;
          } else {
            i++;
          }
        } else {
          r2++;
          exitg1 = 2;
        }
      } while (exitg1 == 0);
      if (exitg1 == 1) {
        exitg2 = true;
      }
    }
    if (iscale) {
      a21 = 0.0;
      r2 = 0;
      exitg2 = false;
      while ((!exitg2) && (r2 < 2)) {
        i = 0;
        do {
          exitg1 = 0;
          if (i <= r2) {
            absx = fabs(ad[i + (r2 << 1)]);
            if (rtIsNaN(absx)) {
              a21 = rtNaN;
              exitg1 = 1;
            } else {
              if (absx > a21) {
                a21 = absx;
              }
              i++;
            }
          } else {
            r2++;
            exitg1 = 2;
          }
        } while (exitg1 == 0);
        if (exitg1 == 1) {
          exitg2 = true;
        }
      }
      if (rtIsInf(a21) || rtIsNaN(a21)) {
        u[0] = rtNaN;
        u[1] = rtNaN;
      } else {
        iscale = false;
        if ((a21 > 0.0) && (a21 < 1.0010415475915505E-146)) {
          iscale = true;
          a21 = 1.0010415475915505E-146 / a21;
          xzlascl(1.0, a21, ad);
        } else if (a21 > 9.9895953610111751E+145) {
          iscale = true;
          a21 = 9.9895953610111751E+145 / a21;
          xzlascl(1.0, a21, ad);
        }
        u[0] = ad[0];
        u[1] = ad[3];
        b_r1 = xdsterf(u, ad[1]);
        if (b_r1 != 0) {
          u[0] = rtNaN;
          u[1] = rtNaN;
        } else if (iscale) {
          r = _mm_loadu_pd(&u[0]);
          _mm_storeu_pd(&u[0], _mm_mul_pd(_mm_set1_pd(1.0 / a21), r));
        }
      }
      p[0].re = u[0];
      p[0].im = 0.0;
      p[1].re = u[1];
      p[1].im = 0.0;
    } else {
      iscale = true;
      r2 = 0;
      exitg2 = false;
      while ((!exitg2) && (r2 < 2)) {
        i = 0;
        do {
          exitg1 = 0;
          if (i <= r2) {
            if (!(ad[i + (r2 << 1)] == -ad[r2 + (i << 1)])) {
              iscale = false;
              exitg1 = 1;
            } else {
              i++;
            }
          } else {
            r2++;
            exitg1 = 2;
          }
        } while (exitg1 == 0);
        if (exitg1 == 1) {
          exitg2 = true;
        }
      }
      if (iscale) {
        double wi[2];
        xzgehrd(ad, 1, 2);
        b_r1 = xdlahqr(1, 2, ad, &a21, u, wi);
        r2 = (unsigned char)b_r1;
        for (i = 0; i < r2; i++) {
          p[i].re = rtNaN;
          p[i].im = 0.0;
        }
        r2 = b_r1 + 1;
        for (i = r2; i < 3; i++) {
          p[i - 1].re = 0.0;
          p[i - 1].im = wi[i - 1];
        }
      } else {
        eigStandard(ad, p);
      }
    }
  }
  if (rtIsNaN(Wn1)) {
    a21 = rtNaN;
  } else {
    a21 = atan2(Wn1, 4.0);
  }
  Wn1 = 2.0 * a21;
  if (2.0 * a21 * 0.0 == 0.0) {
    absx = cos(Wn1);
    Wn1 = sin(Wn1);
  } else if (Wn1 == 0.0) {
    absx = rtNaN;
    Wn1 = 0.0;
  } else {
    absx = rtNaN;
    Wn1 = rtNaN;
  }
  c[0].re = 1.0;
  c[0].im = 0.0;
  for (r2 = 0; r2 < 2; r2++) {
    d = p[r2].re;
    b_x[r2].re = absx - d;
    x_im = p[r2].im;
    b_x[r2].im = Wn1 - x_im;
    x[r2].re = absx - (-2.0 * (double)r2 + 1.0);
    x[r2].im = Wn1;
    a21 = c[r2].im;
    a22 = c[r2].re;
    c[r2 + 1].re = -d * a22 - -x_im * a21;
    c[r2 + 1].im = -d * a21 + -x_im * a22;
    for (b_r1 = r2 + 1; b_r1 >= 2; b_r1--) {
      c[1].re -= d * c[0].re - x_im * c[0].im;
      c[1].im -= d * c[0].im + x_im * c[0].re;
    }
  }
  a22 = b_x[0].re * b_x[1].re - b_x[0].im * b_x[1].im;
  Wn1 = b_x[0].re * b_x[1].im + b_x[0].im * b_x[1].re;
  d = x[0].re * x[1].re - x[0].im * x[1].im;
  x_im = x[0].re * x[1].im + x[0].im * x[1].re;
  if (x_im == 0.0) {
    if (Wn1 == 0.0) {
      a22 /= d;
    } else if (a22 == 0.0) {
      a22 = 0.0;
    } else {
      a22 /= d;
    }
  } else if (d == 0.0) {
    if (a22 == 0.0) {
      a22 = Wn1 / x_im;
    } else if (Wn1 == 0.0) {
      a22 = 0.0;
    } else {
      a22 = Wn1 / x_im;
    }
  } else {
    absx = fabs(d);
    a21 = fabs(x_im);
    if (absx > a21) {
      a21 = x_im / d;
      a22 = (a22 + a21 * Wn1) / (d + a21 * x_im);
    } else if (a21 == absx) {
      if (d > 0.0) {
        d = 0.5;
      } else {
        d = -0.5;
      }
      if (x_im > 0.0) {
        a21 = 0.5;
      } else {
        a21 = -0.5;
      }
      a22 = (a22 * d + Wn1 * a21) / absx;
    } else {
      a21 = d / x_im;
      a22 = (a21 * a22 + Wn1) / (x_im + a21 * d);
    }
  }
  varargout_2[0] = c[0].re;
  varargout_1[0] = a22;
  varargout_2[1] = c[1].re;
  varargout_1[1] = a22 * 0.0;
  varargout_2[2] = c[2].re;
  varargout_1[2] = -a22;
}

/* End of code generation (butter.c) */
