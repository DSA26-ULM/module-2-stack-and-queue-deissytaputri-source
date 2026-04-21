#include "stack.h"
#include <stdexcept>

using namespace std;

void init(Stack* s) {
    s->top = nullptr;
}

bool isEmpty(const Stack* s) {
    return s->top == nullptr;
}

bool isFull(const Stack* s) {
    return s->top == &s->data[MAX - 1];
}

void push(Stack* s, int value) {
    if (isFull(s)) {
        throw overflow_error("Stack penuh");
    }

    if (isEmpty(s)) {
        s->top = &s->data[0];
    } else {
        s->top++;
    }

    *(s->top) = value;
}

void pop(Stack* s) {
    if (isEmpty(s)) {
        throw underflow_error("Stack kosong");
    }

    if (s->top == &s->data[0]) {
        s->top = nullptr;
    } else {
        s->top--;
    }
}

int peek(const Stack* s) {
    if (isEmpty(s)) {
        throw underflow_error("Stack kosong");
    }

    return *(s->top);
}