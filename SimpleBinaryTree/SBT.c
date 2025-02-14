#include "SBT.h"

Node	*SBT_Create_Node(SBT_Type data)
{
	Node	*newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;

	return (newNode);
}

void	SBT_Delete_Node(Node *node_to_delete)
{
	free(node_to_delete);
}

void	SBT_Preorder_Print(Node *node)
{
	if (node == NULL)
		return;

	printf("%c", node->data);
	SBT_Preorder_Print(node->left);
	SBT_Preorder_Print(node->right);
}

void	SBT_Inorder_Print(Node *node)
{
	if (node == NULL)
		return;

	SBT_Inorder_Print(node->left);
	printf("%c", node->data);
	SBT_Inorder_Print(node->right);
}

void	SBT_Postorder_Print(Node *node)
{
	if (node == NULL)
		return;
	SBT_Postorder_Print(node->left);
	SBT_Postorder_Print(node->right);
	printf("%c", node->data);
}
	
void	SBT_Delete_Tree(Node *node)
{
	if (node == NULL)
		return;

	SBT_Delete_Tree(node->left);
	SBT_Delete_Tree(node->right);
	SBT_Delete_Node(node);
}
