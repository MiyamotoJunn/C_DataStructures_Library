#include "LCRST.h"

//ps 1068

int	main()
{
	Node	**family;
	Node	*root;
	int	n;
	scanf("%d", &n);
	family = (Node**)malloc(sizeof(Node*) * n);
	root = (Node*)malloc(sizeof(Node));
	int i = 0;
	while (i < n)
	{
		family[i] = LCRST_Create_Node(i);
		i++;
	}
	i = 0;
	while (i < n)
	{
		int	j;
		scanf("%d", &j);
		if (j == -1)
			root = family[i];
		if (j >= 0)
		{
			LCRST_Add_Child(family[j], family[i]);
		}
		i++;
	}
	LCRST_Print_Tree(root, 0);
	int	kill;
	scanf("%d", &kill);
	if (root == family[kill])
	{
		printf("0");
		return (0);
	}
	LCRST_Delete_Node_In_Tree(root, family[kill]);
	int	*counter = (int*)malloc(sizeof(int));
	(*counter) = 0;
	LCRST_Get_Count_Leafs(root, counter);
	printf("%d", (*counter));
}
