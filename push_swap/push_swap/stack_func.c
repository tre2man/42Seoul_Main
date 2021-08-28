/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <namwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 21:04:54 by namwkim           #+#    #+#             */
/*   Updated: 2021/08/28 01:26:40 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sx(stack *stack_a, stack *stack_b, char c)
{
	int	x;
	int	y;
	if (stack_a->size <= 1 || stack_b->size <= 1)
		return (0);
	if (c == 'a' || c == 's')
	{
		x = del_node_back(stack_a);
		y = del_node_back(stack_a);
		add_node_back(stack_a, x);
		add_node_back(stack_a, y);
	}
	if (c == 'b' || c == 's')
	{
		x = del_node_back(stack_b);
		y = del_node_back(stack_b);
		add_node_back(stack_b, x);
		add_node_back(stack_b, y);
	}
	return (1);
}

int	px(stack *stack_a, stack *stack_b, char c)
{
	int	x;
	if (stack_b->size <= 0 && c == 'a')
		return (0);
	if (stack_a->size <= 0 && c == 'b')
		return (0);
	if (c == 'a')
	{
		x = del_node_back(stack_b);
		add_node_back(stack_a, x);
	}
	if (c == 'b')
	{
		x = del_node_back(stack_a);
		add_node_back(stack_b, x);
	}
	return (1);
}

int	rx(stack *stack_a, stack *stack_b, char c)
{
	int	x;
	if (stack_a->size <= 1 && (c == 'a' || c == 'r'))
		return (0);
	if (stack_b->size <= 1 && (c == 'b' || c == 'r'))
		return (0);
	if (c == 'a' || c == 'r')
	{
		x = del_node_back(stack_a);
		add_node_front(stack_a, x);
	}
	if (c == 'b' || c == 'r')
	{
		x = del_node_back(stack_b);
		add_node_front(stack_b, x);
	}
	return (1);
}

int	rrx(stack *stack_a, stack *stack_b, char c)
{
	int	x;
	if (stack_a->size <= 0 && (c == 'a' || c == 'r'))
		return (0);
	if (stack_b->size <= 0 && (c == 'b' || c == 'r'))
		return (0);
	if (c == 'a' || c == 'r')
	{
		x = del_node_front(stack_a);
		add_node_back(stack_a, x);
	}
	if (c == 'b' || c == 'r')
	{
		x = del_node_front(stack_b);
		add_node_back(stack_b, x);
	}
	return (1);
}
