#include "DS.h"
#include <stdio.h>

//ps 1976

int	main()
{
	int	n;
	int	m;
	int	i = 0;
	int	j = 0;
	int	k = 0;
	Node	**node_list;
	int	*num_list;

	scanf("%d", &n);
	scanf("%d", &m);

	node_list = (Node**)malloc(sizeof(Node*) * n);
	num_list = (int*)malloc(sizeof(int) * m);
	while (i < n)
	{
		node_list[i] = DS_Make_Set(i + 1);
		i++;
	}
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			scanf ("%d", &k);
			if (k == 1)
				DS_Union_Set(node_list[i], node_list[j]);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < m)
	{
		scanf ("%d", &(num_list[i]));
		i++;
	}
	i = 0;
	Node	*root;
	while (i < m - 1)
	{
		root = DS_Find_Set(node_list[num_list[i] - 1]);
		if( DS_Find_Set(node_list[num_list[i + 1] - 1]) != root)
		{
			printf("NO\n");
			return (0);
		}
		printf("%d\n", i);
		i++;
	}
	printf("YES\n");
}
