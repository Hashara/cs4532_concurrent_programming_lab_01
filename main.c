#include <stdio.h>
#include<time.h>
#include <stdlib.h>

#include "linked_list.h"
#include "serial.h"
#include "file_writer.h"
#include "mutex.h"

#define MAX 65535

int main(int argc, char *argv[] ) {
    int m_member;
    int m_insert;
    int m_delete;

    
    int n = 1000; // number of elements in the list
    int m = 10000;

    int count = 0;
    struct list_node *head = NULL;

    int thread_num = 8;
    int fraction = 1;
    int run_type = 2;
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

//    make_csv_file();
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
//
//        case 3:{
//            m_member = 0.5;
//            m_insert = 0.25;
//            m_delete = 0.25;
//            break;
//        }

        default:{
            serial_run(m_member,m_insert,m_delete,&head,m);
            break;
        }
    }


    return 0;
}
