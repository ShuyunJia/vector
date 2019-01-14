// See LICENSE for license details.

//**************************************************************************
// Vector VVADD benchmark for Hwacha v4
//--------------------------------------------------------------------------
//

#include "util.h"
#include "vec_vvadd.h"

//--------------------------------------------------------------------------
// Input/Reference Data

//#include "dataset1.h"
#define DATA_SIZE 8
float input_data_X[DATA_SIZE] = {561, 209, 74, 637, 959, 469, 585, 70};
float input_data_Y[DATA_SIZE] = {561, 209, 74, 637, 959, 469, 585, 70};

//--------------------------------------------------------------------------
// Main

int main( int argc, char* argv[] )
{
  float result[DATA_SIZE];
  // Do the saxpy
  //setStats(1);
  vec_vvadd_asm(DATA_SIZE, result, input_data_X, input_data_Y);
  setStats(0);

  // Check the results
  //return verifyFloat(DATA_SIZE, result, verify_data);
  return 0;
}
