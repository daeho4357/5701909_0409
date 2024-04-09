#include <stdio.h>
#define MAX_STACK_SIZE 5
#include <time.h>
#include <stdlib.h>

typedef int element;
element stack[MAX_STACK_SIZE];
int top = -1;

//is_full
int is_full() {
	//if (top == MAX_STACK_SIZE - 1) return 1;
	//else return 0;
	return(top == MAX_STACK_SIZE - 1); //()의 내용이 참이냐? 거짓 = 0 참 = 1(0을 제외한 모든 숫자)이 출력
}

int is_empty() {
	//if (top == -1) return 1;
	//else return 0;
	return(top == -1);
}


void push(element item) {
	if (is_full()) {
		fprintf(stderr, "Stack is FULL\n");
		return;
	}
	else
	{
		top = top + 1;
		stack[top] = item;
	}
}

element pop() {
	element r;
	if (is_empty()) {
		fprintf(stderr, "Stack is empty\n");
		return -1;
	}
	else
	{
		//r = stack[top];
		//top = top - 1;
		//return r;
		return(stack[top--]);
	}
}


element peek() {

	element r;
	if (is_empty()) {
		fprintf(stderr, "Stack is empty\n");
		exit(1);
	}
	else
	{
		//r = stack[top];
		//top = top - 1;
		//return 1;
		return(stack[top--]);
	}
}

void print_stack() {
    if (is_empty()) {
        printf("Stack is empty\n");
    }
    else {
        printf("Stack elements: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
	printf("\n");
}




int main() {
    srand(time(NULL));
    int i;



    for (i = 0; i < 30; i++) {
        int rand_num = rand() % 100 + 1;
		printf("Current rand_num : %d | %s\n", rand_num, (rand_num % 2 == 0) ? "Even" : "Odd");
        if (rand_num % 2 == 0) {
            if (!is_full()) {
                push(rand_num);
                printf("Push : %d\n", rand_num);
                print_stack();
            }
            else {
                printf("Stack is FULL\n\n");
            }
        }

        else {
            if (!is_empty()) {
                int pop_item = pop();
                printf("Pop : %d\n", pop_item);
                print_stack();
            }
            else {
                printf("Stack is empty\n\n");
            }
        }
    }
    return 0;
}














