#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include <pthread.h>

#include "linked_list.h"
#include "file_writer.h"
#include "mutex.h"

#define MAX 65535
void *op_mtx(void* func_data);

void mutex_run(int m_member, int m_insert, int m_delete, struct list_node **head, int m, int thread_num) {
    pthread_mutex_t mutex;
    struct data func_data;
    struct timeval stop_time;
    struct timeval start_time;
    unsigned long time_interval;
    if (thread_num != 1) {
        m = (int) m/thread_num;
        printf("calculations per thread %d \n", m);
    }
    srand(time(0)); // different random status for each execution

    // Initializing the mutex
    pthread_mutex_init(mutex, NULL);

    // Generate Threads
    pthread_t *thread_handles = malloc(thread_num * sizeof(pthread_t));

    func_data.mutex = mutex;
    func_data.m = m;
    func_data.head = head;
    func_data.m_insert = m_insert;
    func_data.m_delete = m_delete;
    func_data.m_member = m_member;

    gettimeofday(&start_time, NULL); // get start time

    for (int thread = 0; thread < thread_num; ++thread) {
        pthread_create(&thread_handles[thread], NULL, op_mtx, (void *) &func_data);
    }

    for (int thread = 0; thread < thread_num; ++thread) {
        pthread_join(thread_handles[thread], NULL);
    }
    free(thread_handles);

    gettimeofday(&stop_time, NULL); // get end time

    pthread_mutex_destroy(mutex);

    time_interval = (stop_time.tv_sec - start_time.tv_sec) * 1000.0
                    + (stop_time.tv_usec - start_time.tv_usec) / 1000.0;

    printf("Mutex run %lu\n", time_interval);

    write_on_csv("MUTEX", thread_num, m_member, m_insert, m_delete, time_interval);

}
    void *op_mtx(void *func_data) {
        struct data* f_data = func_data;
        int total_operations_count = 0;
        int member_operations_count = 0;
        int insert_operations_count = 0;
        int delete_operations_count = 0;

        int rand_value;
        int rand_operation;

        while (total_operations_count < f_data->m) {
            rand_value = rand() % MAX; // generate random value

            rand_operation = rand() % 3; // randomize the operation

            if (rand_operation == 0 && member_operations_count < f_data->m_member) {
                pthread_mutex_lock(f_data->mutex);
                Member(rand_value, f_data->head);
                member_operations_count++;
                total_operations_count++;
                pthread_mutex_unlock(f_data->mutex);
            } else if (rand_operation == 1 && insert_operations_count < f_data->m_insert) {
                pthread_mutex_lock(f_data->mutex);
                Insert(rand_value, &f_data->head);
                insert_operations_count++;
                total_operations_count++;
                pthread_mutex_unlock(f_data->mutex);

            } else if (rand_operation == 2 && delete_operations_count < f_data->m_delete) {
                pthread_mutex_lock(f_data->mutex);
                Delete(rand_value, &f_data->head);
                delete_operations_count++;
                total_operations_count++;
                pthread_mutex_unlock(f_data->mutex);

            }

        }
        printf("total operations %d \n", total_operations_count);

    }
