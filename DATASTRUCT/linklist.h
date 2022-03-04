#ifndef linklist_H_
#define linklist_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct linklist 
{
	int data;
	struct linklist* next;
}LinkList;

LinkList* LinkList_Create();

int LinkList_Insert_Head(LinkList* head,int data);

void LinkList_Show(LinkList* head);

int LinkList_Insert_Pos(LinkList* head,int data, int pos);

int LinkList_Delete_Pos(LinkList* head, int pos);

int LinkList_Len(LinkList* head);

int LinkList_Find_Pos(LinkList* head, int pos);

int LinkList_Is_Empty(LinkList* head);

#endif
