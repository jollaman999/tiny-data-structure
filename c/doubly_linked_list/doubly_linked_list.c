#include "doubly_linked_list.h"

int main() {
    insertAt(0, 1);
    insertAt(1, 3);
    insertAt(2, 5);
    insertAt(3, 7);
    insertAt(4, 9);
    printAll();
    // [1, 3, 5, 7, 9]
    printf("%d\n", new_list->tail->data);

    deleteAt(1);
    deleteAt(3);
    printAll();
    // [1, 5, 7]
    printf("%d\n", new_list->tail->data);

    insertAt(2, 10);
    printAll();
    // [1, 5, 10, 7]
    printf("%d\n", new_list->tail->data);

    deleteAt(3);
    deleteAt(1);
    printAll();
    // [1, 10]
    printf("%d\n", new_list->tail->data);

    deleteAt(0);
    printAll();
    // [10]
    printf("%d\n", new_list->tail->data);

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
    printf("%d\n", new_list->tail->data);

    freeAll();
    printAll();
    // []

    return 0;
}
