
/*
 *  circ_array.c
 *
 *  Created on: Oct 30, 2015
 *      Author: anirudhmurali
 *  1) Create  circ_array
 *  2) Enqueue node
 *  3) Deque node
 *  3) Print circ_array
 *  4) Free circ_array
 *
 *
 */

#include "circ_array.h"
#include "dslib.h"


circ_array_t* circ_array_create(int num_items)
{
    circ_array_t* array_handle = NULL;
    array_handle = (circ_array_t*)malloc(sizeof(circ_array_t));

    if(!array_handle) {

        return NULL;
    }
    array_handle->buff_mem_ptr = (int*)malloc(num_items*sizeof(int));

    if(!(array_handle->buff_mem_ptr)) {
        return NULL;
    }

    memset(array_handle->buff_mem_ptr, 0, num_items);
    array_handle->read_head = 0;
    array_handle->write_head = 0;
    array_handle->max_items = num_items;
    return array_handle;
}

void circ_array_read(circ_array_t* array_handle, int* data)
{
    if (!array_handle) {
         return;
    }

    if(CIRC_ARRAY_IS_EMPTY(array_handle)){
        data = NULL;
        printf("\n Nothing to read \n");
        return;
    }

    *data = array_handle->buff_mem_ptr[array_handle->read_head];
    array_handle->read_head = (array_handle->read_head + 1) % (array_handle->max_items);

}

void circ_array_write(circ_array_t* array_handle, int data)
{
    if (!array_handle) {
         return;
    }

    array_handle->buff_mem_ptr[array_handle->write_head] = data;
    array_handle->write_head = (array_handle->write_head + 1) % (array_handle->max_items);
    return;
}

void circ_array_print(circ_array_t* array_handle)
{

    int start = array_handle->read_head;
    int end   = array_handle->write_head;
    int i=0;
    if (!array_handle) {
        return;
    }

    if (start == end) {
        printf("\n Empty Array \n");
        return;
    }
    printf("\n");

    for (i=start; i!=end ; i++) {
        printf("\t%d", array_handle->buff_mem_ptr[i]);
    }
    printf("\n");
    return;
}
