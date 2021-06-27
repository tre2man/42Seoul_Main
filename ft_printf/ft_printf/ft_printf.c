/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwoo <namwoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 11:12:28 by namwoo            #+#    #+#             */
/*   Updated: 2021/06/27 12:40:06 by namwoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_lld			dtb_type(va_list ap, t_info *info, char *format)
{
	if (*format == 's')
		return (printf_str(ap, info));
	else if (*format == 'c' || *format == '%')
		return (printf_char(ap, info, format));
	else if (*format == 'p')
		return (printf_ptr(ap, info));
	else if (*format == 'X' || *format == 'x' || *format == 'u')
		return (printf_uint(ap, info));
	else
		return (printf_int(ap, info));
}

void			width_prec(va_list ap, char *format, t_info *info)
{
	int			num;

	if (*format == '.')
	{
		info->isprec = 1;
		format++;
	}
	num = ft_atoi(format);
	if (num < 0)
		format++;
	if (ft_isdigit(*format))
	{
		if (info->isprec == 0 && !(info->width))
			info->width = num;
		else if (info->isprec == 1 && !(info->prec))
			info->prec = num;
	}
	else if (*format == '*')
	{
		if (info->isprec == 0 && !(info->width))
			info->width = va_arg(ap, int);
		else if (info->isprec == 1 && !(info->prec))
			info->prec = va_arg(ap, int);
	}
}

t_lld			parser(va_list ap, char *format, t_info *info)
{
	while (*format && ft_strchr("-0", *format))
	{
		if (*format == '-')
			info->minus = 1;
		if (*format == '0' && !info->minus)
			info->zero = 1;
		format++;
	}
	while (*format && !ft_strchr(FORMAT, *format))
		width_prec(ap, format++, info);
	//printf("[%d %d]", info->width, info->prec);
	/* 맨 앞에 0이 있으면서 prec가 0으로 정의되었다면, prec을 width로 변경 */
	/*
	if (info->zero && !info->isprec && !info->minus)
	{
		info->prec = info->width;
		if (info->prec < 0)
			info->prec *= -1;
		info->width = 0;
	}
	*/
	info->type = *format;
	return (dtb_type(ap, info, format));
}

t_lld			check_fmt(va_list ap, char *format)
{
	t_info		*info;
	int			idx;
	int			rtn;
	int			temp;

	if (!(info = malloc(sizeof(t_info))))
		return (-1);
	idx = 0;
	rtn = 0;
	while (format[idx])
	{
		if (format[idx] && format[idx] != '%')
		{
			ft_putchar_fd(format[idx++], 1);
			rtn++;
		}
		else
		{
			init_info(info);
			rtn += parser(ap, &format[idx + 1], info);
			idx += format_len(&format[idx]);
		}
	}
	free(info);
	return (rtn);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	int			rtn;

	rtn = 0;
	va_start(ap, format);
	rtn = (int)check_fmt(ap, (char*)format);
	va_end(ap);
	return (rtn);
}