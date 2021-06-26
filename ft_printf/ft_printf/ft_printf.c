/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwoo <namwoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 11:12:28 by namwoo            #+#    #+#             */
/*   Updated: 2021/06/25 22:13:43 by namwoo           ###   ########.fr       */
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
	else if (*format == 'X' || *format == 'x')
		return (printf_hex(ap, info));
	else
		return (printf_nbr(ap, info));
}

void			width_prec(va_list ap, char *format, t_info *info)
{
	int			num;

	while (*format == '.' || *format == '0')
	{
		if (*format == '.')
			info->prec = 0;
		format++;
	}
	num = ft_atoi(format);
	if (num < 0)
		format++;
	if (ft_isdigit(*format))
	{
		if (info->prec == -1 && !(info->width))
			info->width = num;
		else if (info->prec == 0)
			info->prec = num;
	}
	else if (*format == '*')
	{
		if (info->prec == -1 && !(info->width))
			info->width = va_arg(ap, int);
		else if (info->prec == 0)
			info->prec = va_arg(ap, int);
	}
}

t_lld			parser(va_list ap, char *format, t_info *info)
{
	if (*format == '0' || *format == '-')
	{
		if (*format == '0')
			info->zero = 1;
		if (*format == '-')
			info->minus = 1;
		format++;
	}
	while (*format && !ft_strchr(FORMAT, *format))
		width_prec(ap, format++, info);
	info->type = *format;
	if (info->zero == 1 && info->prec == -1 && info->width > 0)
	{
		info->prec = info->width;
		info->width = 0;
	}
	return (dtb_type(ap, info, format));
}

t_lld			check_fmt(va_list ap, char* format)
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
		if (format[idx] != '%')
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