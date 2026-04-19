/*
 * File: sort.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 19-Apr-2026 14:57:36
 */

/* Include Files */
#include "sort.h"
#include "rt_nonfinite.h"
#include "sortIdx.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : float x_data[]
 *                const int *x_size
 *                int idx_data[]
 *                int *idx_size
 * Return Type  : void
 */
void b_sort(float x_data[], const int *x_size, int idx_data[], int *idx_size)
{
  float b_xwork_data[98];
  float vwork_data[98];
  float xwork_data[98];
  float x4[4];
  float f;
  float f1;
  int b_iwork_data[98];
  int iidx_data[98];
  int iwork_data[98];
  int dim;
  int i1;
  int i2;
  int i3;
  int i4;
  int j;
  int k;
  int loop_ub_tmp;
  int nNaNs;
  int vlen;
  int vstride;
  int vwork_size;
  signed char idx4[4];
  signed char perm[4];
  dim = 0;
  if (*x_size != 1) {
    dim = -1;
  }
  if (dim + 2 <= 1) {
    vwork_size = *x_size;
  } else {
    vwork_size = 1;
  }
  vlen = vwork_size - 1;
  *idx_size = *x_size;
  vstride = 1;
  for (k = 0; k <= dim; k++) {
    vstride *= *x_size;
  }
  for (j = 0; j < vstride; j++) {
    for (k = 0; k <= vlen; k++) {
      vwork_data[k] = x_data[j + k * vstride];
    }
    loop_ub_tmp = (signed char)vwork_size;
    if (0 <= loop_ub_tmp - 1) {
      memset(&iidx_data[0], 0, loop_ub_tmp * sizeof(int));
    }
    if (vwork_size != 0) {
      x4[0] = 0.0F;
      idx4[0] = 0;
      x4[1] = 0.0F;
      idx4[1] = 0;
      x4[2] = 0.0F;
      idx4[2] = 0;
      x4[3] = 0.0F;
      idx4[3] = 0;
      if (0 <= loop_ub_tmp - 1) {
        memset(&iwork_data[0], 0, loop_ub_tmp * sizeof(int));
      }
      if (0 <= vwork_size - 1) {
        memset(&xwork_data[0], 0, vwork_size * sizeof(float));
      }
      nNaNs = 0;
      dim = -1;
      for (k = 0; k < vwork_size; k++) {
        if (rtIsNaNF(vwork_data[k])) {
          i3 = (vwork_size - nNaNs) - 1;
          iidx_data[i3] = k + 1;
          xwork_data[i3] = vwork_data[k];
          nNaNs++;
        } else {
          dim++;
          idx4[dim] = (signed char)(k + 1);
          x4[dim] = vwork_data[k];
          if (dim + 1 == 4) {
            dim = k - nNaNs;
            if (x4[0] <= x4[1]) {
              i1 = 1;
              i2 = 2;
            } else {
              i1 = 2;
              i2 = 1;
            }
            if (x4[2] <= x4[3]) {
              i3 = 3;
              i4 = 4;
            } else {
              i3 = 4;
              i4 = 3;
            }
            f = x4[i1 - 1];
            f1 = x4[i3 - 1];
            if (f <= f1) {
              f = x4[i2 - 1];
              if (f <= f1) {
                perm[0] = (signed char)i1;
                perm[1] = (signed char)i2;
                perm[2] = (signed char)i3;
                perm[3] = (signed char)i4;
              } else if (f <= x4[i4 - 1]) {
                perm[0] = (signed char)i1;
                perm[1] = (signed char)i3;
                perm[2] = (signed char)i2;
                perm[3] = (signed char)i4;
              } else {
                perm[0] = (signed char)i1;
                perm[1] = (signed char)i3;
                perm[2] = (signed char)i4;
                perm[3] = (signed char)i2;
              }
            } else {
              f1 = x4[i4 - 1];
              if (f <= f1) {
                if (x4[i2 - 1] <= f1) {
                  perm[0] = (signed char)i3;
                  perm[1] = (signed char)i1;
                  perm[2] = (signed char)i2;
                  perm[3] = (signed char)i4;
                } else {
                  perm[0] = (signed char)i3;
                  perm[1] = (signed char)i1;
                  perm[2] = (signed char)i4;
                  perm[3] = (signed char)i2;
                }
              } else {
                perm[0] = (signed char)i3;
                perm[1] = (signed char)i4;
                perm[2] = (signed char)i1;
                perm[3] = (signed char)i2;
              }
            }
            iidx_data[dim - 3] = idx4[perm[0] - 1];
            iidx_data[dim - 2] = idx4[perm[1] - 1];
            iidx_data[dim - 1] = idx4[perm[2] - 1];
            iidx_data[dim] = idx4[perm[3] - 1];
            vwork_data[dim - 3] = x4[perm[0] - 1];
            vwork_data[dim - 2] = x4[perm[1] - 1];
            vwork_data[dim - 1] = x4[perm[2] - 1];
            vwork_data[dim] = x4[perm[3] - 1];
            dim = -1;
          }
        }
      }
      i4 = (vwork_size - nNaNs) - 1;
      if (dim + 1 > 0) {
        perm[1] = 0;
        perm[2] = 0;
        perm[3] = 0;
        if (dim + 1 == 1) {
          perm[0] = 1;
        } else if (dim + 1 == 2) {
          if (x4[0] <= x4[1]) {
            perm[0] = 1;
            perm[1] = 2;
          } else {
            perm[0] = 2;
            perm[1] = 1;
          }
        } else if (x4[0] <= x4[1]) {
          if (x4[1] <= x4[2]) {
            perm[0] = 1;
            perm[1] = 2;
            perm[2] = 3;
          } else if (x4[0] <= x4[2]) {
            perm[0] = 1;
            perm[1] = 3;
            perm[2] = 2;
          } else {
            perm[0] = 3;
            perm[1] = 1;
            perm[2] = 2;
          }
        } else if (x4[0] <= x4[2]) {
          perm[0] = 2;
          perm[1] = 1;
          perm[2] = 3;
        } else if (x4[1] <= x4[2]) {
          perm[0] = 2;
          perm[1] = 3;
          perm[2] = 1;
        } else {
          perm[0] = 3;
          perm[1] = 2;
          perm[2] = 1;
        }
        for (k = 0; k <= dim; k++) {
          i3 = perm[k] - 1;
          i1 = (i4 - dim) + k;
          iidx_data[i1] = idx4[i3];
          vwork_data[i1] = x4[i3];
        }
      }
      dim = (nNaNs >> 1) + 1;
      for (k = 0; k <= dim - 2; k++) {
        i1 = (i4 + k) + 1;
        i2 = iidx_data[i1];
        i3 = (vwork_size - k) - 1;
        iidx_data[i1] = iidx_data[i3];
        iidx_data[i3] = i2;
        vwork_data[i1] = xwork_data[i3];
        vwork_data[i3] = xwork_data[i1];
      }
      if ((nNaNs & 1) != 0) {
        dim += i4;
        vwork_data[dim] = xwork_data[dim];
      }
      i2 = vwork_size - nNaNs;
      if (i2 > 1) {
        i4 = i2 >> 2;
        i3 = 4;
        while (i4 > 1) {
          if ((i4 & 1) != 0) {
            i4--;
            dim = i3 * i4;
            i1 = i2 - dim;
            if (i1 > i3) {
              b_merge(iidx_data, vwork_data, dim, i3, i1 - i3, iwork_data,
                      xwork_data);
            }
          }
          dim = i3 << 1;
          i4 >>= 1;
          for (k = 0; k < i4; k++) {
            b_merge(iidx_data, vwork_data, k * dim, i3, i3, iwork_data,
                    xwork_data);
          }
          i3 = dim;
        }
        if (i2 > i3) {
          if (0 <= loop_ub_tmp - 1) {
            memcpy(&b_iwork_data[0], &iwork_data[0], loop_ub_tmp * sizeof(int));
          }
          if (0 <= vwork_size - 1) {
            memcpy(&b_xwork_data[0], &xwork_data[0],
                   vwork_size * sizeof(float));
          }
          b_merge(iidx_data, vwork_data, 0, i3, i2 - i3, b_iwork_data,
                  b_xwork_data);
        }
      }
    }
    for (k = 0; k <= vlen; k++) {
      dim = j + k * vstride;
      x_data[dim] = vwork_data[k];
      idx_data[dim] = iidx_data[k];
    }
  }
}

/*
 * Arguments    : double x_data[]
 *                const int *x_size
 *                int idx_data[]
 *                int *idx_size
 * Return Type  : void
 */
void sort(double x_data[], const int *x_size, int idx_data[], int *idx_size)
{
  double b_xwork_data[98];
  double vwork_data[98];
  double xwork_data[98];
  double x4[4];
  double d;
  double d1;
  int b_iwork_data[98];
  int iidx_data[98];
  int iwork_data[98];
  int dim;
  int i2;
  int i3;
  int i4;
  int j;
  int k;
  int loop_ub_tmp;
  int vlen;
  int vstride;
  int vwork_size;
  signed char idx4[4];
  signed char perm[4];
  dim = 0;
  if (*x_size != 1) {
    dim = -1;
  }
  if (dim + 2 <= 1) {
    vwork_size = *x_size;
  } else {
    vwork_size = 1;
  }
  vlen = vwork_size - 1;
  *idx_size = *x_size;
  vstride = 1;
  for (k = 0; k <= dim; k++) {
    vstride *= *x_size;
  }
  for (j = 0; j < vstride; j++) {
    for (k = 0; k <= vlen; k++) {
      vwork_data[k] = x_data[j + k * vstride];
    }
    loop_ub_tmp = (signed char)vwork_size;
    if (0 <= loop_ub_tmp - 1) {
      memset(&iidx_data[0], 0, loop_ub_tmp * sizeof(int));
    }
    if (vwork_size != 0) {
      x4[0] = 0.0;
      idx4[0] = 0;
      x4[1] = 0.0;
      idx4[1] = 0;
      x4[2] = 0.0;
      idx4[2] = 0;
      x4[3] = 0.0;
      idx4[3] = 0;
      if (0 <= loop_ub_tmp - 1) {
        memset(&iwork_data[0], 0, loop_ub_tmp * sizeof(int));
      }
      dim = 0;
      for (k = 0; k < vwork_size; k++) {
        xwork_data[k] = 0.0;
        dim++;
        idx4[dim - 1] = (signed char)(k + 1);
        x4[dim - 1] = vwork_data[k];
        if (dim == 4) {
          if (x4[0] <= x4[1]) {
            dim = 1;
            i2 = 2;
          } else {
            dim = 2;
            i2 = 1;
          }
          if (x4[2] <= x4[3]) {
            i3 = 3;
            i4 = 4;
          } else {
            i3 = 4;
            i4 = 3;
          }
          d = x4[dim - 1];
          d1 = x4[i3 - 1];
          if (d <= d1) {
            d = x4[i2 - 1];
            if (d <= d1) {
              perm[0] = (signed char)dim;
              perm[1] = (signed char)i2;
              perm[2] = (signed char)i3;
              perm[3] = (signed char)i4;
            } else if (d <= x4[i4 - 1]) {
              perm[0] = (signed char)dim;
              perm[1] = (signed char)i3;
              perm[2] = (signed char)i2;
              perm[3] = (signed char)i4;
            } else {
              perm[0] = (signed char)dim;
              perm[1] = (signed char)i3;
              perm[2] = (signed char)i4;
              perm[3] = (signed char)i2;
            }
          } else {
            d1 = x4[i4 - 1];
            if (d <= d1) {
              if (x4[i2 - 1] <= d1) {
                perm[0] = (signed char)i3;
                perm[1] = (signed char)dim;
                perm[2] = (signed char)i2;
                perm[3] = (signed char)i4;
              } else {
                perm[0] = (signed char)i3;
                perm[1] = (signed char)dim;
                perm[2] = (signed char)i4;
                perm[3] = (signed char)i2;
              }
            } else {
              perm[0] = (signed char)i3;
              perm[1] = (signed char)i4;
              perm[2] = (signed char)dim;
              perm[3] = (signed char)i2;
            }
          }
          iidx_data[k - 3] = idx4[perm[0] - 1];
          iidx_data[k - 2] = idx4[perm[1] - 1];
          iidx_data[k - 1] = idx4[perm[2] - 1];
          iidx_data[k] = idx4[perm[3] - 1];
          vwork_data[k - 3] = x4[perm[0] - 1];
          vwork_data[k - 2] = x4[perm[1] - 1];
          vwork_data[k - 1] = x4[perm[2] - 1];
          vwork_data[k] = x4[perm[3] - 1];
          dim = 0;
        }
      }
      if (dim > 0) {
        perm[1] = 0;
        perm[2] = 0;
        perm[3] = 0;
        if (dim == 1) {
          perm[0] = 1;
        } else if (dim == 2) {
          if (x4[0] <= x4[1]) {
            perm[0] = 1;
            perm[1] = 2;
          } else {
            perm[0] = 2;
            perm[1] = 1;
          }
        } else if (x4[0] <= x4[1]) {
          if (x4[1] <= x4[2]) {
            perm[0] = 1;
            perm[1] = 2;
            perm[2] = 3;
          } else if (x4[0] <= x4[2]) {
            perm[0] = 1;
            perm[1] = 3;
            perm[2] = 2;
          } else {
            perm[0] = 3;
            perm[1] = 1;
            perm[2] = 2;
          }
        } else if (x4[0] <= x4[2]) {
          perm[0] = 2;
          perm[1] = 1;
          perm[2] = 3;
        } else if (x4[1] <= x4[2]) {
          perm[0] = 2;
          perm[1] = 3;
          perm[2] = 1;
        } else {
          perm[0] = 3;
          perm[1] = 2;
          perm[2] = 1;
        }
        for (k = 0; k < dim; k++) {
          i3 = perm[k] - 1;
          i2 = (vwork_size - dim) + k;
          iidx_data[i2] = idx4[i3];
          vwork_data[i2] = x4[i3];
        }
      }
      if (vwork_size > 1) {
        i4 = vwork_size >> 2;
        i2 = 4;
        while (i4 > 1) {
          if ((i4 & 1) != 0) {
            i4--;
            dim = i2 * i4;
            i3 = vwork_size - dim;
            if (i3 > i2) {
              merge(iidx_data, vwork_data, dim, i2, i3 - i2, iwork_data,
                    xwork_data);
            }
          }
          dim = i2 << 1;
          i4 >>= 1;
          for (k = 0; k < i4; k++) {
            merge(iidx_data, vwork_data, k * dim, i2, i2, iwork_data,
                  xwork_data);
          }
          i2 = dim;
        }
        if (vwork_size > i2) {
          if (0 <= loop_ub_tmp - 1) {
            memcpy(&b_iwork_data[0], &iwork_data[0], loop_ub_tmp * sizeof(int));
          }
          if (0 <= vwork_size - 1) {
            memcpy(&b_xwork_data[0], &xwork_data[0],
                   vwork_size * sizeof(double));
          }
          merge(iidx_data, vwork_data, 0, i2, vwork_size - i2, b_iwork_data,
                b_xwork_data);
        }
      }
    }
    for (k = 0; k <= vlen; k++) {
      dim = j + k * vstride;
      x_data[dim] = vwork_data[k];
      idx_data[dim] = iidx_data[k];
    }
  }
}

/*
 * File trailer for sort.c
 *
 * [EOF]
 */
