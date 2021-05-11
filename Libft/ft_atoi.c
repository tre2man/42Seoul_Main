/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <namwkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 13:58:15 by namwkim           #+#    #+#             */
/*   Updated: 2021/05/08 19:00:56 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define INT32_MAX 2147483647
#define INT32_MIN -INT32_MAX - 1

static int		ft_iscontrol(char c)
{
	if (9 <= c && c <= 13)
		return (1);
	return (0);
}

int				ft_atoi(const char *str)
{
	long long	ans;
	int			minus;

	if (!str)
		return (0);
	ans = 0;
	minus = 1;
	while (*str != '+' && *str != '-' && *str
			&& (ft_iscontrol(*str) || *str == ' '))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			minus = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		ans = (ans * 10) + minus * (*str - '0');
		if (ans < INT32_MIN && INT32_MAX < ans)
			return (0);
		str++;
	}
	return ((int)ans);
}
