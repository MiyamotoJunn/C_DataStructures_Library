#include "ET.h"

Node	*ET_Create_Node(char data)
{
	Node	*newNode;

	newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;

	return (newNode);
}

void	ET_Delete_Node(Node *node)
{
	free(node);
}

void	ET_Delete_Tree(Node *root)
{
	if (root == NULL)
		return;

	ET_Delete_Tree(root->left);
	ET_Delete_Tree(root->right);
	ET_Delete_Node(root);
}

void	ET_Preorder_Print(Node *node)
{
	if (node == NULL)
		return;

	printf(" %c", node->data);
	ET_Preorder_Print(node->left);
	ET_Preorder_Print(node->right);
}

void	ET_Inorder_Print(Node *node)
{
	if (node == NULL)
		return;

	ET_Inorder_Print(node->left);
	printf(" %c", node->data);
	ET_Inorder_Print(node->right);
}

void	ET_Postorder_Print(Node *node)
{
	if (node == NULL)
		return;

	ET_Postorder_Print(node->left);
	ET_Postorder_Print(node->right);
	printf(" %c", node->data);
}

void	ET_Build_ET(char *postfix, Node **p_et)
{
	int	len = strlen(postfix);
	char	token = postfix[len - 1];
	postfix[len - 1] = '\0';

	if (token == '*' || token == '/' || token == '+' || token == '-')
	{
		(*p_et) = ET_Create_Node(token);
		ET_Build_ET(postfix, &((*p_et)->right));
		ET_Build_ET(postfix, &((*p_et)->left));
	}
	else
	{
		(*p_et) = ET_Create_Node(token);
	}
}

double	ET_Evaluate(Node *et)
{
	if (et == NULL)
		return (0);

	double result = 0;
	double operand1 = 0;
	double operand2 = 0;
	if (et->data == '*' || et->data == '/' || et->data == '+' || et->data == '-')
	{
		operand1 = ET_Evaluate(et->left);
		operand2 = ET_Evaluate(et->right);
		if (et->data == '*')
			result = operand1 * operand2;
		else if (et->data == '/')
			result = operand1 / operand2;
		else if (et->data == '+')
			result = operand1 + operand2;
		else if (et->data == '-')
			result = operand1 - operand2;
		return (result);
	}
	else
	{
		result = (double)((et->data) - '0');
		return (result);
	}
}

