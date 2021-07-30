#include <stdio.h>
#include<time.h>
#include <stdlib.h>

#include "linked_list.h"
#include "serial.h"
#include "file_writer.h"
#include "mutex.h"
#include "rwlock.h"

#define MAX 65535
#define RUNS 2

int main(int argc, char *argv[] ) {
    int m_member;
    int m_insert;
    int m_delete;

    
    int n = 1000; // number of elements in the list
    int m = 10000;

    int run_count = 0;
    int count;
    struct list_node *head = NULL;

    int thread_num = 4;
    int fraction = 1;
    int run_type = 1;

    switch (fraction)
    {
        case 1:{
            m_member = 9900;
            m_insert = 50;
            m_delete = 50;
            break;
        }

        case 2:{
            m_member = 9000;
            m_insert = 500;
            m_delete = 500;
            break;
        }

        case 3:{
            m_member = 5000;
            m_insert = 2500;
            m_delete = 2500;
            break;
        }

        default:{
            m_member = 9900;
            m_insert = 50;
            m_delete = 50;
            break;
        }
    }

    make_csv_file();




    while (run_count < RUNS){
        head = NULL;
        count = 0;
        // populate the linked list with 1000 values
        srand(time(0)); // different random status for each execution
        while (count < n) {
            int val = rand() % MAX;
            Insert(val, &head);
            count++;
        }
        switch (run_type)
        {
            case 1:{
                serial_run(m_member,m_insert,m_delete,&head,m);
                break;
            }

            case 2:{
                mutex_run(m_member, m_insert, m_delete, &head, m, thread_num);
                break;
            }

            case 3:{
                rwlock_run(m_member, m_insert, m_delete, &head, m, thread_num);
                break;
            }

            default:{
                serial_run(m_member,m_insert,m_delete,&head,m);
                break;
            }
        }
        run_count ++;
    }


    return 0;
}
