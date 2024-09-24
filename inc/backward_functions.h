#ifndef BACKWARD_FUNCTIONS_H
#define BACKWARD_FUNCTIONS_H

#include "value_node.h"

extern void add_backward(Value_Node *node);
extern void sub_backward(Value_Node *node);
extern void mul_backward(Value_Node *node);
extern void div_backward(Value_Node *node);
extern void ReLU_backward(Value_Node *node);
extern void log2_backward(Value_Node *node);
extern void log10_backward(Value_Node *node);
extern void log_backward(Value_Node *node);
extern void backward(Value_Node *kinda_root);

#endif