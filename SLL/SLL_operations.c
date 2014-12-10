
/*
 * SLL_operations.c
 *
 *  Created on: Dec 3, 2014
 *      Author: anirudhmurali
 *  This file supports the following SLL operations
 *
 *  1) Create Node
 *  2) Insert (insert start, insert after, append)
 *  3) Delete all occurences
 *  4) Reverse
 *  5) Combine & Sort (Given the heads of the 2 lists)
 *  6) Create a list (Given an array)
 *  7) Print elements
 *  8) Modify an element (Given the index)
 *
 */

#include "SLL_operations.h"

/*
 * Input: Data to initialize
 * Output: A new node initialized to data
 */
static nodeT* sll_create_node(int data)
{
    nodeT* new_node;
    new_node = (nodeT*)malloc(sizeof(nodeT));
    new_node-> data = data;
    new_node-> next = NULL;
    return new_node;
}


/*
 * Input: Head of the list, data to append
 * Output: Success or Failure
 */
int sll_append(nodeT** head, int data)
{
    nodeT* temp = *head;
    if (head == NULL) {
        
        return -1;
    }
    while(temp->next !=NULL) {
        temp = temp->next;
    }
    temp->next = sll_create_node(data);
    return 0;
}

/*
 * Input: Array to initialize the list with
 * Output: The head of the newly created list
 */
nodeT* sll_create_list(int array_data[], int size)
{
    nodeT* head = NULL;
    int i = 0;
    
    for (i=0; i<size; i++) {
        if (head == NULL ) {
            /* Create the head */
            head = (nodeT*)malloc(sizeof(nodeT));
            head->data = array_data[0];
        } else {
            sll_append(&head,array_data[i]);
        }
    }
    
    return head;
}

void sll_print_list(const nodeT* head)
{
    
    nodeT* temp = head;
    printf("\n");
    while(temp!= NULL) {
        printf("\t %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void sll_reverse(nodeT** head)
{
    nodeT* curr = *head;
    nodeT* prev = NULL;
    nodeT* next = NULL;
    
    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

void sll_delete(nodeT** head, int value)
{
    nodeT* prev = NULL;
    nodeT* curr = *head;
    
    if (!(*head))
    {
        return;
    }
    
    while (curr)
    {
        if ((*head)->data == value) {
            prev = curr;
            curr = curr->next;
            *head = curr;
            free(prev);
            continue;
        }
        if (curr->data == value)
        {
            prev->next = curr->next;
            free(curr);
            curr = prev->next;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
    return;
    
}


