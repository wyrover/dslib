
/*
 *  circ_array.h
 *
 *  Created on: Oct 30, 2015
 *      Author: anirudhmurali
 *  1) Create  circ_array
 *  2) Enqueue node
 *  3) Deque node
 *  4) Free circ_array
 *
 *
 */


#ifndef __CIRC_ARRAY_H
#define __CIRC_ARRAY_H

typedef struct circ_array_s {
    int* buff_mem_ptr;
    int read_head;
    int write_head;
    int max_items;
} circ_array_t;


circ_array_t* circ_array_create(int num_items);
void circ_array_read(circ_array_t* array_handle, int* data);
void circ_array_write(circ_array_t* array_handle, int data);
void circ_array_print(circ_array_t* array_handle);

#define CIRC_ARRAY_IS_FULL(array_handle) ((array_handle->write_head + 1 )%(array_handle->max_items) == array_handle->read_head)
#define CIRC_ARRAY_IS_EMPTY(array_handle) (array_handle->write_head == array_handle->read_head)

#endif
