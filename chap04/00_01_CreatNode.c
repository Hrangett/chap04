#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>

typedef struct _node
{
	int data;
	struct _node* next;
}Node;

void addNode(Node* h, int d)
{
	//�׻� ù������ ��带 �߰��ϴ� �Լ�
	//1.  newNode�� h�� ��ܾ���.(ù��������� �ּҰ�..)
	//2.  newNode->data�� d�� ��ܾ���
	//ù��° ���,,,,,,,,,,,,,,,,,,
	
	/*
	
	10�̰� ��! �� ó���̾�! �ϰ� d�� addNode�׿� ���
	addNode�� ��? ù�մ��̾�??�ϰ� �ݰ���

	addNode�� �ִ� newNode���� ����
	addNode�� newNode���� ��! �� ���� h ����ü�� ����� ����ü ǥ���� �濡 ��~! ��� ��

	�ֳĸ� ù�մ��̰�
	head�� ó���̾���ϰ�
	10�̰� ù �մ��̴ϱ�
	head�� ����Ű�� next�� ù ��带 ����ؾ���.
	head�� ����Ű�� next�� ù ����� data�� 10�̰� ������

	������ ��������

	*/
	Node* newNode = (Node*)malloc(sizeof(Node));

	//printf("newNode : %d, %p\n", newNode->data, newNode->next);
	//newNode->next= h;
	//h->data = d;
	
	//�׻� ���Ӱ� �����Ǵ� ��尡 ù��° ���� ��ġ��Ű�� �ϱ�

	newNode->data = d;
	newNode->next = h->next;	//�ι�° ��带 ����Ű���Ѵ�
	h->next = newNode;			//ù��° ���� ��ġ��Ų��
	
	//h->next = newNode;
	//newNode->data = d;
	//newNode->next = NULL;
	
	
	//printf("h : %d\n", h->next->data);
	//printf("h : %d\n", h->next->data);
	//printf("newNode..%p\n", newNode->next);
	



}

void printNode(Node* h)
{
	Node* curr = h->next;
	int i = 1;
	while (curr != NULL)
	{
		printf("%d��° ��� --> data : %d, next : %p\n", i, curr->data, curr->next);
		curr = curr->next;
		i++;
	}
	
	
}

int main(void)
{
	Node* head = (Node*)malloc(sizeof(Node));
	head->next = NULL;
	
	/*===== firstNode =====*/
	addNode(head, 10);
	//printf("head : %d\n\n", head->data);

	addNode(head, 20);
	//printf("head : %d\n\n", head->data);
	printNode(head);

	return 0;
}