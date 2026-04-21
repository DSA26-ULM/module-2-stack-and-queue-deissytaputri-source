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
    return q->rear == &q->data[MAX - 1];
}

void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        throw overflow_error("Queue penuh");
    }

    if (isEmpty(q)) {
        q->front = &q->data[0];
        q->rear = &q->data[0];
    } else {
        q->rear++;
    }

    *(q->rear) = value;
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

    return *(q->front);
}

int back(const Queue* q) {
    if (isEmpty(q)) {
        throw underflow_error("Queue kosong");
    }

    return *(q->rear);
}