#ifndef DS_H
#define DS_H

#include<stdlib.h>

typedef int DS_Type;

typedef struct Node
{
	DS_Type	data;
	struct Node *parent;
}Node;

Node	*DS_Find_Set(Node *node);
void	DS_Union_Set(Node *set1, Node *set2);
Node	*DS_Make_Set(DS_Type data);
void	DS_Delete_Set(Node *node);

#endif
