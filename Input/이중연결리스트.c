#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* 노드구조체 정의 */
typedef struct dlistnode {
	int data;
	struct dlistnode* next;
	struct dlistonde* prev;
}DListNode;
typedef struct {
	DListNode* head;
}HeadNode;
/* 헤드노드 생성 함수*/
HeadNode* createHeadNode()
{
	HeadNode* h = (HeadNode*)malloc(sizeof(HeadNode));
	if (h != NULL) h->head = NULL;
	return h;
}
/* 노드 생성 함수*/
DListNode* createNode(int data)
{
	DListNode* newNode = (DListNode*)malloc(sizeof(DListNode));
	if (newNode == NULL)
	{
		printf("메모리 할당 실패!!");
		exit(1);
	}
	else
	{
		newNode->data = data;
		newNode->prev = NULL;
		newNode->next = NULL;
		return newNode;
	}
}
/* 노드 삽입 함수*/
void insertNode(HeadNode* phead, DListNode* preNode, DListNode* newNode)
{
	if (phead->head == NULL) // 리스트에 아무값이 없을 때
	{
		phead->head = newNode;
		newNode->prev = phead;
	}
	else if (preNode->next == NULL) // 맨뒤에 생성
	{
		preNode->next = newNode;
		newNode->prev = preNode;
	}
	else // 중간에 생성
	{
		DListNode* nextNode = preNode->next;

		preNode->next = newNode;
		newNode->prev = preNode;
		newNode->next = nextNode;
		nextNode->prev = newNode;
	}
}
/* 노드 출력 함수 */
void print_node(HeadNode* h)
{
	DListNode* curr = h->head;
	int i = 1;
	if (curr != NULL)
	{
		while (curr != NULL) {
			printf("%d번째 노드 데이터 : %d\n", i, curr->data);
			curr = curr->next;
			i++;
		}
		printf("\n");
	}
	else printf("노드가 없습니다.\n");
}
/* 노드 찾기 */
int select_node(HeadNode* h, int data)
{
	int i = 1;
	DListNode* temp = h->head;
	while (temp != NULL)
	{
		if (temp->data != data)
		{
			temp = temp->next;
			i++;
		}
		else break;
	}
	if (temp != NULL)
		printf("%d번 노드 데이터 : %d\n\n", i, temp->data);
	else
		printf("찾는 데이터가 없습니다.\n\n");

	return temp;
}
/* 노드 삭제 */
void delete_node(HeadNode* h, DListNode* d)
{
	DListNode* pre;
	if(h->head == NULL) return;
	if (h->head->next == NULL) // 데이터가 1개
	{
		h->head = NULL;
		free(d);
		printf("삭제완료\n");
		return;
	}
	else if (d == NULL) // 삭제할 데이터가 없을 때
	{
		printf("삭제할 데이터가 없습니다.");
		return;
	}
	else
	{
		pre = h->head;
		while (pre->next != d)
			pre = pre->next;
		pre->next = d->next;
		free(d);
		printf("삭제완료\n");
	}
}
/* 노드 전체삭제 */
void delete_allnode(HeadNode* h)
{	
	int i = 1;
	while (h->head != NULL)
	{
		DListNode* temp = h->head;
		h->head = temp->next;
		free(temp);
		printf("%d번 노드 삭제\n\n", i);
		i++;
	}
}

int main()
{
	int data1, data2;
	DListNode *p;

	HeadNode* phead = createHeadNode();
	DListNode* node1 = createNode(50);
	DListNode* node2 = createNode(100);
	DListNode* node3 = createNode(150);

	insertNode(phead, NULL, node1);
	insertNode(phead, node1, node2);
	insertNode(phead, node1, node3);
	print_node(phead);

	printf("찾는 데이터 입력 : ");
	scanf("%d", &data1);
	select_node(phead, data1);

	printf("지울 데이터 입력 : ");
	scanf("%d", &data2);
	p = select_node(phead, data2);
	delete_node(phead, p);
	print_node(phead);

	printf("-----전체노드삭제-----\n");
	delete_allnode(phead);
	printf("----------------------\n");
	print_node(phead);

	return 0;
}