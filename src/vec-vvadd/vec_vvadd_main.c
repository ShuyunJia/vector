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
#define DATA_SIZE 4 
//--------------------------------------------------------------------------
// Main

int main( int argc, char* argv[] )
{
  int input_data_X[DATA_SIZE] ;
  int input_data_Y[DATA_SIZE];
  int result[DATA_SIZE];
  // Do the saxpy
  for(int i =0; i<DATA_SIZE ; i++){
    input_data_X[i] = -(i + 0x100);
    input_data_Y[i] = 0x101;
  }
  setStats(1);
  vec_vvadd_asm(DATA_SIZE, result, input_data_X, input_data_Y);
  setStats(0);
  printf("data   = %d %d %d %d\n", input_data_X[0], input_data_X[1], input_data_X[2], input_data_X[3]);
  printf("result = %d %d %d %d\n", result[0], result[1], result[2], result[3]);
  printf("hello wolrd test\n");

  // Check the results
  //return verifyFloat(DATA_SIZE, result, verify_data);
  //while(1);
  return 0;
}
