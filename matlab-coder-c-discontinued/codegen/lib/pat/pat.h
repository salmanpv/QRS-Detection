/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * pat.h
 *
 * Code generation for function 'pat'
 *
 */

#ifndef PAT_H
#define PAT_H

/* Include files */
#include "pat_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void pat(const double ecg_signal[1800], double fs,
                emxArray_real_T *heart_rate, emxArray_real_T *r_peaks);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (pat.h) */
