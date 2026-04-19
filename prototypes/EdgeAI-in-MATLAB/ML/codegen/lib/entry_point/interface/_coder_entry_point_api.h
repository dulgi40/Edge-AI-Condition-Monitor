/*
 * File: _coder_entry_point_api.h
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 19-Apr-2026 14:57:36
 */

#ifndef _CODER_ENTRY_POINT_API_H
#define _CODER_ENTRY_POINT_API_H

/* Include Files */
#include "emlrt.h"
#include "tmwtypes.h"
#include <string.h>

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
uint8_T entry_point(real32_T iq, real32_T id);

void entry_point_api(const mxArray *const prhs[2], const mxArray **plhs);

void entry_point_atexit(void);

void entry_point_initialize(void);

void entry_point_terminate(void);

void entry_point_xil_shutdown(void);

void entry_point_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for _coder_entry_point_api.h
 *
 * [EOF]
 */
