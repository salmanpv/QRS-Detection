/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * diff.c
 *
 * Code generation for function 'diff'
 *
 */

/* Include files */
#include "diff.h"
#include "eml_int_forloop_overflow_check.h"
#include "pat_data.h"
#include "pat_emxutil.h"
#include "pat_types.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo yf_emlrtRSI = {
    108,    /* lineNo */
    "diff", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\datafun\\diff.m" /* pathName
                                                                         */
};

static emlrtRSInfo ag_emlrtRSI = {
    106,    /* lineNo */
    "diff", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\datafun\\diff.m" /* pathName
                                                                         */
};

static emlrtRTEInfo s_emlrtRTEI = {
    78,     /* lineNo */
    21,     /* colNo */
    "diff", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\datafun\\diff.m" /* pName
                                                                         */
};

/* Function Definitions */
void b_diff(const emlrtStack *sp, const emxArray_real_T *x, emxArray_real_T *y)
{
  emlrtStack b_st;
  emlrtStack st;
  const real_T *x_data;
  real_T work_data;
  real_T *y_data;
  int32_T dimSize;
  int32_T m;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  x_data = x->data;
  dimSize = x->size[0];
  m = y->size[0];
  y->size[0] = x->size[0] - 1;
  emxEnsureCapacity_real_T(sp, y, m, &s_emlrtRTEI);
  y_data = y->data;
  work_data = x_data[0];
  st.site = &ag_emlrtRSI;
  if (x->size[0] > 2147483646) {
    b_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (m = 2; m <= dimSize; m++) {
    real_T tmp2;
    st.site = &yf_emlrtRSI;
    tmp2 = work_data;
    work_data = x_data[m - 1];
    y_data[m - 2] = work_data - tmp2;
  }
}

void diff(const real_T x[1800], real_T y[1799])
{
  real_T work;
  int32_T m;
  work = x[0];
  for (m = 0; m < 1799; m++) {
    real_T tmp2;
    tmp2 = work;
    work = x[m + 1];
    y[m] = work - tmp2;
  }
}

/* End of code generation (diff.c) */
