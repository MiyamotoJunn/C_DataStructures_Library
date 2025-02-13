#include "LCRST.h"

Node	*LCRST_Create_Node(LCRST_Type data)
{
	Node	*newNode;

	newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;

	return (newNode);
}

void	LCRST_Delete_Node(Node *node_to_data)
{
	free(node_to_data);
}

void	LCRST_Delete_Tree(Node *root)
{
	if (root->left != NULL)
		LCRST_Delete_Tree(root->left);
	if (root->right != NULL)
		LCRST_Delete_Tree(root->right);
	root->left = NULL;
	root->right = NULL;
	LCRST_Delete_Node(root);
}

void	LCRST_Add_Child(Node *parent, Node *child)
{
	if (parent->left == NULL)
	{
		parent->left = child;
	}
	else
	{
		Node	*current;
		current = parent->left;
		while (current->right != NULL)
		{
			current = current->right;
		}
		current->right = child;
	}
}

void	LCRST_Print_Tree(Node	*root, int depth)
{
	int	i = 0;
	while (i + 1 < depth)
	{
		printf("   ");
		i++;
	}
	if (depth != 0)
		printf("+--");
	printf("%d\n", root->data);
	if (root->left != NULL)
		LCRST_Print_Tree(root->left, depth + 1);
	if (root->right != NULL)
		LCRST_Print_Tree(root->right, depth);
}

void	LCRST_Get_Count_Leafs(Node *root, int *counter)
{
	if (root->left != NULL)
		LCRST_Get_Count_Leafs(root->left, counter);
	if (root->right != NULL)
		LCRST_Get_Count_Leafs(root->right, counter);
	if (root->left == NULL)
	{
		(*counter)++;
	}
}

void	LCRST_Delete_Node_In_Tree(Node *root, Node *node_to_delete)
{
	if (root->left != NULL)
		LCRST_Delete_Node_In_Tree(root->left, node_to_delete);
	if (root->right != NULL)
		LCRST_Delete_Node_In_Tree(root->right, node_to_delete);
	if (root->left == node_to_delete)
	{
		if (node_to_delete->right != NULL)
			root->left = node_to_delete->right;
		else
			root->left = NULL;
	}
	else if (root->left != node_to_delete && root->left != NULL)
	{
		Node	*current = root->left;
		while (current->right != NULL)
		{
			if (current->right == node_to_delete)
			{
				if (node_to_delete->right != NULL)
				{
					current->right = node_to_delete->right;
					break;
				}
				else
				{
					current->right = NULL;
					break;
				}
			}
			current = current->right;
		}
	}
}

/* 실패작 2진트리 만드는거 (완전 2진 트리는 아님)
void	LCRST_Build_Tree(Node *root, int *baby_num, int baby_limit)
{
	Node	*current;
	current = root;
	if (current->left == NULL)
	{
		Node	*baby1 = LCRST_Create_Node(++(*baby_num));
		if (*baby_num < baby_limit)
			LCRST_Add_Child(root, baby1);
		else
			return;
		Node	*baby2 = LCRST_Create_Node(++(*baby_num));
		if (*baby_num < baby_limit)
			LCRST_Add_Child(root, baby2);
		else
			return;
	}
	if (current->right != NULL) (재귀함수 쓰면 결국 안됨 )
		LCRST_Build_Tree(current->right, baby_num, baby_limit);
	if (current->left != NULL)
		LCRST_Build_Tree(current->left, baby_num, baby_limit);
}*/
