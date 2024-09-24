#include <stdio.h>
#include <stdlib.h>
#include "value_node.h"
#include "forward_functions.h"
#include "backward_functions.h"

extern Forward_Function Functions;


void print_computational_graph(Value_Node *kinda_root) {
    if (!kinda_root) return;
    int front = 0;
    int rear = 0;
    Value_Node *queue[1000];
    queue[front] = kinda_root;

    while (front <= rear) {
        Value_Node *temp = queue[front++];
        #ifdef DEBUG
        printf("(%s) ", temp->name);
        #endif
        printf("%.2f : %.2f [%s]\n", temp->data, temp->grad, temp->op);

        if (temp->parents) {

            if (temp->parents[0]) queue[++rear] = temp->parents[0];
            if (temp->parents[1]) queue[++rear] = temp->parents[1];
        }
    }
}

int main (int argc, char **argv) {
    Value_Node *a = NULL, *b = NULL;
    init_value_node(&a, 5);
    init_value_node(&b, 10);

    Value_Node *c = Functions.add(a, b);
    Value_Node *d = NULL;
    init_value_node(&d, 25);
    Value_Node *e = Functions.mul(c, d);
    Value_Node *f = Functions.ReLU(e);
    Value_Node *g = Functions.log2(f);
    Value_Node *h = Functions.log10(g);
    Value_Node *i = Functions.log(h);

    #ifdef DEBUG
    a->name = "a";
    b->name = "b";
    c->name = "c";
    d->name = "d";
    e->name = "e";
    f->name = "f";
    g->name = "g";
    h->name = "h";
    i->name = "i";

    #endif

    backward(i);
    print_computational_graph(i);

    return 0;
}