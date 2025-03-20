/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * pat_initialize.c
 *
 * Code generation for function 'pat_initialize'
 *
 */

/* Include files */
#include "pat_initialize.h"
#include "_coder_pat_mex.h"
#include "pat_data.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void pat_once(void);

/* Function Definitions */
static void pat_once(void)
{
  mex_InitInfAndNan();
  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  /* Initialize Coverage Information */
  covrtScriptInit(
      &emlrtCoverageInstance,
      "C:\\Users\\imsal\\Desktop\\matlab-optimized-for-c\\new\\pat.m", 0U, 1U,
      5U, 2U, 0U, 0U, 0U, 0U, 1U, 0U, 0U);
  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 0U, 0U, "pat", 0, -1, 2563);
  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 4U, 2535, -1, 2551);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 3U, 2412, -1, 2487);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 2U, 2180, -1, 2330);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 1U, 1708, -1, 2113);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 0U, 723, -1, 1554);
  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 0U, 0U, 1594, 1619, 2122, 2342);
  covrtIfInit(&emlrtCoverageInstance, 0U, 1U, 2381, 2403, 2522, 2559);
  /* Initialize MCDC Information */
  /* Initialize For Information */
  /* Initialize While Information */
  covrtWhileInit(&emlrtCoverageInstance, 0U, 0U, 1559, 1585, 2350);
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 0U);
}

void pat_initialize(void)
{
  static const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2022b(&st);
  emlrtClearAllocCountR2012b(&st, false, 0U, NULL);
  emlrtEnterRtStackR2012b(&st);
  emlrtLicenseCheckR2022a(&st, "EMLRT:runTime:MexFunctionNeedsLicense",
                          "signal_toolbox", 2);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    pat_once();
  }
}

/* End of code generation (pat_initialize.c) */
