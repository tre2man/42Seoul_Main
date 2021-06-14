/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <namwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 16:02:55 by namwkim           #+#    #+#             */
/*   Updated: 2021/06/14 18:11:48 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag			check_flag(char *str)
{
	t_flag		rtn;
	size_t		num;

	num = 0;
	ft_memset((void*)&rtn, 0, sizeof(rtn));
	while (ft_isdigit(*str))
	{
		if (*str == '0')
		{
			rtn.zero = 1;
			rtn.idx++;
			str++;
			break ;
		}
		else if (*str == '-')
			rtn.bar = 1;
		else if (*str == '*')
			rtn.star = 1;
		else if (*str == ',')
			rtn.dot = 1;
		str++;
		rtn.idx++;
	}
	return (rtn);
}

t_width			check_width(char *str)
{
	t_width		rtn;

	ft_memset((void*)&rtn, 0, sizeof(rtn));
	if (*str == '*')
	{
		rtn.star = 1;
		rtn.idx++;
	}
	else
	{
		rtn.star = ft_atoi(str);
		while (ft_isdigit(*str++))
			rtn.idx++;
	}
	return (rtn);
}

t_prec			check_prec(char *str)
{
	t_prec		rtn;

	ft_memset((void*)&rtn, 0, sizeof(rtn));
	if (*str == '.')
	{
		rtn.dot = 1;
		rtn.idx++;
		str++;
		rtn.num = ft_atoi(str);
		while (ft_isdigit(*str++))
			rtn.idx++;
	}
	return (rtn);
}

t_type			check_type(char *str)
{
	t_type		rtn;

	ft_memset((void*)&rtn, 0, sizeof(rtn));
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
		rtn.X = 1;
	if (rtn.c || rtn.d || rtn.s || rtn.p || rtn.u || rtn.x || rtn.X)
		rtn.idx = 1;
	return (rtn);
}
