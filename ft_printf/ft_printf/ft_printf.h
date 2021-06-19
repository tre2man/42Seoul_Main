/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwoo <namwoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:51:28 by namwkim           #+#    #+#             */
/*   Updated: 2021/06/19 23:24:54 by namwoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>

# include <stdio.h>

typedef unsigned long long	t_ulld;
typedef long long			t_lld;

typedef struct				s_flag
{
	int						bar;
	char					zero;
	int						dot;
	int						star;
	int						idx;
}							t_flag;

typedef struct				s_width
{
	int						num;
	int						idx;
}							t_width;

typedef struct				s_prec
{
	int						dot;
	int						num;
	int						star;
	int						idx;
}							t_prec;

typedef struct				s_type
{
	int						c;
	int						s;
	int						p;
	int						d;
	int						u;
	int						x;
	int						pct;
	int						idx;
}							t_type;

typedef struct				s_all
{
	t_flag					flag;
	t_width					width;
	t_prec					prec;
	t_type					type;
}							t_all;

/*
** ft_printf.c
*/
int							ft_printf(const char *format, ...);
size_t						ft_check_fmt(va_list ap, char *format);
size_t						ft_parser(va_list ap, char *format);
size_t						fmt_spf_len(char *format);

/*
** utils1.c -> specifier parser
*/
t_flag						check_flag(char *str);
t_width						check_width(char *str);
t_prec						check_prec(char *str);
t_type						check_type(char *str);

/*
** utils2.c -> flags, specifier, etc...
*/
void						print_empty(char c, int i);
void						ft_putnbr_len_fd(t_lld i, int num, int fd, int pf, int len);
int							ft_nbr_len(t_lld n, int num);

/*
** printf_xxx.c -> puts
*/
size_t						ft_printf_char(va_list ap, t_all all);
size_t						ft_printf_str(va_list ap, t_all all);
size_t						ft_printf_ptr(va_list ap, t_all all);
size_t						ft_printf_int(va_list ap, t_all all);

#endif
