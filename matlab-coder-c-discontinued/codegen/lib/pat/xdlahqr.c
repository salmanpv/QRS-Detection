/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * xdlahqr.c
 *
 * Code generation for function 'xdlahqr'
 *
 */

/* Include files */
#include "xdlahqr.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
int xdlahqr(int ilo, int ihi, double h[4], double *z, double wr[2],
            double wi[2])
{
  int b_i;
  int i;
  int info;
  int k;
  *z = 1.0;
  info = 0;
  i = (unsigned char)(ilo - 1);
  for (b_i = 0; b_i < i; b_i++) {
    wr[b_i] = h[b_i + (b_i << 1)];
    wi[b_i] = 0.0;
  }
  if (ihi + 1 <= 2) {
    wr[1] = h[3];
    wi[1] = 0.0;
  }
  if (ilo == ihi) {
    wr[ilo - 1] = h[(ilo + ((ilo - 1) << 1)) - 1];
    wi[ilo - 1] = 0.0;
  } else {
    double smlnum;
    smlnum = 2.2250738585072014E-308 *
             ((double)((ihi - ilo) + 1) / 2.2204460492503131E-16);
    for (b_i = ihi - 1; b_i + 1 >= ilo; b_i = k - 2) {
      double aa;
      double b_z;
      double bb;
      double bcmis;
      double d;
      double s;
      boolean_T exitg1;
      k = b_i + 1;
      exitg1 = false;
      while ((!exitg1) && (k > ilo)) {
        d = fabs(h[1]);
        if (d <= smlnum) {
          exitg1 = true;
        } else {
          s = fabs(h[3]);
          if (d <= 2.2204460492503131E-16 * (fabs(h[0]) + s)) {
            b_z = fabs(h[2]);
            bcmis = fabs(h[0] - h[3]);
            aa = fmax(s, bcmis);
            bb = fmin(s, bcmis);
            s = aa + bb;
            if (fmin(d, b_z) * (fmax(d, b_z) / s) <=
                fmax(smlnum, 2.2204460492503131E-16 * (bb * (aa / s)))) {
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
        h[1] = 0.0;
      }
      if (k == b_i + 1) {
        wr[b_i] = h[b_i + (b_i << 1)];
        wi[b_i] = 0.0;
      } else if (k == b_i) {
        double b_x_tmp;
        double d1;
        double x;
        int x_tmp;
        d = h[0];
        x_tmp = b_i << 1;
        b_x_tmp = h[x_tmp];
        x = h[b_i];
        i = b_i + x_tmp;
        d1 = h[i];
        s = d1;
        if (!(h[b_i] == 0.0)) {
          if (b_x_tmp == 0.0) {
            s = h[0];
            d = d1;
            b_x_tmp = -h[b_i];
            x = 0.0;
          } else {
            double temp;
            temp = h[0] - d1;
            if ((!(temp == 0.0)) || ((b_x_tmp < 0.0) == (h[b_i] < 0.0))) {
              double bcmax;
              int count;
              int i1;
              aa = 0.5 * temp;
              bcmis = fabs(h[x_tmp]);
              s = fabs(h[b_i]);
              bcmax = fmax(bcmis, s);
              if (!(b_x_tmp < 0.0)) {
                count = 1;
              } else {
                count = -1;
              }
              if (!(h[b_i] < 0.0)) {
                i1 = 1;
              } else {
                i1 = -1;
              }
              bcmis = fmin(bcmis, s) * (double)count * (double)i1;
              s = fmax(fabs(aa), bcmax);
              b_z = aa / s * aa + bcmax / s * bcmis;
              if (b_z >= 8.8817841970012523E-16) {
                bb = sqrt(s) * sqrt(b_z);
                if (aa < 0.0) {
                  bb = -bb;
                }
                b_z = aa + bb;
                d = d1 + b_z;
                s = d1 - bcmax / b_z * bcmis;
                b_x_tmp -= h[b_i];
                x = 0.0;
              } else {
                b_z = b_x_tmp + h[b_i];
                s = fmax(fabs(temp), fabs(b_z));
                count = 0;
                while ((s >= 7.4428285367870146E+137) && (count <= 20)) {
                  b_z *= 1.3435752215134178E-138;
                  temp *= 1.3435752215134178E-138;
                  s = fmax(fabs(temp), fabs(b_z));
                  count++;
                }
                while ((s <= 1.3435752215134178E-138) && (count <= 20)) {
                  b_z *= 7.4428285367870146E+137;
                  temp *= 7.4428285367870146E+137;
                  s = fmax(fabs(temp), fabs(b_z));
                  count++;
                }
                s = fabs(b_z);
                bcmis = fabs(temp);
                if (s < bcmis) {
                  bb = s / bcmis;
                  bcmis *= sqrt(bb * bb + 1.0);
                } else if (s > bcmis) {
                  bcmis /= s;
                  bcmis = s * sqrt(bcmis * bcmis + 1.0);
                } else if (rtIsNaN(bcmis)) {
                  bcmis = rtNaN;
                } else {
                  bcmis = s * 1.4142135623730951;
                }
                bcmax = sqrt(0.5 * (s / bcmis + 1.0));
                if (!(b_z < 0.0)) {
                  count = 1;
                } else {
                  count = -1;
                }
                bcmis = -(0.5 * temp / (bcmis * bcmax)) * (double)count;
                aa = h[0] * bcmax + b_x_tmp * bcmis;
                bb = -h[0] * bcmis + b_x_tmp * bcmax;
                b_z = h[b_i] * bcmax + d1 * bcmis;
                s = -h[b_i] * bcmis + d1 * bcmax;
                b_x_tmp = bb * bcmax + s * bcmis;
                x = -aa * bcmis + b_z * bcmax;
                temp = 0.5 *
                       ((aa * bcmax + b_z * bcmis) + (-bb * bcmis + s * bcmax));
                d = temp;
                s = temp;
                if (x != 0.0) {
                  if (b_x_tmp != 0.0) {
                    if ((b_x_tmp < 0.0) == (x < 0.0)) {
                      bb = sqrt(fabs(b_x_tmp)) * sqrt(fabs(x));
                      if (!(x < 0.0)) {
                        aa = bb;
                      } else {
                        aa = -bb;
                      }
                      d = temp + aa;
                      s = temp - aa;
                      b_x_tmp -= x;
                      x = 0.0;
                    }
                  } else {
                    b_x_tmp = -x;
                    x = 0.0;
                  }
                }
              }
            }
          }
        }
        wr[0] = d;
        wr[b_i] = s;
        if (x == 0.0) {
          d1 = 0.0;
          bcmis = 0.0;
        } else {
          d1 = sqrt(fabs(b_x_tmp)) * sqrt(fabs(x));
          bcmis = -d1;
        }
        wi[0] = d1;
        wi[b_i] = bcmis;
        h[0] = d;
        h[x_tmp] = b_x_tmp;
        h[b_i] = x;
        h[i] = s;
      }
    }
  }
  return info;
}

/* End of code generation (xdlahqr.c) */
