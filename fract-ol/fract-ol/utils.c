/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwookim <namwookim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 13:14:49 by namwkim           #+#    #+#             */
/*   Updated: 2021/07/25 12:26:12 by namwookim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	if (x < WIDTH && y < HEIGHT)
	{
		dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

int	throw_error(char *s)
{
	ft_putstr_fd(s, 2);
	return (0);
}
