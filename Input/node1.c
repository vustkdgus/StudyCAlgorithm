#include <stdio.h>

typedef struct node {
	int data;			// data 멤버
	struct node* link;	// 다음 노드의 주소를 저장할 멤버
}Node;

int main()
{
	int i = 1;
	Node* head = malloc(sizeof(Node)); // 헤더노드 생성

	// 노드1
	Node* node1 = malloc(sizeof(Node)); // 노드 생성
	if (node1 == NULL) return;
	node1->data = 10;
	node1->link = NULL;
	head->link = node1;			// 헤더노드에 첫번째 노드의 주소값을 넣는다.
	// 노드2
	Node* node2 = malloc(sizeof(Node));
	node2->data = 11;
	node2->link = NULL;
	node1->link = node2;
	// 노드3
	Node* node3 = malloc(sizeof(Node));
	node3->data = 12;
	node3->link = NULL;
	node2->link = node3;
	// 노드4
	Node* node4 = malloc(sizeof(Node));
	node4->data = 13;
	node4->link = NULL;
	node3->link = node4;
	// 노드5
	Node* node5 = malloc(sizeof(Node));
	node5->data = 14;
	node5->link = NULL;
	node4->link = node5;
	// 출력
	Node* curr = head->link;
	while (curr != NULL) {
		printf("%d번째 노드 데이터 : %d\n", i, curr->data);
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