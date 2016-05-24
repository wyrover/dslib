//
//
//  dslib.h
//
//  Created by Anirudh Murali on 12/4/14.
//  Copyright (c) 2014 Anirudh Murali. All rights reserved.
//

#ifndef DSLIB_H
#define DSLIB_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

using namespace std;

typedef void (*ut_func_t)(void) ;

typedef enum dslib_ret_s {
    DSLIB_INV = -1,
    DSLIB_SUCCESS = 0,
    DSLIB_FAILURE = 1,
} dslib_ret_t;

/* Algorithmic API definitions */

bool bin_search(int arr[], int value, int num_elems, int* idx);
bool lin_search(int arr[], int value, int num_elems, int* idx);
void merge_sort(int a[], int low, int high);
void quick_sort(int a[], int left, int right);
void bubble_sort(int a[], int n);
void insertion_sort(int a[], int n);
void selection_sort(int a[], int n );
void swap(int& a, int& b);

#endif
