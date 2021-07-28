#ifndef MUTEX_H
#define MUTEX_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <sys/time.h>

#include "linked_list.h"

struct data {
    int m_member;
    int m_insert;
    int m_delete;
    struct list_node **head;
    int m;
    pthread_mutex_t mutex;
};
typedef struct data data;

void mutex_run(int m_member, int m_insert, int m_delete, struct list_node **head, int m, int thread_num);

#endif //MUTEX_H
