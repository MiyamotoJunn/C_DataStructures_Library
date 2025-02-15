#include "DS.h"

Node	*DS_Find_Set(Node *node)
{
	while (node->parent != NULL)
	{
		node = node->parent;
	}
	return (node);
}

void	DS_Union_Set(Node *set1, Node *set2)
{
	Node *mom = DS_Find_Set(set2);
	if (mom != DS_Find_Set(set1))
		mom->parent = set1;
}

Node	*DS_Make_Set(DS_Type data)
{
	Node *newNode;

	newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->parent = NULL;

	return (newNode);
}

void	DS_Delete_Set(Node *node)
{
	free(node);
}
