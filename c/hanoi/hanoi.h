#include <stdio.h>
#include "stack.h"

#define HANOI_TOPS 3

static List *list_hanoi[HANOI_TOPS];
static int top_size = 0;
static int hanoi_initialized = 0;

void init_hanoi(int size, int from)
{
    int i;

    top_size = size;

    for (i = 0; i < HANOI_TOPS; i++)
        initList(&list_hanoi[i]);
    
    for (i = 0; i < top_size; i++)
        push(list_hanoi[from], top_size - i);

    hanoi_initialized = 1;
}

void move_hanoi(int n, int from, int to)
{
    int data = 0;
    int res;
    
    res = getAt(list_hanoi[from], &data, list_hanoi[from]->count - 1);
    if (res)
        return;
    pop(list_hanoi[from]);
    push(list_hanoi[to], data);
}

void print_hanoi(void) {
    int ch_total = (top_size - 1) * 2 + 3;
    int stick_pos = ch_total / 2;
    int i, j, k;

    for (i = 0; i < top_size + 1; i++) { // 3개의 탑을 하나씩 순회하면서 위에서 부터 그림
        for (j = 0; j < 3; j++) { // 3개의 하나씩 순회
            if (i == 0) { // 제일 위쪽의 꽂혀 있는게 없는 부분을 그림
                for (k = 0; k < ch_total; k++) {
                    if (k == stick_pos)
                        printf("│");
                    else
                        printf(" ");
                }
            } else { // 꽂혀있는게 있는지 체크하면서 그림
                int data = 0;
                int is_draw = 0;
                int start_pos, end_pos;
                int res;
                
                res = getAt(list_hanoi[j], &data, top_size - i);
                if (!res)
                    is_draw = 1;
                
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
    move_hanoi(n, from, to);
    print_hanoi();
    hanoi(n - 1, temp, to, from);
}

void free_all_hanoi_list()
{
    int i;

    for (i = 0; i < HANOI_TOPS; i++)
        if (list_hanoi[i] != NULL)
            freeAll(list_hanoi[i]);
}
