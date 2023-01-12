#include "doubly_linked_list.h"

int main() {
    insertAt(0, 1);
    insertAt(1, 3);
    insertAt(2, 5);
    insertAt(3, 7);
    insertAt(4, 9);
    printAll();
    // [1, 3, 5, 7, 9]

    deleteAt(1);
    deleteAt(3);
    printAll();
    // [1, 5, 7]

    insertAt(2, 10);
    printAll();
    // [1, 5, 10, 7]

    deleteAt(3);
    deleteAt(1);
    printAll();
    // [1, 10]

    deleteAt(0);
    printAll();
    // [10]

    deleteAt(0);
    printAll();
    // []

    // insertAt(9, 9); // ERROR
    // deleteAt(9); // ERROR

    insertAt(0, 1);
    insertAt(1, 3);
    insertAt(2, 5);
    insertAt(3, 7);
    insertAt(4, 9);
    printAll();
    // [1, 3, 5, 7, 9]

    freeAll();
    printAll();
    // []

    return 0;
}
