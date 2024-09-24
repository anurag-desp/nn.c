#include <stdio.h>
#include <stdlib.h>
#include "../inc/value_node.h"

void init_value_node (Value_Node **node, double data) {
    if ((*node) == NULL) {
        (*node) = new(Value_Node);
        if ((*node) == NULL) {
            perror("someting went wrong while initializing a node");
            exit(EXIT_FAILURE);
        }
    }
    (*node)->data = data;
    (*node)->grad = 0;
    (*node)->op = NULL;
    (*node)->backward_function = NULL;
    (*node)->parents = NULL;
}