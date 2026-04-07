/*
 * File: _coder_PredictStation_api.h
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 07-Apr-2026 23:04:24
 */

#ifndef _CODER_PREDICTSTATION_API_H
#define _CODER_PREDICTSTATION_API_H

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
real_T PredictStation(real_T input_features[3]);

void PredictStation_api(const mxArray *prhs, const mxArray **plhs);

void PredictStation_atexit(void);

void PredictStation_initialize(void);

void PredictStation_terminate(void);

void PredictStation_xil_shutdown(void);

void PredictStation_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for _coder_PredictStation_api.h
 *
 * [EOF]
 */
