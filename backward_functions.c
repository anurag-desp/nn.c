#include "backward_functions.h"
#include <math.h>

void add_backward(Value_Node *node) {
    if (!node) return;
    if (!(node->parents)) return;

    node->parents[0]->grad += node->grad;
    node->parents[1]->grad += node->grad;
}

void sub_backward(Value_Node *node) {
    if (!node) return;
    if (!(node->parents)) return;

    node->parents[0]->grad += node->grad;
    node->parents[1]->grad += -(node->grad);
}

void mul_backward(Value_Node *node) {
    if (!node) return;
    if (!(node->parents)) return;

    node->parents[0]->grad += node->parents[1]->data * node->grad;
    node->parents[1]->grad += node->parents[0]->data * node->grad;
}

void div_backward(Value_Node *node) {
    if (!node) return;
    if (!(node->parents)) return;

    node->parents[0]->grad += (1 / node->parents[1]->data) * node->grad;
    node->parents[1]->grad += (-(node->parents[0]->data) / pow(node->parents[1]->data, 2)) * node->grad;
}

void ReLU_backward(Value_Node *node) {
    if (!node) return;
    if (!(node->parents)) return;

    node->parents[0]->grad += (node->data > 0)? 1: 0;
}

void log2_backward(Value_Node *node) {
    if (!node) return;
    if (!(node->parents)) return;

    node->parents[0]->grad += (1 / ((node->parents[0]->data) * log(2)));
}

void log10_backward(Value_Node *node) {
    if (!node) return;
    if (!(node->parents)) return;

    node->parents[0]->grad += (1 / ((node->parents[0]->data) * log(10)));
}

void log_backward(Value_Node *node) {
    if (!node) return;
    if (!(node->parents)) return;

    node->parents[0]->grad += (1 / (node->parents[0]->data));
}

static void backward_assist(Value_Node *kinda_root) {
    if (!kinda_root) return;
    if (!(kinda_root->backward_function)) return;

    kinda_root->backward_function(kinda_root);
    backward_assist(kinda_root->parents[0]);
    backward_assist(kinda_root->parents[1]);
}

void backward(Value_Node *kinda_root) {
    kinda_root->grad = 1.0;
    backward_assist(kinda_root);
}