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
#include "skip_list.h"

static void print_array(int a[], int n)
{
    int i=0;
    for (i=0; i < n; i++) {
        cout <<"\t " <<a[i];
    }
    cout<<endl;
    return;
}

static void run_ut(ut_func_t ut_func, const char* module_name)
{
    clock_t t;
    cout<<"\n<--------------- "<<module_name << " UT START -------------->\n";
    t = clock();
    (*ut_func)();
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    cout<<"\n Time = "<<time_taken<< "seconds \n";
    cout<<"\n<--------------- "<< module_name << " UT END  --------------->\n";
}

void slist_ut()
{
    slist_t* head      = NULL;
    int data_array[] = {1,3,2,2,4,5,5};

	slist_create_list(&head, data_array, sizeof(data_array)/sizeof(int));
	if (head == NULL) {
		cout <<"\nError in linked list creation.\n";
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
    cout <<"\nBefore Merge Sort \n";
    int n = sizeof(test_array)/sizeof(test_array[0]);
    print_array(test_array, n);
    merge_sort(test_array, 0, n - 1);
    cout<<"\nAfter Merge Sort \n";
    print_array(test_array, n);
    return;
}

void quick_sort_ut()
{
    int test_array [] = { 65,23,1,6,0,1,456,12 };
    cout<<"\nBefore Quick Sort \n";
    int n = sizeof(test_array)/sizeof(test_array[0]);
    print_array(test_array, n);
    quick_sort(test_array, 0, n - 1);
    cout <<"\nAfter Quick Sort \n";
    print_array(test_array, n);
    return;
}

void bubble_sort_ut()
{
    int test_array [] = { 65,23,1,6,0,1,456,12 };
    cout<<"\nBefore Bubble Sort \n";
    int n = sizeof(test_array)/sizeof(test_array[0]);
    print_array(test_array, n);
    bubble_sort(test_array,n);
    cout <<"\nAfter Bubble Sort \n";
    print_array(test_array, n);
    return;
}

void selection_sort_ut()
{
    int test_array [] = { 65,23,1,6,0,1,456,12 };
    cout<<"\nBefore Selection Sort \n";
    int n = sizeof(test_array)/sizeof(test_array[0]);
    print_array(test_array, n);
    selection_sort(test_array,n);
    cout <<"\nAfter Selection Sort \n";
    print_array(test_array, n);
    return;
}

void insertion_sort_ut()
{
    int test_array [] = { 65,23,1,6,0,1,456,12 };
    cout<<"\nBefore Insertion Sort \n";
    int n = sizeof(test_array)/sizeof(test_array[0]);
    print_array(test_array, n);
    insertion_sort(test_array,n);
    cout <<"\nAfter Insertion Sort \n";
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
void bin_search_ut()
{
    int idx = 0, value = 1;
    int test_array [] = { 65,23,1,6,0,1,456,12 };
    int num_elems = sizeof(test_array)/sizeof(test_array[0]);

    if (bin_search(test_array, value, num_elems,  &idx)) {
        cout << "Found value  " << value << " index: "<<idx<<endl;
    } else {
            cout << "Could not find value  :" << value;
    }

}

void lin_search_ut()
{
    int idx = 0, value = 1;

    int test_array [] = { 65,23,1,6,0,1,456,12 };
    int num_elems = sizeof(test_array)/sizeof(test_array[0]);
    if (lin_search(test_array, value, num_elems, &idx)) {
        cout << "Found value " << value << " index: "<<idx<<endl;
    } else {
        cout << "Could not find value  :" << value;
    }
}


void skip_list_ut()
{
      SkipList* sk_lst = new SkipList();

      sk_lst->insertNode(1);
      sk_lst->printAllRows();
      sk_lst->insertNode(23);
      sk_lst->printAllRows();
      sk_lst->insertNode(55);
      sk_lst->printAllRows();
      sk_lst->insertNode(57);
      sk_lst->printAllRows();
      sk_lst->insertNode(22);
      sk_lst->printAllRows();
      sk_lst->deleteNode(1);
      sk_lst->printAllRows();
      SkipListNode* pTemp =sk_lst->searchNode(55);
      if(pTemp) {
        cout <<"Found 55"<<endl;
      }

       pTemp =sk_lst->searchNode(1);
      if(pTemp) {
        cout <<"Found 1" <<endl;
      }

       pTemp =sk_lst->searchNode(22);
      if(pTemp) {
        cout <<"Found 22"<<endl;
      }
      sk_lst->printAllRows();
}

int main()
{
    #ifdef ALL_UT
    run_ut(slist_ut, "slist");
    run_ut(merge_sort_ut,"merge_sort");
    run_ut(quick_sort_ut,"quick_sort");
    run_ut(selection_sort_ut,"selection_sort");
    run_ut(insertion_sort_ut,"insertion_sort");
    run_ut(bubble_sort_ut,"bubble_sort");
    run_ut(circ_array_ut,"circ_array");
    run_ut(lin_search_ut, "lin_search");
    run_ut(bin_search_ut, "bin_search");
    #endif
    run_ut(skip_list_ut,"skip_list");
    return 0;
}
