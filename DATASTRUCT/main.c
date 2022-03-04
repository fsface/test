#include "linklist.h"

int main()
{
	LinkList *myList = LinkList_Create();
	if(LinkList_Is_Empty(myList)){
		printf("the list is empty\n");
	}
	else
	{
		printf("the list is not empty\n");
	}

	LinkList_Insert_Head(myList, 1);
	LinkList_Insert_Head(myList, 2);
	LinkList_Insert_Head(myList, 3);
	LinkList_Insert_Head(myList, 4);

	LinkList_Show(myList);

	LinkList_Delete_Pos(myList, 0);
	LinkList_Insert_Pos(myList, 10, 0);

	LinkList_Show(myList);

	int len = LinkList_Len(myList);
	printf("the list len is %d\n", len);
	return 0;
}
