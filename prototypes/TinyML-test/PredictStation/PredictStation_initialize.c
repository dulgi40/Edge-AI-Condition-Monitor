/*
 * File: PredictStation_initialize.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 07-Apr-2026 23:04:24
 */

/* Include Files */
#include "PredictStation_initialize.h"
#include "PredictStation.h"
#include "PredictStation_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : void
 */
void PredictStation_initialize(void)
{
  rt_InitInfAndNaN();
  PredictStation_init();
  isInitialized_PredictStation = true;
}

/*
 * File trailer for PredictStation_initialize.c
 *
 * [EOF]
 */
