#include <stdio.h>
#include <stdbool.h>
#define SIZE 6

int isEmpty(Qnode* pq);
int isFull(Qnode* pq);
void enQueue(Qnode* pq, int data);	// q에 삽입
int deQueue(Qnode* pq);		// q에서 제거

int rear = 0;
int front = 0;
int queue[SIZE];


typedef struct qnode {
	int data;
	int rear, front;
	// struct qnode* next;
}Qnode;

//typedef struct {
//	Qnode* front;
//	Qnode* rear;
//}Qp;


void intiQueue(Qnode* pq)
{
	pq->front = 0;
	pq->rear = 0;
	pq->data = 0;
}


int main()
{
	Qnode* pq;
	initQueue(&pq);
	/*enQueue(Q, 10);
	enQueue(Q, 20);
	enQueue(Q, 30);*/
	

	return 0;
}

int isEmpty(Qnode *pq)
{
	if (pq->rear == pq->front) return true;
	else return false;
}
int isFull(Qnode* pq)
{
	if (pq->front == (pq->rear + 1) % SIZE) return true;
	else return false;
}
void enQueue(Qnode* pq, int data)
{
	if (isFull(pq))	printf("Queue Overflow!!\n");
	else
	{
		queue[(pq->rear++) % SIZE] = data;
	}
}
int deQueue(Qnode* pq)
{
	if (isEmpty(pq))
	{
		printf("Queue Underflow!!\n");
		return;
	}
	else
	{

	}
}