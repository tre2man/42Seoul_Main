#include "main.h"

//test double linked list

node *new_node(int num)
{
	node *new;

	new = malloc(sizeof(node));
	if (!new)
		return (0);
	new->data = num;
	new->back = NULL;
	new->next = NULL;
	return (new);
}

void print_node(node *start)
{
	if (!start)
		printf("NULL");
	else
	{
		while (start)
		{
			printf("%d ", start->data);
			start = start->next;
		}
	}
	printf("\n");
}

int size_node(node *start)
{
	int rtn;

	rtn = 0;
	if (start)
	{
		while (start)
		{
			start = start->next;
			rtn++;
		}
	}
	return (rtn);
}

void free_node(node *start)
{
	node *temp;

	while (start)
	{
		temp = start->next;
		free(start);
		start = temp;
	}
}

void add_node_front(node **start, int data)
{
	node *new;

	new = new_node(data);
	(*start)->back = new;
	new->next = *start;
	*start = new;
}

void add_node_back(node **start, int data)
{
	node *new;
	node *front;

	front = *start;
	new = new_node(data);
	while ((*start)->next)
		*start = (*start)->next;
	(*start)->next = new;
	new->back = *start;
	*start = front;
}

int pop_node_front(node **start)
{
	node *rtn;
	int rtn_num;

	rtn = *start;
	if (!rtn)
		return (0);
	*start = (*start)->next;
	rtn->next = NULL;
	rtn_num = rtn->data;
	free(rtn);
	return (rtn_num);
}

int pop_node_back(node **start)
{
	node *rtn;
	node *front;
	int rtn_num;

	front = *start;
	if (!front)
		return (0);
	else if (!((*start)->next))
	{
		*start = NULL;
		front->next = NULL;
		rtn_num = front->data;
		free(front);
		return (rtn_num);
	}
	while((*start)->next)
		*start = (*start)->next;
	rtn = *start;
	(*start)->back->next = NULL;
	(*start)->back = NULL;
	*start = front;
	rtn_num = rtn->data;
	free(rtn);
	return (rtn_num);
}

int main()
{
	node *head;
	int data1;

	head = new_node(1);
	add_node_back(&head, 2);
	add_node_back(&head, 3);
	add_node_front(&head, 0);
	add_node_front(&head, -1);
	print_node(head);

	pop_node_front(&head);
	print_node(head);

	pop_node_back(&head);
	print_node(head);

	pop_node_back(&head);
	print_node(head);

	free_node(head);
	return (0);
}
