#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ��� ����ü ����
typedef struct node{
	int data;
	struct node* next;
}Node;
// ��� ����ü ����
typedef struct {
	Node* head;		// ��带 ����ų�� �ִ� Ÿ���� �;��Ѵ�. 
}HeadNode;
#pragma region �Լ�

/* ����� �����ϴ� �Լ� */
HeadNode* createHead(void)
{
	HeadNode* h = (HeadNode*)malloc(sizeof(HeadNode));
	if (h != NULL) h->head = NULL; // ������ ����
	return h;
}
/* ���� ���� �Լ� */
void preinsertNode(HeadNode* h, int data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode != NULL) {
		newNode->data = data;
		newNode->next = h->head;
		h->head = newNode;
	}
}
/* ���� ���� �Լ� */
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
/* ��� �Լ� */
void print_node(HeadNode* h)
{
	int i = 1;
	Node* curr = h->head;
	if (curr != NULL)
	{
		while (curr != NULL) {
			printf("%d��° ��� ������ : %d\n", i, curr->data);
			curr = curr->next;
			i++;
		}
	}
	else printf("��尡 �����ϴ�.");

	printf("\n");
}
/* ��� �˻� */
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
			printf("ã�� ���� �����ϴ�.\n\n");
			break;
		}
	}
	if (curr2->next != NULL)
	{
		printf("%d��° ��� ������ %d \n\n", i, curr->data);
	}

	return curr;
}
/* ���� ��� ���� */
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
		printf("������ ���� �����ϴ�.\n");
		return;
	}
	else
	{
		curr2->next = curr->next;
		free(curr);
	}
}
/* ��ü ��� ���� */
void delete_allnode(HeadNode* h)
{
	int i = 1;
	while (h->head != NULL)
	{
		Node* curr = h->head;
		h->head = curr->next;
		free(curr);
		printf("%d ��° ������\n", i);
		i++;
	}
}
/* �߰� ��� ����*/
void midInsertNode(HeadNode* h, int predata, int data)
{
	int i = 1;
	Node* curr = h->head;
	Node* curr2 = h;
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (h->head == NULL || curr->next == NULL)
	{
		printf("��带 2���̻� �����ѵ� �����Ͽ� �ּ���.\n\n");
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
		printf("\n�Է��� �����Ͱ��� ������ ��尡 ���� ������ �� �����ϴ�.\n");
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
	// ��� ����
	int i = 1;
	HeadNode* h1 = createHead();
	preinsertNode(h1, 1);
	preinsertNode(h1, 2);
	preinsertNode(h1, 3);
	rearInsertNode(h1, 30);
	rearInsertNode(h1, 31);
	rearInsertNode(h1, 32);

	
	// ���
	print_node(h1);

	// �˻�
	/* printf("ã�� ���� �Է����ּ��� : ");
	int data1;
	scanf("%d", &data1);
	searchNode(h1, data1);*/

	// ����
	/* printf("������ ���� �Է����ּ��� : ");
	int data2;
	scanf("%d", &data2);
	delete_node(h1, data2);
	print_node(h1); */

	// �߰�����
	printf("������ ������ ���� ��, �Է��� �����Ͱ� �Է� : ");
	int data3, data4;
	scanf("%d%d", &data3, &data4);
	midInsertNode(h1, data3, data4);
	print_node(h1);

	// ��ü ������
	printf("-----��ü������-----\n");
	delete_allnode(h1);
	free(h1);
	
	return 0;
}