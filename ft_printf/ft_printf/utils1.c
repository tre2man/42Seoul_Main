/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwoo <namwoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 16:02:55 by namwkim           #+#    #+#             */
/*   Updated: 2021/06/19 16:10:30 by namwoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag check_flag(char *str)
{
	t_flag rtn;

	ft_memset((void *) &rtn, 0, sizeof(rtn));
	while (!ft_isalnum(*str)|| *str == '0')
	{
		if (*str == '0')
		{
			rtn.zero = '0';
			rtn.idx++;
			str++;
			break;
		}
		else if (*str == '-')
			rtn.bar = 1;
		else if (*str == '*')
			rtn.star = 1;
		else if (*str == ',')
			rtn.dot = 1;
		else if (*str == '.')
			break;
		str++;
		rtn.idx++;
	}
	return (rtn);
}

t_width check_width(char *str)
{
	t_width rtn;

	ft_memset((void *) &rtn, 0, sizeof(rtn));
	rtn.num = ft_atoi(str);
	while (ft_isdigit(*str++))
		rtn.idx++;
	return (rtn);
}

t_prec check_prec(char *str)
{
	t_prec rtn;

	ft_memset((void *) &rtn, 0, sizeof(rtn));
	if (*str == '.')
	{
		rtn.dot = 1;
		rtn.idx++;
		str++;
		rtn.num = ft_atoi(str);
	}
	if (*str == '*' && rtn.idx)
	{
		rtn.star = 1;
		rtn.idx++;
	}
	else
		while (ft_isdigit(*str++))
			rtn.idx++;
	return (rtn);
}

t_type check_type(char *str)
{
	t_type rtn;

	ft_memset((void *) &rtn, 0, sizeof(rtn));
	if (*str == 'c')
		rtn.c = 1;
	else if (*str == 'd' || *str == 'i')
		rtn.d = 1;
	else if (*str == 's')
		rtn.s = 1;
	else if (*str == 'p')
		rtn.p = 1;
	else if (*str == 'u')
		rtn.u = 1;
	else if (*str == 'x')
		rtn.x = 1;
	else if (*str == 'X')
		rtn.x = 2;
	if (rtn.c || rtn.d || rtn.s || rtn.p || rtn.u || rtn.x)
		rtn.idx = 1;
	return (rtn);
}
