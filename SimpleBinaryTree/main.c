#include "SBT.h"

int main()
{
	int	n;
	scanf("%d", &n);
	
	int i = 0;
	Node	**List = (Node**)malloc(sizeof(Node*) * n);
	while (i < n)
	{
		List[i] = SBT_Create_Node('A' + i);
		i++;
	}
	i = 0;
	char	mom;
	char	child;
	while (i < n)
	{
		scanf(" %c" , &mom);
		scanf(" %c", &child);
		if (child != '.')
			List[mom - 'A']->left = List[child - 'A'];
		scanf(" %c", &child);
		if (child != '.')
			List[mom - 'A']->right = List[child - 'A'];
		i++;
	}
	SBT_Preorder_Print(List[0]);
	printf("\n");
	SBT_Inorder_Print(List[0]);
	printf("\n");
	SBT_Postorder_Print(List[0]);
}
