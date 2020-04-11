#pragma once
# include <stdio.h>
# include <stdlib.h>

typedef struct { // 요소 타입
	int id;
	int arrival_time;
	int service_time;
	int serviced_at;
} element;			
#define MAX_QUEUE_SIZE 30
typedef struct { // 큐 타입
	element  data[MAX_QUEUE_SIZE];
	int  front, rear;
} QueueType;

void error(char* message);
void init_queue(QueueType* q);
int is_empty(QueueType* q);
int is_full(QueueType* q);
void queue_print(QueueType* q);
void enqueue(QueueType* q, element item);
element dequeue(QueueType* q);
element peek(QueueType* q);