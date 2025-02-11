#ifndef LQ_H
#define LQ_H

#include<stdlib.h>

typedef int LQ_Type;

typedef struct Node
{
	LQ_Type data;
	struct Node *next;
}Node;

typedef struct LinkedQueue
{
	Node	*front;
	Node	*rear;
	int		count;
}LinkedQueue;

void	LQ_Create_Queue(LinkedQueue **p_queue);
void	LQ_Delete_Queue(LinkedQueue *queue);
Node	*LQ_Create_Node(LQ_Type data);
void	LQ_Delete_Node(Node *node_to_delete);
void	LQ_Enqueue(LinkedQueue *queue, Node *newNode);
Node	*LQ_Dequeue(LinkedQueue *queue);
int		LQ_Is_Empty(LinkedQueue *queue);
int		LQ_Get_Size(LinkedQueue *queue);

#endif
