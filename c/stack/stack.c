#include "stack.h"

int main() {
    int data;

    push(1);
    push(3);
    push(5);
    push(7);
    push(9);
    printAll();
    // [1, 3, 5, 7, 9]

    pop(&data);
    printf("%d\n", data);
    // 9
    printAll();
    // [1, 3, 5, 7]

    pop(&data);
    printf("%d\n", data);
    // 7
    printAll();
    // [1, 3, 5]

    pop(&data);
    printf("%d\n", data);
    // 5
    printAll();
    // [1, 3]

    pop(&data);
    printf("%d\n", data);
    // 3
    printAll();
    // [1]

    pop(&data);
    printf("%d\n", data);
    // 1
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