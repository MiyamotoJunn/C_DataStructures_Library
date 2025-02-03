#ifndef CDLL_H
#define CDLL_H

#include<stdlib.h>

typedef int CDLL_Type;

typedef struct Node
{
	CDLL_Type data;
	struct Node *prev;
	struct Node *next;
}Node;

Node	*CDLL_Create_Node(DLL_Type data);
void	CDLL_Delete_Node(Node *node);
void	CDLL_Append_Node(Node **p_head, Node *newNode);
Node	*CDLL_Get_Node_At(Node *head, int index);
void	CDLL_Remove_Node(Node **p_head, Node *node_to_remove);
void	CDLL_Insert_Node_After(Node *target_Node, Node *after_node);
int		CDLL_Get_Count_Nodes(Node *head);

#endif
