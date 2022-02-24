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
	//항상 첫ㅅ번쨰 노드를 추가하는 함수
	//1.  newNode엔 h가 담겨야함.(첫번쨰노드의 주소값..)
	//2.  newNode->data에 d가 담겨야함
	//첫번째 노드,,,,,,,,,,,,,,,,,,
	
	/*
	
	10이가 야! 나 처음이야! 하고 d로 addNode네에 놀러옴
	addNode가 어? 첫손님이야??하고 반겨줌

	addNode에 있는 newNode방이 있음
	addNode가 newNode한테 야! 너 여기 h 구조체에 선언된 구조체 표인터 방에 들어가~! 라고 함

	왜냐면 첫손님이고
	head는 처음이어야하고
	10이가 첫 손님이니까
	head가 가리키는 next에 첫 노드를 등록해야함.
	head가 가리키는 next에 첫 노드의 data에 10이가 들어가야함

	개념이 안잡힌다

	*/
	Node* newNode = (Node*)malloc(sizeof(Node));

	//printf("newNode : %d, %p\n", newNode->data, newNode->next);
	//newNode->next= h;
	//h->data = d;
	
	//항상 새롭게 생성되는 노드가 첫번째 노드로 위치시키게 하기

	newNode->data = d;
	newNode->next = h->next;	//두번째 노드를 가리키게한다
	h->next = newNode;			//첫번째 노드로 위치시킨다
	
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
		printf("%d번째 노드 --> data : %d, next : %p\n", i, curr->data, curr->next);
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