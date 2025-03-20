/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * _coder_pat_api.h
 *
 * Code generation for function 'pat'
 *
 */

#ifndef _CODER_PAT_API_H
#define _CODER_PAT_API_H

/* Include files */
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"
#include <string.h>

/* Type Definitions */
#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T
struct emxArray_real_T {
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_real_T */
#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T
typedef struct emxArray_real_T emxArray_real_T;
#endif /* typedef_emxArray_real_T */

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void pat(real_T ecg_signal[1800], real_T fs, emxArray_real_T *heart_rate,
         emxArray_real_T *r_peaks);

void pat_api(const mxArray *const prhs[2], int32_T nlhs,
             const mxArray *plhs[2]);

void pat_atexit(void);

void pat_initialize(void);

void pat_terminate(void);

void pat_xil_shutdown(void);

void pat_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (_coder_pat_api.h) */
