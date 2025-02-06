#ifndef AS_H
#define AS_H

#include<stdlib.h>

typedef int AS_Type;

typedef struct Node
{
	AS_Type data;
}Node;

typedef struct ArrayStack
{
	int	capacity;
	int	top;
	Node	*nodes;
}ArrayStack;

void	AS_Create_Stack(ArrayStack **p_stack, int capacity);
void	AS_Remove_Stack(ArrayStack *stack);
void	AS_Push(ArrayStack *stack, AS_Type data);
AS_Type	AS_Pop(ArrayStack *stack);
AS_Type	AS_Top(ArrayStack *stack);
int		AS_Get_Size(ArrayStack *stack);
int		AS_Is_Empty(ArrayStack *stack);
int		AS_Is_Full(ArrayStack *stack);

#endif
