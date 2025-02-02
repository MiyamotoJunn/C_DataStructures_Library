#include<stdio.h>
#include "DLL.h"

int	main()
{
	Node	*DLL;
	Node	*newNode;
	int	i;
	DLL = NULL;

	printf("make List\n");
	i = 1;
	while (i < 6)
	{
		newNode = DLL_Create_Node(10 * i);
		DLL_Append_Node(&DLL, newNode);
		printf("made %dst Node\n", i);
		i++;
	}
	printf("print List\n");
	i = 0;
	while (i < 5)
	{
		printf("%d\n", DLL_Get_Node_At(DLL, i)->data);
		i++;
	}
}
