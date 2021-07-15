#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int			data;
	struct node	*back;
	struct node	*next;
}	node;

typedef struct stack
{
	node	*front;
	node	*rear;
}	stack;
