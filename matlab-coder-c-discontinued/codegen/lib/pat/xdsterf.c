/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * xdsterf.c
 *
 * Code generation for function 'xdsterf'
 *
 */

/* Include files */
#include "xdsterf.h"
#include "insertionsort.h"
#include "rt_nonfinite.h"
#include "xdlaev2.h"
#include "xzlascl.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
int xdsterf(double d[2], double e)
{
  double rte;
  int i;
  int info;
  int jtot;
  int l1;
  info = 0;
  jtot = 0;
  l1 = 1;
  int exitg1;
  do {
    exitg1 = 0;
    if (l1 > 2) {
      b_insertionsort(d);
      exitg1 = 1;
    } else {
      int l;
      int lend;
      int lendsv_tmp_tmp;
      int lsv;
      int m;
      boolean_T exitg2;
      if (l1 > 1) {
        e = 0.0;
      }
      m = l1;
      exitg2 = false;
      while ((!exitg2) && (m < 2)) {
        if (fabs(e) <=
            sqrt(fabs(d[0])) * sqrt(fabs(d[1])) * 2.2204460492503131E-16) {
          e = 0.0;
          exitg2 = true;
        } else {
          m = 2;
        }
      }
      l = l1;
      lsv = l1;
      lend = m;
      lendsv_tmp_tmp = m + 1;
      l1 = m + 1;
      if (m != l) {
        double anorm;
        double b_anorm;
        int n_tmp;
        n_tmp = m - l;
        if (n_tmp + 1 <= 0) {
          anorm = 0.0;
        } else {
          anorm = fabs(d[(l + n_tmp) - 1]);
          i = 0;
          exitg2 = false;
          while ((!exitg2) && (i <= n_tmp - 1)) {
            b_anorm = fabs(d[l - 1]);
            if (rtIsNaN(b_anorm)) {
              anorm = rtNaN;
              exitg2 = true;
            } else {
              if (b_anorm > anorm) {
                anorm = b_anorm;
              }
              b_anorm = fabs(e);
              if (rtIsNaN(b_anorm)) {
                anorm = rtNaN;
                exitg2 = true;
              } else {
                if (b_anorm > anorm) {
                  anorm = b_anorm;
                }
                i = 1;
              }
            }
          }
        }
        if (!(anorm == 0.0)) {
          int iscale;
          iscale = 0;
          if (anorm > 2.2346346549904327E+153) {
            iscale = 1;
            b_xzlascl(anorm, 2.2346346549904327E+153, n_tmp + 1, d, l);
            c_xzlascl(anorm, 2.2346346549904327E+153, n_tmp, &e);
          } else if (anorm < 3.02546243347603E-123) {
            iscale = 2;
            b_xzlascl(anorm, 3.02546243347603E-123, n_tmp + 1, d, l);
            c_xzlascl(anorm, 3.02546243347603E-123, n_tmp, &e);
          }
          for (i = l; i < m; i++) {
            e *= e;
          }
          if (fabs(d[m - 1]) < fabs(d[l - 1])) {
            lend = lsv;
            l = m;
          }
          if (lend >= l) {
            int exitg4;
            do {
              exitg4 = 0;
              if (l != lend) {
                m = l;
                while ((m < lend) &&
                       (!(fabs(e) <=
                          4.9303806576313238E-32 * fabs(d[0]) * fabs(d[1])))) {
                  m = 2;
                }
              } else {
                m = lend;
              }
              if (m < lend) {
                e = 0.0;
              }
              if (m == l) {
                l++;
                if (l > lend) {
                  exitg4 = 1;
                }
              } else if (m == l + 1) {
                d[0] = xdlaev2(d[0], sqrt(e), d[1], &d[1]);
                e = 0.0;
                exitg4 = 1;
              } else if (jtot == 60) {
                exitg4 = 1;
              } else {
                double b_gamma;
                double c;
                double p;
                double s;
                double sigma;
                jtot++;
                rte = sqrt(e);
                s = d[l - 1];
                sigma = (d[1] - s) / (2.0 * rte);
                b_anorm = fabs(sigma);
                if (b_anorm < 1.0) {
                  b_anorm = sqrt(b_anorm * b_anorm + 1.0);
                } else if (b_anorm > 1.0) {
                  p = 1.0 / b_anorm;
                  b_anorm *= sqrt(p * p + 1.0);
                } else {
                  b_anorm *= 1.4142135623730951;
                }
                if (!(sigma >= 0.0)) {
                  b_anorm = -b_anorm;
                }
                sigma = s - rte / (sigma + b_anorm);
                c = 1.0;
                s = 0.0;
                b_gamma = d[m - 1] - sigma;
                p = b_gamma * b_gamma;
                n_tmp = m - 1;
                for (i = n_tmp; i >= 1; i--) {
                  double oldc;
                  b_anorm = p + e;
                  if (m - 1 != 1) {
                    /* Check node always fails. would cause program termination
                     * and was eliminated */
                  }
                  oldc = c;
                  c = p / b_anorm;
                  s = e / b_anorm;
                  b_anorm = b_gamma;
                  rte = d[0];
                  b_gamma = c * (rte - sigma) - s * b_gamma;
                  d[1] = b_anorm + (rte - b_gamma);
                  if (c != 0.0) {
                    p = b_gamma * b_gamma / c;
                  } else {
                    p = oldc * e;
                  }
                }
                e = s * p;
                d[0] = sigma + b_gamma;
              }
            } while (exitg4 == 0);
          } else {
            int exitg3;
            do {
              exitg3 = 0;
              m = l;
              while ((m > 1) && (!(fabs(e) <= 4.9303806576313238E-32 *
                                                  fabs(d[1]) * fabs(d[0])))) {
                m = 1;
              }
              if (m > 1) {
                e = 0.0;
              }
              if (m == l) {
                l--;
                if (l < 1) {
                  exitg3 = 1;
                }
              } else if (m == l - 1) {
                d[l - 1] = xdlaev2(d[l - 1], sqrt(e), d[0], &rte);
                d[0] = rte;
                e = 0.0;
                exitg3 = 1;
              } else if (jtot == 60) {
                exitg3 = 1;
              } else {
                double b_gamma;
                double c;
                double p;
                double s;
                double sigma;
                jtot++;
                rte = sqrt(e);
                s = d[l - 1];
                sigma = (d[0] - s) / (2.0 * rte);
                b_anorm = fabs(sigma);
                if (b_anorm < 1.0) {
                  b_anorm = sqrt(b_anorm * b_anorm + 1.0);
                } else if (b_anorm > 1.0) {
                  p = 1.0 / b_anorm;
                  b_anorm *= sqrt(p * p + 1.0);
                } else {
                  b_anorm *= 1.4142135623730951;
                }
                if (!(sigma >= 0.0)) {
                  b_anorm = -b_anorm;
                }
                sigma = s - rte / (sigma + b_anorm);
                c = 1.0;
                s = 0.0;
                b_gamma = d[m - 1] - sigma;
                p = b_gamma * b_gamma;
                for (i = m; i < l; i++) {
                  double oldc;
                  b_anorm = p + e;
                  if (m != 1) {
                    /* Check node always fails. would cause program termination
                     * and was eliminated */
                  }
                  oldc = c;
                  c = p / b_anorm;
                  s = e / b_anorm;
                  b_anorm = b_gamma;
                  rte = d[1];
                  b_gamma = c * (rte - sigma) - s * b_gamma;
                  d[0] = b_anorm + (rte - b_gamma);
                  if (c != 0.0) {
                    p = b_gamma * b_gamma / c;
                  } else {
                    p = oldc * e;
                  }
                }
                e = s * p;
                d[l - 1] = sigma + b_gamma;
              }
            } while (exitg3 == 0);
          }
          if (iscale == 1) {
            b_xzlascl(2.2346346549904327E+153, anorm, lendsv_tmp_tmp - lsv, d,
                      lsv);
          } else if (iscale == 2) {
            b_xzlascl(3.02546243347603E-123, anorm, lendsv_tmp_tmp - lsv, d,
                      lsv);
          }
          if (jtot >= 60) {
            if (e != 0.0) {
              info = 1;
            }
            exitg1 = 1;
          }
        }
      }
    }
  } while (exitg1 == 0);
  return info;
}

/* End of code generation (xdsterf.c) */
