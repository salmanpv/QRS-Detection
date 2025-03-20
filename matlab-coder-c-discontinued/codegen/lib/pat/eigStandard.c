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
#include "rt_nonfinite.h"
#include "xdlahqr.h"
#include "xnrm2.h"
#include "xzgehrd.h"
#include "xzlascl.h"
#include "rt_nonfinite.h"
#include <emmintrin.h>
#include <math.h>

/* Function Definitions */
void eigStandard(const double A[4], creal_T V[2])
{
  double b_A[4];
  double absxk;
  double anrm;
  int b_k;
  int i;
  int ix;
  int k;
  boolean_T converged;
  boolean_T exitg1;
  b_A[0] = A[0];
  b_A[1] = A[1];
  b_A[2] = A[2];
  b_A[3] = A[3];
  anrm = 0.0;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 4)) {
    absxk = fabs(A[k]);
    if (rtIsNaN(absxk)) {
      anrm = rtNaN;
      exitg1 = true;
    } else {
      if (absxk > anrm) {
        anrm = absxk;
      }
      k++;
    }
  }
  if (rtIsInf(anrm) || rtIsNaN(anrm)) {
    V[0].re = rtNaN;
    V[0].im = 0.0;
    V[1].re = rtNaN;
    V[1].im = 0.0;
  } else {
    double wi[2];
    double wr[2];
    double cscale;
    int b_i;
    int exitg5;
    int ix0_tmp;
    int iy;
    int kend;
    int l;
    boolean_T notdone;
    boolean_T scalea;
    cscale = anrm;
    scalea = false;
    if ((anrm > 0.0) && (anrm < 6.7178761075670888E-139)) {
      scalea = true;
      cscale = 6.7178761075670888E-139;
      xzlascl(anrm, cscale, b_A);
    } else if (anrm > 1.4885657073574029E+138) {
      scalea = true;
      cscale = 1.4885657073574029E+138;
      xzlascl(anrm, cscale, b_A);
    }
    wr[0] = 1.0;
    wr[1] = 1.0;
    k = 0;
    l = 2;
    notdone = true;
    do {
      exitg5 = 0;
      if (notdone) {
        int exitg4;
        notdone = false;
        ix0_tmp = l;
        do {
          exitg4 = 0;
          if (ix0_tmp > 0) {
            boolean_T exitg6;
            converged = false;
            i = 0;
            exitg6 = false;
            while ((!exitg6) && (i <= l - 1)) {
              if ((i + 1 == ix0_tmp) ||
                  (!(b_A[(ix0_tmp + (i << 1)) - 1] != 0.0))) {
                i++;
              } else {
                converged = true;
                exitg6 = true;
              }
            }
            if (converged) {
              ix0_tmp--;
            } else {
              wr[l - 1] = ix0_tmp;
              if (ix0_tmp != l) {
                ix = (ix0_tmp - 1) << 1;
                iy = (l - 1) << 1;
                for (b_k = 0; b_k < l; b_k++) {
                  int A_tmp;
                  i = ix + b_k;
                  absxk = b_A[i];
                  A_tmp = iy + b_k;
                  b_A[i] = b_A[A_tmp];
                  b_A[A_tmp] = absxk;
                }
                absxk = b_A[ix0_tmp - 1];
                b_A[ix0_tmp - 1] = b_A[l - 1];
                b_A[l - 1] = absxk;
                absxk = b_A[ix0_tmp + 1];
                b_A[ix0_tmp + 1] = b_A[l + 1];
                b_A[l + 1] = absxk;
              }
              exitg4 = 1;
            }
          } else {
            exitg4 = 2;
          }
        } while (exitg4 == 0);
        if (exitg4 == 1) {
          if (l == 1) {
            ix = 1;
            l = 1;
            exitg5 = 1;
          } else {
            l = 1;
            notdone = true;
          }
        }
      } else {
        notdone = true;
        while (notdone) {
          boolean_T exitg6;
          notdone = false;
          ix0_tmp = k + 1;
          exitg6 = false;
          while ((!exitg6) && (ix0_tmp <= l)) {
            boolean_T exitg7;
            converged = false;
            i = k + 1;
            exitg7 = false;
            while ((!exitg7) && (i <= l)) {
              if ((i == ix0_tmp) ||
                  (!(b_A[(i + ((ix0_tmp - 1) << 1)) - 1] != 0.0))) {
                i++;
              } else {
                converged = true;
                exitg7 = true;
              }
            }
            if (converged) {
              ix0_tmp++;
            } else {
              wr[k] = ix0_tmp;
              if (ix0_tmp != k + 1) {
                int A_tmp;
                ix = (ix0_tmp - 1) << 1;
                kend = k << 1;
                for (b_k = 0; b_k < l; b_k++) {
                  i = ix + b_k;
                  absxk = b_A[i];
                  A_tmp = kend + b_k;
                  b_A[i] = b_A[A_tmp];
                  b_A[A_tmp] = absxk;
                }
                ix = (kend + ix0_tmp) - 1;
                iy = kend + k;
                b_i = (unsigned char)(2 - k);
                for (b_k = 0; b_k < b_i; b_k++) {
                  i = b_k << 1;
                  kend = ix + i;
                  absxk = b_A[kend];
                  A_tmp = iy + i;
                  b_A[kend] = b_A[A_tmp];
                  b_A[A_tmp] = absxk;
                }
              }
              k++;
              notdone = true;
              exitg6 = true;
            }
          }
        }
        ix = k + 1;
        converged = false;
        exitg5 = 2;
      }
    } while (exitg5 == 0);
    if (exitg5 != 1) {
      exitg1 = false;
      while ((!exitg1) && (!converged)) {
        int exitg3;
        converged = true;
        i = k;
        do {
          exitg3 = 0;
          if (i + 1 <= l) {
            double c;
            double r;
            double scale;
            double t;
            kend = l - k;
            iy = i << 1;
            c = xnrm2(kend, b_A, (iy + k) + 1);
            ix0_tmp = (k << 1) + i;
            r = 0.0;
            if (kend >= 1) {
              if (kend == 1) {
                r = fabs(b_A[ix0_tmp]);
              } else {
                scale = 3.3121686421112381E-170;
                kend = ix0_tmp + 3;
                for (b_k = ix0_tmp + 1; b_k <= kend; b_k += 2) {
                  absxk = fabs(b_A[b_k - 1]);
                  if (absxk > scale) {
                    t = scale / absxk;
                    r = r * t * t + 1.0;
                    scale = absxk;
                  } else {
                    t = absxk / scale;
                    r += t * t;
                  }
                }
                r = scale * sqrt(r);
              }
            }
            kend = 0;
            if ((l > 1) && (fabs(b_A[iy + 1]) > fabs(b_A[iy]))) {
              kend = 1;
            }
            absxk = fabs(b_A[kend + iy]);
            if (2 - k < 1) {
              kend = -2;
            } else {
              kend = -1;
              if ((2 - k > 1) &&
                  (fabs(b_A[ix0_tmp + 2]) > fabs(b_A[ix0_tmp]))) {
                kend = 0;
              }
            }
            scale = fabs(b_A[i + (((kend + k) + 1) << 1)]);
            if ((c == 0.0) || (r == 0.0)) {
              i++;
            } else {
              double f;
              double s;
              int exitg2;
              t = r / 2.0;
              f = 1.0;
              s = c + r;
              do {
                exitg2 = 0;
                if ((c < t) &&
                    (fmax(f, fmax(c, absxk)) < 4.9896007738368E+291) &&
                    (fmin(r, fmin(t, scale)) > 2.0041683600089728E-292)) {
                  if (rtIsNaN(((((c + f) + absxk) + r) + t) + scale)) {
                    exitg2 = 1;
                  } else {
                    f *= 2.0;
                    c *= 2.0;
                    absxk *= 2.0;
                    r /= 2.0;
                    t /= 2.0;
                    scale /= 2.0;
                  }
                } else {
                  t = c / 2.0;
                  while ((t >= r) && (fmax(r, scale) < 4.9896007738368E+291) &&
                         (fmin(fmin(f, c), fmin(t, absxk)) >
                          2.0041683600089728E-292)) {
                    f /= 2.0;
                    c /= 2.0;
                    t /= 2.0;
                    absxk /= 2.0;
                    r *= 2.0;
                    scale *= 2.0;
                  }
                  if ((!(c + r >= 0.95 * s)) &&
                      ((!(f < 1.0)) || (!(wr[i] < 1.0)) ||
                       (!(f * wr[i] <= 1.0020841800044864E-292))) &&
                      ((!(f > 1.0)) || (!(wr[i] > 1.0)) ||
                       (!(wr[i] >= 9.9792015476736E+291 / f)))) {
                    absxk = 1.0 / f;
                    wr[i] *= f;
                    kend = ix0_tmp + 1;
                    b_i = (ix0_tmp + ((1 - k) << 1)) + 1;
                    for (b_k = kend; b_k <= b_i; b_k += 2) {
                      b_A[b_k - 1] *= absxk;
                    }
                    b_i = iy + l;
                    kend = ((((b_i - iy) / 2) << 1) + iy) + 1;
                    ix0_tmp = kend - 2;
                    for (b_k = iy + 1; b_k <= ix0_tmp; b_k += 2) {
                      __m128d b_r;
                      b_r = _mm_loadu_pd(&b_A[b_k - 1]);
                      _mm_storeu_pd(&b_A[b_k - 1],
                                    _mm_mul_pd(_mm_set1_pd(f), b_r));
                    }
                    for (b_k = kend; b_k <= b_i; b_k++) {
                      b_A[b_k - 1] *= f;
                    }
                    converged = false;
                  }
                  exitg2 = 2;
                }
              } while (exitg2 == 0);
              if (exitg2 == 1) {
                exitg3 = 2;
              } else {
                i++;
              }
            }
          } else {
            exitg3 = 1;
          }
        } while (exitg3 == 0);
        if (exitg3 != 1) {
          exitg1 = true;
        }
      }
    }
    xzgehrd(b_A, ix, l);
    kend = xdlahqr(ix, l, b_A, &absxk, wr, wi);
    if (scalea) {
      b_xzlascl(cscale, anrm, 2 - kend, wr, kend + 1);
      b_xzlascl(cscale, anrm, 2 - kend, wi, kend + 1);
      if (kend != 0) {
        b_xzlascl(cscale, anrm, ix - 1, wr, 1);
        b_xzlascl(cscale, anrm, ix - 1, wi, 1);
      }
    }
    if (kend != 0) {
      for (i = ix; i <= kend; i++) {
        wr[i - 1] = rtNaN;
        wi[i - 1] = 0.0;
      }
    }
    V[0].re = wr[0];
    V[0].im = wi[0];
    V[1].re = wr[1];
    V[1].im = wi[1];
  }
}

/* End of code generation (eigStandard.c) */
