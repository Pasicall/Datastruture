#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
}Node;

Node* initStack() {
	Node* L = (Node*)malloc(sizeof(Node));
	L->data = 0;
	L->next = NULL;
	return L;
}

int isEmpty(Node* L) {
	if (L->data == 0 || L->next == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}

void push(Node* L, int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = L->next;
	L -> next = node;
	L->data++;
}

int pop(Node* L) {
	if (L->data == 0) {
		return 0;
	}
	else {
		Node* node = L->next;
		int data = L->data;
		L->next = node->next;
		free(node);
		L->data--;
		return data;
	}
}

void printStack(Node* stack) {
	Node* node = stack->next;
	while (node) {
		printf("%d -> ", node->data);
		node = node->next;
	}
	printf("NULL\n");
}

int main() {
	Node* Stack = initStack();
	push(Stack, 1);
	push(Stack, 2);
	push(Stack, 3);
	push(Stack, 4);
	push(Stack, 5);
	printStack(Stack);
	printf("pop: %d \n", pop(Stack));
	printStack(Stack);
}