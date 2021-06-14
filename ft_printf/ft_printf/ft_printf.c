/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <namwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:51:32 by namwkim           #+#    #+#             */
/*   Updated: 2021/06/14 18:10:43 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		fmt_spf_len(char *format)
{
	size_t	len;

	len = 0;
	while (*format++)
	{
		len++;
		if (ft_strchr("cspdiuxX%", *format))
			return (len);
	}
	return (0);
}

size_t		ft_parser(va_list ap, char *format)
{
	t_all all;

	format++;
	all.flag = check_flag(format);
	all.width = check_width(format += all.flag.idx);
	all.prec = check_prec(format += all.width.idx);
	all.type = check_type(format += all.prec.idx);
	if (all.type.c)
		ft_printf_char(ap, all);
	else if (all.type.s)
		ft_printf_str(ap, all);
	else
		ft_printf_int(ap, all);
	return (all.flag.idx + all.width.idx + all.prec.idx + all.type.idx);
}

size_t		ft_check_fmt(va_list ap, char *format)
{
	size_t	rtn;
	size_t	len;
	size_t	idx;

	len = ft_strlen(format);
	rtn = 0;
	idx = 0;
	while (format[idx])
	{
		if (format[idx] != '%')
		{
			ft_putchar_fd(format[idx++], 1);
			rtn++;
		}
		else
		{
			rtn += (int)ft_parser(ap, &format[idx]);
			idx += (int)fmt_spf_len(&format[idx]);
		}
	}
	return (rtn);
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	int		rtn;

	rtn = 0;
	va_start(ap, format);
	rtn = (int)ft_check_fmt(ap, (char*)format);
	va_end(ap);
	return (rtn);
}
