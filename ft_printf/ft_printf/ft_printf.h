/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <namwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:51:28 by namwkim           #+#    #+#             */
/*   Updated: 2021/06/14 17:48:58 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>

typedef struct		s_flag
{
	int				bar;
	int				zero;
	int				dot;
	int				star;
	int				idx;
}					t_flag;

typedef struct		s_width
{
	int				star;
	int				num;
	int				idx;
}					t_width;

typedef struct		s_prec
{
	int				dot;
	int				num;
	int				idx;
}					t_prec;

typedef struct		s_type
{
	int				c;
	int				s;
	int				p;
	int				d;
	int				u;
	int				x;
	int				X;
	int				pct;
	int				idx;
}					t_type;

typedef struct		s_all
{
	t_flag			flag;
	t_width			width;
	t_prec			prec;
	t_type			type;
}					t_all;

/*
** ft_printf.c
*/
int					ft_printf(const char *format, ...);
size_t				ft_check_fmt(va_list ap, char *format);
size_t				ft_parser(va_list ap, char *format);
size_t				fmt_spf_len(char *format);

/*
** utils1.c -> specifier parser
*/
t_flag				check_flag(char *str);
t_width				check_width(char *str);
t_prec				check_prec(char *str);
t_type				check_type(char *str);

/*
** utils2.c -> puts
*/
void				ft_printf_char(va_list ap, t_all all);
void				ft_printf_str(va_list ap, t_all all);
void				ft_printf_int(va_list ap, t_all all);

#endif
