
/*
 * slist.c
 *
 *  Created on: Dec 3, 2014
 *      Author: anirudhmurali
 *  This file supports the following SLL operations
 *
 *  1) Create Node
 *  2) Insert after
 *  3) Delete all occurences
 *  4) Reverse
 *  5) Combine & Sort (Given the heads of the 2 lists)
 *  6) Create a list (Given an array)
 *  7) Print elements
 *  8) Modify an element (Given the index)
 *
 *  TODO :
 *  1. Delete nth element from the last.
 *
 */

#include "slist.h"
#include "dslib.h"

/*
 * Input: Data to initialize
 * Output: A new node initialized to data
 */
static slist_t* slist_create_node(int data)
{
    slist_t* new_node;
    new_node = (slist_t*)malloc(sizeof(slist_t));
    if(!new_node) {
        return NULL;
    }
    new_node-> data = data;
    new_node-> next = NULL;
    return new_node;
}


/*
 * Input: Head of the list, data to append
 * Output: Success or Failure
 */
int slist_append(slist_t** head, int data)
{
	
    slist_t* temp = *head;

    if (temp == NULL) {

        return -1;
    }
	
    while(temp->next !=NULL) {
        temp = temp->next;
	
    }
    temp->next = slist_create_node(data);
    return 0;
}

/*
 * Input: Array to initialize the list with
 * Output: The head of the newly created list
 */
void slist_create_list(slist_t** head, int array_data[], int size)
{
    int i = 0;
	int app_ret = 0;
    for (i=0; i<size; i++) {
        if ((*head) == NULL ) {
            /* Create the head */
            *head = (slist_t*)malloc(sizeof(slist_t));
            if(!(*head)) {
                return ;
            }
            (*head)->data = array_data[0];
			(*head)->next = NULL;
        } else {
            app_ret = slist_append(head,array_data[i]);
			if (app_ret == -1) {
				*head = NULL;
				return;
			}
        }
    }

    return ;
}

void slist_free_list(slist_t* head)
{

    slist_t* temp = NULL;
    temp = head;
    while(temp){
        free(temp);
        temp = temp->next;
    }
}

void slist_print_list(slist_t* head)
{

    slist_t* temp = NULL;
    temp = head;
    printf("\n");
    while(temp!= NULL) {
        printf("\t %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void slist_reverse(slist_t** head)
{
    slist_t* curr = *head;
    slist_t* prev = NULL;
    slist_t* next = NULL;

    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

void slist_delete(slist_t** head, int value)
{
    slist_t* prev = NULL;
    slist_t* curr = *head;

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

void slist_insert_after(slist_t* head, int value_to_insert, int value_after)
{
    slist_t* curr = head;
    slist_t* next = NULL;

    while(curr) {
        if(curr->data == value_after){
            slist_t* temp = slist_create_node(value_to_insert);
            next = curr->next;
            curr->next = temp;
            temp->next = next;
            return;
        } else {
            curr= curr->next;
        }
    }
}



slist_t* slist_combine_lists(slist_t* head_1, slist_t* head_2)
{
    return NULL;
}
