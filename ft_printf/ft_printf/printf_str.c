/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <namwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 13:16:45 by namwoo            #+#    #+#             */
/*   Updated: 2021/06/28 17:11:42 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				printf_str(va_list ap, t_info *info)
{
	int			len;
	char		*str;

	if (!(str = va_arg(ap, void*)))
		str = "(null)";
	len = ft_strlen(str);
	//printf("[%s %d %d]", str, info->width, info->prec);
	if (info->width < 0)
	{
		info->width *= -1;
		info->minus = 1;
	}
	if ((len > info->prec) && (info->prec >= 0) && (info->isprec))
		len = info->prec;
	if(!info->minus)
		print_empty(' ', info->width - len);
	if (info->isprec != 2 && len > 0)
		write(1, str, len);
	if (info->minus)
		print_empty(' ', info->width - len);
	if (info->width < len)
		return (len);
	else
		return (info->width);
}