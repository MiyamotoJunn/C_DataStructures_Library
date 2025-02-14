#ifndef SBT_H
#define SBT_H

#include<stdlib.h>
#include<stdio.h>

typedef char SBT_Type;

typedef struct Node
{
	SBT_Type data;
	struct Node *left;
	struct Node *right;
}Node;

Node	*SBT_Create_Node(SBT_Type data);
void	SBT_Delete_Node(Node *node_to_delete);
void	SBT_Preorder_Print(Node *node);
void	SBT_Inorder_Print(Node *node);
void	SBT_Postorder_Print(Node *node);
void	SBT_Delete_Tree(Node *node);

#endif
