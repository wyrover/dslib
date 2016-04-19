
/*
 *  queue.h
 *
 *  Created on: Oct 30, 2015
 *      Author: anirudhmurali
 *  1) Create  queue
 *  2) Enqueue node
 *  3) Deque node
 *  3) Print queue
 *  4) Free queue
 *
 *
 */

typedef struct queue_s {
    int* mem_buff_ptr;
    int front;
    int rear;
    int curr_items;
    int  max_items;
} queue_t;

void queue_create(queue_t* queue_handle, int num_items);
void queue_read(queue_t* queue_handle, int num_items);
void queue_write(queue_t* queue_handle, int num_items);
