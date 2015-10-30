//
//  main.c
//  Slist
//
//  Created by Anirudh Murali on 12/4/14.
//  Copyright (c) 2014 Anirudh Murali. All rights reserved.
//

#include "slist.h"
#include "circ_array.h"
#include "dslib.h"

static void print_array(int a[], int n)
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
    clock_t t;
    printf("\n<--------------- %s UT START -------------->\n",module_name);
    t = clock();
    (*ut_func)();
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("\n Time = %f seconds \n",time_taken);
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

void quick_sort_ut()
{
    int test_array [] = { 65,23,1,6,0,1,456,12 };
    printf("\nBefore Quick Sort \n");
    int n = sizeof(test_array)/sizeof(test_array[0]);
    print_array(test_array, n);
    quick_sort(test_array, 0, n - 1);
    printf("\nAfter Quick Sort \n");
    print_array(test_array, n);
    return;
}

void circ_array_ut()
{
    int read_data = 0;
    int i = 0;
    circ_array_t* test_hdl = NULL;
    test_hdl = circ_array_create(5);
    circ_array_write(test_hdl,13);
    circ_array_write(test_hdl,14);
    circ_array_write(test_hdl,15);
    circ_array_write(test_hdl,16);
    circ_array_write(test_hdl,18);
    circ_array_write(test_hdl,99);

    circ_array_print(test_hdl);
    for (i = 0 ; i < 5 ; i++) {
        circ_array_read(test_hdl, &read_data);
        circ_array_print(test_hdl);
    }


}

int main()
{
    run_ut(slist_ut, "slist");
    run_ut(merge_sort_ut,"merge_sort");
    run_ut(quick_sort_ut,"quick_sort");
    run_ut(circ_array_ut,"circ_array");
    return 0;
}
