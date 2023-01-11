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

List *new_list = NULL;

void checkIndex(int index) {
    if (index < 0 || index > new_list->count) {
        printf("ERROR: Index out of bound!\n");
        exit(-1);
    }
}

void insertAt(int index, int data) {
    Node *new_node = NULL;

    new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (new_list == NULL) {
        new_list = (List *)malloc(sizeof(List));
        new_list->head = NULL;
        new_list->count = 0;
    }

    checkIndex(index);
    
    if (index == 0) {
        new_node->next = new_list->head;
        new_list->head = new_node;
    } else {
        Node *current_node = new_list->head;
        int i;

        for (i = 0; i < index - 1; i++) {
            current_node = current_node->next;
        }
        new_node->next = current_node->next;
        current_node->next = new_node;
    }
    new_list->count++;
}

void deleteAt(int index) {
    Node *current_node = new_list->head;
    Node *target_node = NULL;
    int i;

    checkIndex(index);

    for (i = 0; i < index - 1; i++) {
        current_node = current_node->next;
    }
    target_node = current_node->next;
    current_node->next = current_node->next->next;
    free(target_node);
    target_node = NULL;
    
    new_list->count--;
}

void printAll() {
    printf("[");
    if (new_list != NULL) {
        Node *current_node = new_list->head;
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
    Node *current_node = new_list->head;
    Node *next_node = NULL;
    int i;

    for (i = 0; i < new_list->count; i++) {
        next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }

    free(new_list);
    new_list = NULL;
}
