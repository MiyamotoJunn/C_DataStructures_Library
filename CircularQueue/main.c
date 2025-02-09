#include "CQ.h"
#include<string.h>

//ps 10845

int	main()
{
	int	n;
	int	i;
	char	*command;
	CircularQueue *CQ = NULL;

	scanf("%d", &n);
	i = 0;
	command = (char*)malloc(sizeof(char) * 6);
	CQ_Create_Queue(&CQ, n);
	while (i < n)
	{
		scanf("%s", command);
		if (strcmp(command, "push") == 0)
		{
			int data;
			scanf("%d", &data);
			CQ_Enqueue(CQ, data);
		}
		else if (strcmp(command, "pop") == 0)
		{
			if (CQ_Is_Empty(CQ))
				printf("-1\n");
			else
			{
				printf("%d\n", CQ_Dequeue(CQ));
			}
		}
		else if (strcmp(command, "size") == 0)
		{
			printf("%d\n", CQ_Get_Size(CQ));
		}
		else if (strcmp(command, "empty") == 0)
		{
			printf("%d\n", CQ_Is_Empty(CQ));
		}
		else if (strcmp(command, "front") == 0)
		{
			if (CQ_Is_Empty(CQ))
				printf("-1\n");
			else
			{
				printf("%d\n", CQ->nodes[CQ->front].data);
			}
		}
		else if (strcmp(command, "back") == 0)
		{
			if (CQ_Is_Empty(CQ))
				printf("-1\n");
			else
			{
				printf("%d\n", CQ->nodes[CQ->rear - 1].data);
			}
		}
		i++;
	}
}
