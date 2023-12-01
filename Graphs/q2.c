#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

struct pair {
    int x;
    int y;
};

typedef struct pair *Pair;

struct pair *createPair(int x, int y) {
    struct pair *p = (struct pair *)malloc(sizeof(struct pair));
    p->x = x;
    p->y = y;
    return p;
}

struct Queue {
    Pair vertex;
    struct Queue *next;
    struct Queue *prev;
};

typedef struct Queue *Queue;

Queue createQueue() {
    Queue head = malloc(sizeof(struct Queue));
    head->next = head;
    head->prev = head;
    return head;
}

void push(Queue head, Pair vertex) {
    Queue temp = malloc(sizeof(struct Queue));
    temp->vertex = vertex;
    if (head->next == head) {
        head->next = temp;
        head->prev = temp;
        temp->next = head;
        temp->prev = head;
    } else {
        temp->next = head;
        temp->prev = head->prev;
        (head->prev)->next = temp;
        head->prev = temp;
    }
}

Queue pop(Queue head) {
    if (head->next == head) {
        return NULL;
    } else {
        Queue temp = head->next;
        (head->next->next)->prev = head;
        head->next = head->next->next;
        return temp;
    }
}

void inject(Queue head, Pair vertex) {
    Queue temp = malloc(sizeof(struct Queue));
    temp->vertex = vertex;
    if (head->next == head) {
        head->next = temp;
        head->prev = temp;
        temp->next = head;
        temp->prev = head;
    } else {
        temp->next = head->next;
        temp->prev = head;
        (head->next)->prev = temp;
        head->next = temp;
    }
}

int isEmpty(Queue head) {
    return head->next == head;
}

int main() {
    short int t;
    scanf("%hd", &t);
    short int *dist = malloc(sizeof(short int) * 1000005);
    short int *A = malloc(sizeof(short int) * 1000005);
    for (int i = 0; i < t; i++) {
        short int n, m;
        scanf("%hd %hd", &n, &m);
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                scanf("%hd", &A[j * m + k]);
                dist[j * m + k] = SHRT_MAX;
            }
        }

        dist[0] = 0;
        Queue Q = createQueue();
        Pair p = createPair(0, 0);
        inject(Q, p);

        while (!isEmpty(Q)) {
            Queue t = pop(Q);
            Pair p = t->vertex;
            int x = p->x;
            int y = p->y;
            free(p);
            free(t);

            if (x != n - 1) {
                int dis = A[(x + 1) * m + y] - A[x * m + y];
                if (dis != 0) {
                    dis = 1;
                }
                if (dist[(x + 1) * m + y] > dist[x * m + y] + dis) {
                    // Pair p2 = createPair(x + 1, y);
                    dist[(x + 1) * m + y] = dist[x * m + y] + dis;
                    if (dis == 0) {
                        inject(Q, createPair(x + 1, y));
                    } else {
                        push(Q, createPair(x + 1, y));
                    }
                }
            }
            if (y != m - 1) {
                int dis = A[x * m + y + 1] - A[x * m + y];
                if (dis != 0) {
                    dis = 1;
                }
                if (dist[x * m + y + 1] > dist[x * m + y] + dis) {
                    // Pair p2 = createPair(x, y + 1);
                    dist[x * m + y + 1] = dist[x * m + y] + dis;
                    if (dis == 0) {
                        inject(Q, createPair(x, y + 1));
                    } else {
                        push(Q, createPair(x, y + 1));
                    }
                }
            }
            if (x != 0) {
                int dis = A[(x - 1) * m + y] - A[x * m + y];
                if (dis != 0) {
                    dis = 1;
                }
                if (dist[(x - 1) * m + y] > dist[x * m + y] + dis) {
                    // Pair p2 = createPair(x - 1, y);
                    dist[(x - 1) * m + y] = dist[x * m + y] + dis;
                    if (dis == 0) {
                        inject(Q, createPair(x - 1, y));
                    } else {
                        push(Q, createPair(x - 1, y));
                    }
                }
            }
            if (y != 0) {
                int dis = A[x * m + y - 1] - A[x * m + y];
                if (dis != 0) {
                    dis = 1;
                }
                if (dist[x * m + y - 1] > dist[x * m + y] + dis) {
                    // Pair p2 = createPair(x, y - 1);
                    dist[x * m + y - 1] = dist[x * m + y] + dis;
                    if (dis == 0) {
                        inject(Q, createPair(x, y - 1));
                    } else {
                        push(Q, createPair(x, y - 1));
                    }
                }
            }
        }

        printf("%hd\n", dist[n * m - 1]);

        free(Q);
    }
    free(A);
    free(dist);
}
