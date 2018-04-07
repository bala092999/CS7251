#include<stdio.h>
#include<malloc.h>

typedef enum bool {FALSE,TRUE} bool;

struct LIST_node {
	int data;
	struct LIST_node* next;
};
typedef struct LIST_node LIST;

struct queue_header {  //pointers to the linked LIST that really holds them. 
	LIST* front;
	LIST* rear;
};
typedef struct queue_header queue;

bool queue_empty(queue * Q){
	return Q->front == Q->rear;
}

queue * queue_new(){
	queue *Q;
	LIST* p;
	Q =(queue *) malloc(sizeof(struct queue_header));
	p = (LIST *)malloc(sizeof(struct LIST_node));
	Q->front = p;
	Q->rear = p;
	return Q;
}

void enq(queue *Q, int val){
	LIST* p = (LIST *)malloc(sizeof(LIST));
	Q->rear->data = val;
	Q->rear->next = p;
	Q->rear = p;
}

int deq(queue *Q){
	if (queue_empty(Q)) return -1;
	int val = Q->front->data;
	Q->front = Q->front->next;
	return val;
}

void display(queue *Q){
	if (queue_empty(Q)) return;
	printf("\n");
	LIST *temp=Q->front;
	while(temp!=Q->rear){
		printf(" %d",temp->data);
		temp=temp->next;
	}
}
