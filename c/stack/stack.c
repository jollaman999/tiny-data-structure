#include "stack.h"

int main() {
    push(1);
    push(3);
    push(5);
    push(7);
    push(9);
    printAll();
    // [1, 3, 5, 7, 9]

    pop();
    printAll();
    // [1, 3, 5, 7]

    pop();
    printAll();
    // [1, 3, 5]

    pop();
    printAll();
    // [1, 3]

    pop();
    printAll();
    // [1]

    pop();
    printAll();
    // []

    push(1);
    push(3);
    push(5);
    push(7);
    push(9);
    printAll();
    // [1, 3, 5, 7, 9]

    popAll();
    printAll();
    // []

    push(1);
    push(3);
    push(5);
    push(7);
    push(9);
    printAll();
    // [1, 3, 5, 7, 9]

    freeAll();
    printAll();
    // []

    return 0;
}