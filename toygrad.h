#ifndef TOYGRAD_H
#define TOYGRAD_H

#include <stdlib.h>
#include <stdio.h>

typedef struct Value {
    double data;           // scalar value
    double grad;          // gradient value
    struct Value** prev;  // array of child nodes
    int n_prev;          // number of child nodes
    void (*backward)(struct Value*);  // backward function pointer
    char* label;         // label for debugging
} Value;

Value* create_value(double data);
Value* add_value(Value* a, Value* b);
Value* mul_value(Value* a, Value* b);
void backward(Value* v);
// Todo: Add activation functions

#endif
