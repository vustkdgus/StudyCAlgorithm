#include <stdio.h>

/* 원형리스트 구조체정의 */  // 원형리스트에선 헤더가 마지막노드를 가리킴
typedef struct listnode {
	int data;
	struct listnode* link;
}ListNode;
typedef struct {
	ListNode* head;
}HeadNode; 
/* 헤더생성 함수 */
HeadNode* createHead()
{
	HeadNode* h = (HeadNode*)malloc(sizeof(HeadNode));
	if (h != NULL) 
	h->head = NULL;
	return h;
}
/* 노드생성 함수 */
ListNode* createNode(HeadNode* phead, int data)
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	if (newNode == NULL) {
		printf("메모리 할당 실패!!!");
		return;
	}
	else {
		newNode->data = data;
		newNode->link = NULL;
		return newNode;
	}
}
/* 처음에 노드 삽입 */
void insertFirstNode(HeadNode* phead, ListNode* newNode)
{
	if (phead->head == NULL) // 노드가 공백이면
	{
		phead->head = newNode;
		newNode->link = newNode;
	}
	else
	{
		newNode->link = phead->head->link;
		phead->head->link = newNode;
	}
}
/* 마지막에 노드 삽입 */
void insertLastNode(HeadNode* phead, ListNode* newNode)
{
	if (phead->head == NULL)
	{
		phead->head = newNode;
		newNode->link = newNode;
	}
	else
	{
		newNode->link = phead->head->link;
		phead->head->link = newNode;
		phead->head = newNode;
	}
}
/* 노드출력 함수 */
void print_node(HeadNode* phead)
{
	int i = 1;
	if (phead->head == NULL || phead == NULL)
	{
		printf("출력할 값이 없습니다.\n");
		return;
	}
	ListNode* temp = phead->head->link;
	do{
		printf("%d번 노드 : %d\n", i, temp->data);
		temp = temp->link;
		i++;
	} while (temp != phead->head);
	printf("%d번 노드 : %d\n\n", i, temp->data);
}
/* 전체삭제 함수 */ // 보수중
void delete_allnode(HeadNode* phead)
{
	if (phead->head == NULL)
		return;
	int i = 1, a;
	ListNode* temp = phead->head;
	
	if (temp->link == NULL)
	{
		free(temp);
		return;
	}
	else 
	{
		while (temp->link != phead->head)
		{
			temp = temp->link;
			i++;
		}
		free(temp);
		printf("%d번 노드 삭제\n", i);
		a = i;
		for (i = 0; i < a; i++)
		{
			printf("%d\n", i);
			ListNode* temp = phead->head;
			phead->head = temp->link;
			free(temp);
			printf("%d번 노드 삭제\n", i);
			i++;
		}
		free(phead);
		printf("전체 삭제완료!!\n");
	}
}
/* 노드선택 함수 */
int select_node(HeadNode* phead, int data)
{
	if (phead->head == NULL)
		return;
	ListNode* temp = phead->head;
	
	do{
		if (temp->data != data)
		{
			temp = temp->link;
		}
		else break;
	} while (temp != phead->head);

	if (temp->data == data)
		printf("선택노드 데이터 : %d\n\n", temp->data);
	else
		printf("찾는 데이터가 없습니다.\n\n");

	return temp;
}
/* 노드삭제 함수 */
void delete_node(HeadNode* phead, ListNode* p)
{
	if (phead->head == NULL)
		return;
	ListNode* temp = phead->head;
	while (temp->link != p)
		temp = temp->link;
	if (temp->link->data != p->data)
	{
		printf("삭제할 값이 없습니다.\n");
		return;
	}
	else 
	{
		temp->link = p->link;
		if (phead->head = p)
			phead->head = temp;
		free(p);
	}
}

int main(void)
{
	HeadNode* h = createHead();
	ListNode* node1 = createNode(h, 10);
	ListNode* node2 = createNode(h, 20);
	ListNode* node3 = createNode(h, 30);
	ListNode* node4 = createNode(h, 1);

	insertLastNode(h, node1);
	insertLastNode(h, node2);
	insertLastNode(h, node3);
	insertFirstNode(h, node4);
	print_node(h);

	select_node(h, 20);

	ListNode* a = select_node(h, 10);
	delete_node(h, a);
	print_node(h);

	/*delete_allnode(h);
	print_node(h);*/

	return 0;
}