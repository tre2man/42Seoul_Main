/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwoo <namwoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 23:18:35 by namwoo            #+#    #+#             */
/*   Updated: 2021/06/19 23:42:07 by namwoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void     ft_print_str_(t_all all, char *str, int len, int width)
{
    if (!all.flag.bar)
		print_empty(all.flag.zero, width - len);
	write(1, str, len);
	if (all.flag.bar)
		print_empty(all.flag.zero, width - len);
}

/*
** 줄넘어감
*/
size_t			ft_printf_str(va_list ap, t_all all)
{
	char		*str;
	int			width;
	int			prec;
	int			len;

	prec = all.prec.num;
	width = all.width.num;
	if (all.flag.star)
		width = va_arg(ap, int);
	if (width < 0)
	{
		width *= -1;
		all.flag.bar = 1;
	}
	if (all.prec.star)
		prec = va_arg(ap, int);
	str = va_arg(ap, char *);
	len = ft_strlen(str);
	if ((len > prec) && (all.prec.dot == 1))
		len = prec;
    ft_print_str_(all, str, len, width);
	if (width - len < 0)
		return (len);
	else
		return (width);
}
