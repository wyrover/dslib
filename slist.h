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
typedef struct slist_s{
    int data;
    struct slist_s* next;
}slist_t;


/*  Function Declaration */

slist_t* slist_create_list(int* array_data, int size);
int slist_append(slist_t** head, int data);
void slist_print_list(slist_t* head);
void slist_free_list(slist_t* head);
void slist_reverse(slist_t** head);
void slist_delete(slist_t** head, int data);
void slist_insert_after(slist_t* head, int value_to_insert, int value_after);
void slist_insert_before(slist_t* head, int value_to_insert, int value_before);
slist_t* slist_combine_lists(slist_t* head_1, slist_t* head_2);

#endif
