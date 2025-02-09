#include "CQ.h"

void	CQ_Create_Queue(CircularQueue **p_queue, int capacity)
{
	 *p_queue = (CircularQueue*)malloc(sizeof(CircularQueue));
	 (*p_queue)->capacity = capacity;
	 (*p_queue)->front = 0;
	 (*p_queue)->rear = 0;
	 (*p_queue)->nodes = (Node*)malloc(sizeof(Node) * (capacity + 1));
}

void	CQ_Delete_Queue(CircularQueue *queue)
{
	free(queue->nodes);
	free(queue);
}

int	CQ_Is_Full(CircularQueue *queue)
{
	if (queue->front < queue->rear)
		return (queue->rear - queue->front == queue->capacity);
	return (queue->front - queue->rear == 1);
}

int	CQ_Is_Empty(CircularQueue *queue)
{
	return (queue->front == queue->rear);
}

void	CQ_Enqueue(CircularQueue *queue, CQ_Type data)
{
	if (CQ_Is_Full(queue))
	{
		printf("\n!!!! QUEUE IS FULL !!!!\n");
		return;
	}

	int	index = 0;

	if (queue->rear == queue->capacity)
	{
		index = queue->rear;
		queue->rear = 0;
	}
	else
	{
		index = queue->rear;
		queue->rear++;
	}
	queue->nodes[index].data = data;
}

CQ_Type	CQ_Dequeue(CircularQueue *queue)
{
	int	index = 0;

	if (queue->front == queue->capacity)
	{
		index = queue->front;
		queue->front = 0;
	}
	else
	{
		index = queue->front;
		queue->front++;
	}
	return (queue->nodes[index].data);
}

int	CQ_Get_Size(CircularQueue *queue)
{
	if (queue->rear >= queue->front)
	{
		return (queue->rear - queue->front);
	}
	else
	{
		return (queue->rear + queue->capacity - queue->front + 1);
	}
}
