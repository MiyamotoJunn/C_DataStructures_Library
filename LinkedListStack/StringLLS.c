#include "StringLLS.h"

void	LLS_Create_Stack(LinkedListStack **p_stack)
{
	*p_stack = (LinkedListStack*)malloc(sizeof(LinkedListStack));
	(*p_stack)->list = NULL;
	(*p_stack)->top = NULL;
}

void	LLS_Delete_Stack(LinkedListStack *stack)
{
	Node	*poped;
	while (! LLS_Is_Empty(stack))
	{
		poped = LLS_Pop(stack);
		LLS_Delete_Node(poped);
	}
	free(stack);
}

Node	*LLS_Create_Node(char *data)
{
	Node	*newNode;

	newNode = (Node*)malloc(sizeof(Node));
	newNode->data = (char*)malloc(strlen(data) + 1);
	strcpy(newNode->data, data);
	newNode->next = NULL;
	
	return (newNode);
}

void	LLS_Delete_Node(Node *node_to_delete)
{
	free(node_to_delete->data);
	free(node_to_delete);
}

void	LLS_Push(LinkedListStack *stack, Node *node_to_push)
{
	if (stack->list == NULL)
	{
		stack->list = node_to_push;
	}
	else
	{
		stack->top->next = node_to_push;
	}
	stack->top = node_to_push;
}

Node	*LLS_Pop(LinkedListStack *stack)
{
	Node	*node_to_pop;
	node_to_pop = stack->top;

	if (stack->list == stack->top)
	{
		stack->list = NULL;
		stack->top = NULL;
	}
	else
	{
		Node	*current;
		current = stack->list;
		while (current->next != stack->top)
		{
			current = current->next;
		}
		stack->top = current;
		current->next = NULL;
	}
	return (node_to_pop);
}

Node	*LLS_Top(LinkedListStack *stack)
{
	return (stack->top);
}

int	LLS_Get_Size(LinkedListStack *stack)
{
	int	size;
	Node	*current;

	size = 0;
	current = stack->list;
	while (current != NULL)
	{
		current = current->next;
		size++;
	}
	return (size);
}

int	LLS_Is_Empty(LinkedListStack *stack)
{
	return (stack->list == NULL);
}
