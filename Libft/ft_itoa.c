/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <namwkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:52:32 by namwkim           #+#    #+#             */
/*   Updated: 2021/05/13 17:35:41 by namwkim          ###   ########.fr       */
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

static void		ft_init(int n, char **ans,
						size_t *isminus, unsigned long *check)
{
	if (n < 0)
	{
		*check = -(unsigned long)n;
		*ans[0] = '-';
		*isminus = 1;
	}
	else
	{
		*check = (unsigned long)n;
		*isminus = 0;
	}
}

char			*ft_itoa(int n)
{
	char		*ans;
	size_t		len;
	size_t		check;
	size_t		isminus;

	len = ft_numlen((long int)n);
	if (!(ans = malloc(len + 1)))
		return (0);
	ans[len] = '\0';
	ft_init(n, &ans, &isminus, &check);
	while (len-- > isminus)
	{
		ans[len] = '0' + (check % 10);
		check /= 10;
	}
	return (ans);
}
