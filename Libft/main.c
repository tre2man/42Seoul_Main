/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <namwkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 14:45:49 by namwkim           #+#    #+#             */
/*   Updated: 2021/05/08 19:23:27 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

int main()
{
	char *s1 = "lol";
    char *s2 = "\t \n";
	char dest[15];
	int i = 0;
	
	ft_putstr_fd(ft_strdup(s1), 1);
}