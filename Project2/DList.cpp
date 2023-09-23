#include<stdio.h>
#include<stdlib.h>
#define True 1;
#define False 0;

typedef struct Node {
	int data;
	struct Node* pre;
	struct Node* next;
}Node;

Node* initList() {
	Node* L = (Node*)malloc(sizeof(Node));
	L->data = 0;
	L->pre = NULL;
	L->next = NULL;
	return L;
}

void headInsert(Node* L,int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = L->next;
	node -> pre = L;
	if (L->next) {
		L->next->pre = node;
		L->next = node;
	}
	else {
		L->next = node;
	}
}

void tailInsert(Node* L, int data) {
	Node* n = (Node*)malloc(sizeof(Node));
	Node* node = L;
	n->data = data;
	while (node->next) {
		node = node->next;
	}
	n->next = node->next;
	node->next = n;
	n->pre = node;
	L->data++;
}

int listdelete(Node* L, int data) {
	Node* node = L->next;
	while (node) {
		if (node->data == data) {
			node->pre->next = node->next;
			if (node->next) {
				node->next->pre = node->pre;
			}
			L->data--;
			free(node);
			return True;
		}
		node = node->next;
	}
	
	return False;
}

void PrintList(Node* L) {
	Node* node = L->next;
	while(node) {
		printf("%d", node->data);
		node = node->next;
	}
	printf("\n");
}

int main() {
	Node* L=initList();
	headInsert(L, 1);
	headInsert(L, 2);
	headInsert(L, 3);
	headInsert(L, 4);
	headInsert(L, 5);
	tailInsert(L, 6);
	tailInsert(L, 7);
	listdelete(L, 7);
	PrintList(L);
}