#include<stdio.h>
#include "CDLL.h"

// ps 1158

int	main()
{
	int	n;
	int	k;
	int	i;
	Node	*CDLL = NULL;
	Node	*newNode;

	scanf("%d %d", &n, &k);
	i = 0;
	while (i < n)
	{
		newNode = CDLL_Create_Node(1 + i);
		CDLL_Append_Node(&CDLL, newNode);
		i++;
	}
	i = 0;
	printf("<");
	while  (CDLL != NULL)
	{
		Node	*node_to_delete;
		node_to_delete = CDLL_Get_Node_From_Index(CDLL, k - 1);
		if (CDLL->next != CDLL)
		{
			printf("%d, ", node_to_delete->data);
		}
		else
			printf("%d>", node_to_delete->data);
		CDLL = node_to_delete;
		CDLL_Remove_Node(&CDLL, node_to_delete);
	}
}
	

