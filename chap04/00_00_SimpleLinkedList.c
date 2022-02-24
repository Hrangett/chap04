#include <stdio.h>
#include <Windows.h>
#define _CRT_SECURE_NO_WARNINGS


typedef struct _node
{
	int data;			//�����͸� ������ �������
	struct _node* next; //������带 �������ִ�, �ּڰ��� �����ϴ� ����(������)
}Node;

int main()
{
	/* �Ú����Ḯ��Ʈ */
	/* 1. �����͸� ó���ϴ� �ɹ� 2.�ּҸ� ó���ϴ� �ɹ� �ʿ� */

	/*
	Node node1;
	node1.data = 10;
	node1.next = NULL; // ���� �ʱ�ȭ

	Node node2;
	node2.data = 20;
	node2.next = NULL;

	node1.next = &node2;	//node1�� next������ node2�� �ּҰ��� �ִ´�.

	printf("node1 ---> %d, %d\n", node1.data, node1.next);
	printf("node2 ---> %d, %d\n", node2.data, node2.next);

	printf("&node2 --->  , %d", &node2);
	*/

	/*==================================================================*/
	/* �����Ҵ����� ��带 �����غ���*/
	Node* node1 = (Node*)malloc(sizeof(Node)); // �� ������ �Ҵ��� �ȴ�.
	if (node1 == NULL)
		return -1;
	
	node1->data = 10;
	node1->next = NULL;	//�ʱ�ȭ

	Node* node2 = (Node*)malloc(sizeof(Node));
	if (node2 == NULL)
		return -1;
	node1->next = node2;	

	node2->data = 20;
	node2->next = NULL;

	//printf(" node2 --->   , %p", node2);

	Node* node3 = (Node*)malloc(sizeof(Node));
	if (node3 == NULL)return -1;
	node2->next = node3;

	node3->data = 30;
	node3->next = NULL;

	Node* node4 = (Node*)malloc(sizeof(Node));
	
	node3->next = node4;
	node4->data = 40;
	node4->next = NULL;

	printf(" node1 --->  , %p\n", node1);
	printf("*node1 ---> %d, %p\n", node1->data, node1->next);
	printf(" node2 --->  , %p\n", node2);
	printf("*node2 ---> %d, %p\n", node2->data, node2->next);
	printf(" node3 --->  , %p\n", node3);
	printf("*node3 ---> %d, %p\n", node3->data, node3->next);
	printf(" node4 --->  , %p\n", node4);
	printf("*node4 ---> %d, %p\n", node4->data, node4->next);
	

	/*==================================================*/
	//head��带 �����ؼ� ù��° ��带 ���夷�ϵ�������
	Node* head = (Node*)malloc(sizeof(Node));
	if (head == NULL)return -1;

	head->next = node1;//head�� ������ ���� :: head�� ù��° ��带 ����Ű���� �ڵ带 �ۼ�����!

	printf("*head ---> %d, %p\n", head->data, head->next);

	/*==================================================*/
	//��带 �ڵ� �����ϴ� �ڵ带 �ۼ�����
	
	Node* curr = head->next; //curr�� ù��° ��带 ����Ų��.
	
	/*
	Ŀ��Ʈ�� ����� �ؽ�Ʈ���ڰ� ����Ű�� �ּҸ� ����
	����� �ؽ�Ʈ�� ��� ���� ����Ŵ
	������� �ؽ�Ʈ�� ����̸� ����Ŵ
	*/

	while (1)
	{
		
		printf(" ---> %d, %p\n", curr->data, curr->next);
		Sleep(1000);
		curr = curr->next; //curr�� curr->next�� ����Ű�� �ּҸ� �ٽ� �������ش�!
		//if (curr->next == NULL)// ��...������ ��带 ���� �� next�� null�̴ϱ� ��������尡 ������ �ȵǴ±���
		if (curr == NULL) //������ ��尡 ���, �� next���� null!
			break;

	}
	free(node1);
	free(node2);
	free(node3);
	free(node4);
	free(head);
	free(curr);


	return 0;

}