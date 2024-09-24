#ifndef VALUE_NODE_H
#define VALUE_NODE_H
#include <stdint.h>

#define new_value_node              (Value_Node*)(malloc(sizeof(Value_Node)))
#define new(x)                      (x*)(malloc(sizeof(x)))
#define new_array(x, n)             (x*)(calloc(n, sizeof(x*)))              

#define DEBUG

typedef struct Value_Node {
    double  data;
    double  grad;
    char    *op;
    struct Value_Node **parents;
    void (*backward_function)(struct Value_Node*);

    #ifdef DEBUG
    char *name;
    #endif

} Value_Node;

extern void init_value_node (Value_Node **node, double data);
#endif