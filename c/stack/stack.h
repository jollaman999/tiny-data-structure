#include "../doubly_linked_list/doubly_linked_list.h"

void push(int data) {
    int index = 0;

    if (new_list != NULL)
        index = new_list->count;
    insertAt(index, data);
}

int isEmpty() {
    return new_list != NULL && new_list->count == 0;
}

// *data 변수에 pop() 하면서 나온 데이터 값을 저장
int pop(int *data) {
    int index = 0;

    if (isEmpty())
        return -1;

    if (new_list != NULL)
        index = new_list->count - 1;

    if (data != NULL)
        *data = new_list->tail->data;

    deleteAt(index);

    return 0;
}

void popAll() {
    while(!isEmpty())
        pop(NULL);
}
