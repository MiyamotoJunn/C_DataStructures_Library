#include "LQ.h"

void	LQ_Create_Queue(LinkedQueue **p_queue)
{
	*p_queue = (LinkedQueue*)malloc(sizeof(LinkedQueue));
	(*p_queue)->front = NULL;
	(*p_queue)->rear = NULL;
	(*p_queue)->count = 0;
}

void	LQ_Delete_Queue(LinkedQueue *queue)
{
	if (! LQ_Is_Empty(queue))
	{
		Node* dequeued = LQ_Dequeue(queue);
		LQ_Delete_Node(dequeued);
	}
	free(queue);
}

Node*	LQ_Create_Node(LQ_Type data)
{
	Node	*newNode;
	newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;

	return (newNode);
}

void	LQ_Delete_Node(Node *node_to_delete)
{
	free(node_to_delete);
}

void	LQ_Enqueue(LinkedQueue *queue, Node *newNode)
{
	if (queue->front == NULL)
	{
		queue->front = newNode;
		queue->rear = newNode;
		queue->count++;
	}
	else
	{
		queue->rear->next = newNode;
		queue->rear = newNode;
		queue->count++;
	}
}

Node	*LQ_Dequeue(LinkedQueue *queue)
{
	Node	*node_to_return;
	node_to_return = queue->front;
	if (queue->front->next == NULL)
	{
		queue->front = NULL;
		queue->rear = NULL;
		queue->count = 0;
	}
	else
	{
		queue->front = queue->front->next;
		queue->count--;
	}
	return (node_to_return);
}

int	LQ_Is_Empty(LinkedQueue *queue)
{
	return (queue->front == NULL);
}

int	LQ_Get_Size(LinkedQueue *queue)
{
	return (queue->count);
}
