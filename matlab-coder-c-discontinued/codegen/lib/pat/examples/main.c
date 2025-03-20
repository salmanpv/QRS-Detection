/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * main.c
 *
 * Code generation for function 'main'
 *
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/

/* Include files */
#include "main.h"
#include "pat.h"
#include "pat_emxAPI.h"
#include "pat_terminate.h"
#include "pat_types.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void argInit_1800x1_real_T(double result[1800]);

static double argInit_real_T(void);

/* Function Definitions */
static void argInit_1800x1_real_T(double result[1800])
{
  int idx0;
  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 1800; idx0++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[idx0] = argInit_real_T();
  }
}

static double argInit_real_T(void)
{
  return 0.0;
}

int main(int argc, char **argv)
{
  (void)argc;
  (void)argv;
  /* The initialize function is being called automatically from your entry-point
   * function. So, a call to initialize is not included here. */
  /* Invoke the entry-point functions.
You can call entry-point functions multiple times. */
  main_pat();
  /* Terminate the application.
You do not need to do this more than one time. */
  pat_terminate();
  return 0;
}

void main_pat(void)
{
  emxArray_real_T *heart_rate;
  emxArray_real_T *r_peaks;
  double dv[1800];
  /* Initialize function 'pat' input arguments. */
  /* Initialize function input argument 'ecg_signal'. */
  /* Call the entry-point 'pat'. */
  emxInitArray_real_T(&heart_rate, 1);
  emxInitArray_real_T(&r_peaks, 1);
  argInit_1800x1_real_T(dv);
  pat(dv, argInit_real_T(), heart_rate, r_peaks);
  emxDestroyArray_real_T(heart_rate);
  emxDestroyArray_real_T(r_peaks);
}

/* End of code generation (main.c) */
