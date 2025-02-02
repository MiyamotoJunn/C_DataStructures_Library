#ifndef DLL_H
#define DLL_H

#include<stdlib.h>

typedef int DLL_Type;

typedef struct Node
{
	DLL_Type data;
	struct Node *prev;
	struct Node *next;
}Node;

Node	*DLL_Create_Node(DLL_Type data);
void	DLL_Delete_Node(Node *node);
void	DLL_Append_Node(Node **p_head, Node *newNode);
Node	*DLL_Get_Node_At(Node *head, int index);
void	DLL_Remove_Node(Node **p_head, Node *node_to_remove);
void	DLL_Insert_Node_After(Node *target_node, Node *after_node);
int		DLL_Get_Count_Nodes(Node *head);


#endif
