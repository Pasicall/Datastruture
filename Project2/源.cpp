#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	Node* pre;
	Node* next;
}Node;

Node* initList() {
	Node* L = (Node*)malloc(sizeof(Node));
	L->data = 0;
	L->next = L;
	L->pre = L;
	return L;
}

void headInsert(Node* L, int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = L->next;
	node->pre = L;
	L->next->pre = node;
	L->next = node;
	L->data++;
}

void tailInsert(Node* L, int data) {

}
void listprint(Node* L) {
	Node* node = L->next;
	while (node!=L) {
		printf("%d", node->data);
		node = node->next;
	}
	printf("\n");
}

int main() {
	Node* L = initList();
	headInsert(L, 5);
	headInsert(L, 4);
	headInsert(L, 3);
	headInsert(L, 2);
	headInsert(L, 1);
	listprint(L);
}