/*
 * File: entry_point_internal_types.h
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 19-Apr-2026 14:57:36
 */

#ifndef ENTRY_POINT_INTERNAL_TYPES_H
#define ENTRY_POINT_INTERNAL_TYPES_H

/* Include Files */
#include "entry_point_types.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef struct_emxArray_int32_T_1x98
#define struct_emxArray_int32_T_1x98
struct emxArray_int32_T_1x98 {
  int data[98];
  int size[2];
};
#endif /* struct_emxArray_int32_T_1x98 */
#ifndef typedef_emxArray_int32_T_1x98
#define typedef_emxArray_int32_T_1x98
typedef struct emxArray_int32_T_1x98 emxArray_int32_T_1x98;
#endif /* typedef_emxArray_int32_T_1x98 */

#ifndef struct_emxArray_real_T_3
#define struct_emxArray_real_T_3
struct emxArray_real_T_3 {
  double data[3];
  int size[1];
};
#endif /* struct_emxArray_real_T_3 */
#ifndef typedef_emxArray_real_T_3
#define typedef_emxArray_real_T_3
typedef struct emxArray_real_T_3 emxArray_real_T_3;
#endif /* typedef_emxArray_real_T_3 */

#ifndef struct_emxArray_real_T_3x2
#define struct_emxArray_real_T_3x2
struct emxArray_real_T_3x2 {
  double data[6];
  int size[2];
};
#endif /* struct_emxArray_real_T_3x2 */
#ifndef typedef_emxArray_real_T_3x2
#define typedef_emxArray_real_T_3x2
typedef struct emxArray_real_T_3x2 emxArray_real_T_3x2;
#endif /* typedef_emxArray_real_T_3x2 */

#ifndef struct_emxArray_boolean_T_3
#define struct_emxArray_boolean_T_3
struct emxArray_boolean_T_3 {
  boolean_T data[3];
  int size[1];
};
#endif /* struct_emxArray_boolean_T_3 */
#ifndef typedef_emxArray_boolean_T_3
#define typedef_emxArray_boolean_T_3
typedef struct emxArray_boolean_T_3 emxArray_boolean_T_3;
#endif /* typedef_emxArray_boolean_T_3 */

#ifndef typedef_struct_T
#define typedef_struct_T
typedef struct {
  double X[196];
  char Distance[9];
  double BucketSize;
  emxArray_int32_T_1x98 wasnanIdx;
  int numNodes;
  emxArray_real_T_3 cutDim;
  emxArray_real_T_3 cutVal;
  emxArray_real_T_3x2 lowerBounds;
  emxArray_real_T_3x2 upperBounds;
  emxArray_real_T_3 leftChild;
  emxArray_real_T_3 rightChild;
  emxArray_boolean_T_3 leafNode;
  double nx_nonan;
  unsigned int idxAll[98];
  emxArray_real_T_3 idxDim;
} struct_T;
#endif /* typedef_struct_T */

#endif
/*
 * File trailer for entry_point_internal_types.h
 *
 * [EOF]
 */
