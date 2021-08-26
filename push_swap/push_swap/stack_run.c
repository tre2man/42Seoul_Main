/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_run.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <namwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 21:04:54 by namwkim           #+#    #+#             */
/*   Updated: 2021/08/26 21:04:59 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sx(node **stack_a, node **stack_b, char c)
{
	int	x;
	int	y;
	if (get_stack_size(*stack_a) <= 1 || get_stack_size(*stack_b) <= 1)
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

int	px(node **stack_a, node **stack_b, char c)
{
	int	x;
	if (get_stack_size(*stack_b) <= 0 && c == 'a')
		return (0);
	if (get_stack_size(*stack_a) <= 0 && c == 'b')
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

int	rx(node **stack_a, node **stack_b, char c)
{
	int	x;
	if (get_stack_size(*stack_a) <= 1 && (c == 'a' || c == 'r'))
		return (0);
	if (get_stack_size(*stack_b) <= 1 && (c == 'b' || c == 'r'))
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

int	rrx(node **stack_a, node **stack_b, char c)
{
	int	x;
	if (get_stack_size(*stack_a) <= 0 && (c == 'a' || c == 'r'))
		return (0);
	if (get_stack_size(*stack_b) <= 0 && (c == 'b' || c == 'r'))
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
