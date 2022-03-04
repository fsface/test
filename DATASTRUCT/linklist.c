#include "linklist.h"

int LinkList_Is_Empty(LinkList* head)  //is list empty
{
	if (head->next == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


LinkList* LinkList_Create()  //creat a list with head
{
	LinkList* head = (LinkList* )malloc(sizeof(LinkList));
	if(NULL == head)
	{
		printf("malloc failed\n");
		return NULL;
	}
	
	head->data = -1;
	head->next = NULL;

	return head;
}

int LinkList_Insert_Head(LinkList* head,int data)   //insert data behind of the head node
{
	LinkList* new = (LinkList* )malloc(sizeof(LinkList));
	if (NULL == new)
	{
		printf("malloc failed\n");
		return -1;
	}

	new->data = data;
	new->next = NULL;

	new->next = head->next;
	head->next = new;

	return 0;	
}

void LinkList_Show(LinkList* head)  // show each node of the list
{
	LinkList* p;
	p = head->next;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

int LinkList_Insert_Pos(LinkList* head,int data, int pos) //insert data by pos
{

	if (pos > LinkList_Len(head) || pos < 0)  //is pos vaild
	{
		printf("pos error\n");
		return -1;
	}

	LinkList* new = (LinkList* )malloc(sizeof(LinkList));
	
	new->data = data;
	new->next = NULL;

	LinkList* p;
	p = head;
	
	while(pos--)
	{
		p = p->next;
	}

	new->next = p->next;
	p->next = new;

	return 0;
}

int LinkList_Delete_Pos(LinkList* head, int pos)  //delete node by pos 
{

	if ( LinkList_Is_Empty(head) )    //
	{
		printf("LinkList is empty\n");
		return -1;	
	}

	if (pos > LinkList_Len(head) - 1 || pos < 0)  //is pos vaild
	{
		printf("pos error\n");
		return -1;
	}

	LinkList* p;
	p = head;


	while(pos--)
	{
		p = head->next;	
	}

	p->next = p->next->next;
	return 0;
}

int LinkList_Len(LinkList* head)  //lenth of the list
{
	int len=0;
	LinkList* p = head;
	while (p->next != NULL)
	{
		len++;
		p = p->next;
	}

	return len;
}

int LinkList_Find_Pos(LinkList* head, int pos)  //get the data of node by pos
{
	if ( LinkList_Is_Empty(head) )    //
	{
		printf("LinkList is empty\n");
		return -1;	
	}

	if (pos > LinkList_Len(head) - 1 || pos < 0)  //is pos vaild
	{
		printf("pos error\n");
		return -1;
	}

	LinkList* p = head->next;
	
	while(pos--)
	{
		p = p->next;
	}
	return p->data;	
}

