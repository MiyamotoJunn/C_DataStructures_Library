#include "CDLL.h"

Node *CDLL_Create_Node(CDLL_Type data)
{
	Node *newNode;

	newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->prev = NULL;
	newNode->next = NULL;

	return (newNode);
}

void	CDLL_Delete_Node(Node *node)
{
	free(node);
}

void	CDLL_Append_Node(Node **p_head, Node *newNode)
{
	if (*p_head == NULL)
	{
		*p_head = newNode;
		newNode->prev = newNode;
		newNode->next = newNode;
	}
	else
	{
		(*p_head)->prev->next = newNode;
		newNode->prev = (*p_head)->prev;
		newNode->next = (*p_head);
		(*p_head)->prev = newNode;
	}
}

Node	*CDLL_Get_Node_At(Node *head, int index)
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

void	CDLL_Remove_Node(Node **p_head, Node *node_to_remove)
{
	if (*p_head == node_to_remove)
	{
		if (node_to_remove->prev == node_to_remove->next)
			*p_head = NULL;
		else
		{
			(*p_head)->prev->next = (*p_head)->next;
			(*p_head)->next->prev = (*p_head)->prev;
			*p_head = (*p_head)->next;
			CDLL_Delete_Node(node_to_remove);
		}
	}
	else
	{
		node_to_remove->prev->next = node_to_remove->next;
		node_to_remove->next->prev = node_to_remove->prev;
		node_to_remove->prev = NULL;
		node_to_remove->next = NULL;
	}
}

void	CDLL_Insert_Node_After(Node *target_node, Node *after_node)
{
	target_node->next->prev = after_node;
	after_node->next = target_node->next;
	after_node->prev = target_node;
	target_node->next = after_node;
}

int	CDLL_Get_Count_Nodes(Node *head)
{
	int	count;
	Node *current;

	if (head == NULL)
		return (0);
	if (head->prev == head->next)
		return (1);
	count = 1;
	current = head;
	while (current->next != head)
	{
		current = current->next;
		count++;
	}
	return (count);
}

