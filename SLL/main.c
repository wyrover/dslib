//
//  main.c
//  SLL
//
//  Created by Anirudh Murali on 12/4/14.
//  Copyright (c) 2014 Anirudh Murali. All rights reserved.
//

#include <stdio.h>

#include "SLL_operations.h"


int main()
{
    nodeT* head = NULL;
    int data_array[] = {1,2,3,4,5};
    head = sll_create_list(data_array, sizeof(data_array)/sizeof(int));
    sll_print_list(head);
    return 0;
}
