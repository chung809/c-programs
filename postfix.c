#include <stdio.h>
#include <stdlib.h>

#define DIGIT_0 48
#define DIGIT_9 57

char input_string[100];    
char op_set[5]={'^', '*', '/', '+', '-'};

struct stackNode {
  int data;
  struct stackNode *nextPtr;
};

typedef struct stackNode StackNode;     

int is_stack_empty(StackNode* head)
{
	return head == NULL ? 1 : 0;
}

StackNode *push(StackNode *head, int data)
{
	StackNode *tmp = (StackNode*)malloc(sizeof(StackNode));
	//printf("push:tmp=%p\n", tmp);
	tmp->data = data;
	//printf("data = %d\n", tmp->data);
	tmp->nextPtr = head;
	head = tmp; 
	//printf("push:head=%p\n", head);
	return head;
}

StackNode *pop(StackNode *head, int *data)
{
	StackNode *tmp = head;
	//printf("pop:tmp=%p\n", tmp);
	*data = head->data;
	//printf("*data=%d\n", *data);
	head = head-> nextPtr;
	//printf("pop:head=%p\n", head);
	free(tmp);
	return head;
}

void user_display(StackNode *head)
{
	StackNode *current;
	current = head;
	//printf("display:current=%p\n", current);
	if (current != NULL) {
		do {
			printf("%d", current->data);
			current = current->nextPtr;
		}
		while (current != NULL);
		printf("\n");
	}
	else
		printf("The Stack is empty\n");
}

int user_operator(int x, int y, char op)
{
	int i;
	switch (op) {
		case '^':
			if (x > 0) {
				for (i = 0; i < (x - 1); i++)
					y *=y;
			} else if (x == 0) {
				y = 1;
			} else {
				y *= y;
				y = 1/y;
			}			
			return (y);
		case '*':
			return (y * x);
		case '/':
			return (y / x);
		case '+':
			return (y + x);
		case '-':
			return (y - x);
		default:
			return 0;
	}		
}
						
int main()
{
	int i, j, x, y;
	StackNode *head = NULL;
	
	scanf("%s", input_string);
	i = 0;
	while (input_string[i] != 0) {
		if ((input_string[i] >= DIGIT_0) && (input_string[i] <= DIGIT_9)) {
			head = push(head, (input_string[i] - DIGIT_0));
		} else {
			for (j = 0; j < 5; j++) { 
				if ((input_string[i] == op_set[j])) {
					if(!is_stack_empty(head)) {
						head = pop(head, &x);
						//printf("x=%d\n", x);
					} else {
						printf("stack underflow!\n");
						return 1;
					}					
					if(!is_stack_empty(head)) {
						head = pop(head, &y);
						//printf("y=%d\n", y);
					} else {
						printf("stack underflow!\n");
						return 1;
					}
					head = push(head, user_operator(x, y, input_string[i]));
					//user_display(head);
				}
			}
		}
		i++;
	}
	while(!is_stack_empty(head)) {
		user_display(head);
		head = pop(head, &x);
	}	
	return 0;
}
