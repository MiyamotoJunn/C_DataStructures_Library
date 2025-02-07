#include "StringLLS.h"
#include<stdio.h>

int	main()
{
	LinkedListStack	*LLS;
	Node	*newNode;

	LLS = NULL;
	LLS_Create_Stack(&LLS);
	newNode = LLS_Create_Node("ang");
	LLS_Push(LLS, newNode);
	newNode = LLS_Create_Node("gie");
	LLS_Push(LLS, newNode);
	newNode = LLS_Create_Node("moe");
	LLS_Push(LLS, newNode);
	newNode = LLS_Create_Node("zzy");
	LLS_Push(LLS, newNode);
	printf("Stack Size : %d\n", LLS_Get_Size(LLS));
	printf("Top : %s\n", LLS_Top(LLS)->data);
	printf("------------------------\n");
	while (! LLS_Is_Empty(LLS))
	{
		printf("%s\n", LLS_Pop(LLS)->data);
	}
}
