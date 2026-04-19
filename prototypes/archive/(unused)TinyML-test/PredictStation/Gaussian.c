/*
 * File: Gaussian.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 07-Apr-2026 23:04:24
 */

/* Include Files */
#include "Gaussian.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
/*
 * Arguments    : const double svT[1374]
 *                const double svInnerProduct[458]
 *                const double x[3]
 *                double kernelProduct[458]
 * Return Type  : void
 */
void Gaussian(const double svT[1374], const double svInnerProduct[458],
              const double x[3], double kernelProduct[458])
{
  double b_x;
  double d;
  double d1;
  double d2;
  int k;
  b_x = (x[0] * x[0] + x[1] * x[1]) + x[2] * x[2];
  d = x[0];
  d1 = x[1];
  d2 = x[2];
  for (k = 0; k < 458; k++) {
    kernelProduct[k] =
        exp(-((((-2.0 * d * svT[3 * k] + -2.0 * d1 * svT[3 * k + 1]) +
                -2.0 * d2 * svT[3 * k + 2]) +
               b_x) +
              svInnerProduct[k]));
  }
}

/*
 * File trailer for Gaussian.c
 *
 * [EOF]
 */
