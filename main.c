#include <stdio.h>
#include<time.h>
#include <stdlib.h>

#include "linked_list.h"
#include "serial.h"
#include "file_writer.h"
#include "mutex.h"
#include "rwlock.h"

#define MAX 65535
#define RUNS 500

int main(int argc, char *argv[] ) {
    int m_member;
    int m_insert;
    int m_delete;

    
    int m = 10000;

    int run_count = 0;

    int thread_num = 8;
    int fraction = 2;
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
        srand(time(0)); // different random status for each execution

        switch (run_type)
        {
            case 1:{
                serial_run(m_member,m_insert,m_delete,m);
                break;
            }

            case 2:{
                mutex_run(m_member, m_insert, m_delete, m, thread_num);
                break;
            }

            case 3:{
                rwlock_run(m_member, m_insert, m_delete, m, thread_num);
                break;
            }

            default:{
                serial_run(m_member,m_insert,m_delete,m);
                break;
            }
        }
        run_count ++;
    }


    return 0;
}
