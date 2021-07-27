#include <stdio.h>
#include<time.h>
#include <stdlib.h>

int main(int argc, char *argv[] ) {
    float m_member;
    float m_insert;
    float m_delete;

    int n = 1000; // number of elements in the list
    int m = 1000;

    int index = 0;

    switch (argc)
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

    // populate the linked list with 1000 values
    srand(time(0)); // different random status for each execution
    while (index<n){
//        Insert(rand()%MAX, &head);
        index++ ;
    }

    return 0;
}
