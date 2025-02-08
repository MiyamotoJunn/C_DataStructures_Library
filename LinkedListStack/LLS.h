#ifndef LLS_H
#define LLS_H

#include<stdlib.h>

typedef float LLS_Type;

typedef struct Node
{
	LLS_Type	data;
	struct Node	*next;
}Node;

typedef struct LinkedListStack
{
	Node	*list;
	Node	*top;
}LinkedListStack;

void	LLS_Create_Stack(LinkedListStack **p_stack);
void	LLS_Delete_Stack(LinkedListStack *stack);
Node	*LLS_Create_Node(LLS_Type data);
void	LLS_Delete_Node(Node *node_to_delete);
void	LLS_Push(LinkedListStack *stack, Node *node_to_push);
Node	*LLS_Pop(LinkedListStack *stack);
Node	*LLS_Top(LinkedListStack *stack);
int		LLS_Get_Size(LinkedListStack *stack);
int		LLS_Is_Empty(LinkedListStack *stack);

#endif
