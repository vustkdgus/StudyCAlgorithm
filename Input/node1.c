#include <stdio.h>

typedef struct node {
	int data;			// data ���
	struct node* link;	// ���� ����� �ּҸ� ������ ���
}Node;

int main()
{
	int i = 1;
	Node* head = malloc(sizeof(Node)); // ������ ����

	// ���1
	Node* node1 = malloc(sizeof(Node)); // ��� ����
	if (node1 == NULL) return;
	node1->data = 10;
	node1->link = NULL;
	head->link = node1;			// �����忡 ù��° ����� �ּҰ��� �ִ´�.
	// ���2
	Node* node2 = malloc(sizeof(Node));
	node2->data = 11;
	node2->link = NULL;
	node1->link = node2;
	// ���3
	Node* node3 = malloc(sizeof(Node));
	node3->data = 12;
	node3->link = NULL;
	node2->link = node3;
	// ���4
	Node* node4 = malloc(sizeof(Node));
	node4->data = 13;
	node4->link = NULL;
	node3->link = node4;
	// ���5
	Node* node5 = malloc(sizeof(Node));
	node5->data = 14;
	node5->link = NULL;
	node4->link = node5;
	// ���
	Node* curr = head->link;
	while (curr != NULL) {
		printf("%d��° ��� ������ : %d\n", i, curr->data);
		curr = curr->link;
		i++;
	}

	free(head);
	free(node1);
	free(node2);
	free(node3);
	free(node4);
	free(node5);

	return 0;
}