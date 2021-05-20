#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct {
	int data;
	struct node* link;
}Node;

void addNode(Node* target, int data)
{
	Node* newNode = malloc(sizeof(Node));
	newNode->data = data;
	newNode->link = target->link;
	target->link = newNode;
}
int main(void)
{
	int i = 1;

	Node* head = malloc(sizeof(Node)); // 헤더노드 생성
	head->link = NULL;

	addNode(head, 1); // 1 -> null

	addNode(head, 2); // 2 -> 1

	addNode(head, 3); // 3 -> 2

	Node* curr = head->link;
	while (curr != NULL) {
		printf("%d번째 노드 데이터 : %d\n", i, curr->data);
		curr = curr->link;
		i++;
	}
	
	free(head);
	free(curr);
	
	return 0;
}