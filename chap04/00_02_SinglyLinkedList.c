#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>


typedef struct _node {
	int data;
	struct _node* next;
}Node;

void pre_insertNode(Node* h, int d)
{
	//전위 노드삽입?
	Node* newNode = malloc(sizeof(Node));
	if (newNode == NULL)return;

	newNode->data = d;
	newNode->next = h->next;
	h->next = newNode;

}

void rear_insertNode(Node* h, int d)
{
	//후위 노드 삽입
	//맨 마지막 노드엔 NULL값이 저장되어있을것이다.,
	//printf("%d의 주솟값 어디갔어~~\n", d);
	Node* newNode = malloc(sizeof(Node));
	if (newNode == NULL)return;
	newNode->data = d;
	newNode->next = NULL;

	Node* cur;
	cur = h;		//첫번쨰 노드를 가리킴
	


	if (cur == NULL)
	{
		h->next = newNode;
		//printf("%d의 주솟값\n", d);
	}
	else
	{
		//printf("%d의 주솟값? %p\n", d, cur->next);
		while (cur->next != NULL)
		{
			cur = cur->next;
			//printf("..%d의 주솟값? %p\n", d, cur->next);

		}
		cur->next = newNode;
		
	}
	


	//while (1)
	//{
	//	if (cur == NULL)
	//	{
	//		newNode->data = d;
	//		newNode->next = NULL;

	//		cur->next = newNode;
	//		break;
	//	}

	//	cur = cur->next;

	//}
	


}

void freeNode(Node* h)
{
	Node* cur;
	Node* cur_next;

	cur = h->next;
	

	while (cur->next != NULL)
	{
		cur_next = cur->next;

		printf("%d에 동적으로 할당된 메모리를 해제합니다\n", cur->data);
		free(cur);

		printf("%d...\n", cur->data);
		cur = cur_next;

		printf("%p에 동적으로 할당된 메모리를 해제하러갑니다\n\n", cur);
	}

	//Node* curr = NULL;
	//while (h->next == NULL)
	//{
	//	curr = h->next;
	//	h->next = h->next->next;
	//	free(curr);
	//}
	free(h);
}

void mid_insertNode(Node* h, int d, int cur_data)
{
	
	Node* newNode = malloc(sizeof(Node));
	Node* cur;
	cur = h->next;
	while(cur != NULL)
	{
		printf("==== %d, %p ====\n", cur->data, cur->next);
		if (cur->data == cur_data)
		{
			newNode->next = cur->next;
			cur->next = newNode;
			newNode->data = d;
			
		}

		cur = cur->next;
	}

	printf("신규노드생성을 종료합니다...\n\n");
}

Node* searchNode(Node* h, int d)
{
	printf("%d의 데이터를 가진 노드를 탐색합니다..\n", d);
	Node* curr = h->next;
	int i = 1;
	while (curr != NULL)
	{
		printf("%d번째 노드의 데이터 --> %d\n", i, curr->data);
		//Sleep(1000);
		/*printf("찾는중~~");*/
		if (curr->data == d)
		{
			printf("찾았아요~~\n");
			return curr;
		}
		curr = curr->next;
		i++;
	}
	printf("없어요~~\n");


}

void delNode(Node* del, Node* h)
{
	printf("%d, %p\n", del->data, del->next);
	Node* curr;
	Node* bef_curr;
	//Node* aft_curr;

	bef_curr = h;
	curr = h->next;
	//aft_curr = curr->next;

	//printf("%d, %d\n", bef_curr->data, bef_curr->next);
	
	while (curr != NULL)
	{
		printf("%d, %p\n", curr->data, curr->next);
		if (curr == del)
		{
			
			bef_curr->next = curr->next;
			free(curr);
			curr = bef_curr->next;
			//aft_curr = curr->next;

		}
		else 
		{
			bef_curr = curr;
			curr = curr->next;
			//aft_curr = curr->next;
		}
		//curr = curr->next;


	}

	//Node* curr = h->next;
	//if (curr == del)
	//{
	//	h->next = del->next;
	//}
	//else
	//{
	//	while (curr->next != del)
	//	{
	//		curr = curr->next;
	//	}
	//	curr->next = del->next;
	//}
	//free(del);

}

void printNode(Node* h)
{
	Node* cur = h->next;

	while (cur != NULL)
	{
		printf("-->%d\n",cur->data);
		cur = cur->next;
	}

}

int main(void)
{

	Node* Head = malloc(sizeof(Node));
	if (Head != NULL)Head->next = NULL;
	Node* Search = malloc(sizeof(Node));
	if (Search != NULL)Search->next = NULL;
	//pre_insertNode(Head, 10);
	//pre_insertNode(Head, 20);
	//pre_insertNode(Head, 30);

	rear_insertNode(Head, 30);
	rear_insertNode(Head, 50);
	rear_insertNode(Head, 10);
	rear_insertNode(Head, 60);
	rear_insertNode(Head, 25);

	printNode(Head);
	//freeNode(Head);
	//printNode(Head);

	Search = searchNode(Head, 50);
	printf("%d 발견!\n노드를 삭제합니다.", Search->data);
	delNode(Search, Head);

	printf("\n");
	printNode(Head);

	printf("\n신규노드추가\n");
	mid_insertNode(Head, 11, 10);
	printNode(Head);

	return 0;

}