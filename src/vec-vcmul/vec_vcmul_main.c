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
  uint32_t input_data[4] = {0x00040008,0x00140018,0xfffeffd0,0x11221122};
  uint32_t output_data[4] = {0, 0, 0, 0};
  uint32_t verify_data[4] = {0xffd00040,0xff5003c0,0xf70400c0,0x00001108}; 
  // Do the saxpy
  setStats(1);
  vec_vvadd_asm(input_data, output_data);
  setStats(0);

  // Check the results
  //return verifyFloat(DATA_SIZE, result, verify_data);
  return verifyuint32_t(4, output_data, verify_data);
}
