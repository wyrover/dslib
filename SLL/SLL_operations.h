//
//  SLL_operations.h
//  SLL
//
//  Created by Anirudh Murali on 12/4/14.
//  Copyright (c) 2014 Anirudh Murali. All rights reserved.
//

#ifndef SLL_SLL_operations_h
#define SLL_SLL_operations_h

#include <stdio.h>
#include <stdlib.h>


/* typedefs and enums */
typedef struct nodeT{
    int data;
    struct nodeT* next;
}nodeT;


/*  Function Declaration */

nodeT* sll_create_list(int* array_data, int size);
int sll_append(nodeT** head, int data);
void sll_print_list(const nodeT* head);


#endif
