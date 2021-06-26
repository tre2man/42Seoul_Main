/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwoo <namwoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 13:16:45 by namwoo            #+#    #+#             */
/*   Updated: 2021/06/25 13:16:17 by namwoo           ###   ########.fr       */
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
	if (info->width < 0)
	{
		info->width *= -1;
		info->minus = 1;
	}
	if ((len > info->prec) && (info->prec >= 0))
		len = info->prec;
	if(!info->minus)
		print_empty(' ', info->width - len);
	write(1, str, len);
	if (info->minus)
		print_empty(' ', info->width - len);
	if (info->width < len)
		return (len);
	else
		return (info->width);
}