/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <namwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 21:04:12 by namwkim           #+#    #+#             */
/*   Updated: 2021/08/26 21:04:14 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void add_node_front(node **start, int data)
{
	node	*new;

	if (!(*start))
		*start = new_node(data);
	else
	{
		new = new_node(data);
		(*start)->back = new;
		new->next = *start;
		*start = new;
	}
}

void add_node_back(node **start, int data)
{
	node	*new;
	node	*front;

	if (!(*start))
		*start = new_node(data);
	else
	{
		front = *start;
		new = new_node(data);
		while ((*start)->next)
			*start = (*start)->next;
		(*start)->next = new;
		new->back = *start;
		*start = front;
	}
}

int del_node_front(node **start)
{
	node	*rtn;
	int		rtn_num;

	rtn = *start;
	if (!rtn)
		return (0);
	*start = (*start)->next;
	rtn->next = NULL;
	rtn_num = rtn->data;
	free(rtn);
	return (rtn_num);
}

int del_node_back(node **start)
{
	node	*rtn;
	node	*front;
	int		rtn_num;

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
