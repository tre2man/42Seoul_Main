/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <namwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 11:12:28 by namwoo            #+#    #+#             */
/*   Updated: 2021/06/29 20:36:46 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_lld			dtb_type(va_list ap, t_info *info, char *format)
{
	if (*format == 's')
		return (printf_str((char *)va_arg(ap, void*), info));
	else if (*format == 'c')
		return (printf_char((char)va_arg(ap, int), info));
	else if (*format == '%')
		return (printf_char('%', info));
	else if (*format == 'p')
		return (printf_ptr(va_arg(ap, void*), info));
	else if (*format == 'X' || *format == 'x' || *format == 'u')
		return (printf_uint((unsigned int)va_arg(ap, int), info));
	else
		return (printf_int(va_arg(ap, int), info));
}

void			width_prec(va_list ap, char *format, t_info *info)
{
	int			num;

	if (*format == '.')
		info->prec = 0;
	num = ft_atoi(format);
	if (ft_isdigit(*format))
	{
		if (info->prec == -1 && !(info->width))
			info->width = num;
		else if (info->prec >= 0 && !(info->prec))
			info->prec = num;
	}
	else if (*format == '*')
	{
		if (info->prec == -1 && !(info->width))
			info->width = va_arg(ap, int);
		else if (info->prec >= 0 && !(info->prec))
			info->prec = va_arg(ap, int);
	}
}

t_lld			parser(va_list ap, char *format, t_info *info)
{
	while (*format && ft_strchr("-0", *format))
	{
		if (*format == '-')
			info->minus = 1;
		if (*format == '0')
			info->zero = 1;
		format++;
	}
	while (*format && !ft_strchr(FORMAT, *format))
		width_prec(ap, format++, info);
	if (info->prec < 0)
		info->prec = -1;
	if (info->width < 0)
	{
		info->width *= -1;
		info->minus = 1;
	}
	info->type = *format;
	return (dtb_type(ap, info, format));
}

t_lld			check_fmt(va_list ap, char *format)
{
	t_info		*info;
	int			idx;
	int			rtn;

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
