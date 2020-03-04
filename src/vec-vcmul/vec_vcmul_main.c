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
  uint64_t input_data[4] = {0x0000000400000008,0x0000001400000018,0xfffffffeffffffd0,0x0000112200001122};
  uint64_t output_data[4] = {0, 0, 0, 0};
  uint64_t verify_data[4] = {0xffffffd000000040,0xffffff50000003c0,0xfffff704000000c0,0x0000000000001108}; 
  // Do the saxpy
  setStats(1);
  vec_vvadd_asm(input_data, output_data);
  setStats(0);

  // Check the results
  //return verifyFloat(DATA_SIZE, result, verify_data);
  return verifyuint32_t(4, output_data, verify_data);
}
