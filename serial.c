#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include "serial.h"
#include "linked_list.h"
#include "file_writer.h"
#define MAX 65535

void serial_run(int m_member, int m_insert, int m_delete, int m) {
    int count = 0;
    int n = 1000; // number of elements in the list
    struct list_node *head = NULL;
    int total_operations_count = 0;
    int member_operations_count = 0;
    int insert_operations_count = 0;
    int delete_operations_count = 0;

    struct timeval stop_time;
    struct timeval start_time;
    unsigned long time_interval;
    int rand_value;
    int rand_operation;

    srand(time(0)); // different random status for each execution

    // populate the linked list with 1000 values
    while (count < n) {
        int val = rand() % MAX;
        Insert(val, &head);
        count++;
    }

    gettimeofday(&start_time, NULL); // get start time

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
    time_interval = (stop_time.tv_sec - start_time.tv_sec) * 1000000
            + stop_time.tv_usec - start_time.tv_usec;

    printf("Serial run %lu\n", time_interval);

    destructor(head);
    write_on_csv("SERIAL", 1, m_member, m_insert, m_delete, time_interval);
}