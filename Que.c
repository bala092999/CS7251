#include<stdio.h>
#include<malloc.h>
#define MAX 10
typedef enum BOOL{false,true} Bool;

typedef struct {
	int q[MAX];
	int front,rear;
}Q;

Q *createq(){
    Q *que;
    que=(Q*)malloc(sizeof(Q));
    que->front=0;
    que->rear=0;
    return que;
}

Bool isempty(Q *que){
    if(que->rear==que->front) return 1;
    return 0;
}
Bool isfull(Q *que){
    if((que->rear+1)%MAX==que->front) return 1; // when the position next to rear is front, the list is full
    return 0;
}

Bool enque(Q *que,int val){
    if(isfull(que)) return 0;
    que->rear=(que->rear+1)%MAX;
    que->q[que->rear]=val;
}

int deque(Q *que){
    if (isempty(que)){
    	que->front=0;
   		que->rear=0;
    	return -1;
    }
    que->front=(que->front+1)%MAX;
    int val=que->q[que->front];
    return val;
}
int qsize(Q *q){
    int size=(q->rear-q->front+MAX)%MAX;
    return size;
}
void print(Q *que){
    int i;
    printf("\nThe queue is: \n");
    if(!isempty(que))
    {
        for(i=que->front+1;i!=que->rear;i=(i+1)%MAX)
            printf("%d ",que->q[i]);
        printf("%d",que->q[i]);
    }
    else printf("Empty");
}
