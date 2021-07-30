#ifndef RWLOCK_H
#define RWLOCK_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <sys/time.h>

#include "linked_list.h"

struct data_rw {
    int m_member;
    int m_insert;
    int m_delete;
    struct list_node *head;
    int m;
    pthread_rwlock_t rwlock;
};
typedef struct data_rw data_rw;

void rwlock_run(int m_member, int m_insert, int m_delete, int m, int thread_num);

#endif //RWLOCK_H
