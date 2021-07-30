#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include "serial.h"
#include "linked_list.h"
#include "file_writer.h"
#define MAX 65535

void serial_run(int m_member, int m_insert, int m_delete, struct list_node **head, int m) {
    int total_operations_count = 0;
    int member_operations_count = 0;
    int insert_operations_count = 0;
    int delete_operations_count = 0;

    struct timeval stop_time;
    struct timeval start_time;
    unsigned long time_interval;
    gettimeofday(&start_time, NULL); // get start time

    srand(time(0)); // different random status for each execution

    int rand_value;
    int rand_operation;

    while (total_operations_count < m) {
        rand_value = rand() % MAX; // generate random value

        rand_operation = rand() % 3; // randomize the operation

        if (rand_operation == 0 && member_operations_count < m_member) {
            Member(rand_value, head);
            member_operations_count++;
            total_operations_count++;
        }
        else if (rand_operation == 1 && insert_operations_count < m_insert) {
            Insert(rand_value, &head);
            insert_operations_count++;
            total_operations_count++;
        }
        else if (rand_operation == 2 && delete_operations_count < m_delete) {
            Delete(rand_value, &head);
            delete_operations_count++;
            total_operations_count++;
        }

    }
    gettimeofday(&stop_time, NULL); // get end time
    time_interval = (stop_time.tv_sec - start_time.tv_sec) * 1000.0
            + (stop_time.tv_usec - start_time.tv_usec) / 1000.0;

    printf("Serial run %lu\n", time_interval);

    destructor(head);
    write_on_csv("SERIAL", 1, m_member, m_insert, m_delete, time_interval);
}