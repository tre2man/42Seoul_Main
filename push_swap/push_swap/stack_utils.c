/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_onenode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <namwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 22:23:53 by namwkim           #+#    #+#             */
/*   Updated: 2021/08/28 01:22:30 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

stack		new_stack(void)
{
	stack	new;

	new.head = NULL;
	new.tail = NULL;
	new.size = 0;
	return (new);
}

void		print_stack(stack stack)
{
	if (!(stack.head))
		ft_putstr_fd("NULL", 1);
	else
	{
		while (stack.head)
		{
			ft_putnbr_fd((stack.head)->data, 1);
			ft_putstr_fd(" ", 1);
			stack.head = (stack.head)->next;
		}
	}
	ft_putstr_fd("\n", 1);
}

void		free_stack(stack stack)
{
	node	*temp;

	while (stack.head)
	{
		temp = (stack.head)->next;
		free(stack.head);
		stack.head = temp;
	}
}
