#include "linked_list.h"

void push(List *list, int data) {
    int index = 0;

    if (list != NULL)
        index = list->count;
    insertAt(list, index, data);
}

int isEmpty(List *list) {
    return list != NULL && list->count == 0;
}

void pop(List *list) {
    int index = 0;

    if (isEmpty(list))
        return;

    if (list != NULL)
        index = list->count - 1;

    deleteAt(list, index);
}