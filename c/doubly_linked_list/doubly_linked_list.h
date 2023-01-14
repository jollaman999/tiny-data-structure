#include <malloc.h>
#include <stdlib.h>

typedef struct node node;
typedef struct list list;

struct node {
    int data;
    node *prev;
    node *next;
};

struct list {
    node *head;
    node *tail;
    int count;
};

list *new_list = NULL;
    
void checkIndex(int index) {
    if (index < 0 || (new_list != NULL && index > new_list->count)) {
        printf("ERROR: Index out of bound!\n");
        exit(-1);
    }
}

void insertAt(int index, int data) {
    node *new_node = NULL;

    if (new_list == NULL) {
        new_list = (list *)malloc(sizeof(list));
        new_list->head = NULL;
        new_list->tail = NULL;
        new_list->count = 0;
    }

    if (index < 0 || index > new_list->count) {
        printf("ERROR: Index out of bound!\n");
        exit(-1);
    }

    new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    
    if (index == 0) {
        new_node->next = new_list->head;
        if (new_list->count == 0)
            new_list->tail = new_node;
        new_list->head = new_node;
    } else if (index == new_list->count) {
        new_node->prev = new_list->tail;
        new_list->tail->next = new_node;
        new_list->tail = new_node;
    } else {
        node *current_node = new_list->head;
        int i;

        for (i = 0; i < index - 1; i++)
            current_node = current_node->next;
    
        new_node->next = current_node->next;
        new_node->prev = current_node;
        current_node->next->prev = new_node;
        current_node->next = new_node;
    }
    new_list->count++;
}

node *deleteAt(int index) {
    node *current_node = new_list->head;
    node *deleted_node = NULL;
    int i;

    if (index < 0 || (new_list != NULL && index > new_list->count - 1)) {
        printf("ERROR: Index out of bound!\n");
        exit(-1);
    }

    if (index == 0) {
        deleted_node = current_node;
        new_list->head = deleted_node->next;
        if (deleted_node->next != NULL)
            new_list->head->prev = NULL;
        else
            new_list->tail = NULL;
    } else if (index == new_list->count - 1) {
        deleted_node = new_list->tail;
        deleted_node->prev->next = NULL;
        new_list->tail = deleted_node->prev;
    } else {
        for (i = 0; i < index - 1; i++) {
            current_node = current_node->next;
        }
        deleted_node = current_node->next;
        if (deleted_node->next != NULL)
            deleted_node->next->prev = current_node;
        current_node->next = deleted_node->next;
    }
    new_list->count--;
    return deleted_node;
}

void printAll() {
    printf("[");
    if (new_list != NULL) {
        node *current_node = new_list->head;
        int i;

        for (i = 0; i < new_list->count; i++) {
            if (i == new_list->count - 1)
                printf("%d", current_node->data);
            else
                printf("%d, ", current_node->data);
            current_node = current_node->next;
        }
    }
    printf("]\n");
}

void freeAll() {
    node *current_node = new_list->head;
    node *next_node = NULL;
    int i;

    for (i = 0; i < new_list->count; i++) {
        next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }

    free(new_list);
    new_list = NULL;
}
