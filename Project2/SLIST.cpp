#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
}Node;

Node* initList() {
	Node* list = (Node*)malloc(sizeof(Node));
	list->data = 0 ;
	list->next = NULL;
	return list;
}

void headInsert(Node* list, int data) {
	Node* node = (Node*)malloc(sizeof(node));
	node -> data = data;
	node -> next = list -> next;
	list->next = node;
	list->data++;
}

void tailInsert(Node* list, int data) {
	Node* head = list;
	Node* node = (Node*)malloc(sizeof(node));
	node->data = data;
	node->next = NULL;
	list = list->next;
	while (list->next) {
		list = list->next;
	}
	list->next = node;
	head->data++;
}

void print(Node* list) {
	list = list->next;
	while (list) {
		printf("%d", list->data);
		list = list->next;
	}
}

void Delete(Node* list, int data) {
	Node* pre = list;
	Node* current = list->next;
	while (current) {
		if (current->data == data) {
			pre->next = current->next;
			free(current);
			break;
		}
		pre = current;
		current = current->next;
	}
	list->data--;
}
int main() {
	Node* list = initList();
	headInsert(list, 1);
	headInsert(list, 2);
	headInsert(list, 3);
	headInsert(list, 4);
	headInsert(list, 5);
	
	Delete(list, 1);

	print(list);
	return 0;
}