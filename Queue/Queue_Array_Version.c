#define MAX_QUEUE_SIZE 10
#include <stdio.h>

int Queue[MAX_QUEUE_SIZE];
int front, rear;

void InitQueue(){
  front = 0;
  rear = 0;
  return;
}

void EnQueue(int data){
  if((rear+1)%MAX_QUEUE_SIZE == front){
    printf("Error: Queue is full\n");
	return;
  }

  Queue[rear++] = data;
  rear %= MAX_QUEUE_SIZE;
  return;
}

int DeQueue(){
  if(front == rear){
    printf("Error: Queue is Empty.\n");
	return -404;
  }
  
  int res = Queue[front++];
  front %= MAX_QUEUE_SIZE;
  return res;
}

int getFrontValue(){
  if(front == rear){
    printf("Error: Queue is Empty.\n");
	return -404;
  }

  return Queue[front];
}

void PrintQueue(){
  if(front == rear){
    printf("There is no data in Queue\n");
	return;
  }

  printf("----------------------------------------\n");
  printf("Print All data in Queue (front -> rear)\n");
  int cnt = 1;

  for(int idx=front; idx!=rear; idx++){
    idx %= MAX_QUEUE_SIZE;
    printf("%d'th element in Queue: %d\n", cnt++, Queue[idx]);
  }

  return;
}

int main(){
  InitQueue();

  EnQueue(1);
  EnQueue(2);
  EnQueue(3);
  EnQueue(4);
  PrintQueue();

  DeQueue();
  DeQueue();
  PrintQueue();

  printf("Current Front value in Queue: %d\n", getFrontValue());

  return 0;
}

