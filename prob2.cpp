#include <iostream>
#include "queue.h"

using namespace std;

int main() {
    Queue q;
    init(&q);

    int n, k;
    cin >> n >> k;

    int sum = 0;
    bool firstOutput = true;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        enqueue(&q, x);
        sum += x;

        while (!isEmpty(&q) && (q.rear - q.front + 1) > k) {
            sum -= front(&q);
            dequeue(&q);
        }

        if (!isEmpty(&q) && (q.rear - q.front + 1) == k) {
            if (!firstOutput) {
                cout << " ";
            }
            cout << sum;
            firstOutput = false;
        }
    }

    cout << endl;
    return 0;
}