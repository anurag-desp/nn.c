#include <stdlib.h>
#include <stdlib.h>
#include "../inc/forward_functions.h"
#include "../inc/backward_functions.h"

#ifndef max
#define max(a, b)       (a > b)? a: b
#endif

static Value_Node* forward_add(Value_Node *node_a, Value_Node *node_b) {
    Value_Node *node_c = new(Value_Node);
    init_value_node(&node_c, 0);

    node_c->data = node_a->data + node_b->data;
    node_c->op = "+";
    node_c->parents = new_array(Value_Node*, 2);
    node_c->parents[0] = node_a;
    node_c->parents[1] = node_b;
    node_c->backward_function = add_backward;

    return node_c;
}

static Value_Node* forward_sub(Value_Node *node_a, Value_Node *node_b) {
    Value_Node *node_c = new(Value_Node);
    init_value_node(&node_c, 0);

    node_c->data = node_a->data - node_b->data;
    node_c->op = "-";
    node_c->parents = new_array(Value_Node*, 2);
    node_c->parents[0] = node_a;
    node_c->parents[1] = node_b;
    node_c->backward_function = sub_backward;

    return node_c;
}

static Value_Node* forward_mul(Value_Node *node_a, Value_Node *node_b) {
    Value_Node *node_c = new(Value_Node);
    init_value_node(&node_c, 0);

    node_c->data = node_a->data * node_b->data;
    node_c->op = "*";
    node_c->parents = new_array(Value_Node*, 2);
    node_c->parents[0] = node_a;
    node_c->parents[1] = node_b;
    node_c->backward_function = mul_backward;

    return node_c;
}

static Value_Node* forward_div(Value_Node *node_a, Value_Node *node_b) {
    Value_Node *node_c = new(Value_Node);
    init_value_node(&node_c, 0);

    node_c->data = node_a->data / node_b->data;
    node_c->op = "-";
    node_c->parents = new_array(Value_Node*, 2);
    node_c->parents[0] = node_a;
    node_c->parents[1] = node_b;
    node_c->backward_function = div_backward;

    return node_c;
}

static Value_Node* forward_ReLU(Value_Node *node) {
    Value_Node *node_c = new(Value_Node);
    init_value_node(&node_c, 0);

    node_c->data = max(node->data, 0);
    node_c->op = "ReLU";
    node_c->parents = new_array(Value_Node*, 1);
    node_c->parents[0] = node;
    node_c->backward_function = ReLU_backward;

    return node_c;
}

static Value_Node* forward_log2(Value_Node *node) {
    Value_Node *node_c = new(Value_Node);
    init_value_node(&node_c, 0);

    node_c->data = log2(node->data);
    node_c->op = "log2";
    node_c->parents = new_array(Value_Node*, 2);
    node_c->parents[0] = node;
    node_c->parents[1] = NULL;
    node_c->backward_function = log2_backward;

    return node_c;
}

static Value_Node* forward_log10(Value_Node *node) {
    Value_Node *node_c = new(Value_Node);
    init_value_node(&node_c, 0);

    node_c->data = log10(node->data);
    node_c->op = "log10";
    node_c->parents = new_array(Value_Node*, 2);
    node_c->parents[0] = node;
    node_c->parents[1] = NULL;
    node_c->backward_function = log10_backward;

    return node_c;
}

static Value_Node* forward_log(Value_Node *node) {
    Value_Node *node_c = new(Value_Node);
    init_value_node(&node_c, 0);

    node_c->data = log(node->data);
    node_c->op = "log";
    node_c->parents = new_array(Value_Node*, 2);
    node_c->parents[0] = node;
    node_c->parents[1] = NULL;
    node_c->backward_function = log_backward;

    return node_c;
}

Forward_Function Functions = {
    forward_add,
    forward_sub,
    forward_mul,
    forward_div,
    forward_ReLU,
    forward_log2,
    forward_log10,
    forward_log,
};
