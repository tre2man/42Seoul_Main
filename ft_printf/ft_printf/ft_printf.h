/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <namwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 11:09:03 by namwoo            #+#    #+#             */
/*   Updated: 2021/06/28 20:36:43 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include "libft/libft.h"

#include <stdio.h>
#define BASE_X "0123456789ABCDEF"
#define BASE_x "0123456789abcdef"
#define BASE_D "0123456789"
#define FORMAT "cspiduxX%"

typedef unsigned long long	t_ulld;
typedef long long int		t_lld;

typedef struct				s_info
{
	int						minus;
	int						zero;
	int						width;
	int						prec;
	char					type;
}							t_info;

/*
** ft_printf.c
*/
int							ft_printf(const char *format, ...);

/*
** ft_printf_xxx.c
*/
int							printf_char(char c, t_info *info);
int							printf_str(char *str, t_info *info);
int							printf_uint(unsigned int i, t_info *info);
int							printf_ptr(void *ptr, t_info *info);
int							printf_int(int i, t_info *info);

/*
** utils1.c
*/
void						init_info(t_info *info);
void						print_empty(char c, int len);
int							num_len_int(t_lld n);
t_lld						format_len(char *format);

#endif