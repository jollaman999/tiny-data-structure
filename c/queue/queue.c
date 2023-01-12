#include "queue.h"

int main() {
    /*******************
    [1]
    [1, 3]
    [1, 3, 5]
    [1, 3, 5, 7]
    [1, 3, 5, 7, 9]
    [3, 5, 7, 9]
    [5, 7, 9]
    [7, 9]
    [9]
    []
    []
    *******************/

    enqueue(1);
    printAll();

    enqueue(3);
    printAll();

    enqueue(5);
    printAll();

    enqueue(7);
    printAll();

    enqueue(9);
    printAll();

    dequeue();
    printAll();

    dequeue();
    printAll();

    dequeue();
    printAll();

    dequeue();
    printAll();

    dequeue();
    printAll();

    freeAll();
    printAll();

    return 0;
}