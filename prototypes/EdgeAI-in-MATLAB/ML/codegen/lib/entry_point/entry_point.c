/*
 * File: entry_point.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 19-Apr-2026 14:57:36
 */

/* Include Files */
#include "entry_point.h"
#include "createkds.h"
#include "entry_point_data.h"
#include "entry_point_initialize.h"
#include "entry_point_internal_types.h"
#include "kdsearchfun.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Type Definitions */
#ifndef enum_c_classreg_learning_coderutils_
#define enum_c_classreg_learning_coderutils_
enum c_classreg_learning_coderutils_
{
  Logit = 0, /* Default value */
  Doublelogit,
  Invlogit,
  Ismax,
  Sign,
  Symmetric,
  Symmetricismax,
  Symmetriclogit,
  Identity
};
#endif /* enum_c_classreg_learning_coderutils_ */
#ifndef typedef_c_classreg_learning_coderutils_
#define typedef_c_classreg_learning_coderutils_
typedef enum c_classreg_learning_coderutils_ c_classreg_learning_coderutils_;
#endif /* typedef_c_classreg_learning_coderutils_ */

#ifndef typedef_ClassificationKNN
#define typedef_ClassificationKNN
typedef struct {
  double OutputPrecision;
  double ClassNames[2];
  int ClassNamesLength[2];
  c_classreg_learning_coderutils_ ScoreTransform;
  double Prior[2];
  boolean_T ClassLogicalIndices[2];
  double Cost[4];
  double X[196];
  unsigned int YIdx[98];
  double W[98];
  double Mu[2];
  double Sigma[2];
} ClassificationKNN;
#endif /* typedef_ClassificationKNN */

/* Variable Definitions */
static boolean_T model_not_empty;

/* Function Declarations */
static float rt_atan2f_snf(float u0, float u1);

static double rt_roundd_snf(double u);

/* Function Definitions */
/*
 * Arguments    : float u0
 *                float u1
 * Return Type  : float
 */
static float rt_atan2f_snf(float u0, float u1)
{
  float y;
  int b_u0;
  int b_u1;
  if (rtIsNaNF(u0) || rtIsNaNF(u1)) {
    y = rtNaNF;
  } else if (rtIsInfF(u0) && rtIsInfF(u1)) {
    if (u0 > 0.0F) {
      b_u0 = 1;
    } else {
      b_u0 = -1;
    }
    if (u1 > 0.0F) {
      b_u1 = 1;
    } else {
      b_u1 = -1;
    }
    y = (float)atan2((float)b_u0, (float)b_u1);
  } else if (u1 == 0.0F) {
    if (u0 > 0.0F) {
      y = RT_PIF / 2.0F;
    } else if (u0 < 0.0F) {
      y = -(RT_PIF / 2.0F);
    } else {
      y = 0.0F;
    }
  } else {
    y = (float)atan2(u0, u1);
  }
  return y;
}

/*
 * Arguments    : double u
 * Return Type  : double
 */
static double rt_roundd_snf(double u)
{
  double y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }
  return y;
}

/*
 * Arguments    : float iq
 *                float id
 * Return Type  : unsigned char
 */
unsigned char entry_point(float iq, float id)
{
  static ClassificationKNN model;
  static const double dv[196] = {
      -0.994047388579142,   0.015024945670808292, -0.94827878459502934,
      -0.94498634787790936, -0.94215601666627413, -0.93809394550021152,
      -0.92466087514634188, -0.936250463144766,   -0.94011627150221588,
      -0.93175176795318992, -0.93532883947483381, -0.951826164568387,
      -0.95550298381352716, -0.96024318276177112, -0.95385004283453978,
      -0.95762721821637486, -0.9621900200885718,  -0.96272478264089723,
      -0.94915108300849182, -0.966647172174906,   -0.96601576131909761,
      -0.96969125559200264, -0.96236790824616747, -0.96221496096726689,
      -0.958963133403405,   -0.96035395794309242, -0.95385004283453978,
      -0.94551151684571311, -0.95483234693113561, -0.94409338001553211,
      -0.96020135181854371, -0.94228245238192376, -0.94215212341872079,
      -0.93277947543810591, -0.95745309391466149, -0.934663693545402,
      -0.92120459722573322, -0.92118317430316521, -0.93485914130675807,
      -0.93990854182635863, -0.93920148123088643, -0.95396355754902884,
      -0.93342657823337227, -0.93834402726990906, -0.97773342646699235,
      -0.96018788697663537, -0.96865188759393261, -0.9359457388057324,
      -0.9610657341928186,  -2.2710655595205869,  0.99471505749271516,
      1.003867997982824,    0.99769779406896542,  0.897475550865104,
      0.89843435962644957,  1.0392174973034918,   1.226037165425536,
      1.0456194529441984,   1.2248980838442598,   1.2953842075855653,
      1.0046715910758053,   0.99218621964299947,  0.9175413038813629,
      0.97269271133193858,  1.0379159164167093,   1.0390730229982919,
      0.98822851324369931,  0.70183092853257079,  1.3746276946669607,
      1.0094113341323288,   1.0065137128352242,   1.0824974296051588,
      1.0078214513990653,   0.91243582500641063,  0.90985526825367924,
      1.0116797279540606,   1.0700970829576113,   0.94245595129641935,
      1.0111869457759632,   0.89894008022111027,  1.0870931976708584,
      1.042135795778846,    0.68372317504378866,  1.0658023781424273,
      1.0859474287052902,   1.0843120154379688,   0.87257794956715273,
      1.2595456332846215,   0.9693666492319033,   0.88926833631294477,
      0.76631704964797975,  0.907004234341948,    1.0441629152025946,
      0.79062604767998157,  0.97728454022542577,  0.941210922225175,
      0.9014254230266574,   0.96176262210180452,  -0.53391892010885911,
      -0.17916895243703626, -1.2862952722629541,  -1.063106416964569,
      -0.87941895890638488, -0.76937340045684044, -0.79724296945685347,
      -0.82149311670256064, -0.78356099209612773, -0.69384935688813787,
      -0.67821812536364645, -0.65623702955163676, -0.59915394288037294,
      -0.53786673799772589, -0.52686597862192908, -0.62155867426509515,
      -0.80846733979537633, -0.29538108768186594, -1.1863436571720811,
      -1.2878293944356936,  -1.2925720853924905,  -0.37876673914353148,
      -1.1085049673196676,  -1.2745975423524012,  -1.2436349958712458,
      -1.1482369670061188,  -1.2959088062907691,  -1.3088610499673907,
      -1.3018726205130751,  -1.1012247695237809,  -0.98854326915600921,
      -0.78501169199250231, -0.809860576116525,   -1.2852122405292816,
      -1.2807573858311598,  -1.2763500683095714,  -1.3175636461913052,
      -1.273637131426923,   -1.245954815152805,   -1.0375797315916859,
      -1.1256454441297736,  -1.0117231378193643,  -0.928388185271235,
      -0.83796210301921692, -0.87558518430025845, -0.93819887541138181,
      -1.2925916404352691,  -1.2897742447706186,  -1.3123723396016385,
      0.94554083655209009,  0.948976521231673,    0.84117583281627484,
      0.91956774384455109,  0.963977865549412,    0.96571320388012738,
      0.92404486299127331,  0.98844005253724976,  1.0158852255056352,
      0.95361250055660352,  0.95661007811204668,  0.95484905863994984,
      0.9611858962201586,   0.97902117180175319,  0.952435859539941,
      0.96946753971856592,  0.9559384067237936,   0.93068062234462268,
      0.92751244569904567,  0.91066824215094622,  0.85836803538039075,
      0.952386600323172,    1.0090426624108884,   0.81254412288024813,
      1.0284711043101873,   1.0891679829564493,   0.80502646199005656,
      1.5333210003321811,   1.3294994538349429,   0.883839731538191,
      1.0339171127490576,   0.954197039624843,    0.98507442983424531,
      0.945599503939135,    1.0909506118005103,   0.932040800684277,
      1.0585597893412928,   0.7800448912100949,   0.92985964089346462,
      0.89994204234731789,  1.0052793105297806,   0.97186638783357793,
      0.96648850571214906,  0.95117641482966919,  0.9567929280035844,
      0.987667715012267,    0.76908774172450256,  1.148518411355369,
      0.73820817868525712};
  static const signed char iv[98] = {
      1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
      1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2,
      2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
      2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
  struct_T expl_temp;
  double count_idx_0;
  double count_idx_1;
  double posteriors_idx_0;
  double wgt;
  float b_expl_temp[196];
  float inputData[2];
  float distTemp_data;
  unsigned int CNeighbor;
  int distTemp_size;
  int i;
  int idx_data;
  int loop_ub;
  int nanUpLim;
  unsigned char label;
  signed char vecToRep_data;
  boolean_T x_data[98];
  boolean_T b[2];
  boolean_T exitg1;
  boolean_T wasNaNY;
  if (!isInitialized_entry_point) {
    entry_point_initialize();
  }
  inputData[0] = (float)sqrt(iq * iq + id * id);
  inputData[1] = rt_atan2f_snf(iq, id);
  if (!model_not_empty) {
    model.OutputPrecision = 1.0;
    model.ClassNames[0] = 0.0;
    model.ClassNamesLength[0] = 1;
    model.ClassLogicalIndices[0] = true;
    model.ClassNames[1] = 1.0;
    model.ClassNamesLength[1] = 1;
    model.ClassLogicalIndices[1] = true;
    model.ScoreTransform = Identity;
    memcpy(&model.X[0], &dv[0], 196U * sizeof(double));
    for (i = 0; i < 98; i++) {
      model.YIdx[i] = (unsigned int)iv[i];
      model.W[i] = 0.01020408163265306;
    }
    model.Mu[0] = 0.78980989833039006;
    model.Sigma[0] = 0.7871369436530925;
    model.Prior[0] = 0.5;
    model.Mu[1] = 0.9220937177554156;
    model.Sigma[1] = 0.67610232108499146;
    model.Prior[1] = 0.5;
    model.Cost[0] = 0.0;
    model.Cost[1] = 1.0;
    model.Cost[2] = 1.0;
    model.Cost[3] = 0.0;
    model_not_empty = true;
  }
  inputData[0] = (inputData[0] - (float)model.Mu[0]) / (float)model.Sigma[0];
  count_idx_0 = 0.0;
  inputData[1] = (inputData[1] - (float)model.Mu[1]) / (float)model.Sigma[1];
  count_idx_1 = 0.0;
  createkds(model.X, &expl_temp);
  x_data[0] = rtIsNaNF(inputData[0]);
  x_data[1] = rtIsNaNF(inputData[1]);
  wasNaNY = false;
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i <= 1)) {
    if (!x_data[i]) {
      i++;
    } else {
      wasNaNY = true;
      exitg1 = true;
    }
  }
  if ((1.0 < expl_temp.nx_nonan) || rtIsNaN(expl_temp.nx_nonan)) {
    wgt = 1.0;
  } else {
    wgt = expl_temp.nx_nonan;
  }
  if ((int)wgt > 0) {
    if (wasNaNY) {
      distTemp_data = rtNaNF;
      idx_data = 1;
    } else {
      for (i = 0; i < 196; i++) {
        b_expl_temp[i] = (float)expl_temp.X[i];
      }
      search_kdtree(expl_temp.cutDim.data, expl_temp.cutVal.data,
                    expl_temp.lowerBounds.data, expl_temp.lowerBounds.size,
                    expl_temp.upperBounds.data, expl_temp.upperBounds.size,
                    expl_temp.leftChild.data, expl_temp.rightChild.data,
                    expl_temp.leafNode.data, expl_temp.idxAll,
                    expl_temp.idxDim.data, b_expl_temp, inputData,
                    (float *)&distTemp_data, &distTemp_size,
                    (unsigned int *)&CNeighbor, &i);
      for (i = 0; i < distTemp_size; i++) {
        distTemp_data = (float)sqrt(distTemp_data);
      }
      if (CNeighbor > 2147483647U) {
        CNeighbor = 2147483647U;
      }
      idx_data = (int)CNeighbor;
    }
  }
  if (1 - (int)wgt > 0) {
    idx_data = expl_temp.wasnanIdx.data[0];
    if (!wasNaNY) {
      nanUpLim = wasNaNY;
    } else {
      nanUpLim = 1;
    }
    if (wasNaNY) {
      if ((int)wgt + 1 > 1) {
        i = 0;
        distTemp_size = 0;
      } else {
        i = (int)wgt;
        distTemp_size = 1;
      }
      loop_ub = distTemp_size - i;
      for (distTemp_size = 0; distTemp_size < loop_ub; distTemp_size++) {
        vecToRep_data = (signed char)((signed char)(i + distTemp_size) + 1);
      }
      distTemp_size = (signed char)loop_ub;
      if (0 <= distTemp_size - 1) {
        for (i = 0; i < nanUpLim; i++) {
          idx_data = vecToRep_data;
        }
      }
    }
    if ((int)wgt + 1 > 1) {
      loop_ub = -1;
    } else {
      loop_ub = 0;
    }
    for (i = 0; i <= loop_ub; i++) {
      distTemp_data = rtNaNF;
    }
  }
  if (!rtIsNaNF(distTemp_data)) {
    vecToRep_data = 1;
    if (rtIsNaNF(distTemp_data)) {
      vecToRep_data = 0;
    }
    CNeighbor = model.YIdx[idx_data - 1];
    wgt = (double)vecToRep_data * 0.01020408163265306;
    if (CNeighbor == 1U) {
      count_idx_0 = wgt;
    }
    if (CNeighbor == 2U) {
      count_idx_1 = wgt;
    }
  }
  wgt = count_idx_0 + count_idx_1;
  count_idx_0 /= wgt;
  posteriors_idx_0 = count_idx_0;
  b[0] = rtIsNaN(count_idx_0);
  count_idx_0 = count_idx_1 / wgt;
  b[1] = rtIsNaN(count_idx_0);
  wasNaNY = true;
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i < 2)) {
    if (!b[i]) {
      wasNaNY = false;
      exitg1 = true;
    } else {
      i++;
    }
  }
  count_idx_1 = posteriors_idx_0 * model.Cost[0] + count_idx_0 * model.Cost[1];
  wgt = posteriors_idx_0 * model.Cost[2] + count_idx_0 * model.Cost[3];
  count_idx_0 = model.ClassNames[model.Prior[0] < model.Prior[1]];
  if (!wasNaNY) {
    if ((count_idx_1 > wgt) || (rtIsNaN(count_idx_1) && (!rtIsNaN(wgt)))) {
      i = 2;
    } else {
      i = 1;
    }
    count_idx_0 = model.ClassNames[i - 1];
  }
  wgt = rt_roundd_snf(count_idx_0);
  if (wgt < 256.0) {
    if (wgt >= 0.0) {
      label = (unsigned char)wgt;
    } else {
      label = 0U;
    }
  } else if (wgt >= 256.0) {
    label = MAX_uint8_T;
  } else {
    label = 0U;
  }
  return label;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void entry_point_init(void)
{
  model_not_empty = false;
}

/*
 * File trailer for entry_point.c
 *
 * [EOF]
 */
