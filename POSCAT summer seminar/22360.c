#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 200000

typedef struct node {
    int index;
    struct node *next;
    struct node *prev;
} NODE;

typedef struct queue {
    int size;
    NODE *head;
    NODE *tail;
} QUEUE;

void push(QUEUE *q, int value){

    NODE *temp;

    temp = (NODE*) malloc(sizeof(NODE));
    temp->index = value;
    temp->next = NULL;

    if (q->size == 0) {
        temp->prev = NULL;
        q->head = temp;
        q->tail = temp;
    }
    else {
        temp->prev = q->tail;
        q->tail->next = temp;
        q->tail = temp;
    }
    q->size++;
}

int pop (QUEUE *q){

    int index;

    if (q->size == 0)  return -1;

    index = q->head->index;

    if (q->size == 1) {
        q->tail = NULL;
        q->head = NULL;
    }
    else {
        q->head = q->head->next;
        q->head->prev = NULL;
    }

    q->size--;

    return index;
}


int finalCount = 0;
int count[3] = {0,0,0};
int *isVisited;

int isDone () {
    int k = count[0];
    if (count[1] == 2*k && count[2] == k) return 1;
    return 0;
}

int dfs(char *s, int index, QUEUE *neigh) {

    isVisited[index] = 1;
    QUEUE toVisit = neigh[index];

    if (s[index] == 'U') count[0] += 1;
    else if (s[index] == 'C') count[1] += 1;
    else if (s[index] == 'P') count[2] += 1;

    if (isDone() == 1) finalCount++;

    int nextInd;

    while (toVisit.size >= 1) {
        nextInd = pop(&toVisit);
        if (isVisited[nextInd] == 0) dfs(s, nextInd, neigh);
    }

    if (s[index] == 'U') count[0] -= 1;
    else if (s[index] == 'C') count[1] -= 1;
    else if (s[index] == 'P') count[2] -= 1;
    isVisited[index] = 0;

    return 0;
}

int main() {

    int n;
    scanf("%d", &n);

    NODE nodes[n]; // 새로 추가할때 push에서 이니셜라이즈

    QUEUE neigh[n];
    int neighNum[n];
    isVisited = malloc(sizeof (int)*n);

    for (int i=0; i<n; i++) {
        QUEUE temp = {0, NULL, NULL};
        neigh[i] = temp;
        neighNum[i] = 0;
        isVisited[i] = 0;
    }

    char *s = malloc(sizeof(char)*MAX_LEN);
    scanf("%s", s);

    int a, b;

    for (int i=0; i<n-1; i++) {
        scanf("%d %d", &a, &b);
            push(&neigh[a-1], b-1);
            push(&neigh[b-1], a-1);
    }

    dfs(s, 0, neigh);

    printf("%d", finalCount);
    return 0;
}

























