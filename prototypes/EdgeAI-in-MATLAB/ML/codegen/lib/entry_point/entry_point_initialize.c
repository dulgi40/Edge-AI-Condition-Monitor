/*
 * File: entry_point_initialize.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 19-Apr-2026 14:57:36
 */

/* Include Files */
#include "entry_point_initialize.h"
#include "entry_point.h"
#include "entry_point_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : void
 */
void entry_point_initialize(void)
{
  rt_InitInfAndNaN();
  entry_point_init();
  isInitialized_entry_point = true;
}

/*
 * File trailer for entry_point_initialize.c
 *
 * [EOF]
 */
