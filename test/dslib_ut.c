//
//  main.c
//  Slist
//
//  Created by Anirudh Murali on 12/4/14.
//  Copyright (c) 2014 Anirudh Murali. All rights reserved.
//

#include "slist.h"
#include "dslib.h"

static void print_array(int a[], int n )
{
    int i=0;
    for (i=0; i < n; i++) {
        printf("\t %d",a[i]);
    }
    printf("\n");
    return;
}

static void run_ut(ut_func_t ut_func, const char* module_name)
{
    printf("\n<--------------- %s UT START -------------->\n",module_name);
    (*ut_func)();
    printf("\n<--------------- %s UT END  --------------->\n",module_name);
}

void slist_ut()
{
    slist_t* head      = NULL;
    int data_array[] = {1,3,2,2,4,5,5};
  
	slist_create_list(&head, data_array, sizeof(data_array)/sizeof(int));
	if (head == NULL) {
		printf("\nError in linked list creation.\n");
		return;
	}
    slist_print_list(head);
    slist_insert_after(head,77,1);
    slist_print_list(head);
    slist_free_list(head);
    return;
}


void merge_sort_ut()
{
    int test_array [] = { 65,23,1,6,0,1,456,12 };
    printf("\nBefore Merge Sort \n");
    int n = sizeof(test_array)/sizeof(test_array[0]);
    print_array(test_array, n);
    merge_sort(test_array, 0, n - 1);
    printf("\nAfter Merge Sort \n");
    print_array(test_array, n);
    return;
}

int main()
{
    run_ut(slist_ut, "slist");
    run_ut(merge_sort_ut,"merge_sort");
    return 0;
}
