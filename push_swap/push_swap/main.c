/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <namwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 18:43:14 by namwkim           #+#    #+#             */
/*   Updated: 2021/08/28 01:21:30 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	int		idx;
	int		loc;
	tree	*argv_dup_checker;

	idx = 0;
	if (argc <= 1)
		return (0);
	while (++idx <= argc)
	{
		loc = -1;
		while (argv[idx][++loc])
			if (!ft_isdigit(argv[idx][loc]))
				return (throw_error("Input error!"));
	}
	idx = 0;
	while (++idx <= argc)
	{
		if (tree_insert_data(&argv_dup_checker, ft_atoi(argv[idx])))
		{
			free_all_tree(argv_dup_checker);
			return (throw_error("Duplocated args!"));
		}
	}
	free_all_tree(argv_dup_checker);
	// 실제 계산 실행되는 로직
	return (0);
}