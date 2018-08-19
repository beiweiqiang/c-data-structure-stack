#include <stdio.h>
#include <stdlib.h>
#include "include/gtstack.h"

int main() {
  GtStack *stack = gt_stack_create(10);

  gt_stack_push(stack, "he an qi");
  gt_stack_push(stack, "he an");
  gt_stack_push(stack, "he qi");

  char *p;
  int err;

  // 这里要对 &p 进行强制转换
  while ((err = gt_stack_pop(stack, (void **) &p)) == GT_OK) {
    printf("%s \n", p);
  }
  gt_stack_destroy(&stack);

  return 0;
}