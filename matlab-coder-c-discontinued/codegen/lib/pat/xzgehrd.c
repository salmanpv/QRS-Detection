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
#include "rt_nonfinite.h"
#include "xnrm2.h"
#include "rt_nonfinite.h"
#include <emmintrin.h>
#include <math.h>
#include <string.h>

/* Function Definitions */
void xzgehrd(double a[4], int ilo, int ihi)
{
  double work[2];
  int i;
  int ia;
  int lastv;
  if ((ihi - ilo) + 1 > 1) {
    work[0] = 0.0;
    work[1] = 0.0;
    for (i = ilo; i < ihi; i++) {
      double alpha1;
      double beta1;
      double d;
      double tau;
      int exitg1;
      int knt;
      int lastc;
      alpha1 = a[1];
      tau = 0.0;
      if (ihi - 1 > 0) {
        beta1 = xnrm2(0, a, 2);
        if (beta1 != 0.0) {
          double b_tmp;
          d = a[1];
          tau = fabs(d);
          b_tmp = fabs(beta1);
          if (tau < b_tmp) {
            tau /= b_tmp;
            beta1 = b_tmp * sqrt(tau * tau + 1.0);
          } else if (tau > b_tmp) {
            beta1 = b_tmp / tau;
            beta1 = tau * sqrt(beta1 * beta1 + 1.0);
          } else if (rtIsNaN(b_tmp)) {
            beta1 = rtNaN;
          } else {
            beta1 = tau * 1.4142135623730951;
          }
          if (d >= 0.0) {
            beta1 = -beta1;
          }
          if (fabs(beta1) < 1.0020841800044864E-292) {
            knt = 0;
            do {
              knt++;
              beta1 *= 9.9792015476736E+291;
              alpha1 *= 9.9792015476736E+291;
            } while ((fabs(beta1) < 1.0020841800044864E-292) && (knt < 20));
            tau = fabs(alpha1);
            if (tau < b_tmp) {
              tau /= b_tmp;
              beta1 = b_tmp * sqrt(tau * tau + 1.0);
            } else if (tau > b_tmp) {
              beta1 = b_tmp / tau;
              beta1 = tau * sqrt(beta1 * beta1 + 1.0);
            } else if (rtIsNaN(b_tmp)) {
              beta1 = rtNaN;
            } else {
              beta1 = tau * 1.4142135623730951;
            }
            if (alpha1 >= 0.0) {
              beta1 = -beta1;
            }
            tau = (beta1 - alpha1) / beta1;
            for (lastv = 0; lastv < knt; lastv++) {
              beta1 *= 1.0020841800044864E-292;
            }
            alpha1 = beta1;
          } else {
            tau = (beta1 - d) / beta1;
            alpha1 = beta1;
          }
        }
      }
      a[1] = 1.0;
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
        int vectorUB;
        if (lastc != 0) {
          knt = (unsigned char)lastc;
          memset(&work[0], 0, (unsigned int)knt * sizeof(double));
          knt = lastc + 2;
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
        if (!(-tau == 0.0)) {
          d = a[1];
          if (d != 0.0) {
            beta1 = d * -tau;
            knt = lastc + 3;
            lastv = (knt - 3) / 2 * 2 + 3;
            vectorUB = lastv - 2;
            for (ia = 3; ia <= vectorUB; ia += 2) {
              r = _mm_loadu_pd(&work[ia - 3]);
              r = _mm_mul_pd(r, _mm_set1_pd(beta1));
              r1 = _mm_loadu_pd(&a[ia - 1]);
              r = _mm_add_pd(r1, r);
              _mm_storeu_pd(&a[ia - 1], r);
            }
            for (ia = lastv; ia < knt; ia++) {
              a[ia - 1] += work[ia - 3] * beta1;
            }
          }
        }
      }
      if (tau != 0.0) {
        lastv = ihi - 1;
        knt = ihi;
        while ((lastv > 0) && (a[knt - 1] == 0.0)) {
          lastv = 0;
          knt--;
        }
        lastc = 1;
        ia = 4;
        do {
          exitg1 = 0;
          if (ia <= lastv + 3) {
            if (a[3] != 0.0) {
              exitg1 = 1;
            } else {
              ia++;
            }
          } else {
            lastc = 0;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      } else {
        lastv = 0;
        lastc = 0;
      }
      if (lastv > 0) {
        if (lastc != 0) {
          work[0] = a[1] * a[3];
        }
        if (!(-tau == 0.0)) {
          knt = 4;
          for (lastv = 0; lastv < lastc; lastv++) {
            if (work[0] != 0.0) {
              beta1 = work[0] * -tau;
              for (ia = knt; ia <= knt; ia++) {
                a[ia - 1] += a[(ia - knt) + 1] * beta1;
              }
            }
            knt += 2;
          }
        }
      }
      a[1] = alpha1;
    }
  }
}

/* End of code generation (xzgehrd.c) */
