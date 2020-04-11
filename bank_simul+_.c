#include "queue.h"
#include <time.h>

int get_count(QueueType q) {
	if (q.front > q.rear)
		q.rear += MAX_QUEUE_SIZE;
	int count = q.rear - q.front;
	return count;
}
void show_log(QueueType* q) {
	printf("�� ���� �α�\n");
	for (int i = 1; i <= get_count(*q); i++) {
		int wait_time = q->data[i].serviced_at - q->data[i].arrival_time;
		int end_clock = q->data[i].serviced_at + q->data[i].service_time;
			printf("[%2d]   %2d�� ����, [%2d�� ���]  %2d~%2d��\n"
				, q->data[i].id, q->data[i].arrival_time, wait_time, q->data[i].serviced_at, end_clock);
	}
}
void show_remain(QueueType* q) {
	printf("��� �� %d��\n", get_count(*q));
	for (int i = q->front + 1; i <= q->rear; i++) {
		int wait_time = 60 - q->data[i].arrival_time;
		printf("[%2d]   %2d�� ����, [%2d�� ���]  �۾��ð� %2d��\n"
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
		printf("����ð� = %d�� \t [%d�� ���]\n", clock, wait_custnum);

		if ((rand() % 10) < 3) {
			element customer;
			customer.id = total_customers++;
			customer.arrival_time = clock;
			customer.service_time = rand() % 3 + 1;
			enqueue(&cust_q, customer);
			printf("�� %d�� %d�п� ���ɴϴ�. ����ó���ð�= %d��\n",
				customer.id, customer.arrival_time, customer.service_time);
		}

		if (service_time > 0) {
			printf("�� %d ����ó�����Դϴ�. \n", service_customer);
			service_time--;
		}
		else {
			if (!is_empty(&cust_q)) {
				element customer = dequeue(&cust_q);
				service_customer = customer.id;
				service_time = customer.service_time;
				customer.serviced_at = clock;

				wait_time = clock - customer.arrival_time;
				printf("�� %d�� %d�п� ������ �����մϴ�. ���ð��� %d���̾����ϴ�.\n",
					customer.id, clock, wait_time);
				total_wait += wait_time;
				enqueue(&log_q, customer);
			}
		}
		printf("\n");
	}
	printf("��ü ��� �ð�=%d�� \n\n", total_wait);
	show_remain(&cust_q);
	show_log(&log_q);
	return 0;
}