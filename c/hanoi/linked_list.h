#include <malloc.h>
#include <stdlib.h>

typedef struct node Node;
typedef struct list List;

struct node {
    int data;
    Node *next;
};

struct list {
    Node *head;
    int count;
};

void initList(List **list)
{
    *list = (List *)malloc(sizeof(List));
    (*list)->head = NULL;
    (*list)->count = 0;
}

int getListSize(List *list)
{
    return list->count;
}

// *data 변수에 해당 index 의 값을 저장
int getAt(List *list, int *data, int index)
{
    int i;
    Node *current_node = NULL;

    if (list == NULL)
        return -1;

    if (list->count == 0)
        return -1;

    if (index > list->count - 1)
        return -1;

    current_node = list->head;
    for (i = 0; i < index; i++)
        current_node = current_node->next;
    
    *data = current_node->data;

    return 0;
}

void checkIndex(List *list, int index)
{
    if (index < 0 || (list != NULL && index > list->count)) {
        printf("ERROR: Index out of bound!\n");
        exit(-1);
    }
}

void insertAt(List *list, int index, int data)
{
    Node *new_node = NULL;

    checkIndex(list, index);

    new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (list == NULL) {
        return;
    }
    
    if (index == 0) {
        new_node->next = list->head;
        list->head = new_node;
    } else {
        Node *current_node = list->head;
        int i;

        for (i = 0; i < index - 1; i++) {
            current_node = current_node->next;
        }
        new_node->next = current_node->next;
        current_node->next = new_node;
    }
    list->count++;
}

void deleteAt(List *list, int index)
{
    Node *current_node = list->head;
    Node *target_node = NULL;
    int i;

    checkIndex(list, index);

    if (index == 0) {
        target_node = current_node;
        list->head = target_node->next;
    } else {
        for (i = 0; i < index - 1; i++)
            current_node = current_node->next;
        target_node = current_node->next;
        current_node->next = current_node->next->next;
    }

    free(target_node);
    target_node = NULL;
    
    list->count--;
}

void printAll(List *list)
{
    printf("[");
    if (list != NULL) {
        Node *current_node = list->head;
        int i;

        for (i = 0; i < list->count; i++) {
            if (i == list->count - 1)
                printf("%d", current_node->data);
            else
                printf("%d, ", current_node->data);
            current_node = current_node->next;
        }
    }
    printf("]\n");
}

void freeAll(List *list)
{
    Node *current_node = list->head;
    Node *next_node = NULL;
    int i;

    for (i = 0; i < list->count; i++) {
        next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }

    free(list);
    list = NULL;
}
