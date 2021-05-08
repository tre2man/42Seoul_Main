/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <namwkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:52:32 by namwkim           #+#    #+#             */
/*   Updated: 2021/05/08 16:14:43 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_numlen(long int n)
{
	size_t		len;
	long int	check;

	len = 1;
	check = 10;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n / check)
	{
		check *= 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	char		*ans;
	size_t		len;
	size_t		check;
	size_t		isminus;

	len = ft_numlen((long int)n);
	ans = malloc(len + 1);
	ans[len] = '\0';
	if (n < 0)
	{
		check = -(unsigned int)n;
		ans[0] = '-';
		isminus = 1;
	}
	else
	{
		check = (unsigned int)n;
		isminus = 0;
	}
	while (len-- > isminus)
	{
		ans[len] = '0' + (check % 10);
		check /= 10;
	}
	return (ans);
}
