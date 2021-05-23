#ifndef _QUEUE_
#define _QUEUE_

#define QMAX 100

typedef struct{
    int qu[QMAX];
    int qAfter, qFirst;
}queue;

void init(queue *node);
void insert(queue *node, int x);
int isempty(queue *node);
void print(queue *node);
int removeL(queue *node);

#endif