#include "SLL.h"

Node	*SLL_Create_Node(SLL_Type data)
{
	Node *newNode;

    newNode	= (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	return (newNode);
}

void	SLL_Deleate_Node(Node *node)
{
	free(node);
}

void	SLL_Append_Node(Node **p_Head, Node *newNode)
{
	if (*p_Head == NULL)
		*p_Head = newNode;
	else
	{
		Node *tail;
		tail = *p_Head;
		while (tail->next != NULL)
			tail = tail->next;
		tail->next = newNode;
	}
}

Node	*SLL_Get_Node_At(Node *head, int index)
{
	Node *current;

	current = head;
	while (index > 0 && current != NULL)
	{
		current = current->next;
		index--;
	}
	return (current);
}

void	SLL_Remove_Node(Node **p_head, Node *node_to_remove)
{
	if (*p_head == node_to_remove)
		*p_head = node_to_remove->next;
	else
	{
		Node *current = *p_head;
		while (current->next != node_to_remove && current != NULL)
			current = current->next;
		if (current != NULL)
			current->next = node_to_remove->next;
	}
}

void	SLL_Insert_Node_After(Node *target_node, Node *after_node)
{
	after_node->next = target_node->next;
	target_node->next = after_node;
}

void	SLL_Insert_Node_Before(Node **p_head, Node *target_node, Node *before_node)
{
	if (*p_head == target_node)
	{
		*p_head = before_node;
		before_node->next = target_node;
	}
	else
	{
		Node *current;
		current = *p_head;
		while (current->next != target_node && current != NULL)
			current = current->next;
		if (current != NULL)
		{
			current->next = before_node;
			before_node->next = target_node;
		}
	}
}

int	SLL_Get_Count_Nodes(Node *head)
{
	Node *current;
	int	count;

	count = 0;
	current = head;
	while (current != NULL)
	{
		current = current->next;
		count++;
	}
	return (count);
}
