#ifndef FORWARD_FUNCTION_H
#define FORWARD_FUNCTION_H
#include <math.h>
#include "value_node.h"

typedef struct {
    struct Value_Node* (*add)(struct Value_Node*, struct Value_Node*);
    struct Value_Node* (*sub)(struct Value_Node*, struct Value_Node*);
    struct Value_Node* (*mul)(struct Value_Node*, struct Value_Node*);
    struct Value_Node* (*div)(struct Value_Node*, struct Value_Node*);
    struct Value_Node* (*ReLU)(struct Value_Node*);
    struct Value_Node* (*log2)(struct Value_Node*);
    struct Value_Node* (*log10)(struct Value_Node*);
    struct Value_Node* (*log)(struct Value_Node*);
} Forward_Function;

extern Forward_Function Functions;
// extern Value_Node* forward_add(Value_Node *node_a, Value_Node *node_b);
// extern Value_Node* forward_sub(Value_Node *node_a, Value_Node *node_b);
// extern Value_Node* forward_mul(Value_Node *node_a, Value_Node *node_b);
// extern Value_Node* forward_div(Value_Node *node_a, Value_Node *node_b);

#endif