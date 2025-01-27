#ifndef SLL_H
#define SLL_H

#include<stdlib.h>

typedef int	SLL_Type;

typedef struct Node{
	SLL_Type data;
	struct Node *next;
}Node;

Node	*SLL_Create_Node(SLL_Type data);
void	SLL_Deleate_Node(Node *node);
void	SLL_Append_Node(Node **p_Head, Node *newNode);
Node	*SLL_Get_Node_At(Node *head, int index);
void	SLL_Remove_Node(Node **p_head, Node *node_to_remove);
void	SLL_Remove_Node_ALL(Node **p_head);
void	SLL_Insert_Node_After(Node *target_node, Node *after_node);
void	SLL_Insert_Node_Before(Node **p_head, Node *target_node, Node *before_node);
int		SLL_Get_Count_Nodes(Node *head);



#endif
