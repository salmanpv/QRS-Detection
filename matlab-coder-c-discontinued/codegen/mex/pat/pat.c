/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * pat.c
 *
 * Code generation for function 'pat'
 *
 */

/* Include files */
#include "pat.h"
#include "butter.h"
#include "diff.h"
#include "filter.h"
#include "filtfilt.h"
#include "pat_data.h"
#include "pat_emxutil.h"
#include "pat_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <emmintrin.h>

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = {
    27,    /* lineNo */
    "pat", /* fcnName */
    "C:\\Users\\imsal\\Desktop\\matlab-optimized-for-c\\new\\pat.m" /* pathName
                                                                     */
};

static emlrtRSInfo b_emlrtRSI = {
    28,    /* lineNo */
    "pat", /* fcnName */
    "C:\\Users\\imsal\\Desktop\\matlab-optimized-for-c\\new\\pat.m" /* pathName
                                                                     */
};

static emlrtRSInfo c_emlrtRSI = {
    38,    /* lineNo */
    "pat", /* fcnName */
    "C:\\Users\\imsal\\Desktop\\matlab-optimized-for-c\\new\\pat.m" /* pathName
                                                                     */
};

static emlrtRSInfo d_emlrtRSI = {
    50,    /* lineNo */
    "pat", /* fcnName */
    "C:\\Users\\imsal\\Desktop\\matlab-optimized-for-c\\new\\pat.m" /* pathName
                                                                     */
};

static emlrtRSInfo e_emlrtRSI = {
    75,    /* lineNo */
    "pat", /* fcnName */
    "C:\\Users\\imsal\\Desktop\\matlab-optimized-for-c\\new\\pat.m" /* pathName
                                                                     */
};

static emlrtRSInfo vf_emlrtRSI = {
    17,    /* lineNo */
    "max", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\datafun\\max.m" /* pathName
                                                                        */
};

static emlrtRSInfo wf_emlrtRSI =
    {
        58,         /* lineNo */
        "minOrMax", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax."
        "m" /* pathName */
};

static emlrtRSInfo xf_emlrtRSI =
    {
        97,        /* lineNo */
        "maximum", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax."
        "m" /* pathName */
};

static emlrtBCInfo emlrtBCI = {
    1,            /* iFirst */
    1800,         /* iLast */
    50,           /* lineNo */
    46,           /* colNo */
    "ecg_signal", /* aName */
    "pat",        /* fName */
    "C:\\Users\\imsal\\Desktop\\matlab-optimized-for-c\\new\\pat.m", /* pName */
    0 /* checkKind */
};

static emlrtDCInfo emlrtDCI = {
    50,    /* lineNo */
    48,    /* colNo */
    "pat", /* fName */
    "C:\\Users\\imsal\\Desktop\\matlab-optimized-for-c\\new\\pat.m", /* pName */
    1 /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = {
    1,            /* iFirst */
    1800,         /* iLast */
    50,           /* lineNo */
    48,           /* colNo */
    "ecg_signal", /* aName */
    "pat",        /* fName */
    "C:\\Users\\imsal\\Desktop\\matlab-optimized-for-c\\new\\pat.m", /* pName */
    0 /* checkKind */
};

static emlrtRTEInfo b_emlrtRTEI = {
    198,             /* lineNo */
    27,              /* colNo */
    "unaryMinOrMax", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\unaryMinOrMax.m" /* pName */
};

static emlrtDCInfo b_emlrtDCI = {
    38,    /* lineNo */
    30,    /* colNo */
    "pat", /* fName */
    "C:\\Users\\imsal\\Desktop\\matlab-optimized-for-c\\new\\pat.m", /* pName */
    1 /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = {
    38,    /* lineNo */
    30,    /* colNo */
    "pat", /* fName */
    "C:\\Users\\imsal\\Desktop\\matlab-optimized-for-c\\new\\pat.m", /* pName */
    4 /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = {
    1,         /* iFirst */
    1799,      /* iLast */
    48,        /* lineNo */
    20,        /* colNo */
    "mwi_ecg", /* aName */
    "pat",     /* fName */
    "C:\\Users\\imsal\\Desktop\\matlab-optimized-for-c\\new\\pat.m", /* pName */
    0 /* checkKind */
};

static emlrtRTEInfo o_emlrtRTEI = {
    38,                                                             /* lineNo */
    22,                                                             /* colNo */
    "pat",                                                          /* fName */
    "C:\\Users\\imsal\\Desktop\\matlab-optimized-for-c\\new\\pat.m" /* pName */
};

static emlrtRTEInfo p_emlrtRTEI = {
    1,                                                              /* lineNo */
    34,                                                             /* colNo */
    "pat",                                                          /* fName */
    "C:\\Users\\imsal\\Desktop\\matlab-optimized-for-c\\new\\pat.m" /* pName */
};

/* Function Definitions */
void pat(const emlrtStack *sp, const real_T ecg_signal[1800], real_T fs,
         emxArray_real_T *heart_rate, emxArray_real_T *r_peaks)
{
  __m128d r;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  emxArray_real_T *r1;
  real_T filtered_ecg[1800];
  real_T diff_ecg[1799];
  real_T squared_ecg[1799];
  real_T a_band[3];
  real_T b_band[3];
  real_T dv[2];
  real_T NPKI;
  real_T SPKI;
  real_T b_i;
  real_T d;
  real_T threshold;
  real_T window_size;
  real_T *heart_rate_data;
  int32_T i;
  int32_T idx;
  int32_T k;
  int32_T scalarLB;
  int32_T vectorUB;
  boolean_T exitg1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  covrtLogFcn(&emlrtCoverageInstance, 0U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 0U);
  /* PAN_TOMPKINS_ECG Detects R-peaks and computes heart rate from an ECG
   * signal. */
  /*    [heart_rate, r_peaks] = PAN_TOMPKINS_ECG(ecg_signal, fs) processes the
   */
  /*    input ECG signal sampled at frequency fs, detects R-peaks using the */
  /*    Pan-Tompkins algorithm, and calculates the instantaneous heart rate. */
  /*  */
  /*    Inputs: */
  /*        ecg_signal - Vector containing the ECG signal data. */
  /*        fs         - Sampling frequency of the ECG signal in Hz. */
  /*  */
  /*    Outputs: */
  /*        heart_rate - Vector of instantaneous heart rates in beats per minute
   * (BPM). */
  /*        r_peaks    - Indices of detected R-peaks in the ECG signal. */
  /*  Ensure the input signal is a column vector */
  /*  Length of the input signal */
  /*  Initialize variables */
  heart_rate->size[0] = 0;
  r_peaks->size[0] = 0;
  /*  Store detected R-peak locations */
  /*  Bandpass Filter Design (5-15 Hz) */
  threshold = fs / 2.0;
  dv[0] = 5.0 / threshold;
  dv[1] = 15.0 / threshold;
  st.site = &emlrtRSI;
  butter(&st, dv, b_band, a_band);
  st.site = &b_emlrtRSI;
  filtfilt(&st, b_band, a_band, ecg_signal, filtered_ecg);
  /*  Differentiation */
  diff(filtered_ecg, diff_ecg);
  /*  Squaring */
  for (k = 0; k <= 1796; k += 2) {
    r = _mm_loadu_pd(&diff_ecg[k]);
    _mm_storeu_pd(&squared_ecg[k], _mm_mul_pd(r, r));
  }
  squared_ecg[1798] = diff_ecg[1798] * diff_ecg[1798];
  /*  Moving Window Integration */
  window_size = muDoubleScalarRound(0.15 * fs);
  /*  150 ms window */
  if (!(window_size >= 0.0)) {
    emlrtNonNegativeCheckR2012b(window_size, &c_emlrtDCI, (emlrtConstCTX)sp);
  }
  if (window_size != (int32_T)window_size) {
    emlrtIntegerCheckR2012b(window_size, &b_emlrtDCI, (emlrtConstCTX)sp);
  }
  emxInit_real_T(sp, &r1, 2, &o_emlrtRTEI);
  i = r1->size[0] * r1->size[1];
  r1->size[0] = 1;
  idx = (int32_T)window_size;
  r1->size[1] = (int32_T)window_size;
  emxEnsureCapacity_real_T(sp, r1, i, &o_emlrtRTEI);
  heart_rate_data = r1->data;
  for (i = 0; i < idx; i++) {
    heart_rate_data[i] = 1.0 / window_size;
  }
  st.site = &c_emlrtRSI;
  b_filter(&st, r1, squared_ecg, diff_ecg);
  emxFree_real_T(sp, &r1);
  /*  Threshold Initialization */
  if (!muDoubleScalarIsNaN(diff_ecg[0])) {
    idx = 1;
  } else {
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 1800)) {
      if (!muDoubleScalarIsNaN(diff_ecg[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  if (idx == 0) {
    threshold = diff_ecg[0];
  } else {
    threshold = diff_ecg[idx - 1];
    i = idx + 1;
    for (k = i; k < 1800; k++) {
      d = diff_ecg[k - 1];
      if (threshold < d) {
        threshold = d;
      }
    }
  }
  threshold *= 0.6;
  /*  Initial threshold */
  SPKI = threshold;
  /*  Initial signal peak estimate */
  NPKI = 0.5 * threshold;
  /*  Initial noise peak estimate */
  /*  Peak Detection */
  b_i = 1.0;
  while (covrtLogWhile(&emlrtCoverageInstance, 0U, 0U, 0,
                       b_i <= 1800.0 - window_size)) {
    if (((int32_T)b_i < 1) || ((int32_T)b_i > 1799)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)b_i, 1, 1799, &c_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    d = diff_ecg[(int32_T)b_i - 1];
    if (covrtLogIf(&emlrtCoverageInstance, 0U, 0U, 0, d > threshold)) {
      real_T d1;
      covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 1U);
      /*  Search back for the corresponding peak in the original signal */
      d1 = (b_i + window_size) - 1.0;
      if (b_i > d1) {
        i = 0;
        scalarLB = 0;
      } else {
        if (((int32_T)b_i < 1) || ((int32_T)b_i > 1800)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)b_i, 1, 1800, &emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        i = (int32_T)b_i - 1;
        if (d1 != (int32_T)d1) {
          emlrtIntegerCheckR2012b(d1, &emlrtDCI, (emlrtConstCTX)sp);
        }
        if (((int32_T)d1 < 1) || ((int32_T)d1 > 1800)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)d1, 1, 1800, &b_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        scalarLB = (int32_T)d1;
      }
      st.site = &d_emlrtRSI;
      b_st.site = &vf_emlrtRSI;
      c_st.site = &wf_emlrtRSI;
      d_st.site = &xf_emlrtRSI;
      vectorUB = scalarLB - i;
      if (vectorUB < 1) {
        emlrtErrorWithMessageIdR2018a(
            &d_st, &b_emlrtRTEI, "Coder:toolbox:eml_min_or_max_varDimZero",
            "Coder:toolbox:eml_min_or_max_varDimZero", 0);
      }
      if (vectorUB <= 2) {
        if (vectorUB == 1) {
          idx = 1;
        } else {
          d1 = ecg_signal[scalarLB - 1];
          if ((ecg_signal[i] < d1) || (muDoubleScalarIsNaN(ecg_signal[i]) &&
                                       (!muDoubleScalarIsNaN(d1)))) {
            idx = 2;
          } else {
            idx = 1;
          }
        }
      } else {
        if (!muDoubleScalarIsNaN(ecg_signal[i])) {
          idx = 1;
        } else {
          idx = 0;
          k = 2;
          exitg1 = false;
          while ((!exitg1) && (k <= vectorUB)) {
            if (!muDoubleScalarIsNaN(ecg_signal[(i + k) - 1])) {
              idx = k;
              exitg1 = true;
            } else {
              k++;
            }
          }
        }
        if (idx == 0) {
          idx = 1;
        } else {
          threshold = ecg_signal[(i + idx) - 1];
          scalarLB = idx + 1;
          for (k = scalarLB; k <= vectorUB; k++) {
            d1 = ecg_signal[(i + k) - 1];
            if (threshold < d1) {
              threshold = d1;
              idx = k;
            }
          }
        }
      }
      i = r_peaks->size[0];
      scalarLB = r_peaks->size[0];
      r_peaks->size[0]++;
      emxEnsureCapacity_real_T(sp, r_peaks, scalarLB, &p_emlrtRTEI);
      heart_rate_data = r_peaks->data;
      heart_rate_data[i] = (b_i + (real_T)idx) - 1.0;
      /*  Update signal peak estimate */
      SPKI = 0.125 * d + 0.875 * SPKI;
      /*  Update threshold */
      threshold = NPKI + 0.25 * (SPKI - NPKI);
      /*  Skip refractory period (200 ms) */
      b_i += muDoubleScalarRound(0.2 * fs);
    } else {
      covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 2U);
      /*  Update noise peak estimate */
      NPKI = 0.125 * d + 0.875 * NPKI;
      /*  Update threshold */
      threshold = NPKI + 0.25 * (SPKI - NPKI);
      b_i++;
    }
  }
  /*  Compute Heart Rate */
  if (covrtLogIf(&emlrtCoverageInstance, 0U, 0U, 1, r_peaks->size[0] > 1)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 3U);
    st.site = &e_emlrtRSI;
    b_diff(&st, r_peaks, heart_rate);
    heart_rate_data = heart_rate->data;
    idx = heart_rate->size[0];
    scalarLB = (heart_rate->size[0] / 2) << 1;
    vectorUB = scalarLB - 2;
    for (i = 0; i <= vectorUB; i += 2) {
      r = _mm_loadu_pd(&heart_rate_data[i]);
      _mm_storeu_pd(&heart_rate_data[i], _mm_div_pd(r, _mm_set1_pd(fs)));
    }
    for (i = scalarLB; i < idx; i++) {
      heart_rate_data[i] /= fs;
    }
    idx = heart_rate->size[0];
    scalarLB = (heart_rate->size[0] / 2) << 1;
    vectorUB = scalarLB - 2;
    for (i = 0; i <= vectorUB; i += 2) {
      r = _mm_loadu_pd(&heart_rate_data[i]);
      _mm_storeu_pd(&heart_rate_data[i], _mm_div_pd(_mm_set1_pd(60.0), r));
    }
    for (i = scalarLB; i < idx; i++) {
      heart_rate_data[i] = 60.0 / heart_rate_data[i];
    }
    /*  Convert RR intervals to BPM */
  } else {
    covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 4U);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (pat.c) */
