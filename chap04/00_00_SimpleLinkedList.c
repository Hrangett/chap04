#include <stdio.h>
#include <Windows.h>
#define _CRT_SECURE_NO_WARNINGS


typedef struct _node
{
	int data;			//데이터를 저장할 멤버변수
	struct _node* next; //다음노드를 연결해주는, 주솟값을 저장하는 변수(포인터)
}Node;

int main()
{
	/* 댠슌연결리수트 */
	/* 1. 데이터를 처리하는 맴버 2.주소를 처리하는 맴버 필요 */

	/*
	Node node1;
	node1.data = 10;
	node1.next = NULL; // 변수 초기화

	Node node2;
	node2.data = 20;
	node2.next = NULL;

	node1.next = &node2;	//node1의 next변수에 node2의 주소값을 넣는다.

	printf("node1 ---> %d, %d\n", node1.data, node1.next);
	printf("node2 ---> %d, %d\n", node2.data, node2.next);

	printf("&node2 --->  , %d", &node2);
	*/

	/*==================================================================*/
	/* 동적할당으로 노드를 생성해보자*/
	Node* node1 = (Node*)malloc(sizeof(Node)); // 힙 영역에 할당이 된다.
	if (node1 == NULL)
		return -1;
	
	node1->data = 10;
	node1->next = NULL;	//초기화

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
	//head노드를 생성해서 첫번째 노드를 저장ㅇ하도록하자
	Node* head = (Node*)malloc(sizeof(Node));
	if (head == NULL)return -1;

	head->next = node1;//head를 선언한 이유 :: head는 첫번째 노드를 가리키도록 코드를 작성하자!

	printf("*head ---> %d, %p\n", head->data, head->next);

	/*==================================================*/
	//노드를 자동 연결하는 코드를 작성하자
	
	Node* curr = head->next; //curr은 첫번째 노드를 가리킨다.
	
	/*
	커런트에 헤드의 넥스트인자가 가리키는 주소를 저장
	헤드의 넥스트는 노드 일을 가리킴
	노드일의 넥스트는 노드이를 가리킴
	*/

	while (1)
	{
		
		printf(" ---> %d, %p\n", curr->data, curr->next);
		Sleep(1000);
		curr = curr->next; //curr에 curr->next가 가리키는 주소를 다시 대입해준다!
		//if (curr->next == NULL)// 아...마지막 노드를 담을 때 next가 null이니까 마지막노드가 실행이 안되는구나
		if (curr == NULL) //마지막 노드가 담김, 그 next값은 null!
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