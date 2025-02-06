#include "AS.h"

void	AS_Create_Stack(ArrayStack **p_stack, int capacity)
{
	*p_stack = (ArrayStack*)malloc(sizeof(ArrayStack));
	(*p_stack)->capacity = capacity;
	(*p_stack)->top = -1;
	(*p_stack)->nodes = (Node*)malloc(sizeof(Node) * capacity);
}

void	AS_Delete_Stack(ArrayStack *stack)
{
	free(stack->nodes);
	free(stack);
}

void	AS_Push(ArrayStack *stack, AS_Type data)
{
	stack->top++;
	stack->nodes[stack->top].data = data;
}

AS_Type	AS_Pop(ArrayStack *stack)
{
	AS_Type data;

	if (stack->top == -1)
		return (-1);
	data = stack->nodes[stack->top].data;
	stack->top--;

	return (data);
}

AS_Type AS_Top(ArrayStack *stack)
{
	if (stack->top == -1)
		return (-1);
	return (stack->nodes[stack->top].data);
}

int	AS_Get_Size(ArrayStack *stack)
{
	return (stack->top + 1);
}

int	AS_Is_Empty(ArrayStack *stack)
{
	return (stack->top == -1);
}

int	AS_Is_Full(ArrayStack *stack)
{
	return (stack->top + 1 == stack->capacity);
}
