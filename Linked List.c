#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node * next;
} Node;

typedef struct list {
  Node *head;
} List;

List *emptylist(){
  List *list = malloc(sizeof(List));
  list->head = NULL;
  return list;
}

Node *createnode(int data){
  Node *newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

void display(List *list) {
  Node *current = list->head;
  if(list->head == NULL) return;
  while(current->next != NULL){
    printf("%d,",current->data);
    current = current->next;
  }
  printf("%d\n", current->data);
}
//Display using recursion
void recdisplay(List list){
    if (list.head==NULL) return;
    printf("%d,",(list.head->data));
    List temp = list;
    temp.head = temp.head->next;
    recdisplay(temp);
}
//Display reverse using recursion
void reversedis (List list) {
    if (list.head == NULL) {
        return;
    }
    List temp = list;
    temp.head = temp.head->next;
    reversedis(temp);
    printf("%d,", list.head->data);
}

// Size using recursion
int size(List list){
    if (list.head==NULL) return 0;
    list.head=list.head->next;

    return 1+size(list);

}

//Insertions
void insertfirst(int val, List *list){
        Node *s=createnode(val);
        s->next=list->head;
        list->head=s;

}
void insertatend(int data, List *list){
  Node *current = NULL;
  if(list->head == NULL){
    list->head = createnode(data);
  }
  else {
    current = list->head;
    while (current->next!=NULL){
      current = current->next;
    }
    current->next = createnode(data);
  }
}

void insertat(int val,int pos,List *list){
    if(pos==0){
        insertfirst(val,list);
        return;
    }
    Node *temp;
    temp=list->head;
    Node *s;
    s=createnode(val);
    int i;
    for(i=0;i<pos-1;i++){
            temp=temp->next;
    }

    if (temp->next==NULL &&pos==i+1){
        insertatend(val,list);
        return;
    }
    s->next=temp->next;
    temp->next=s;
}


//deletions
void deleteval(int data, List *list){
  Node *current = list->head;
  Node *previous = current;
  while(current != NULL){
    if(current->data == data){
      previous->next = current->next;
      if(current == list->head)
        list->head = current->next;
      free(current);
      return;
    }
    previous = current;
    current = current->next;
  }
}

void deleteend(List *list){
    if (size(*list)==0){
            printf("\nList is empty");
            return;
    }
    Node* temp;
    temp=list->head;
    int i;
    for(i=0;temp->next->next!=NULL;i++){
            temp=temp->next;
    }
    free(temp->next->next);
    temp->next=NULL;
}

void deletefirst(Node **head){
    Node* temp=*head;
    temp = temp->next;
    free(head);
    *head=temp;
}

void deletemid(List *list){
    if (size(*list)==0){
            printf("\nList is empty");
            return;
    }
    Node* prev;
    Node* temp1=list->head;
    Node* temp2=list->head;
    while(temp1!=NULL && temp1->next!=NULL){
            temp1=temp1->next->next;
            prev=temp2;
            temp2=temp2->next;
    }
    prev->next=temp2->next;
    free(temp2);
}

void destroy(List *list){
  Node *current = list->head;
  Node *next ;
  while(current != NULL){
    next = current->next;
    free(current);
    current = next;
  }
  free(list);
}

//END
