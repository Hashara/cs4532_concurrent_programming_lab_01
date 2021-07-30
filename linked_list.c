#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "linked_list.h"

int Member(int value, struct list_node* head_p){
    struct list_node *curr_p = head_p;

    while (curr_p != NULL && curr_p -> data < value){
        curr_p = curr_p->next;
    }

    if (curr_p == NULL || curr_p -> data > value){
//        printf("not member %d \n", value);
        return 0;
    }
    else{
//        printf("member %d \n", value);
        return 1;
    }
}

int Insert(int value, struct list_node** head_p){
    struct list_node *curr_p = *head_p;
    struct list_node *pred_p = NULL;
    struct list_node *temp_p = NULL;

    while (curr_p != NULL && curr_p->data < value){
        pred_p = curr_p;
        curr_p = curr_p->next;
    }

    if(curr_p == NULL || curr_p->data > value){
        temp_p = malloc(sizeof(struct list_node));
        temp_p -> data = value;
        temp_p -> next = curr_p;
        if(pred_p == NULL){
            *head_p = temp_p;
        }
        else{
            pred_p -> next = temp_p;
        }
//        printf("insert_success %d \n", value);
        return 1;
    }
    else{
        return 0;
    }
}

int Delete(int value, struct list_node ** head_p){
    struct list_node *curr_p = *head_p;
    struct list_node *pred_p = NULL;

    while (curr_p != NULL && curr_p->data < value){
        pred_p = curr_p;
        curr_p = curr_p->next;
    }
    if (curr_p != NULL && curr_p->data == value){
        if (pred_p == NULL){
            *head_p = curr_p ->next;
            free(curr_p);
        }
        else{
            pred_p->next = curr_p->next;
            free(curr_p);
        }
//        printf("delete_success %d \n", value);
        return 1;
    }
    else{
        return 0;
    }
}

void Print(struct list_node *head_p){
    struct list_node *curr_p = head_p;

    while (curr_p != NULL){
//        printf("node value: %d \n",curr_p->data);
        curr_p = curr_p->next;
    }
}

void destructor(struct list_node* head_p){
    struct list_node* curr_p = head_p;
    struct list_node* temp_p = NULL;

    while (curr_p != NULL)
    {
        temp_p = curr_p;
        curr_p = curr_p->next;
        free(temp_p);
    }
    printf("Entire linked list destructed!!\n");
}