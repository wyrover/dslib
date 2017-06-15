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
#include "bst.h"
#include "disjoint_set.h"
#include "graph.h"
#include "matrix.h"

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

      sk_lst->insert(1);
      sk_lst->print();
      sk_lst->insert(23);
      sk_lst->print();
      sk_lst->insert(55);
      sk_lst->print();
      sk_lst->insert(57);
      sk_lst->print();
      sk_lst->insert(22);
      sk_lst->print();
      sk_lst->remove(1);
      sk_lst->print();

      sk_lst->remove(22);
      sk_lst->print();
      sk_lst->remove(57);
      sk_lst->print();
      sk_lst->remove(1);
      sk_lst->print();
      SkipListNode* pTemp =sk_lst->search(55);
      if(pTemp) {
        cout <<"Found 55"<<endl;
      }

       pTemp =sk_lst->search(1);
      if(pTemp) {
        cout <<"Found 1" <<endl;
      }

       pTemp =sk_lst->search(22);
      if(pTemp) {
        cout <<"Found 22"<<endl;
      }

      sk_lst->remove(23);
      sk_lst->print();

      sk_lst->remove(55);
      sk_lst->print();
}

void bst_ut()
{
    Bst* tree_1 = new Bst();
    tree_1->insert(43);
    tree_1->insert(32);
    tree_1->insert(12);
    tree_1->insert(12);
    tree_1->insert(64);
    tree_1->insert(56);
    tree_1->insert(72);
    tree_1->inOrder();
    BstNode* closest_node = tree_1->findAncestor(72);
    cout << "\n Closest Node to 72 is "<< closest_node->getData();
  }

void djset_ut()
{
    vector<int> inp_groups;
    inp_groups.push_back(1);
    inp_groups.push_back(2);
    inp_groups.push_back(3);
    inp_groups.push_back(4);
    inp_groups.push_back(5);

    DisjointSet djs(inp_groups);
    cout << djs;
    djs.makeSet(1,2);
    djs.makeSet(2,3);
    djs.makeSet(1,3);
    cout << djs;

}

void graph_ut()
{
    Graph* g = new Graph();
    g->addVertex("0");
    g->addVertex("1");
    g->addVertex("2");
    g->addVertex("3");

    g->addEdge("0", "1",1);
    g->addEdge("0", "2",1);
    g->addEdge("1", "2",1);
    g->addEdge("2", "0",1);
    g->addEdge("2", "3",1);
    g->addEdge("3", "3",1);
    g->bfs("2");
    //g->bfs("2");
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
    run_ut(skip_list_ut,"skip_list");
    run_ut(djset_ut, "disjoint_set");
    run_ut(graph_ut, "graph");
    #endif
    run_ut(bst_ut, "bst");
    return 0;
}
