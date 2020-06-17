#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

typedef struct Node {
	int data;
	struct Node* next;
}Node;

Node* GetNode(int data) {
	Node *temp = (Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->next = NULL;
	return temp;
}

void addOne(Node *head) {
	int allNine = 0; //999=>1000
	Node* earlyNine = 0; //1299=>1300
	Node* lastNine = 0; //1919=>1920

}

void printList(Node* head) {
	printf("\nList: ");
	Node* itr = head;
	while (itr) {
		printf("%d ", itr->data);
		itr = itr->next;
	}
	printf("\n");
}

void freeList(Node *head) {
	Node *itr = head;
	while (itr) {
		Node* temp = itr;
		itr = itr->next;
		free(temp);
	}
}

int main() {

	Node *head = GetNode(1);
	head->next = GetNode(2);
	head->next->next = GetNode(9);
	head->next->next->next = GetNode(9);
	head->next->next->next->next = GetNode(9);
	head->next->next->next->next->next = GetNode(9);
	printList(head);
	addOne(head);
	printList(head);
	freeList(head);

	getchar();
	return 0;
}