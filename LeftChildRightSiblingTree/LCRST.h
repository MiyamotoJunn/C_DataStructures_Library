#ifndef LCRST_H
#define LCRST_H

#include<stdlib.h>
#include<stdio.h>

typedef int LCRST_Type;

typedef struct Node
{
	LCRST_Type	data;
	struct Node	*left;
	struct Node	*right;
}Node;

Node	*LCRST_Create_Node(LCRST_Type data);
void	LCRST_Delete_Node(Node *node_to_data);
void	LCRST_Delete_Tree(Node *root);
void	LCRST_Add_Child(Node *parent, Node *child);
void	LCRST_Print_Tree(Node *root, int depth);
void	LCRST_Get_Count_Leafs(Node *root, int *counter);
void	LCRST_Delete_Node_In_Tree(Node *root, Node *node_to_delete);
//void	LCRST_Build_Tree(Node *root, int *baby_num, int baby_limit);

#endif
