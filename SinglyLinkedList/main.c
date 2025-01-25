#include<unistd.h>
#include<stdio.h>
#include "SLL.h"

int	main()
{
	Node *SLL;
	Node *newNode;
	Node *tNode;
	int	i;

	SLL = NULL;
	i = 1;
	while (i < 6)
	{
		newNode = SLL_Create_Node(i * 10);
		SLL_Append_Node(&SLL, newNode);
		i++;
	}
	i = 0;
	while (i < 5)
	{
		printf("%d\n", SLL_Get_Node_At(SLL, i)->data);
		i++;
	}
	newNode = SLL_Create_Node(100);
	tNode = SLL_Get_Node_At(SLL, 2);
	SLL_Insert_Node_After(tNode, newNode);
	i = 0;
	printf("---------------------\n");
	while (i < 6)
	{
		printf("%d\n", SLL_Get_Node_At(SLL, i)->data);
		i++;
	}
	printf("---------------------\n");
	newNode = SLL_Create_Node(200);
	tNode = SLL_Get_Node_At(SLL, 4);
	SLL_Insert_Node_Before(&SLL, tNode, newNode);
	i = 0;
	while (i < 7)
	{
		printf("%d\n", SLL_Get_Node_At(SLL, i)->data);
		i++;
	}
	printf("---------------------\n");
	i = 0;
	while (i < 7)
	{
		Node *node_to_remove;
		node_to_remove = SLL_Get_Node_At(SLL, 0);
		SLL_Remove_Node(&SLL, node_to_remove);
		SLL_Deleate_Node(node_to_remove);
		i++;
	}
	printf("%p", SLL);
}
