#include "DLL.h"

Node	*DLL_Create_Node(DLL_Type data)
{
	Node	*newNode;

	newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->prev = NULL;
	newNode->next = NULL;

	return (newNode);
}

void	DLL_Delete_Node(Node *node)
{
	free(node);
}

void	DLL_Append_Node(Node **p_head, Node *newNode)
{
	if (*p_head == NULL)
	{
		*p_head = newNode;
	}
	else
	{
		Node	*current;

		current = *p_head;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = newNode;
		newNode->prev = current;
	}
}

Node	*DLL_Get_Node_At(Node *head, int index)
{
	Node	*current;

	current = head;
	while (index > 0 && current != NULL)
	{
		current = current->next;
		index--;
	}
	return (current);
}

void	DLL_Remove_Node(Node **p_head, Node *node_to_remove)
{
	if (*p_head == node_to_remove)
	{
		*p_head = node_to_remove->next;
		if ((*p_head)->next != NULL)
			node_to_remove->next->prev = NULL;
		node_to_remove->prev = NULL;
		node_to_remove->next = NULL;
	}
	else
	{
		node_to_remove->prev->next = node_to_remove->next;
		if (node_to_remove->next != NULL)
			node_to_remove->next->prev = node_to_remove->prev;
		node_to_remove->prev = NULL;
		node_to_remove->next = NULL;
	}
}

void	DLL_Insert_Node_After(Node *target_node, Node *after_node)
{
	if (target_node->next != NULL)
	{
		target_node->next->prev = after_node;
		after_node->next = target_node->next;
		target_node->next = after_node;
		after_node->prev = target_node;
	}
	else
	{
		target_node->next = after_node;
		after_node->prev = target_node;
	}
}

int	DLL_Get_Count_Nodes(Node *head)
{
	int	count;
	Node	*current;

	count = 0;
	current = head;
	while (current != NULL)
	{
		current = current->next;
		count++;
	}
	return (count);
}
