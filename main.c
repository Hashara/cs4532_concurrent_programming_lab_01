#include <stdio.h>
#include<time.h>
#include <stdlib.h>

#include "linked_list.h"
#include "serial.h"

#define MAX 65535

int main(int argc, char *argv[] ) {
    float m_member;
    float m_insert;
    float m_delete;

    
    int n = 1000; // number of elements in the list
    int m = 10000;

    int count = 0;
    struct list_node *head = NULL;

    int fraction = 1;
    int run_type = 1;
    switch (fraction)
    {
        case 1:{
            m_member = 0.99;
            m_insert = 0.005;
            m_delete = 0.005;
            break;
        }

        case 2:{
            m_member = 0.9;
            m_insert = 0.05;
            m_delete = 0.05;
            break;
        }

        case 3:{
            m_member = 0.5;
            m_insert = 0.25;
            m_delete = 0.25;
            break;
        }

        default:{
            m_member = 0.99;
            m_insert = 0.005;
            m_delete = 0.005;
            break;
        }
    }

    switch (run_type)
    {
        case 1:{
            serial_run(m_member,m_insert,m_delete,&head,m);
            break;
        }

        case 2:{
            m_member = 0.9;
            m_insert = 0.05;
            m_delete = 0.05;
            break;
        }

        case 3:{
            m_member = 0.5;
            m_insert = 0.25;
            m_delete = 0.25;
            break;
        }

        default:{
            m_member = 0.99;
            m_insert = 0.005;
            m_delete = 0.005;
            break;
        }
    }
    // populate the linked list with 1000 values
    srand(time(0)); // different random status for each execution
    while (count < n) {
        int val = rand() % MAX;
        Insert(val, &head);
        count++;
    }

    return 0;
}
