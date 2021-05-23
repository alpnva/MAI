#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void init(queue *node) {
    node->qFirst = 1;
    node->qAfter = 0;
    return;
}

void insert(queue *node, int key) { // Добавление элемента с клавиатуры key в очередь
    if(node->qAfter < QMAX-1) {
        node->qAfter++;
        node->qu[node->qAfter]=key;
    }
    else
        printf("Очередь полна!\n");
    return;
}

int isempty(queue *node) { // Проверка, пуста ли очередь
    if(node->qAfter < node->qFirst)    return 1;
    else  return 0;
}

void print(queue *node) {
    int h;
    for(h = node->qFirst; h<= node->qAfter; h++)
        printf("%d ",node->qu[h]);
    return;
}

int removeL(queue *node) {
    int x;
    if(isempty(node)==1) {
        printf("Очередь пуста!\n");
        return(0);
    }
    x = node->qu[node->qFirst];
    node->qFirst++;
    return x;
}

void sort(queue *node){
    int previous;
    int key;
    int next;
    for(next = node->qFirst; next<= node->qAfter; next++) {
        // i = qu->qFirst; i<= qu->qAfter; i++
        // i = 0; i < *sizeQueue; i++
        previous = next - 1;
        key = node->qu[next];
        while (node->qu[previous] > key && previous >= 0) {
            node->qu[previous + 1] = node->qu[previous];
            previous -= 1;
        }
        node->qu[previous + 1] = key;
    }
    return;
}




int main(){
    queue *q;
    int answer;
    int action;
    q = (queue*)malloc(sizeof(queue));
    while (1)
    {
        printf("Меню:\n");
        printf("1) Создать очередь\n");
        printf("2) Удалить очередь\n");
        printf("3) Cортирвка\n");
        printf("4) Выход\n");
        printf("Выберите действие: ");
        scanf("%d", &action);

        switch (action)
        {
            case 1:
            {
                init(q);
                for(int i = 0; i < QMAX; i++) {
                    printf("Введите элемент очереди или число 100 чтобы закончить ввод: ");
                    scanf("%d", &answer);
                    if (answer == 100)
                        break;
                    insert(q, answer);
                }
                print(q);
                printf("\n");
                break;
            }

            case 2:
            {
                while(q->qFirst <= q->qAfter) {
                    answer = removeL(q);
                    printf("\nУдален элемент %d\n", answer);
                    print(q);
                }

                break;
            }

            case 3:
            {
                sort(q);
                print(q);
            }

            case 4: break;

            default:
            {
                printf("Ошибка. Такого пункта меню не существует\n");
                break;
            }
        }

        if (action == 4)
            break;
    }
    return 0;
}