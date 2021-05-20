#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* ��屸��ü ���� */
typedef struct dlistnode {
	int data;
	struct dlistnode* next;
	struct dlistonde* prev;
}DListNode;
typedef struct {
	DListNode* head;
}HeadNode;
/* ����� ���� �Լ�*/
HeadNode* createHeadNode()
{
	HeadNode* h = (HeadNode*)malloc(sizeof(HeadNode));
	if (h != NULL) h->head = NULL;
	return h;
}
/* ��� ���� �Լ�*/
DListNode* createNode(int data)
{
	DListNode* newNode = (DListNode*)malloc(sizeof(DListNode));
	if (newNode == NULL)
	{
		printf("�޸� �Ҵ� ����!!");
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
/* ��� ���� �Լ�*/
void insertNode(HeadNode* phead, DListNode* preNode, DListNode* newNode)
{
	if (phead->head == NULL) // ����Ʈ�� �ƹ����� ���� ��
	{
		phead->head = newNode;
		newNode->prev = phead;
	}
	else if (preNode->next == NULL) // �ǵڿ� ����
	{
		preNode->next = newNode;
		newNode->prev = preNode;
	}
	else // �߰��� ����
	{
		DListNode* nextNode = preNode->next;

		preNode->next = newNode;
		newNode->prev = preNode;
		newNode->next = nextNode;
		nextNode->prev = newNode;
	}
}
/* ��� ��� �Լ� */
void print_node(HeadNode* h)
{
	DListNode* curr = h->head;
	int i = 1;
	if (curr != NULL)
	{
		while (curr != NULL) {
			printf("%d��° ��� ������ : %d\n", i, curr->data);
			curr = curr->next;
			i++;
		}
		printf("\n");
	}
	else printf("��尡 �����ϴ�.\n");
}
/* ��� ã�� */
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
		printf("%d�� ��� ������ : %d\n\n", i, temp->data);
	else
		printf("ã�� �����Ͱ� �����ϴ�.\n\n");

	return temp;
}
/* ��� ���� */
void delete_node(HeadNode* h, DListNode* d)
{
	DListNode* pre;
	if(h->head == NULL) return;
	if (h->head->next == NULL) // �����Ͱ� 1��
	{
		h->head = NULL;
		free(d);
		printf("�����Ϸ�\n");
		return;
	}
	else if (d == NULL) // ������ �����Ͱ� ���� ��
	{
		printf("������ �����Ͱ� �����ϴ�.");
		return;
	}
	else
	{
		pre = h->head;
		while (pre->next != d)
			pre = pre->next;
		pre->next = d->next;
		free(d);
		printf("�����Ϸ�\n");
	}
}
/* ��� ��ü���� */
void delete_allnode(HeadNode* h)
{	
	int i = 1;
	while (h->head != NULL)
	{
		DListNode* temp = h->head;
		h->head = temp->next;
		free(temp);
		printf("%d�� ��� ����\n\n", i);
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

	printf("ã�� ������ �Է� : ");
	scanf("%d", &data1);
	select_node(phead, data1);

	printf("���� ������ �Է� : ");
	scanf("%d", &data2);
	p = select_node(phead, data2);
	delete_node(phead, p);
	print_node(phead);

	printf("-----��ü������-----\n");
	delete_allnode(phead);
	printf("----------------------\n");
	print_node(phead);

	return 0;
}