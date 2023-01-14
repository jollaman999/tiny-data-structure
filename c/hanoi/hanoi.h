#include <stdio.h>
#include "../stack/stack.h"

#define HANOI_TOPS 3

static list *list_hanoi[HANOI_TOPS];
static int top_size = 0;
static int hanoi_initialized = 0;

void init_hanoi(int size, int from)
{
    int i;

    top_size = size;

    for (i = 0; i < HANOI_TOPS; i++) {
        list_hanoi[i] = (list *)malloc(sizeof(list));
        list_hanoi[i]->head = NULL;
        list_hanoi[i]->tail = NULL;
        list_hanoi[i]->count = 0;
    }

    for (i = 0; i < top_size; i++) {
        new_list = list_hanoi[from];
        push(top_size - i);
    }

    hanoi_initialized = 1;
}

// *data 변수에 해당 index 의 값을 저장
int getAt(list *list, int *data, int index)
{
    int i;
    node *current_node = NULL;

    if (list == NULL)
        return -1;

    if (list->count == 0)
        return -1;

    if (index < 0 || index > list->count - 1)
        return -1;

    current_node = list->head;
    for (i = 0; i < index; i++)
        current_node = current_node->next;

    *data = current_node->data;

    return 0;
}

void move_hanoi(int from, int to)
{
    int data;
    int res;

    if (list_hanoi[from] == NULL || list_hanoi[to] == NULL)
        return;

    new_list = list_hanoi[from];
    res = pop(&data);
    if (res)
        return;
    new_list = list_hanoi[to];
    push(data);
}

void print_hanoi(void) {
    int ch_total = (top_size - 1) * 2 + 3; // 원반의 반쪽 * 2 + (원반의 양끝(2) + 막대기 가운데(1))
    int stick_pos = ch_total / 2; // 막대기 가운데 부분
    int i, j, k;

    for (i = 0; i < top_size + 1; i++) { // 3개의 탑을 하나씩 순회 하면서 위에서 부터 그림
        for (j = 0; j < 3; j++) { // 3개의 탑을 하나씩 순회
            int data; // 몇번째 원반 인지 구분
            int is_draw = 0; // 꽂혀 있는게 있는지 체크
            int start_pos, end_pos; // 원반의 양 끝부분
            int res;

            if (i == 0) // 맨 윗 부분은 꽂혀 있는것 없이 막대기 만 그림
                is_draw = 0;
            else { // 꽂혀 있는게 있는지 체크
                res = getAt(list_hanoi[j], &data, top_size - i);
                new_list = list_hanoi[j];
                if (!res)
                    is_draw = 1;
            }

            if (is_draw) {
                start_pos = top_size - data;
                end_pos = stick_pos + data;
                for (k = 0; k < ch_total; k++) {
                    if (k == start_pos)
                        printf("┌");
                    else if (k == end_pos)
                        printf("┐");
                    else if (k == stick_pos)
                        printf("│");
                    else if (k > start_pos && k < end_pos)
                        printf("─");
                    else
                        printf(" ");
                }
            } else {
                for (k = 0; k < ch_total; k++) {
                    if (k == stick_pos)
                        printf("│");
                    else
                        printf(" ");
                }
            }
            printf("　");
        }
        printf("\n");
    }
    printf("\n");
}

void hanoi(int n, int from, int to, int temp)
{
    if (n == 0)
        return;

    if (from < 0 || from > 2 || to < 0 || to > 2 || temp < 0 || temp > 2)
        return;

    if (!hanoi_initialized) {
        init_hanoi(n, from);
        print_hanoi();
    }

    hanoi(n - 1, from, temp, to);
    move_hanoi(from, to);
    print_hanoi();
    hanoi(n - 1, temp, to, from);
}

void free_all_hanoi_list()
{
    int i;

    for (i = 0; i < HANOI_TOPS; i++) {
        if (list_hanoi[i] != NULL) {
            new_list = list_hanoi[i];
            freeAll();
        }
    }
}
