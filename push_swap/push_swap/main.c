/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <namwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 18:43:14 by namwkim           #+#    #+#             */
/*   Updated: 2022/02/02 17:21:47 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	int		rtn;

	rtn = check_notnumber_args(argc, argv);
	if (rtn != 0)
		return throw_error("Args invalid!");
	rtn = check_duplicate_args(argc, argv);
	if (rtn != 0)
		return throw_error("Args duplicated!");
	// 실제 계산 실행되는 로직
	sorter(argc, argv);
	return (0);
}