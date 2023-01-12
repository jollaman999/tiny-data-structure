// #include "../doubly_linked_list/doubly_linked_list.h"
#include "../linked_list/linked_list.h"

void push(int data) {
    int index = 0;

    if (new_list != NULL)
        index = new_list->count;
    insertAt(index, data);
}

int isEmpty() {
    return new_list != NULL && new_list->count == 0;
}

void pop() {
    int index = 0;

    if (isEmpty())
        return;

    if (new_list != NULL)
        index = new_list->count - 1;

    deleteAt(index);
}

void popAll() {
    while(!isEmpty())
        pop();
}
