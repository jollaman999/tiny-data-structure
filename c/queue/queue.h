#include "../doubly_linked_list/doubly_linked_list.h"

void enqueue(int data) {
    int index = 0;

    if (new_list != NULL) 
        index = new_list->count;
    insertAt(index, data);
}

int isEmpty() {
    return new_list != NULL && new_list->count == 0;
}

void dequeue() {
    if (isEmpty())
        return;

    deleteAt(0);
}
