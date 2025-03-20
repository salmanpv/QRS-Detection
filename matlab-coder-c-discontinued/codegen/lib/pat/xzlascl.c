/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * xzlascl.c
 *
 * Code generation for function 'xzlascl'
 *
 */

/* Include files */
#include "xzlascl.h"
#include "rt_nonfinite.h"
#include <emmintrin.h>
#include <math.h>

/* Function Definitions */
void b_xzlascl(double cfrom, double cto, int m, double A[2], int iA0)
{
  double cfromc;
  double ctoc;
  int b_i;
  boolean_T notdone;
  cfromc = cfrom;
  ctoc = cto;
  notdone = true;
  while (notdone) {
    double cfrom1;
    double cto1;
    double mul;
    int i;
    int i1;
    int scalarLB;
    int vectorUB;
    cfrom1 = cfromc * 2.0041683600089728E-292;
    cto1 = ctoc / 4.9896007738368E+291;
    if ((fabs(cfrom1) > fabs(ctoc)) && (ctoc != 0.0)) {
      mul = 2.0041683600089728E-292;
      cfromc = cfrom1;
    } else if (fabs(cto1) > fabs(cfromc)) {
      mul = 4.9896007738368E+291;
      ctoc = cto1;
    } else {
      mul = ctoc / cfromc;
      notdone = false;
    }
    i = (unsigned char)m;
    scalarLB = ((unsigned char)m >> 1) << 1;
    vectorUB = scalarLB - 2;
    for (b_i = 0; b_i <= vectorUB; b_i += 2) {
      __m128d r;
      i1 = (iA0 + b_i) - 1;
      r = _mm_loadu_pd(&A[i1]);
      _mm_storeu_pd(&A[i1], _mm_mul_pd(r, _mm_set1_pd(mul)));
    }
    for (b_i = scalarLB; b_i < i; b_i++) {
      i1 = (iA0 + b_i) - 1;
      A[i1] *= mul;
    }
  }
}

void c_xzlascl(double cfrom, double cto, int m, double *A)
{
  double cfromc;
  double ctoc;
  int i;
  boolean_T notdone;
  cfromc = cfrom;
  ctoc = cto;
  notdone = true;
  while (notdone) {
    double cfrom1;
    double cto1;
    double mul;
    cfrom1 = cfromc * 2.0041683600089728E-292;
    cto1 = ctoc / 4.9896007738368E+291;
    if ((fabs(cfrom1) > fabs(ctoc)) && (ctoc != 0.0)) {
      mul = 2.0041683600089728E-292;
      cfromc = cfrom1;
    } else if (fabs(cto1) > fabs(cfromc)) {
      mul = 4.9896007738368E+291;
      ctoc = cto1;
    } else {
      mul = ctoc / cfromc;
      notdone = false;
    }
    for (i = 0; i < m; i++) {
      *A *= mul;
    }
  }
}

void xzlascl(double cfrom, double cto, double A[4])
{
  double cfromc;
  double ctoc;
  boolean_T notdone;
  cfromc = cfrom;
  ctoc = cto;
  notdone = true;
  while (notdone) {
    double cfrom1;
    double cto1;
    double mul;
    cfrom1 = cfromc * 2.0041683600089728E-292;
    cto1 = ctoc / 4.9896007738368E+291;
    if ((fabs(cfrom1) > fabs(ctoc)) && (ctoc != 0.0)) {
      mul = 2.0041683600089728E-292;
      cfromc = cfrom1;
    } else if (fabs(cto1) > fabs(cfromc)) {
      mul = 4.9896007738368E+291;
      ctoc = cto1;
    } else {
      mul = ctoc / cfromc;
      notdone = false;
    }
    A[0] *= mul;
    A[1] *= mul;
    A[2] *= mul;
    A[3] *= mul;
  }
}

/* End of code generation (xzlascl.c) */
