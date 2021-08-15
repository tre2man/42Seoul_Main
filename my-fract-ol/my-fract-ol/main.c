/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwookim <namwookim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 13:05:15 by namwkim           #+#    #+#             */
/*   Updated: 2021/08/15 21:45:00 by namwookim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (throw_error(INPUT_ERROR));
	if (!ft_strncmp(argv[1], "Mandelbrot", ft_strlen("Mandelbrot") + 1))
	{
		if (!mandel_main())
			return (throw_error(MLX_ERROR));
	}
	else if (!ft_strncmp(argv[1], "Julia", ft_strlen("Julia") + 1))
	{
		if (!julia_main())
			return (throw_error(MLX_ERROR));
	}
		else if (!ft_strncmp(argv[1], "Ship", ft_strlen("Ship") + 1))
	{
		if (!ship_main())
			return (throw_error(MLX_ERROR));
	}
	else
		return (throw_error(INPUT_ERROR));
	return (0);
}
