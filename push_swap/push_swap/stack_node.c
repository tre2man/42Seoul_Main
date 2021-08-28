/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <namwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 21:04:12 by namwkim           #+#    #+#             */
/*   Updated: 2021/08/28 01:22:33 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

node		*new_node(int num)
{
	node	*new;

	new = malloc(sizeof(node));
	if (!new)
		return (0);
	new->data = num;
	new->back = NULL;
	new->next = NULL;
	return (new);
}

void add_node_front(stack *stack, int data)
{
	node	*new;

	new = new_node(data);
	if (!(stack->head))
	{
		stack->head = new;
		stack->tail = new;
	}
	else
	{
		stack->head->back = new;
		new->next = stack->head;
		stack->head = new;
	}
	stack->size++;
}

void add_node_back(stack *stack, int data)
{
	node	*new;

	new = new_node(data);
	if (!stack->tail)
	{
		stack->head = new;
		stack->tail = new;
	}
	else
	{
		stack->tail->next = new;
		new->back = stack->tail;
		stack->tail = new;
	}
	stack->size++;
}

int del_node_front(stack *stack)
{
	node	*del;
	int		rtn_num;

	del = stack->head;
	if (!del)
		return (0);
	stack->head = stack->head->next;
	stack->head->back = NULL;
	del->next = NULL;
	rtn_num = del->data;
	stack->size--;
	free(del);
	return (rtn_num);
}

int del_node_back(stack *stack)
{
	node	*del;
	int		rtn_num;

	del = stack->tail;
	if (!del)
		return (0);
	stack->tail = stack->tail->back;
	stack->tail->next = NULL;
	del->back = NULL;
	rtn_num = del->data;
	stack->size--;
	free(del);
	return (rtn_num);
}
