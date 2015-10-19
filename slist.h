//
//  SLL_operations.h
//  SLL
//
//  Created by Anirudh Murali on 12/4/14.
//  Copyright (c) 2014 Anirudh Murali. All rights reserved.
//

#ifndef SLIST_H
#define SLIST_H

#include <stdio.h>
#include <stdlib.h>


/* typedefs and enums */
typedef struct nodeT{
    int data;
    struct nodeT* next;
}nodeT;


/*  Function Declaration */

nodeT* slist_create_list(int* array_data, int size);
int slist_append(nodeT** head, int data);
void slist_print_list(nodeT* head);
void slist_reverse(nodeT** head);
void slist_delete(nodeT** head, int data);
void slist_insert_after(nodeT* head, int value_to_insert, int value_after);
nodeT* slist_combine_lists(nodeT* head_1, nodeT* head_2);

#endif
