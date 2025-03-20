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
#include "minOrMax.h"
#include "pat_emxutil.h"
#include "pat_types.h"
#include "rt_nonfinite.h"
#include <emmintrin.h>
#include <math.h>

/* Function Definitions */
void pat(const double ecg_signal[1800], double fs, emxArray_real_T *heart_rate,
         emxArray_real_T *r_peaks)
{
  __m128d r;
  emxArray_real_T *r1;
  double filtered_ecg[1800];
  double diff_ecg[1799];
  double squared_ecg[1799];
  double a_band[3];
  double b_band[3];
  double dv[2];
  double NPKI;
  double SPKI;
  double b_fs;
  double b_i;
  double threshold;
  double window_size;
  double *heart_rate_data;
  int i;
  int k;
  int loop_ub;
  int vectorUB;
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
  b_fs = fs / 2.0;
  dv[0] = 5.0 / b_fs;
  dv[1] = 15.0 / b_fs;
  butter(dv, b_band, a_band);
  filtfilt(b_band, a_band, ecg_signal, filtered_ecg);
  /*  Differentiation */
  diff(filtered_ecg, diff_ecg);
  /*  Squaring */
  for (k = 0; k <= 1796; k += 2) {
    r = _mm_loadu_pd(&diff_ecg[k]);
    _mm_storeu_pd(&squared_ecg[k], _mm_mul_pd(r, r));
  }
  squared_ecg[1798] = diff_ecg[1798] * diff_ecg[1798];
  /*  Moving Window Integration */
  window_size = 0.15 * fs;
  if (fabs(window_size) < 4.503599627370496E+15) {
    if (window_size >= 0.5) {
      window_size = floor(window_size + 0.5);
    } else if (window_size > -0.5) {
      window_size *= 0.0;
    } else {
      window_size = ceil(window_size - 0.5);
    }
  }
  /*  150 ms window */
  emxInit_real_T(&r1, 2);
  i = r1->size[0] * r1->size[1];
  r1->size[0] = 1;
  k = (int)window_size;
  r1->size[1] = (int)window_size;
  emxEnsureCapacity_real_T(r1, i);
  heart_rate_data = r1->data;
  for (i = 0; i < k; i++) {
    heart_rate_data[i] = 1.0 / window_size;
  }
  b_filter(r1, squared_ecg, diff_ecg);
  emxFree_real_T(&r1);
  /*  Threshold Initialization */
  threshold = 0.6 * maximum(diff_ecg);
  /*  Initial threshold */
  SPKI = threshold;
  /*  Initial signal peak estimate */
  NPKI = 0.5 * threshold;
  /*  Initial noise peak estimate */
  /*  Peak Detection */
  b_i = 1.0;
  while (b_i <= 1800.0 - window_size) {
    double d;
    d = diff_ecg[(int)b_i - 1];
    if (d > threshold) {
      /*  Search back for the corresponding peak in the original signal */
      b_fs = (b_i + window_size) - 1.0;
      if (b_i > b_fs) {
        i = 0;
        vectorUB = 0;
      } else {
        i = (int)b_i - 1;
        vectorUB = (int)b_fs;
      }
      loop_ub = vectorUB - i;
      for (vectorUB = 0; vectorUB < loop_ub; vectorUB++) {
        filtered_ecg[vectorUB] = ecg_signal[i + vectorUB];
      }
      b_maximum(filtered_ecg, loop_ub, &k);
      i = r_peaks->size[0];
      vectorUB = r_peaks->size[0];
      r_peaks->size[0]++;
      emxEnsureCapacity_real_T(r_peaks, vectorUB);
      heart_rate_data = r_peaks->data;
      heart_rate_data[i] = (b_i + (double)k) - 1.0;
      /*  Update signal peak estimate */
      SPKI = 0.125 * d + 0.875 * SPKI;
      /*  Update threshold */
      threshold = NPKI + 0.25 * (SPKI - NPKI);
      /*  Skip refractory period (200 ms) */
      b_fs = 0.2 * fs;
      if (fabs(b_fs) < 4.503599627370496E+15) {
        if (b_fs >= 0.5) {
          b_fs = floor(b_fs + 0.5);
        } else if (b_fs > -0.5) {
          b_fs *= 0.0;
        } else {
          b_fs = ceil(b_fs - 0.5);
        }
      }
      b_i += b_fs;
    } else {
      /*  Update noise peak estimate */
      NPKI = 0.125 * d + 0.875 * NPKI;
      /*  Update threshold */
      threshold = NPKI + 0.25 * (SPKI - NPKI);
      b_i++;
    }
  }
  /*  Compute Heart Rate */
  if (r_peaks->size[0] > 1) {
    b_diff(r_peaks, heart_rate);
    heart_rate_data = heart_rate->data;
    loop_ub = heart_rate->size[0];
    k = (heart_rate->size[0] / 2) << 1;
    vectorUB = k - 2;
    for (i = 0; i <= vectorUB; i += 2) {
      r = _mm_loadu_pd(&heart_rate_data[i]);
      _mm_storeu_pd(
          &heart_rate_data[i],
          _mm_div_pd(_mm_set1_pd(60.0), _mm_div_pd(r, _mm_set1_pd(fs))));
    }
    for (i = k; i < loop_ub; i++) {
      heart_rate_data[i] = 60.0 / (heart_rate_data[i] / fs);
    }
    /*  Convert RR intervals to BPM */
  }
}

/* End of code generation (pat.c) */
