#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#define OPERAND_LENGTH 32 // 32 bits (simple 4-byte unsigned int)

unsigned int a = 123;
unsigned int b = 498;
unsigned int r = 0;
unsigned int a_bin[OPERAND_LENGTH] = {};
unsigned int b_bin[OPERAND_LENGTH] = {};
unsigned int res = 0;
unsigned int res_parts[OPERAND_LENGTH]; // len of array must be same with len of operands
unsigned int res_len = 4 + (4-1); // 7

int main(void){
  r = a * b; // reference result
  
  printf("\nPartial Calculation\n");
  for(int i = 0; i < OPERAND_LENGTH; i++){
    b_bin[i] = (b & (0x1 << i)) >> i;
    printf("[%d]: %d\n", i, b_bin[i]);
    res_parts[i] = b_bin[i] ? a : 0;
    printf("[%d] : %d * %d = %d\n", i,a,b_bin[i], res_parts[i]);
    res_parts[i] = res_parts[i] << i;
    printf("[%d]': %d * %d = %d\n\n", i,a,b_bin[i], res_parts[i]);
  }
  
  printf("\nPartial Addition\n");
  for(int i = 0; i < OPERAND_LENGTH; i++)
    res += res_parts[i];
  
  printf("Final result: %d\n", res);
  printf("Reference result: %d\n", r);
  assert(res == r);
  printf("PASS\n");
  
  return 0;
}
