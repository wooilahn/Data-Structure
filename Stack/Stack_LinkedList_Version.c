#include <stdio.h>
#include <stdlib.h>

/* structure of Node */
typedef struct Node {
  int data;
  struct Node* next;
} Node;

/* structure of Stack */
typedef struct Stack {
  Node* top;
} Stack;

/* function to initialize stack */
void InitStack(Stack* stack) {
  stack->top = NULL;
  return;
}

/* function to check whether stack is empty or not */
int isEmpty(Stack* stack){
  return stack->top == NULL;
}

/* function to push the data in stack */
void Push(Stack* stack, int value) {
  Node* cur = (Node*)malloc(sizeof(Node));
  cur->data = value;
  cur->next = stack->top;
  stack->top = cur;

  printf("Succeed in Pushing the data: %d\n", value);
  return;
}

/* function to pop the data in stack */
int Pop(Stack* stack) {
  if(isEmpty(stack)){
    printf("Error: Stack is Empty.\n");
    return -404;
  }

  Node* cur =  stack->top;
  int res = cur->data;

  stack->top = cur->next;
  free(cur);

  printf("Succeed in Popping the data: %d\n", res);
  return res;
}

/* function to print all nodes(data) in stack */
void PrintAllNodes(Stack* stack){
  Node* cur = stack->top;
  int cnt = 1;

  printf("---------------------------------\n");
  if(cur == NULL){
    printf("There is no element in stack\n");
	return;
  }

  while(cur != NULL){
    printf("%d'th element is %d\n", cnt, cur->data); 
    cur = cur->next;
	cnt++;
  }

  return;
}

int main(){
  Stack st;
  InitStack(&st);

  Push(&st, 1);
  Push(&st, 2);
  Push(&st, 3);
  Push(&st, 4);
  PrintAllNodes(&st);

  Pop(&st);
  Pop(&st);
  PrintAllNodes(&st);

  return 0;
}
