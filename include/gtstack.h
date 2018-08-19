#ifndef GRANDMA_TURNER_GTSTACK_H
#define GRANDMA_TURNER_GTSTACK_H

#ifdef __cplusplus
extern "C" {
#endif

#include "gttypes.h"
typedef struct gtStack GtStack;

GT_API GtStack* gt_stack_create(size_t);
GT_API int gt_stack_push(GtStack*, void*);
GT_API int gt_stack_pop(GtStack*, void**);
GT_API void gt_stack_destroy(GtStack**);


#ifdef __cplusplus
}
#endif

#endif //GRANDMA_TURNER_GTSTACK_H
