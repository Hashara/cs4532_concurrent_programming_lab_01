#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct list_node {
    int data;
    struct list_node * next;
};

int Member(int value, struct list_node *head_p);
int Insert(int value, struct list_node **head_p);
int Delete(int value, struct list_node **head_p);
void Print(struct list_node * head_p);
void destructor(struct list_node* head_p);

#endif //LINKED_LIST_H