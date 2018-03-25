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
// Some Test Cases
void main(){
    Q *q=createq();
    int i,d;
    for(i=0;i<10;i++){
        enque(q,i);
    }
    printf("\nInitially\n");
    print(q);

    printf("\n\nTrying to enter an element\n");
    if(enque(q,89))
        printf("\nInserted:%d\n",i);
    else printf("Full\n");
    printf("\nDeleting one element");
    d==deque(q);
    if(d!=-1)printf("\nDeleted element is %d",d);
    else printf("\nDeletion unsuccessful");

    print(q);
    printf("\n\nSize: %d",qsize(q));
    if(enque(q,25))
        printf("\nInserted:%d\n",25);
    print(q);
    printf("\n\nSize: %d\n",qsize(q));
    int e=qsize(q);
    for(i=0;i<e;i++){
        deque(q);
    }
    print(q);
    printf("\nTrying to insert");
    if(enque(q,89))
        printf("\n\nInserted:%d\n",89);
    print(q);
    printf("\n\nSize: %d",qsize(q));
}
