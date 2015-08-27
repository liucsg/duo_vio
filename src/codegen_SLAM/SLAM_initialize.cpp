//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: SLAM_initialize.cpp
//
// MATLAB Coder version            : 2.8
// C/C++ source code generated on  : 27-Aug-2015 21:45:03
//

// Include Files
#include "rt_nonfinite.h"
#include "SLAM.h"
#include "SLAM_initialize.h"
#include "eml_rand_mt19937ar_stateful.h"
#include "SLAM_updIT.h"
#include "SLAM_data.h"
#include <stdio.h>

// Named Constants
#define b_fixFeatures                  (false)
#define b_numStates                    (12.0)
#define b_numTrackFeatures             (16.0)
#define b_numStatesxt                  (13.0)
#define b_minFeatureThreshold          (2.0)

// Variable Definitions
static double numTrackFeatures;

// Function Definitions

//
// Arguments    : void
// Return Type  : void
//
void SLAM_initialize()
{
  static const double b_R_bc[9] = { -0.0077, -0.9999, 0.0101, 0.0087, -0.0101,
    -0.9999, 0.9999, -0.0077, 0.0087 };

  rt_InitInfAndNaN(8U);
  minFeatureThreshold = b_minFeatureThreshold;
  fixFeatures = b_fixFeatures;
  numStatesxt = b_numStatesxt;
  numTrackFeatures = b_numTrackFeatures;
  numStates = b_numStates;
  memcpy(&R_bc[0], &b_R_bc[0], 9U * sizeof(double));
  initialized_not_empty_init();
  SLAM_init();
  SLAM_updIT_init();
  c_eml_rand_mt19937ar_stateful_i();
}

//
// File trailer for SLAM_initialize.cpp
//
// [EOF]
//
