/*
 * File: kdsearchfun.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 19-Apr-2026 14:57:36
 */

/* Include Files */
#include "kdsearchfun.h"
#include "rt_nonfinite.h"
#include "sort.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Type Definitions */
#ifndef struct_emxArray_uint32_T_98
#define struct_emxArray_uint32_T_98
struct emxArray_uint32_T_98 {
  unsigned int data[98];
  int size[1];
};
#endif /* struct_emxArray_uint32_T_98 */
#ifndef typedef_emxArray_uint32_T_98
#define typedef_emxArray_uint32_T_98
typedef struct emxArray_uint32_T_98 emxArray_uint32_T_98;
#endif /* typedef_emxArray_uint32_T_98 */

#ifndef struct_emxArray_real32_T_98
#define struct_emxArray_real32_T_98
struct emxArray_real32_T_98 {
  float data[98];
  int size[1];
};
#endif /* struct_emxArray_real32_T_98 */
#ifndef typedef_emxArray_real32_T_98
#define typedef_emxArray_real32_T_98
typedef struct emxArray_real32_T_98 emxArray_real32_T_98;
#endif /* typedef_emxArray_real32_T_98 */

#ifndef typedef_b_struct_T
#define typedef_b_struct_T
typedef struct {
  emxArray_real32_T_98 D;
  emxArray_uint32_T_98 b_I;
} b_struct_T;
#endif /* typedef_b_struct_T */

/* Function Declarations */
static void search_node(const float X[196], const float queryPt[2],
                        const unsigned int node_idx_start_data[],
                        int node_idx_start_size, b_struct_T *pq);

/* Function Definitions */
/*
 * Arguments    : const float X[196]
 *                const float queryPt[2]
 *                const unsigned int node_idx_start_data[]
 *                int node_idx_start_size
 *                b_struct_T *pq
 * Return Type  : void
 */
static void search_node(const float X[196], const float queryPt[2],
                        const unsigned int node_idx_start_data[],
                        int node_idx_start_size, b_struct_T *pq)
{
  float diffAllDim_data[196];
  float tmp_data[99];
  float aDistOut_data[98];
  float f;
  unsigned int b_tmp_data[99];
  int iidx_data[98];
  int aDistOut_size;
  int acoef;
  int b_k;
  int cD2;
  int i;
  int k;
  boolean_T exitg1;
  cD2 = (signed char)node_idx_start_size;
  if ((signed char)node_idx_start_size != 0) {
    acoef = (node_idx_start_size != 1);
    i = (signed char)node_idx_start_size - 1;
    for (k = 0; k < 2; k++) {
      for (b_k = 0; b_k <= i; b_k++) {
        diffAllDim_data[b_k + (signed char)node_idx_start_size * k] =
            X[((int)node_idx_start_data[acoef * b_k] + 98 * k) - 1] -
            queryPt[k];
      }
    }
  }
  acoef = (signed char)node_idx_start_size * 2;
  for (i = 0; i < acoef; i++) {
    f = diffAllDim_data[i];
    f *= f;
    diffAllDim_data[i] = f;
  }
  if ((signed char)node_idx_start_size == 0) {
    aDistOut_size = 0;
  } else {
    aDistOut_size = (signed char)node_idx_start_size;
    for (acoef = 0; acoef < cD2; acoef++) {
      aDistOut_data[acoef] =
          diffAllDim_data[acoef] +
          diffAllDim_data[(signed char)node_idx_start_size + acoef];
    }
  }
  b_sort(aDistOut_data, &aDistOut_size, iidx_data, &acoef);
  if (pq->D.size[0] == 0) {
    if (aDistOut_size <= 1) {
      pq->D.size[0] = aDistOut_size;
      for (i = 0; i < aDistOut_size; i++) {
        pq->D.data[0] = aDistOut_data[0];
      }
      pq->b_I.size[0] = acoef;
      for (i = 0; i < acoef; i++) {
        pq->b_I.data[i] = node_idx_start_data[iidx_data[i] - 1];
      }
    } else {
      pq->D.size[0] = 1;
      pq->D.data[0] = aDistOut_data[0];
      pq->b_I.size[0] = 1;
      pq->b_I.data[0] = node_idx_start_data[iidx_data[0] - 1];
    }
  } else {
    cD2 = 0;
    acoef = pq->D.size[0] + aDistOut_size;
    if (acoef > 1) {
      acoef = 0;
    } else {
      acoef--;
    }
    k = acoef + 1;
    if (0 <= acoef) {
      memset(&tmp_data[0], 0, (acoef + 1) * sizeof(float));
      memset(&b_tmp_data[0], 0, (acoef + 1) * sizeof(unsigned int));
    }
    b_k = 0;
    exitg1 = false;
    while ((!exitg1) && (b_k <= acoef)) {
      if (pq->D.data[0] <= aDistOut_data[cD2]) {
        tmp_data[0] = pq->D.data[0];
        b_tmp_data[0] = pq->b_I.data[0];
        exitg1 = true;
      } else {
        tmp_data[0] = aDistOut_data[cD2];
        b_tmp_data[0] = node_idx_start_data[iidx_data[cD2] - 1];
        cD2++;
        if (cD2 + 1 > aDistOut_size) {
          exitg1 = true;
        } else {
          b_k = 1;
        }
      }
    }
    pq->D.size[0] = acoef + 1;
    if (0 <= k - 1) {
      memcpy(&pq->D.data[0], &tmp_data[0], k * sizeof(float));
    }
    pq->b_I.size[0] = acoef + 1;
    if (0 <= k - 1) {
      memcpy(&pq->b_I.data[0], &b_tmp_data[0], k * sizeof(unsigned int));
    }
  }
}

/*
 * Arguments    : const double obj_cutDim_data[]
 *                const double obj_cutVal_data[]
 *                const double obj_lowerBounds_data[]
 *                const int obj_lowerBounds_size[2]
 *                const double obj_upperBounds_data[]
 *                const int obj_upperBounds_size[2]
 *                const double obj_leftChild_data[]
 *                const double obj_rightChild_data[]
 *                const boolean_T obj_leafNode_data[]
 *                const unsigned int obj_idxAll[98]
 *                const double obj_idxDim_data[]
 *                const float X[196]
 *                const float queryPt[2]
 *                float pq_D_data[]
 *                int *pq_D_size
 *                unsigned int pq_I_data[]
 *                int *pq_I_size
 * Return Type  : void
 */
void search_kdtree(
    const double obj_cutDim_data[], const double obj_cutVal_data[],
    const double obj_lowerBounds_data[], const int obj_lowerBounds_size[2],
    const double obj_upperBounds_data[], const int obj_upperBounds_size[2],
    const double obj_leftChild_data[], const double obj_rightChild_data[],
    const boolean_T obj_leafNode_data[], const unsigned int obj_idxAll[98],
    const double obj_idxDim_data[], const float X[196], const float queryPt[2],
    float pq_D_data[], int *pq_D_size, unsigned int pq_I_data[], int *pq_I_size)
{
  b_struct_T r;
  double lowBounds_data[2];
  double upBounds_data[2];
  double d;
  double start_node;
  double y;
  float nodeStack_data[10];
  float x_data[3];
  float currentNode;
  float lowDist_idx_0;
  float pRadIn;
  float upDist_idx_0;
  unsigned int node_idx_this_data[98];
  int i;
  int k;
  int nodeStack_size;
  int vlen;
  boolean_T ballIsWithinBounds;
  boolean_T exitg1;
  start_node = 1.0;
  while (!obj_leafNode_data[(int)start_node - 1]) {
    if (queryPt[(int)obj_cutDim_data[(int)start_node - 1] - 1] <=
        obj_cutVal_data[(int)start_node - 1]) {
      start_node = obj_leftChild_data[(int)start_node - 1];
    } else {
      start_node = obj_rightChild_data[(int)start_node - 1];
    }
  }
  d = obj_idxDim_data[(int)start_node - 1];
  if (d == 0.0) {
    k = 0;
  } else if (start_node == 1.0) {
    if (1.0 > obj_idxDim_data[0]) {
      k = 0;
    } else {
      k = (int)obj_idxDim_data[0];
    }
    if (0 <= k - 1) {
      memcpy(&node_idx_this_data[0], &obj_idxAll[0], k * sizeof(unsigned int));
    }
  } else {
    vlen = (int)(start_node - 1.0);
    y = obj_idxDim_data[0];
    for (k = 2; k <= vlen; k++) {
      y += obj_idxDim_data[1];
    }
    i = (int)y + (int)d;
    if ((int)y + 1 > i) {
      vlen = 0;
      i = 0;
    } else {
      vlen = (int)y;
    }
    k = i - vlen;
    for (i = 0; i < k; i++) {
      node_idx_this_data[i] = obj_idxAll[vlen + i];
    }
  }
  r.D.size[0] = 0;
  r.b_I.size[0] = 0;
  search_node(X, queryPt, node_idx_this_data, k, &r);
  *pq_D_size = r.D.size[0];
  k = r.D.size[0];
  if (0 <= k - 1) {
    memcpy(&pq_D_data[0], &r.D.data[0], k * sizeof(float));
  }
  *pq_I_size = r.b_I.size[0];
  k = r.b_I.size[0];
  if (0 <= k - 1) {
    memcpy(&pq_I_data[0], &r.b_I.data[0], k * sizeof(unsigned int));
  }
  if (r.D.size[0] != 0) {
    currentNode = queryPt[0] - (float)obj_lowerBounds_data[(int)start_node - 1];
    currentNode *= currentNode;
    lowDist_idx_0 = currentNode;
    pRadIn = queryPt[0] - (float)obj_upperBounds_data[(int)start_node - 1];
    pRadIn *= pRadIn;
    upDist_idx_0 = pRadIn;
    currentNode =
        queryPt[1] -
        (float)
            obj_lowerBounds_data[((int)start_node + obj_lowerBounds_size[0]) -
                                 1];
    currentNode *= currentNode;
    pRadIn =
        queryPt[1] -
        (float)
            obj_upperBounds_data[((int)start_node + obj_upperBounds_size[0]) -
                                 1];
    pRadIn *= pRadIn;
    if ((lowDist_idx_0 > currentNode) ||
        (rtIsNaNF(lowDist_idx_0) && (!rtIsNaNF(currentNode)))) {
      lowDist_idx_0 = currentNode;
    }
    if (lowDist_idx_0 <= r.D.data[0]) {
      ballIsWithinBounds = false;
    } else {
      if ((upDist_idx_0 > pRadIn) ||
          (rtIsNaNF(upDist_idx_0) && (!rtIsNaNF(pRadIn)))) {
        upDist_idx_0 = pRadIn;
      }
      if (upDist_idx_0 <= r.D.data[0]) {
        ballIsWithinBounds = false;
      } else {
        ballIsWithinBounds = true;
      }
    }
  } else {
    ballIsWithinBounds = false;
  }
  if ((r.D.size[0] != 1) || (!ballIsWithinBounds)) {
    nodeStack_size = 1;
    nodeStack_data[0] = 1.0F;
    while (nodeStack_size != 0) {
      currentNode = nodeStack_data[0];
      if (0 <= nodeStack_size - 1) {
        memcpy(&x_data[0], &nodeStack_data[0], nodeStack_size * sizeof(float));
      }
      for (k = 0; k <= nodeStack_size - 2; k++) {
        x_data[k] = x_data[k + 1];
      }
      if (1 > nodeStack_size - 1) {
        k = 0;
      } else {
        k = nodeStack_size - 1;
      }
      nodeStack_size = k;
      if (0 <= k - 1) {
        memcpy(&nodeStack_data[0], &x_data[0], k * sizeof(float));
      }
      lowBounds_data[0] = obj_lowerBounds_data[(int)currentNode - 1];
      upBounds_data[0] = obj_upperBounds_data[(int)currentNode - 1];
      lowBounds_data[1] =
          obj_lowerBounds_data[((int)currentNode + obj_lowerBounds_size[0]) -
                               1];
      upBounds_data[1] =
          obj_upperBounds_data[((int)currentNode + obj_upperBounds_size[0]) -
                               1];
      ballIsWithinBounds = true;
      lowDist_idx_0 = 0.0F;
      vlen = 0;
      exitg1 = false;
      while ((!exitg1) && (vlen < 2)) {
        if (queryPt[vlen] < lowBounds_data[vlen]) {
          pRadIn = queryPt[vlen] - (float)lowBounds_data[vlen];
          lowDist_idx_0 += pRadIn * pRadIn;
        } else if (queryPt[vlen] > upBounds_data[vlen]) {
          pRadIn = queryPt[vlen] - (float)upBounds_data[vlen];
          lowDist_idx_0 += pRadIn * pRadIn;
        }
        if (lowDist_idx_0 > pq_D_data[0]) {
          ballIsWithinBounds = false;
          exitg1 = true;
        } else {
          vlen++;
        }
      }
      if ((*pq_D_size < 1) || ballIsWithinBounds) {
        if (!obj_leafNode_data[(int)currentNode - 1]) {
          if (queryPt[(int)obj_cutDim_data[(int)currentNode - 1] - 1] <=
              obj_cutVal_data[(int)currentNode - 1]) {
            nodeStack_size = k + 2;
            nodeStack_data[0] = (float)obj_leftChild_data[(int)currentNode - 1];
            nodeStack_data[1] =
                (float)obj_rightChild_data[(int)currentNode - 1];
            if (0 <= k - 1) {
              memcpy(&nodeStack_data[2], &x_data[0], k * sizeof(float));
            }
          } else {
            nodeStack_size = k + 2;
            nodeStack_data[0] =
                (float)obj_rightChild_data[(int)currentNode - 1];
            nodeStack_data[1] = (float)obj_leftChild_data[(int)currentNode - 1];
            if (0 <= k - 1) {
              memcpy(&nodeStack_data[2], &x_data[0], k * sizeof(float));
            }
          }
        } else if (currentNode != start_node) {
          d = obj_idxDim_data[(int)currentNode - 1];
          if (d == 0.0) {
            k = 0;
          } else if (currentNode == 1.0F) {
            if (1.0 > obj_idxDim_data[0]) {
              k = 0;
            } else {
              k = (int)obj_idxDim_data[0];
            }
            if (0 <= k - 1) {
              memcpy(&node_idx_this_data[0], &obj_idxAll[0],
                     k * sizeof(unsigned int));
            }
          } else {
            vlen = (int)(currentNode - 1.0F);
            y = obj_idxDim_data[0];
            for (k = 2; k <= vlen; k++) {
              y += obj_idxDim_data[1];
            }
            i = (int)y + (int)d;
            if ((int)y + 1 > i) {
              vlen = 0;
              i = 0;
            } else {
              vlen = (int)y;
            }
            k = i - vlen;
            for (i = 0; i < k; i++) {
              node_idx_this_data[i] = obj_idxAll[vlen + i];
            }
          }
          r.D.size[0] = *pq_D_size;
          if (0 <= *pq_D_size - 1) {
            r.D.data[0] = pq_D_data[0];
          }
          r.b_I.size[0] = *pq_I_size;
          if (0 <= *pq_I_size - 1) {
            r.b_I.data[0] = pq_I_data[0];
          }
          search_node(X, queryPt, node_idx_this_data, k, &r);
          *pq_D_size = r.D.size[0];
          k = r.D.size[0];
          if (0 <= k - 1) {
            memcpy(&pq_D_data[0], &r.D.data[0], k * sizeof(float));
          }
          *pq_I_size = r.b_I.size[0];
          k = r.b_I.size[0];
          if (0 <= k - 1) {
            memcpy(&pq_I_data[0], &r.b_I.data[0], k * sizeof(unsigned int));
          }
        }
      }
    }
  }
}

/*
 * File trailer for kdsearchfun.c
 *
 * [EOF]
 */
