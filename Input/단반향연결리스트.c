#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 노드 구조체 정의
typedef struct node{
	int data;
	struct node* next;
}Node;
// 헤드 구조체 정의
typedef struct {
	Node* head;		// 노드를 가리킬수 있는 타입이 와야한다. 
}HeadNode;
#pragma region 함수

/* 헤더를 생성하는 함수 */
HeadNode* createHead(void)
{
	HeadNode* h = (HeadNode*)malloc(sizeof(HeadNode));
	if (h != NULL) h->head = NULL; // 역참조 방지
	return h;
}
/* 전위 삽입 함수 */
void preinsertNode(HeadNode* h, int data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode != NULL) {
		newNode->data = data;
		newNode->next = h->head;
		h->head = newNode;
	}
}
/* 후위 삽입 함수 */
void rearInsertNode(HeadNode* h, int data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	Node* curr = (Node*)malloc(sizeof(Node));
	if (h->head == NULL)
	{
		if (newNode != NULL)
		{
			newNode->data = data;
			newNode->next = NULL;
			h->head = newNode;
		}
	}
	else if (newNode != NULL)
	{
		newNode->data = data;
		newNode->next = NULL;
		if (curr != NULL)
		{
			curr = h->head;
			while (curr->next != NULL) curr = curr->next;
			curr->next = newNode;
		}
	}
}
/* 출력 함수 */
void print_node(HeadNode* h)
{
	int i = 1;
	Node* curr = h->head;
	if (curr != NULL)
	{
		while (curr != NULL) {
			printf("%d번째 노드 데이터 : %d\n", i, curr->data);
			curr = curr->next;
			i++;
		}
	}
	else printf("노드가 없습니다.");

	printf("\n");
}
/* 노드 검색 */
Node* searchNode(HeadNode* h, int data)
{
	int i = 1;
	Node* curr = h->head;
	Node* curr2 = h->head;
	while (curr->data != data)
	{
		curr2 = curr;
		curr = curr->next;
		i++;
		if (curr2->next == NULL)
		{
			printf("찾는 값이 없습니다.\n\n");
			break;
		}
	}
	if (curr2->next != NULL)
	{
		printf("%d번째 노드 데이터 %d \n\n", i, curr->data);
	}

	return curr;
}
/* 선택 노드 삭제 */
void delete_node(HeadNode* h, int data)
{
	int i = 1;
	Node* curr = h->head;
	Node* curr2 = h;
	while (curr->data != data)
	{
		curr2 = curr;
		curr = curr->next;
		i++;
		if (curr2->next == NULL)
			break;
	}
	if (i == 1)
	{
		h->head = curr->next;
		free(curr);
	}
	else if (curr2->next == NULL)
	{
		printf("삭제할 값이 없습니다.\n");
		return;
	}
	else
	{
		curr2->next = curr->next;
		free(curr);
	}
}
/* 전체 노드 삭제 */
void delete_allnode(HeadNode* h)
{
	int i = 1;
	while (h->head != NULL)
	{
		Node* curr = h->head;
		h->head = curr->next;
		free(curr);
		printf("%d 번째 노드삭제\n", i);
		i++;
	}
}
/* 중간 노드 삽입*/
void midInsertNode(HeadNode* h, int predata, int data)
{
	int i = 1;
	Node* curr = h->head;
	Node* curr2 = h;
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (h->head == NULL || curr->next == NULL)
	{
		printf("노드를 2개이상 생성한뒤 실행하여 주세요.\n\n");
		return;
	}
	
	while (curr2->data != predata)
	{
		curr2 = curr;
		curr = curr->next;
		i++;
		
		if (curr2->next == NULL)
			break;
	}
	
	if (curr2->next == NULL)
	{
		printf("\n입력한 데이터값을 가지는 노드가 없어 삽입할 수 없습니다.\n");
		return;
	}
	else
	{
		curr2->next = newNode;
		if (newNode != NULL) {
			newNode->next = curr;
			newNode->data = data;
		}
	}
}

#pragma endregion


int main()
{
	// 노드 생성
	int i = 1;
	HeadNode* h1 = createHead();
	preinsertNode(h1, 1);
	preinsertNode(h1, 2);
	preinsertNode(h1, 3);
	rearInsertNode(h1, 30);
	rearInsertNode(h1, 31);
	rearInsertNode(h1, 32);

	
	// 출력
	print_node(h1);

	// 검색
	/* printf("찾을 값을 입력해주세요 : ");
	int data1;
	scanf("%d", &data1);
	searchNode(h1, data1);*/

	// 삭제
	/* printf("삭제할 값을 입력해주세요 : ");
	int data2;
	scanf("%d", &data2);
	delete_node(h1, data2);
	print_node(h1); */

	// 중간삽입
	printf("삽입할 데이터 앞의 값, 입력할 데이터값 입력 : ");
	int data3, data4;
	scanf("%d%d", &data3, &data4);
	midInsertNode(h1, data3, data4);
	print_node(h1);

	// 전체 노드삭제
	printf("-----전체노드삭제-----\n");
	delete_allnode(h1);
	free(h1);
	
	return 0;
}