#include <stdlib.h>
#include "../include/gtstack.h"

typedef struct gtStack {
  size_t max;
  int index;
  // ?
  void **elems;
} GtStack;

GtStack* gt_stack_create(size_t max) {
  GtStack * out = (GtStack *) malloc(sizeof(GtStack));
  if (!out) {
    exit(GT_ERROR_OUTMEM);
  }

  if (max <= 0) {
    max = 16;
  }
  out->elems = (void**) calloc(max, sizeof(void*));
  if (!out->elems) {
    exit(GT_ERROR_OUTMEM);
  }

  out->max = max;
  out->index = 0;
  return out;
}

int gt_stack_push(GtStack* in, void* data) {
  if (in->index >= in->max) {
    return GT_ERROR_FULL;
  }

  // elems 是一个数组指针
  // 存放的是指向 data 的指针
  in->elems[in->index++] = data;
  return GT_OK;
}

/**
 *
 * @param in
 * @param data 传入想要用于存放 指向data指针(*data), 的地址(**data)
 * @return
 */
int gt_stack_pop(GtStack* in, void** data) {
  if (in->index <= 0) {
    return GT_ERROR_EMPTY;
  }

  *data = in->elems[--in->index];
  return GT_OK;
}

void gt_stack_destroy(GtStack** in) {
  if (*in) {
    GtStack *stack = *in;
    free(stack->elems);
    free(stack);
    *in = NULL;
    // 此时 in 地址还是存在的, 但是指向的是 NULL
  }
}

