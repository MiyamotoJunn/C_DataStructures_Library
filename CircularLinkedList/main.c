#include<stdio.h>
#include "CDLL.h"

int	main()
{
	int	N;
	int	M;
	int	*index_box;
	int	i;

	Node	*CDLL;
	CDLL = NULL;
	Node	*newNode;
	int		totalCount = 0;
	int		nextCount = 0;
	int		prevCount = 0;

	scanf("%d %d", &N, &M);
	index_box = (int*)malloc(sizeof(int) * M);
	if (index_box == NULL)
		return (0);
	i = 0;
	while (i < M)
	{
		scanf("%d", &(index_box[i]));
		i++;
	}

	i = 0;
	while (i < N)
	{
		newNode = CDLL_Create_Node(1 + i);
		CDLL_Append_Node(&CDLL, newNode);
		i++;
	}
	i = 0;
	while (i < M)
	{
		int data = index_box[i];
		nextCount = CDLL_Get_Rindex_From_Data(CDLL, data);
		prevCount = CDLL_Get_Lindex_From_Data(CDLL, data);
		if (nextCount == prevCount)
			totalCount += nextCount;
		else if (nextCount < prevCount)
			totalCount += nextCount;
		else
			totalCount += prevCount;
		Node *node_to_remove = CDLL_Get_Node_From_Index(CDLL, nextCount);
		CDLL = node_to_remove;
		CDLL_Remove_Node(&CDLL, node_to_remove);
		i++;
	}
	printf("%d", totalCount);

}
	

