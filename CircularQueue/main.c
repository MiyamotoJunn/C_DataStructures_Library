#include "CQ.h"
#include<string.h>

//ps 2164

int	main()
{
	int	n;
	int	i;
	CircularQueue *CQ = NULL;
	scanf("%d", &n);
	CQ_Create_Queue(&CQ, n);
	i = 1;
	while (i <= n)
	{
		CQ_Enqueue(CQ, i);
		i++;
	}
	int data;
	while (CQ_Get_Size(CQ) != 1)
	{
		CQ_Dequeue(CQ);
		data = CQ_Dequeue(CQ);
		CQ_Enqueue(CQ, data);
	}
	printf("rast : %d", CQ_Dequeue(CQ));

}
