//
//  main.c
//  Slist
//
//  Created by Anirudh Murali on 12/4/14.
//  Copyright (c) 2014 Anirudh Murali. All rights reserved.
//

#include "slist.h"
#include "dslib.h"


int main()
{
    slist_t* head      = NULL;
    int data_array[] = {1,3,2,2,4,5,5};
    head             = slist_create_list(data_array, sizeof(data_array)/sizeof(int));
    slist_print_list(head);
    slist_insert_after(head,77,1);
    slist_print_list(head);
    slist_free_list(head);
    return 0;
}
