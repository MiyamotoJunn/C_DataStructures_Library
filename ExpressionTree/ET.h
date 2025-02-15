#ifndef ET_H
#define ET_H

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct Node
{
	char	data;
	struct Node *left;
	struct Node *right;
}Node;

Node	*ET_Create_Node(char data);
void	ET_Delete_Node(Node *node);
void	ET_Delete_Tree(Node *root);
void	ET_Preorder_Print(Node *node);
void	ET_Inorder_Print(Node *node);
void	ET_Postorder_Print(Node *node);
void	ET_Build_ET(char *postfix, Node **p_et);
double	ET_Evaluate(Node *et);

#endif
