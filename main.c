#include <stdio.h>
#include <time.h>
#include "linked_list.h"

int main() {
    const int max_val = 65535;
    const int elementsNum = 10;
    int count = 0;
    struct list_node *head = NULL;

    srand(time(0));
    while (count < elementsNum) {
        int val = rand() % max_val;
        Insert(val, &head);
        count++;
    }
    Insert(20000, &head);
    Print(head);

//    Delete(20000, &head);
//    Print(head);

//    destructor(&head);
    printf("Hello, World!\n");
    Member(20000, head);
    Member(200000, head);
}
