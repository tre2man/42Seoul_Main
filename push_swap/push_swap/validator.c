/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <namwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 16:39:42 by namwkim           #+#    #+#             */
/*   Updated: 2022/02/02 17:41:32 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_notnumber_args(int argc, char **argv)
{
	int idx;
	int loc;

	idx = 0;
	while (++idx < argc)
	{
		loc = -1;
		while (argv[idx] && argv[idx][++loc])
		{
			if (!ft_isdigit(argv[idx][loc]))
			{
				if (!(loc == 0 && (argv[idx][loc] == '+' || argv[idx][loc] == '-')))
					return (2);
			}
		}
	}
	return (0);
}

int check_duplicate_args(int argc, char **argv)
{
	int idx;
	tree *argv_duplicate_checker;

	idx = 0;
	argv_duplicate_checker = NULL;
	while (++idx < argc)
	{
		if (tree_insert_data(&argv_duplicate_checker, ft_atoi(argv[idx])))
		{
			free_all_tree(argv_duplicate_checker);
			return (2);
		}
	}
	print_tree_preorder(argv_duplicate_checker);
	return (0);
}

int get_pivot(stack a, int size)
{
	int idx;
	int ans;
	tree *checker;

	idx = 0;
	checker = NULL;
	if (size <= 2)
		return a.head->data;
	while (idx++ < size)
	{
		tree_insert_data(&checker, a.head->data);
		a.head = a.head->next;
	}
	get_value_from_index(checker, size / 2, 0, &ans);
	return ans;
}
