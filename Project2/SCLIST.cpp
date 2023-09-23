#include<stdio.h>
#include<stdlib.h>

#define TRUE 1;
#define FALSE 0;

typedef struct Node {
	int data;
	struct Node* next;
}Node;

Node* inilist1() {
	Node* L = (Node*)malloc(sizeof(Node));
	L->data = 0;
	L->next = L;
	return L;
}

void headInsert1(Node* L, int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = L -> next;
	L->next = node;
	L->data++;
}

void tailInsert1(Node* L, int data) {
	Node* n = L;
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	while (n->next != L) {
		n = n->next;
	}
	node->next = L;
	n->next = node;
	L->data++;
}

int del(Node* L, int data) {
	Node* pre = L;
	Node* node = L->next;
	while (node != L) {
		if (node->data == data) {
			pre->next = node->next;
			free(node);
			L->data--;
			return TRUE;

		}
		pre = node;
		node = node->next;
	}
	return FALSE;
}

void printfun(Node* L) {
	Node* node = L->next;
	while (node != L) {
		printf("%d ", node->data);
		node = node->next;
	}
	printf("\n");
}

int main() {
	Node* L = inilist1();
	headInsert1(L, 1);
	headInsert1(L, 2);
	headInsert1(L, 3);
	headInsert1(L, 4);
	headInsert1(L, 5);
	tailInsert1(L, 6);
	tailInsert1(L, 7);
	tailInsert1(L, 8);
	tailInsert1(L, 9);
	tailInsert1(L, 10);
	printfun(L);


}