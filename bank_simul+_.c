#include "queue.h"
#include <time.h>

int get_count(QueueType q) {
	if (q.front > q.rear)
		q.rear += MAX_QUEUE_SIZE;
	int count = q.rear - q.front;
	return count;
}
void show_log(QueueType* q) {
	printf("고객 서비스 로그\n");
	for (int i = 1; i <= get_count(*q); i++) {
		int wait_time = q->data[i].serviced_at - q->data[i].arrival_time;
		int end_clock = q->data[i].serviced_at + q->data[i].service_time;
			printf("[%2d]   %2d분 도착, [%2d분 대기]  %2d~%2d분\n"
				, q->data[i].id, q->data[i].arrival_time, wait_time, q->data[i].serviced_at, end_clock);
	}
}
void show_remain(QueueType* q) {
	printf("대기 고객 %d명\n", get_count(*q));
	for (int i = q->front + 1; i <= q->rear; i++) {
		int wait_time = 60 - q->data[i].arrival_time;
		printf("[%2d]   %2d분 도착, [%2d분 대기]  작업시간 %2d분\n"
			, q->data[i].id, q->data[i].arrival_time, wait_time, q->data[i].service_time);
	}
	printf("\n");
}
int main(void)
{
	int minutes = 60;
	int total_wait = 0;
	int total_customers = 0;
	int service_time = 0;
	int service_customer, wait_time;
	QueueType cust_q, log_q;
	init_queue(&cust_q);
	init_queue(&log_q);

	srand(time(NULL));
	for (int clock = 0; clock < minutes; clock++) {
		int wait_custnum = get_count(cust_q);
		printf("현재시각 = %d분 \t [%d명 대기]\n", clock, wait_custnum);

		if ((rand() % 10) < 3) {
			element customer;
			customer.id = total_customers++;
			customer.arrival_time = clock;
			customer.service_time = rand() % 3 + 1;
			enqueue(&cust_q, customer);
			printf("고객 %d이 %d분에 들어옵니다. 업무처리시간= %d분\n",
				customer.id, customer.arrival_time, customer.service_time);
		}

		if (service_time > 0) {
			printf("고객 %d 업무처리중입니다. \n", service_customer);
			service_time--;
		}
		else {
			if (!is_empty(&cust_q)) {
				element customer = dequeue(&cust_q);
				service_customer = customer.id;
				service_time = customer.service_time;
				customer.serviced_at = clock;

				wait_time = clock - customer.arrival_time;
				printf("고객 %d이 %d분에 업무를 시작합니다. 대기시간은 %d분이었습니다.\n",
					customer.id, clock, wait_time);
				total_wait += wait_time;
				enqueue(&log_q, customer);
			}
		}
		printf("\n");
	}
	printf("전체 대기 시간=%d분 \n\n", total_wait);
	show_remain(&cust_q);
	show_log(&log_q);
	return 0;
}