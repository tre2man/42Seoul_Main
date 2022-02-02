/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <namwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:12:14 by namwkim           #+#    #+#             */
/*   Updated: 2022/02/02 17:48:23 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int sorter(int argc, char **argv)
{
	int idx;
	int pivot;
	stack *a;
	stack *b;

	a = init_stack();
	b = init_stack();
	idx = 0;
	while (++idx < argc)
		add_node_front(a, ft_atoi(argv[idx]));
	pivot = get_pivot(*a, argc - 1);
	printf("\n%d\n", pivot);

	free_stack(*a);
	free_stack(*b);
	return (0);
}
