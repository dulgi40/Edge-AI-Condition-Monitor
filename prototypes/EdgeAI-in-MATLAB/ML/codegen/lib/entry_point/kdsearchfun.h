/*
 * File: kdsearchfun.h
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 19-Apr-2026 14:57:36
 */

#ifndef KDSEARCHFUN_H
#define KDSEARCHFUN_H

/* Include Files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void search_kdtree(
    const double obj_cutDim_data[], const double obj_cutVal_data[],
    const double obj_lowerBounds_data[], const int obj_lowerBounds_size[2],
    const double obj_upperBounds_data[], const int obj_upperBounds_size[2],
    const double obj_leftChild_data[], const double obj_rightChild_data[],
    const boolean_T obj_leafNode_data[], const unsigned int obj_idxAll[98],
    const double obj_idxDim_data[], const float X[196], const float queryPt[2],
    float pq_D_data[], int *pq_D_size, unsigned int pq_I_data[],
    int *pq_I_size);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for kdsearchfun.h
 *
 * [EOF]
 */
