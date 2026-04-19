/*
 * File: createkds.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 19-Apr-2026 14:57:36
 */

/* Include Files */
#include "createkds.h"
#include "entry_point_internal_types.h"
#include "rt_nonfinite.h"
#include "sort.h"
#include <math.h>
#include <string.h>

/* Type Definitions */
#ifndef typedef_cell_wrap_38
#define typedef_cell_wrap_38
typedef struct {
  emxArray_int32_T_1x98 f1;
} cell_wrap_38;
#endif /* typedef_cell_wrap_38 */

#ifndef typedef_emxArray_cell_wrap_38_3
#define typedef_emxArray_cell_wrap_38_3
typedef struct {
  cell_wrap_38 data[3];
  int size[1];
} emxArray_cell_wrap_38_3;
#endif /* typedef_emxArray_cell_wrap_38_3 */

/* Function Definitions */
/*
 * Arguments    : const double X[196]
 *                struct_T *sObj
 * Return Type  : void
 */
void createkds(const double X[196], struct_T *sObj)
{
  static const char dist[9] = {'e', 'u', 'c', 'l', 'i', 'd', 'e', 'a', 'n'};
  emxArray_cell_wrap_38_3 idxTemp1;
  double sx_data[98];
  double lowerBoundsTemp_data[6];
  double upperBoundsTemp_data[6];
  double cutValTemp_data[3];
  double leftChildTemp_data[3];
  double rightChildTemp_data[3];
  double minval[2];
  double temp[2];
  double cc;
  double d;
  int iidx_data[98];
  int currentNode;
  int i;
  int j;
  int loop_ub;
  int m;
  int nextUnusedNode;
  int unusedNodes;
  signed char notnan_data[98];
  signed char cutDimTemp_data[3];
  signed char tempDim_data[3];
  boolean_T leafNodeTemp_data[3];
  for (i = 0; i < 98; i++) {
    notnan_data[i] = (signed char)(i + 1);
  }
  sObj->wasnanIdx.size[0] = 1;
  sObj->wasnanIdx.size[1] = 0;
  frexp(1.96, &m);
  for (i = 0; i < 3; i++) {
    cutDimTemp_data[i] = 0;
    cutValTemp_data[i] = 0.0;
  }
  for (i = 0; i < 6; i++) {
    upperBoundsTemp_data[i] = rtInf;
    lowerBoundsTemp_data[i] = rtMinusInf;
  }
  for (i = 0; i < 3; i++) {
    leftChildTemp_data[i] = 0.0;
    rightChildTemp_data[i] = 0.0;
    leafNodeTemp_data[i] = false;
    idxTemp1.data[i].f1.size[0] = 1;
    idxTemp1.data[i].f1.size[1] = 0;
  }
  idxTemp1.data[0].f1.size[0] = 1;
  idxTemp1.data[0].f1.size[1] = 98;
  for (i = 0; i < 98; i++) {
    idxTemp1.data[0].f1.data[i] = notnan_data[i];
  }
  currentNode = 0;
  nextUnusedNode = 1;
  while (currentNode + 1 < nextUnusedNode + 1) {
    if (idxTemp1.data[currentNode].f1.size[1] <= 50) {
      leafNodeTemp_data[currentNode] = true;
    } else {
      m = idxTemp1.data[currentNode].f1.size[1];
      unusedNodes = idxTemp1.data[currentNode].f1.size[1];
      for (j = 0; j < 2; j++) {
        cc = X[(idxTemp1.data[currentNode].f1.data[0] + 98 * j) - 1];
        temp[j] = cc;
        for (loop_ub = 2; loop_ub <= m; loop_ub++) {
          d = X[(idxTemp1.data[currentNode].f1.data[loop_ub - 1] + 98 * j) - 1];
          if (temp[j] < d) {
            temp[j] = d;
          }
        }
        minval[j] = cc;
        for (loop_ub = 2; loop_ub <= unusedNodes; loop_ub++) {
          d = X[(idxTemp1.data[currentNode].f1.data[loop_ub - 1] + 98 * j) - 1];
          if (minval[j] > d) {
            minval[j] = d;
          }
        }
        temp[j] -= minval[j];
      }
      j = (temp[0] < temp[1]);
      m = idxTemp1.data[currentNode].f1.size[1];
      loop_ub = idxTemp1.data[currentNode].f1.size[1];
      for (i = 0; i < loop_ub; i++) {
        sx_data[i] = X[(idxTemp1.data[currentNode].f1.data[i] + 98 * j) - 1];
      }
      sort(sx_data, &m, iidx_data, &unusedNodes);
      for (i = 0; i < unusedNodes; i++) {
        notnan_data[i] =
            (signed char)idxTemp1.data[currentNode].f1.data[iidx_data[i] - 1];
      }
      m = (int)ceil((double)m / 2.0);
      cc = (sx_data[m - 1] + sx_data[m]) / 2.0;
      cutDimTemp_data[currentNode] = (signed char)(j + 1);
      cutValTemp_data[currentNode] = cc;
      leftChildTemp_data[currentNode] = nextUnusedNode + 1;
      rightChildTemp_data[currentNode] = (double)(nextUnusedNode + 1) + 1.0;
      temp[0] = upperBoundsTemp_data[currentNode];
      temp[1] = upperBoundsTemp_data[currentNode + 3];
      upperBoundsTemp_data[2] = upperBoundsTemp_data[currentNode];
      upperBoundsTemp_data[5] = upperBoundsTemp_data[currentNode + 3];
      temp[j] = cc;
      upperBoundsTemp_data[nextUnusedNode] = temp[0];
      temp[0] = lowerBoundsTemp_data[currentNode];
      upperBoundsTemp_data[nextUnusedNode + 3] = temp[1];
      temp[1] = lowerBoundsTemp_data[currentNode + 3];
      lowerBoundsTemp_data[nextUnusedNode] = lowerBoundsTemp_data[currentNode];
      lowerBoundsTemp_data[nextUnusedNode + 3] =
          lowerBoundsTemp_data[currentNode + 3];
      temp[j] = cc;
      lowerBoundsTemp_data[2] = temp[0];
      lowerBoundsTemp_data[5] = temp[1];
      idxTemp1.data[currentNode].f1.size[0] = 1;
      idxTemp1.data[currentNode].f1.size[1] = 0;
      idxTemp1.data[nextUnusedNode].f1.size[0] = 1;
      idxTemp1.data[nextUnusedNode].f1.size[1] = m;
      for (i = 0; i < m; i++) {
        idxTemp1.data[nextUnusedNode].f1.data[i] = notnan_data[i];
      }
      if (m + 1 > unusedNodes) {
        m = 0;
        unusedNodes = 0;
      }
      idxTemp1.data[2].f1.size[0] = 1;
      loop_ub = unusedNodes - m;
      idxTemp1.data[2].f1.size[1] = loop_ub;
      for (i = 0; i < loop_ub; i++) {
        idxTemp1.data[2].f1.data[i] = notnan_data[m + i];
      }
      nextUnusedNode += 2;
    }
    currentNode++;
  }
  unusedNodes = nextUnusedNode - 1;
  memcpy(&sObj->X[0], &X[0], 196U * sizeof(double));
  for (i = 0; i < 9; i++) {
    sObj->Distance[i] = dist[i];
  }
  sObj->BucketSize = 50.0;
  sObj->numNodes = nextUnusedNode;
  sObj->nx_nonan = 98.0;
  sObj->cutDim.size[0] = nextUnusedNode;
  sObj->cutVal.size[0] = nextUnusedNode;
  for (i = 0; i < nextUnusedNode; i++) {
    sObj->cutDim.data[i] = cutDimTemp_data[i];
    sObj->cutVal.data[i] = cutValTemp_data[i];
  }
  sObj->lowerBounds.size[0] = nextUnusedNode;
  sObj->lowerBounds.size[1] = 2;
  sObj->upperBounds.size[0] = nextUnusedNode;
  sObj->upperBounds.size[1] = 2;
  for (i = 0; i < 2; i++) {
    for (j = 0; j < nextUnusedNode; j++) {
      m = j + 3 * i;
      sObj->lowerBounds.data[j + sObj->lowerBounds.size[0] * i] =
          lowerBoundsTemp_data[m];
      sObj->upperBounds.data[j + sObj->upperBounds.size[0] * i] =
          upperBoundsTemp_data[m];
    }
  }
  memset(&sObj->idxAll[0], 0, 98U * sizeof(unsigned int));
  cc = 1.0;
  for (m = 0; m <= unusedNodes; m++) {
    i = idxTemp1.data[m].f1.size[1];
    tempDim_data[m] = (signed char)i;
    if ((signed char)i > 0) {
      d = (cc + (double)(signed char)i) - 1.0;
      if (cc > d) {
        i = -1;
        j = 0;
      } else {
        i = (int)cc - 2;
        j = (int)d;
      }
      loop_ub = (j - i) - 1;
      for (j = 0; j < loop_ub; j++) {
        sObj->idxAll[(i + j) + 1] = (unsigned int)idxTemp1.data[m].f1.data[j];
      }
      cc += (double)tempDim_data[m];
    }
  }
  sObj->idxDim.size[0] = nextUnusedNode;
  for (i = 0; i < nextUnusedNode; i++) {
    sObj->idxDim.data[i] = tempDim_data[i];
  }
  sObj->leftChild.size[0] = nextUnusedNode;
  sObj->rightChild.size[0] = nextUnusedNode;
  sObj->leafNode.size[0] = nextUnusedNode;
  if (0 <= nextUnusedNode - 1) {
    memcpy(&sObj->leftChild.data[0], &leftChildTemp_data[0],
           nextUnusedNode * sizeof(double));
    memcpy(&sObj->rightChild.data[0], &rightChildTemp_data[0],
           nextUnusedNode * sizeof(double));
    memcpy(&sObj->leafNode.data[0], &leafNodeTemp_data[0],
           nextUnusedNode * sizeof(boolean_T));
  }
}

/*
 * File trailer for createkds.c
 *
 * [EOF]
 */
