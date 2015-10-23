//
//
//  dslib.h
//
//  Created by Anirudh Murali on 12/4/14.
//  Copyright (c) 2014 Anirudh Murali. All rights reserved.
//

#ifndef DSLIB_H
#define DSLIB_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>


typedef void (*ut_func_t)(void) ;

typedef enum dslib_ret_s {
    DSLIB_INV = -1,
    DSLIB_SUCCESS = 0,
    DSLIB_FAILURE = 1,
} dslib_ret_t;

/* Algorithmic API definitions */


void merge_sort(int a[], int low, int high);

#endif
