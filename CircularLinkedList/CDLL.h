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

Node	*CDLL_Create_Node(CDLL_Type data);
void	CDLL_Delete_Node(Node *node);
void	CDLL_Append_Node(Node **p_head, Node *newNode);
Node	*CDLL_Get_Node_From_Index(Node *head, int index);
int		CDLL_Get_Rindex_From_Data(Node *head, CDLL_Type data);
int		CDLL_Get_Lindex_From_Data(Node *head, CDLL_Type data);
void	CDLL_Remove_Node(Node **p_head, Node *node_to_remove);
void	CDLL_Insert_Node_After(Node *target_Node, Node *after_node);
int		CDLL_Get_Count_Nodes(Node *head);
void	CDLL_Move_pHead_R(Node **p_head);
void	CDLL_Move_pHead_L(Node **p_head);

#endif
