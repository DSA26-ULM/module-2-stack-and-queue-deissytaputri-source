#include "queue.h"
#include <stdexcept>

using namespace std;

void init(Queue* q) {
    q->front = nullptr;
    q->rear = nullptr;
}

bool isEmpty(const Queue* q) {
    return q->front == nullptr;
}

bool isFull(const Queue* q) {
    return !isEmpty(q) && q->front == &q->data[0] && q->rear == &q->data[MAX - 1];
}

void enqueue(Queue* q, int value) {
    if (isEmpty(q)) {
        q->front = &q->data[0];
        q->rear = &q->data[0];
        *q->rear = value;
        return;
    }

    if (q->rear == &q->data[MAX - 1]) {
        if (q->front == &q->data[0]) {
            throw overflow_error("Queue penuh");
        }

        int* dest = &q->data[0];
        int* src = q->front;

        while (src <= q->rear) {
            *dest = *src;
            dest++;
            src++;
        }

        int count = q->rear - q->front + 1;
        q->front = &q->data[0];
        q->rear = &q->data[count - 1];
    }

    q->rear++;
    *q->rear = value;
}

void dequeue(Queue* q) {
    if (isEmpty(q)) {
        throw underflow_error("Queue kosong");
    }

    if (q->front == q->rear) {
        q->front = nullptr;
        q->rear = nullptr;
    } else {
        q->front++;
    }
}

int front(const Queue* q) {
    if (isEmpty(q)) {
        throw underflow_error("Queue kosong");
    }

    return *q->front;
}

int back(const Queue* q) {
    if (isEmpty(q)) {
        throw underflow_error("Queue kosong");
    }

    return *q->rear;
}