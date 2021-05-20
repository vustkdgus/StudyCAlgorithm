#include <stdio.h>

/* ��������Ʈ ����ü���� */  // ��������Ʈ���� ����� ��������带 ����Ŵ
typedef struct listnode {
	int data;
	struct listnode* link;
}ListNode;
typedef struct {
	ListNode* head;
}HeadNode; 
/* ������� �Լ� */
HeadNode* createHead()
{
	HeadNode* h = (HeadNode*)malloc(sizeof(HeadNode));
	if (h != NULL) 
	h->head = NULL;
	return h;
}
/* ������ �Լ� */
ListNode* createNode(HeadNode* phead, int data)
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	if (newNode == NULL) {
		printf("�޸� �Ҵ� ����!!!");
		return;
	}
	else {
		newNode->data = data;
		newNode->link = NULL;
		return newNode;
	}
}
/* ó���� ��� ���� */
void insertFirstNode(HeadNode* phead, ListNode* newNode)
{
	if (phead->head == NULL) // ��尡 �����̸�
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
/* �������� ��� ���� */
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
/* ������ �Լ� */
void print_node(HeadNode* phead)
{
	int i = 1;
	if (phead->head == NULL || phead == NULL)
	{
		printf("����� ���� �����ϴ�.\n");
		return;
	}
	ListNode* temp = phead->head->link;
	do{
		printf("%d�� ��� : %d\n", i, temp->data);
		temp = temp->link;
		i++;
	} while (temp != phead->head);
	printf("%d�� ��� : %d\n\n", i, temp->data);
}
/* ��ü���� �Լ� */ // ������
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
		printf("%d�� ��� ����\n", i);
		a = i;
		for (i = 0; i < a; i++)
		{
			printf("%d\n", i);
			ListNode* temp = phead->head;
			phead->head = temp->link;
			free(temp);
			printf("%d�� ��� ����\n", i);
			i++;
		}
		free(phead);
		printf("��ü �����Ϸ�!!\n");
	}
}
/* ��弱�� �Լ� */
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
		printf("���ó�� ������ : %d\n\n", temp->data);
	else
		printf("ã�� �����Ͱ� �����ϴ�.\n\n");

	return temp;
}
/* ������ �Լ� */
void delete_node(HeadNode* phead, ListNode* p)
{
	if (phead->head == NULL)
		return;
	ListNode* temp = phead->head;
	while (temp->link != p)
		temp = temp->link;
	if (temp->link->data != p->data)
	{
		printf("������ ���� �����ϴ�.\n");
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