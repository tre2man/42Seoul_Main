/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_onenode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <namwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 21:04:38 by namwkim           #+#    #+#             */
/*   Updated: 2021/08/26 21:17:05 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void print_stack(node *start)
{
	if (!start)
		ft_putendl_fd("NULL", 2);
	else
	{
		while (start)
		{
			ft_putnbr_fd(start->data, 1);
			ft_putstr_fd(" ", 1);
			start = start->next;
		}
	}
	ft_putstr_fd("\n", 2);
}

int get_stack_size(node *start)
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

void free_all_node(node *start)
{
	node *temp;

	while (start)
	{
		temp = start->next;
		free(start);
		start = temp;
	}
}
