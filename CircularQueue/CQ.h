#ifndef CQ_H
#define CQ_H

#include<stdlib.h>
#include<stdio.h>

typedef int CQ_Type;

typedef struct Node
{
	CQ_Type data;
}Node;

typedef struct CircularQueue
{
	int	capacity;
	int	front;
	int	rear;
	Node	*nodes;
}CircularQueue;

void	CQ_Create_Queue(CircularQueue **p_queue, int capacity);
void	CQ_Delete_Queue(CircularQueue *queue);
void	CQ_Enqueue(CircularQueue *queue, CQ_Type data);
CQ_Type	CQ_Dequeue(CircularQueue *queue);
int		CQ_Is_Empty(CircularQueue *queue);
int		CQ_Is_Full(CircularQueue *queue);
int		CQ_Get_Size(CircularQueue *queue);

#endif
